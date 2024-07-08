%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define bool int
#define TRUE 1
#define FALSE 0
#define LACO 1
#define BLOCO 0
#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;
string Tipagens;
int qtd_simb;
int qtd_tabelas;
int qtd_laco;


struct escopo{
	string label;
	int tipo;
};

struct tabelaSimbolos{
	string nome;
	string tipo;
	string classe;
	string endereco;
	string tam;
	string dim;
	int mod;
	string val;
};
struct atributos
{
	string label;
	string traducao;
	string tipo;
	string classe;
	string val;
	string tam;
};

std::vector <atributos> listaattr;
std::vector<atributos>ref_switch;
std::vector <tabelaSimbolos> listaSimb;
std::vector <escopo> infobloco;
std::vector<vector<tabelaSimbolos>>listaEscopo;

int yylex(void);
void yyerror(string);
string gentempcode(string tipo);
string gentemplabel();
string imprimirFree();
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso, string tamanho, string nDim);
tabelaSimbolos buscarSimbolos(string nome);
atributos funcString(atributos e1, string operador, atributos e2);
atributos buscaEnd(string nome);
escopo buscarbloco(int k);
void modatrib(string nome, string tam);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
void limparpilha();

bool traducao(string op);
%}

%token TK_NUM TK_REAL TK_CHAR TK_STRING TK_BOOL 
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_STRING  TK_GLOBAL TK_LOCAL
%token TK_TIPO_CHAR TK_TIPO_BOOL TK_CONV
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_MAIOR TK_MENOR TK_IGUALDADE TK_DESIGUALDADE
%token TK_CONJUNCAO TK_DISNJUNCAO
%token TK_ALT TK_START
%token TK_SCANNER TK_PRINT
%token TK_IF TK_ELSE TK_DO TK_WHILE TK_FOR TK_SWITCH TK_CASE TK_DEFAULT TK_BREAK TK_NEXT 
%token TK_FIM TK_ERROR

%start S

%right TK_DISNJUNCAO
%right TK_CONJUNCAO 

%right TK_IGUALDADE  TK_DESIGUALDADE
%right TK_MENOR TK_MENOR_IGUAL TK_MAIOR TK_MAIOR_IGUAL

%left '+' '-'
%left '*' '/' '%'
%left '^'

%%

S 			:   CODS
			{
				int i;
				string codigo = "/*Compilador FOCA*/\n"
								"#include <iostream>\n"
								"#include<string.h>\n"
								"#include<stdio.h>\n"
								"#define TRUE 1\n"
								"#define FALSE 0\n"
								"#define bool int\n"
								"int main(void) {\n";	
				for(i=0; i<listaattr.size(); i++){
					if(listaattr[i].tipo.compare("string") == 0){
						listaattr[i].tipo = "char*";
					}
					codigo += "\t" + listaattr[i].tipo +" "+ listaattr[i].label + ";\n";
				};
				codigo+= "\n";
				codigo += $1.traducao + "\n";
								
				codigo += 	"\treturn 0;"
							"\n}";
				
				cout << codigo << endl;

				limparpilha();

				//checarlista();
			}
			;

CODS		: COD CODS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			};
			
COD         : TK_TIPO_INT TK_MAIN '(' ')' BLOCO
            {
				$$.traducao = $5.traducao;
            }
			| COMANDOS
			{
				$$.traducao = $1.traducao + imprimirFree();
				listaEscopo.pop_back();
				infobloco.pop_back();
				//cout << " tamanho final de escopo, vazio " << listaEscopo.size() << endl;
			}

BLOCO		: INIT COMANDOS '}'
			{
				//cout << listaEscopo.size();
				/*std::vector<tabelaSimbolos>v1;
				listaEscopo.push_back(v1);
				qtd_tabelas++;
				cout << "quantidade de escopo: "<<  qtd_tabelas << endl;*/
				$$.traducao = $2.traducao + imprimirFree();
				listaEscopo.pop_back();
				infobloco.pop_back();
				//cout << " tamanho final de escopo " << listaEscopo.size() << endl;
			}
			;

INIT		: TK_START
			{
				//cout << "cheguei" << endl;
				vector<tabelaSimbolos> v1;
				escopo x; 
				x.label = "";
				x.tipo = BLOCO;
				
				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				//cout << " tamanho inicio de escopo " << listaEscopo.size() << endl;
			}
			;

INIB		: TK_START
			{
				escopo x;
				vector<tabelaSimbolos> v1;
				x.label = gentemplabel();
				x.tipo = LACO;

				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				//cout<< "bloco laço, tamanho pilha "<< listaEscopo.size() << endl;
			}
			;


COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			{
				$$ = $1;
			}
			|CONTROLES
			{
				$$ = $1;
			}
			| TK_TIPO_INT MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "int", "Number", $2.label, "0", "0");
			}
			| TK_TIPO_FLOAT MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "float", "Number", $2.label, "0","0");
			}
			| TK_TIPO_CHAR MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "char", "String", $2.label, "0", "0");
			}
			| TK_TIPO_BOOL MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "bool", "Boolean", $2.label, "0", "0");
			}
			| TK_TIPO_STRING MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "string", "String", $2.label, "0", "0");
			}
			| TK_TIPO_INT MODO LISTA_ID REF_ARRAY ';'
			{
				tabelaSimbolos flag;
				string l1;
				if($4.tipo.compare("int") != 0){
					yyerror("Tipo incompativel para declarar tamanho");
				}
				inserirSimbolos($3.label, "int", "Number", $2.label, $4.label, $4.val);
				flag = buscarSimbolos($3.label);
				l1 = gentempcode("int");

				if($4.val.compare("0") == 0){
				$$.traducao = $4.traducao + "\t" + l1 + " = (int*) malloc(" + $4.label+ ");\n" +"\t" +flag.endereco+ "[0] = " +l1+";\n"; 
				}else{
					$$.traducao = $4.traducao + "\t" + l1 + " = (int*) malloc(" +$4.val+ "*" + $4.label+  ");\n" +"\t" +flag.endereco+ "[0] = " +l1+";\n"; 
				}


			}
			| TK_TIPO_FLOAT MODO LISTA_ID REF_ARRAY ';'
			{
				tabelaSimbolos flag;
				string l1;
				inserirSimbolos($3.label, "float", "Number", $2.label, $4.label, $4.val);
				flag = buscarSimbolos($3.label);
				l1 = gentempcode("float");
				$$.traducao = $4.traducao + "\t" + l1 + " = (float*) malloc(" + $4.val+"*" +$4.label+ ");\n" +"\t" +flag.endereco+ "[0] = " +l1+";\n";
			}
			| TK_TIPO_STRING MODO LISTA_ID REF_ARRAY ';'
			{
				tabelaSimbolos flag;
				string l1;
				inserirSimbolos($3.label, "string", "String", $2.label, $4.label, $4.val);
				flag = buscarSimbolos($3.label);
				l1 = gentempcode("char");
				$$.traducao = $4.traducao + "\t" + l1 + " = (char*) malloc(" + $4.val+ "*" +$4.label+ ");\n" +"\t" +flag.endereco+ "[0] = " +l1+";\n";
			}
			|TK_SCANNER'('TK_ID')'';'{
				tabelaSimbolos flag;
				flag=buscarSimbolos($3.label);
				$$.label=flag.nome;
				$$.tipo=flag.tipo;
				if(flag.tipo.compare("string")==0 && flag.tam.compare("0") !=0){
					$$.traducao="\tfree("+flag.endereco+")\n\tcin>>"+flag.endereco+";\n";
				}else{
					$$.traducao="\tcin>>"+flag.endereco+";\n";
				}
				if(flag.tipo.compare("string")==0){
				  string cout=gentempcode("int");
				  string temp=gentempcode("int");
				  string varChar=gentempcode("char");
				  string e1=gentempcode("char");
				  string e2=gentempcode("char");
				  string rel=gentempcode("bool");
				  string relneg=gentempcode("bool");

				  modatrib(cout, "0");
				  modatrib(temp, "0");
				  modatrib(varChar, "1");
				  modatrib(e1, "1");
				  modatrib(e2, "1");
				  modatrib(rel, "0");
				  modatrib(relneg, "0");

				  $$.traducao= $$.traducao+"\t"+cout+" = 0;\n\t"+
				  varChar+" = "+flag.endereco+"["+cout+"];\n\tInicio_"+rel+":\n"
				  +"\t"+e1+" = "+varChar+";\n\t"+e2+" = '\\0';\n"+
				  "\t"+rel+" = "+e1+" != "+e2+";\n"+
				  "\t"+relneg+" = !"+rel+";\n"+
				  "\tIF("+relneg+") goto Fim "+rel+";\n\t"+
				  temp+" = "+cout+";\n\t"+cout+" = "+temp+" + 1;\n\t"+
				  varChar+" = "+flag.endereco+"["+cout+"];\n"
				 +"\tgoto Inicio_"+rel+";\n\tFim "+rel+":\n";
				 flag.tam = cout;
				 alterarSimbolos(flag);
				}	

			}
			|TK_PRINT'('E')'';'{
				$$.traducao=$3.traducao+"\tcout<<"+$3.label+"<<endl;\n";
				if($3.tipo.compare("string")==0){
				 $$.traducao=$$.traducao+"\tfree("+$3.label+");\n";
				}
			}
			;

LISTA_ID	: TK_ID ',' LISTA_ID
			{
				$$.label = $1.label;
			}
			|TK_ID
			{
				$$.label = $1.label;
			};
MODO		: TK_GLOBAL
			{
				$$.label = "global";
			}
			| TK_LOCAL
			{
				$$.label = "local";
			}
			|
			{
				$$.label = "global";
			};
REF_ARRAY   : '[' E ']'
            {
				if($2.tipo.compare("int") == 0){
				$$.label = $2.label;
				$$.tipo = $2.tipo;
				$$.val = "0";
				$$.traducao = $2.traducao;
				}else{
					yyerror("Tipo incompativel para declaração de tamanho ");
				}

			}
			| '[' E ']''[' E ']'
			{
				if($2.tipo.compare("int") == 0 &&  $5.tipo.compare("int") == 0){
					$$.label = $5.label;
				    $$.tipo = $2.tipo;
					$$.val = $2.label;
					$$.traducao = $2.traducao + $5.traducao;
				}else{
					yyerror("Tipo incompativel para declaração de tamanho ");
				}
			}
CONTROLES	: TK_IF E BLOCO
			{
				string jp;
				atributos tst;
				if($2.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				tst.traducao = "\t"+tst.label + " = " +"!"+ $2.label+";\n";
				jp = $2.traducao + tst.traducao+"\tif("+ tst.label+") goto IF-"+tst.label+";\n";

				$$.traducao = jp + $3.traducao +"\tIF-"+ tst.label + ";\n";


			}
			|TK_IF E BLOCO TK_ELSE BLOCO
			{
				string jp, finif;
				atributos tst;
				atributos tfin;
				if($2.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				tst.traducao = "\t"+tst.label + " = " +"!"+ $2.label+";\n";
				jp = $2.traducao + tst.traducao+"\tif("+ tst.label+") goto IF-"+tst.label+";\n";
				
				tfin.label = gentempcode("bool");
				tfin.traducao = "\tgoto Else-" + tfin.label +";\n";
				
				$$.traducao = jp + $3.traducao + tfin.traducao +"\tIF-"+ tst.label +";\n" +  $5.traducao +"\tElse-" + tfin.label +";\n";

			}
			|TK_WHILE E INIB COMANDOS '}'
			{
				string jp, ciclowhile, iniwhile;
				atributos tst;
				escopo laco;
				if($2.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				laco = buscarbloco(1);
				tst.traducao = "\t"+tst.label + " = " +"!"+ $2.label+";\n";

				iniwhile = "\tinicio_"+laco.label+";\n" ;
				jp =  iniwhile +$2.traducao + tst.traducao+"\tif("+ tst.label+") goto FIM "+laco.label+";\n";
				ciclowhile = "\tgoto inicio_"+laco.label +";\n";
				$$.traducao = jp + $4.traducao + ciclowhile + "\tFIM "+laco.label+";\n";
				$$.traducao += imprimirFree();
				listaEscopo.pop_back();
				infobloco.pop_back();
				//cout << " tamanho final de escopo, while" << listaEscopo.size() << endl;
				
			} 
			|TK_DO INIB COMANDOS '}' TK_WHILE E ';'
			{
				string jp, ciclowhile, iniwhile;
				atributos tst;
				escopo laco;
				if($6.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				laco = buscarbloco(1);
				iniwhile = "\tinicio_"+laco.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ $6.label+";\n";
				jp = iniwhile +$3.traducao + imprimirFree()+ $6.traducao + tst.traducao+"\tif("+ tst.label+") goto FIM "+laco.label+";\n";
				ciclowhile = "\tgoto inicio_"+tst.label +";\n";
				$$.traducao = jp + ciclowhile + "\tFIM "+laco.label+";\n";

				listaEscopo.pop_back();
				infobloco.pop_back();
				//cout << " tamanho final de escopo, Do while" << listaEscopo.size() << endl;
			}
			|TK_FOR '(' ATB ';' E ';' E')' INIB COMANDOS '}'
			{
				escopo laco;
				atributos tst;
				string jp, E1, atrib, cicloI, cicloF;
				if($3.classe.compare("Number") != 0 and $5.classe.compare("Boolean") != 0){
					yyerror("Atribuição incorreta para essa operação");
				}
				
				tst.label = gentempcode("bool");
				laco = buscarbloco(1);
				cicloI = "\tinicio_"+laco.label +";\n";
				

				tst.traducao = "\t"+tst.label + " = " +"!"+ $5.label+";\n";
				cicloF = "\tgoto inicio_"+laco.label +";\n";
				jp = $3.traducao + cicloI+ $5.traducao + tst.traducao+"\tif("+ tst.label+") goto FIM "+laco.label+";\n";

				$$.traducao = jp + $10.traducao + imprimirFree()+ $7.traducao + cicloF +"\tFIM "+ laco.label + ";\n";
				listaEscopo.pop_back();
				infobloco.pop_back();
				//cout << " tamanho final de escopo, for" << listaEscopo.size() << endl;

			}
			| TK_SWITCH REF INIB CASES '}'
			{
				string fim;
			 	escopo laco;

				laco = buscarbloco(1);
				fim = "\tFIM " + laco.label + ";\n";
				$$.traducao = $2.traducao + $4.traducao + imprimirFree() +fim;

				listaEscopo.pop_back();
				infobloco.pop_back();
				ref_switch.clear();
			}
			;

REF			: E
			{
				atributos x;
				x.label = $1.label;
				ref_switch.push_back(x);
				$$.traducao = $1.traducao;
			}
CASES		: CASE CASES
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			};

CASE		: TK_CASE E INIT COMANDOS
			{
				escopo laco;
				atributos tst, comp, ref;
				int cont;
				string inicio, jp; 

				comp.label = gentempcode("bool");
				tst.label = gentempcode("bool");
				cont = ref_switch.size() -1;
				ref = ref_switch[cont];

				laco = buscarbloco(1);
			
				comp.traducao = "\t" + comp.label + " = " + ref.label +" == "+ $2.label +";\n";
				
				tst.traducao = "\t"+tst.label + " = " +"!"+ comp.label+";\n";

				jp = $2.traducao + comp.traducao + tst.traducao+"\tif("+ tst.label+") goto IF-"+tst.label+";\n";
				
				$$.traducao = jp + $4.traducao +"\tIF-"+ tst.label +";\n";
				listaEscopo.pop_back();
				infobloco.pop_back();

			}
			| TK_DEFAULT INIT COMANDOS
			{
				$$.traducao = $3.traducao;
				listaEscopo.pop_back();
				infobloco.pop_back();
				
			};

E 			: E '+' E
			{
				int r1;
				int result;
				float r2;

				if(($1.tipo.compare("string") == 0||$1.tipo.compare("char") == 0 )&&($3.tipo.compare("string") == 0||$3.tipo.compare("char") == 0)){
					atributos resultado = funcString($1, "+", $3);
					$$.label = gentempcode(resultado.tipo);
					$$.tipo = resultado.tipo;
					atributos temp1=buscaEnd($1.label);
					atributos temp2=buscaEnd($3.label);
					atributos temp3=buscaEnd(resultado.label);
					string label4=gentempcode("int");
					string label5=gentempcode("int");

				//	cout << "traducao de $2" << $2.traducao << endl;
					//cout << "traducao de soma" << resultado.traducao << endl;

					if(temp1.tipo.compare("char") == 0 && temp2.tipo.compare("char") == 0){
						string vetor2= gentempcode("string");
						string labelx2=gentempcode("int");

						$$.traducao=resultado.traducao+"\t"+labelx2+" =  2;\n\t"+vetor2+"= (char*)malloc("+labelx2+");\n\t"+vetor2+"[0] = "+$1.label+";\n";

						$$.traducao += "\t"+label4+" = "+labelx2+"- 1;\n\t"+
						label5+"="+temp3.tam+"+"+label4+";\n";
						modatrib($$.label, label5);
						$$.traducao += "\t"+$$.label+" = (char*) malloc("+label5+");\n"+
					"\t"+$$.label+" = strcat("+resultado.label+","+vetor2+");\n"+"\tfree("+vetor2+");\n";
					}
					else if(temp1.tipo.compare("char")==0){
						$$.traducao = resultado.traducao+"\t"+label4+" = "+temp2.tam+"- 1;\n\t"+
						label5+"="+temp3.tam+"+"+label4+";\n";
						modatrib($$.label, label5);
						$$.traducao = $$.traducao+ "\t"+$$.label+" = (char*) malloc("+label5+");\n"+
					"\t"+$$.label+" = strcat("+resultado.label+","+$3.label+");\n"+"\tfree("+$3.label+");\n";
					}else{
						$$.traducao = resultado.traducao+"\t"+label4+" = "+temp3.tam+"- 1;\n\t"+
						label5+"="+temp1.tam+"+"+label4+";\n";
						modatrib($$.label, label5);

						$$.traducao += "\t"+$$.label+" = (char*) malloc("+label5+");\n"+
						"\t"+$$.label+" = strcat("+$1.label+","+resultado.label+");\n"+"\tfree("+resultado.label+");\n";
					}
					// $$.traducao = elemento.traducao+
					// "\t"+label4+"="+temp2.tam+"- 1;\n\t"+
					// label5+"="+temp1.tam+"+"+temp2.tam+";\n";

					// insereTabela($$.label,$$.tipo,true,"",label5);
					// $$.traducao = $$.traducao+ "\t"+$$.label+"= (char*) malloc("+label5+");\n"
					// +"\t"+$$.label+" = strcat("+$1.label+","+$3.label+") ;\n"+"\tfree("+$3.label+");\n"; 
				}
				else if($1.tipo.compare($3.tipo) != 0 ){
					atributos conv;
					int x;
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						x = 1;

					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("char") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + " = " + "(int) " + $3.label + ";\n"; 
						$3.tipo = "int";
						x = 1;

					}else if($1.tipo.compare("char") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + "=" + "(int) " + $1.label + ";\n"; 
						$1.tipo = "int";
						x = 0;
						
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
					
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " + " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " + " + conv.label + ";\n";
					}

				}
				else{
					if($1.tipo.compare("bool")==0){
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " + " + $3.label + ";\n";
				}
				$$.val = $1.val + "+" + $3.val;
				
				/*parser.SetExpr($$.val);
				result = parser.Eval();
				cout << "conta" << $$.val << " = "<< result << endl;*/
				
			}
			| E '-' E
			{
				int r1;
				float r2;
				if($1.tipo.compare($3.tipo) != 0 ){
					atributos conv;
					int x;
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
					
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " - " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " - " + conv.label + ";\n";
					}

				}
				else{
					if($1.tipo.compare("bool")==0 || $1.tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " - " + $3.label + ";\n";
				}
				
			}
			| E '*' E
			{
				int r1;
				float r2;
				if($1.tipo.compare($3.tipo) != 0 ){
					atributos conv;
					int x;
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
					
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " * " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " * " + conv.label + ";\n";
					}

				}
				else{
					if($1.tipo.compare("bool")==0 || $1.tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " * " + $3.label + ";\n";
				}
				
			}
			| E '/' E
			{
				int r1;
				float r2;
				if($1.tipo.compare($3.tipo) != 0 ){
					atributos conv;
					int x;
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
					
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " / " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " / " + conv.label + ";\n";
					}

				}
				else{
					if($1.tipo.compare("bool")==0 || $1.tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " / " + $3.label + ";\n";
				}
				
			}
			| E '%' E
			{
				int r1;
				float r2;
				if($1.tipo.compare($3.tipo) != 0 ){
					atributos conv;
					int x;
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + " = " + "(int) " + $1.label + ";\n"; 
						$1.tipo = "float";
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + " = " + "(int) " + $3.label + ";\n"; 
						$3.tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
					
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " % " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " % " + conv.label + ";\n";
					}

				}
				else{
					if($1.tipo.compare("bool")==0 || $1.tipo.compare("char") == 0 || $1.tipo.compare("float") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " % " + $3.label + ";\n";
				}
				
			}
			| E '^' E
			{
				int r1;
				float r2;
				if($1.tipo.compare($3.tipo) != 0 ){
					atributos conv;
					int x;
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
					
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " ^ " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " ^ " + conv.label + ";\n";
					}

				}
				else{
					if($1.tipo.compare("bool")==0 || $1.tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					
					$$.label = gentempcode($1.tipo);
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " ^ " + $3.label + ";\n";
				}
				
			}
			| '-' E
			{
				if($2.tipo.compare("int") == 0 or $2.tipo.compare("float") == 0){
					$$.label = gentempcode($2.tipo);
					$$.tipo = $2.tipo;
					$$.traducao = $2.traducao + "\t" + $$.label + 
							" = " + "-" + $2.label + ";\n";

				}else{
					yyerror("Tipo da expressão é incompativel para essa operação");
				}
			}
			| '(' E ')'
			{
				$$.label = $2.label;
				$$.tipo = $2.tipo;
				$$.traducao = $2.traducao + "\t" + $$.label + " = " + $2.label +";\n";
			}
			| E TK_MAIOR_IGUAL E
			{
				bool x;
				atributos conv; 
				if($1.tipo.compare($3.tipo) != 0){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n";
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " >= " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " >= " + conv.label + ";\n";
					}
				}else{
					if($1.traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " >= " + $3.label + ";\n";
				}
				
			}
			| E TK_MENOR_IGUAL E
			{
				bool x;
				atributos conv; 
				if($1.tipo.compare($3.tipo) != 0){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n";
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " <= " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " <= " + conv.label + ";\n";
					}
				}else{
					if($1.traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " <= " + $3.label + ";\n";
				}
			}
			| E TK_MAIOR E
			{
				bool x;
				atributos conv; 
				if($1.tipo.compare($3.tipo) != 0){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n";
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " > " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " > " + conv.label + ";\n";
					}
				}else{
					if($1.traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " > " + $3.label + ";\n";
				}
			}
			| E TK_MENOR E
			{
				bool x;
				atributos conv; 
				if($1.tipo.compare($3.tipo) != 0){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n";
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " < " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " < " + conv.label + ";\n";
					}
				}else{
					if($1.traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " < " + $3.label + ";\n";
				}
			}
			| E TK_IGUALDADE E
			{
				bool x;
				atributos conv; 
				if($1.tipo.compare($3.tipo) != 0){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $1.label + ";\n";
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " == " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " == " + conv.label + ";\n";
					}
				}else{
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " == " + $3.label + ";\n";
				}
			}
			| E TK_DESIGUALDADE E
			{
				bool x;
				atributos conv; 
				if($1.tipo.compare($3.tipo) != 0){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $1.label + ";\n";
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $3.label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					
					if(x == 0){
					$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + conv.label + " != " + $3.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $3.traducao + conv.traducao +"\t" + $$.label + 
							" = " + $1.label + " != " + conv.label + ";\n";
					}
				}else{
					$$.label = gentempcode("bool");
					$$.tipo = "bool";
					$$.classe = "Boolean";
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " != " + $3.label + ";\n";
				}
			}
			| E TK_CONJUNCAO E
			{
				bool x;
				if($1.tipo.compare("bool") == 0 && $3.tipo.compare("bool") == 0){
					x = traducao($1.val) && traducao($3.val);
				}else{
					yyerror("Tipos incompativeis para essa operação");
				}

				$$.val = $1.label +" && " + $3.label;
				$$.label = gentempcode("bool");
				$$.tipo = "bool";
				$$.classe = "Boolean";

				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " && " + $3.label + ";\n";
			}
			| E TK_DISNJUNCAO E
			{
				bool x;
				if($1.tipo.compare("bool") == 0 && $3.tipo.compare("bool") == 0){
					x = traducao($1.val) || traducao($3.val);
				}else{
					yyerror("Tipos incompativeis para essa operação");
				}


				$$.val = $1.label +" || " + $3.label;
				$$.label = gentempcode("bool");
				$$.tipo = "bool";
				$$.classe = "Boolean";

				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " || " + $3.label + ";\n";
			}
			| '!'E
			{
				bool x;
				if($2.tipo.compare("bool") == 0){
					x = !traducao($2.val);
				}else{
					yyerror("Tipo incompativeis para essa operação");
				}
				$$.val = "!" +$2.label;
				$$.label = gentempcode("bool");
				$$.tipo = "bool";
				$$.classe = "Boolean";

				$$.traducao = $2.traducao + "\t" + $$.label + 
						" = " +"!"+ $2.label + ";\n";
			}
			| E TK_ALT
			{
				string x;
				if($1.classe.compare("Number") != 0){
					yyerror("Tipo incompativeis para essa operação");
				}
				$$.label = $1.label;
				//cout << "incremento da var"<< $$.label <<endl;
				$$.tipo = $1.tipo;
				$$.classe = $1.classe;

				$1.tipo.compare("int") == 0 ?  x = "1" : x = "1.0000";
				$$.traducao = $1.traducao + "\t" + $$.label + " = " + $1.label + " "+ $2.label[0] + " "+ x +";\n";
				
			}
			| '(' TK_TIPO_INT ')' E
			{
				int conv;
				if($4.tipo.compare("int") == 0 || $4.tipo.compare("float") == 0){
					$$.label = gentempcode("int");
					$$.tipo = "int";
					conv = stoi($4.val);
					$$.val = to_string(conv);
					$$.traducao = $4.traducao + "\t" + $$.label + " = " + "(int) " + $4.label + ";\n"; 
				}else{
					yyerror("Tipo de expressão incompativel para a conversão");
				}
			}
			| '(' TK_TIPO_FLOAT ')' E
			{
				float conv;
				if($4.tipo.compare("int") == 0 || $4.tipo.compare("float") == 0){
					$$.label = gentempcode("int");
					$$.tipo = "float";
					conv = stof($4.val);
					$$.val = to_string(conv);
					$$.traducao =  $4.traducao +"\t" + $$.label + " = " + "(float) " + $4.label+";\n"; 
				}else{
					yyerror("Tipo de expressão incompativel para a conversão");
				}

			}
			| '(' TK_TIPO_BOOL ')' E
			{
				if($4.tipo.compare("bool") != 0){
				yyerror("Tipo de expressão incompativel para a conversão");
				}
				$$.label = gentempcode("bool");
				$$.tipo = $4.tipo;
				$$.traducao =  $4.traducao +"\t" + $$.label + " = " + "(bool) " + $4.label+";\n"; 
			}
			| ATB
			{
				$$.traducao = $1.traducao;
			}
			| C_LOOP
			{
				$$.traducao = $1.traducao;
			}
			| TK_NUM
			{
				$$.label = gentempcode("int");
				$$.tipo = "int";
				$$.classe = "Number";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";

				//cout << "Variavel atribuida " << $$.val << endl;
			}
			| TK_REAL
			{
				$$.label = gentempcode("float");
				$$.tipo = "float";
				$$.classe = "Number";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_CHAR
			{
				$$.label = gentempcode("char");
				$$.tipo = "char";
				$$.classe = "String";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			|TK_BOOL{
				$$.label = gentempcode("bool");
				$$.tipo = "bool";
				$$.classe = "Boolean";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label +";\n";
			}
			|TK_STRING
			{
				string l1;
				$$.label = gentempcode("char*");
				l1 = gentempcode("int");
				$$.tipo = "string";
				$$.classe = "String";
				$$.traducao = "\t"+l1+" = "+to_string($1.label.size()-1)+";\n";
				$$.val = $1.label;
				modatrib($$.label, l1);
				$$.traducao += "\t" + $$.label + " = (char*) malloc(" + l1 +");\n"+"\tstrcpy("+$$.label+","+$1.label+");\n";
			    
			}
			| ID_F
			{
				$$.traducao = $1.traducao;

			}
			| TK_CONV
			{
				$$.label = gentempcode("char");
				$$.val = $1.label;
				//cout << $$.val << endl;
			}
			;
ATB			: TK_ID '=' E
			{
				tabelaSimbolos flag;
				bool TS;
				flag = buscarSimbolos($1.label);
				
				//cout << "atribuindo" << endl;
				if(flag.endereco.compare("") == 0){
					cout << "não existia" << endl;
					flag = inserirSimbolos($1.label, $3.tipo, $3.classe, "global", "0", "0");
				}else if(flag.classe.compare($3.classe) == 0  && flag.classe.compare("String") == 0 && flag.tipo.compare("string") == 0){
					TS = true;
				}
				else if(flag.tipo.compare($3.tipo) != 0){
					//checarlista();
					//cout << flag.tipo << " " <<  $3.tipo << endl;
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				$$.label = flag.endereco;
				$$.tipo = $3.tipo;
				$$.val = $3.val;
				flag.val = $$.val;
				alterarSimbolos(flag);
				//cout << flag.nome <<" yo "<< flag.tipo << endl;


				if(flag.tipo.compare("string") !=0){
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n";
				
				}
				else if($3.classe.compare("String") == 0){
					$1.tipo = flag.tipo;
					$1.label = flag.endereco;
					atributos resultado = funcString($1, "=", $3);
					//cout<< resultado.traducao << endl;
					if($1.tipo.compare("string") == 0 && $3.tipo.compare("char") == 0){						
						$3=resultado;
						//cout<< flag.nome <<$3.tipo << endl;
					}

					if($1.tipo.compare($3.tipo) == 0){
						//cout << "entrou segundo if " <<$3.label << endl;
						atributos a = buscaEnd($3.label);
						//cout << "busca por tam " <<a.tam << endl;
						if(flag.tam.compare("0") != 0){
							$$.traducao= resultado.traducao+"\tfree("+$1.label+");\n";
							$$.traducao=$$.traducao+"\t"+$1.label+" = (char*) malloc("+a.tam+");\n\tstrcpy("
						+$1.label+","+$3.label+");\n"+
						"\tfree("+$3.label+");\n";
						}else{
							$$.traducao=resultado.traducao+"\t"+$1.label+" = (char*) malloc("+a.tam+");\n\tstrcpy("
					+$1.label+","+$3.label+");\n"+"\tfree("+$3.label+");\n";

					//cout << $$.traducao << endl;
						}
						//$$.traducao = $1.traducao + $3.traducao + "\t"+ "strcpy(" + $$.label + ","+ $3.label + ");\n";
					flag.tam = a.tam;
					alterarSimbolos(flag);
					modatrib(flag.endereco, a.tam);
					}
				}
			}
			| TK_ID REF_ARRAY '=' E
			{
				tabelaSimbolos flag;
				string l1, l2;
				bool TS;
				flag = buscarSimbolos($1.label);
				
				//cout << "atribuindo" << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("variavel não declarada");
				}else if($2.tipo.compare("int") != 0){
					yyerror("Expressão incompativel para localizar elemento no array");
				}else if(flag.classe.compare($3.classe) == 0  && flag.classe.compare("String") == 0 && flag.tipo.compare("string") == 0){
					TS = true;
				}else if(flag.tipo.compare($4.tipo) != 0){
					//checarlista();
					//cout << flag.tipo << " " <<  $3.tipo << endl;
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				$$.label = flag.endereco;
				$$.tipo = $2.tipo;
				$$.val = $2.val;
				flag.val = $$.val;
				alterarSimbolos(flag);
				//cout << flag.nome <<" yo "<< flag.tipo << endl;
				l1 = gentempcode("int");
				l2 = gentempcode("int");


				if(flag.tipo.compare("string") !=0){
					if($2.val.compare("0") == 0){
						$$.traducao = $1.traducao + $2.traducao + $4.traducao + "\t" + $$.label + "["+ $2.label +"] = " + $4.label + ";\n";
					}else{
						$$.traducao = $1.traducao + $2.traducao + $4.traducao + "\t" + l1 + " = " + $2. val + " * "+ flag.tam +";\n\t" + l2 + " = " + l1 + " + "+ $2.label +";\n\t" + $$.label + "["+ l2 +"] = " + $4.label + ";\n";
					}
				
				}else if($4.classe.compare("String") == 0){
					string ref;
					$1.tipo = flag.tipo;
					$1.label = flag.endereco;
					atributos resultado = funcString($1, "=", $4);
				//	cout<< resultado.traducao << endl;
					if($1.tipo.compare("string") == 0 && $4.tipo.compare("char") == 0){						
						$3=resultado;
						cout<< flag.nome <<$3.tipo << endl;
					}

					if($1.tipo.compare($4.tipo) == 0){
						//cout << "entrou segundo if " <<$3.label << endl;
						atributos a = buscaEnd($4.label);
						//cout << "busca por tam " <<a.tam << endl;
						if(flag.tam.compare("0") != 0){
							ref = $2.traducao + "\t" + l1 + " = " + $2. val + " * "+ flag.tam +";\n\t" + l2 + " = " + l1 + " + "+ $2.label +";\n";
							$$.traducao= resultado.traducao+ ref + "\tfree("+$1.label+"["+ l2 +"]);\n";
							$$.traducao=$$.traducao+"\t"+$1.label+"["+l2+"] = (char*) malloc("+a.tam+");\n\tstrcpy("
						+$1.label+"["+ l2 +"],"+$4.label+");\n"+
						"\tfree("+$4.label+");\n";
						}
						//$$.traducao = $1.traducao + $3.traducao + "\t"+ "strcpy(" + $$.label + ","+ $3.label + ");\n";
					}
				}
				
			};

ID_F		: TK_ID
			{
				tabelaSimbolos flag;
				flag = buscarSimbolos($1.label);
				//cout << $1.label <<endl;
				//cout <<"variavel encontrada. " << flag.endereco << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("Variavel não declarada");
				}
				$$.label = flag.endereco;
				$$.val = flag.val;
				$$.tipo = flag.tipo;
				$$.classe = flag.classe;
				$$.val = flag.nome;
				if(flag.tipo.compare("string") == 0){
					$$.tam = flag.tam;
					$$.traducao = "\t"+$$.label+"= (char*) malloc("+flag.tam+");\n"+
				"\tstrcpy("+ $$.label+"," +flag.endereco + ");\n";
				}else{
				$$.traducao = "\t" + $$.label + " = " + $$.label + ";\n";
				//cout << "Variavel atribuida " << $$.val << endl;
				}
			}
			| TK_ID REF_ARRAY
			{
				tabelaSimbolos flag;
				string l1, l2;
				flag = buscarSimbolos($1.label);
				//cout << $1.label <<endl;
				//cout <<"variavel encontrada. " << flag.endereco << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("Variavel não declarada");
				}else if($2.tipo.compare("int") != 0){
					yyerror("indice incompativel");
				}

				$$.label = gentempcode("int");
				$$.val = flag.val;
				$$.tipo = flag.tipo;
				$$.classe = flag.classe;
				$$.val = flag.nome;
				$$.tam = "0";
				l1 = gentempcode("int");
				l2 = gentempcode("int");
				if(flag.dim.compare("0") == 0){
				$$.traducao = $2.traducao + "\t" + l1 + " = " + $2.label + ";\n\t" + $$.label + " = " + flag.endereco + "["+ l1 +"];\n";
				}else{
					$$.traducao = $2.traducao + "\t" + l1 + " = " + $2. val + " * "+ flag.tam +";\n\t" + l2 + " = " + l1 + " + "+ $2.label +";\n\t"+ $$.label + " = " + flag.endereco + "["+ l2 +"];\n";
				}

				//cout << "Variavel atribuida " << $$.val << endl;
				
			};
C_LOOP		: TK_BREAK
			{
				escopo alvo;
				alvo = buscarbloco(1);

				$$.traducao = "\tgoto FIM " + alvo.label + ";\n";
			}
			| TK_NEXT
			{
				escopo alvo;
				alvo = buscarbloco(1);

				$$.traducao = "\tgoto inicio_" + alvo.label + ";\n";
			};

%%

#include "lex.yy.c"

int yyparse();
using namespace std;
string gentempcode(string tipo)
{
	atributos x;
	var_temp_qnt++;
	x.label = "t" + to_string(var_temp_qnt);
	x.tipo = tipo;
	x.tam = "0";

	listaattr.push_back(x);
	return "t" + to_string(var_temp_qnt);
}

string gentemplabel(){
	string x;
	qtd_laco++;
	x = "P" + to_string(qtd_laco);

	return x;
}

bool traducao(string op){
	bool resp;
	if(op.compare("TRUE") ==0){
		resp = TRUE;
	}else{
		resp = FALSE;
	}
	return resp;
}

void checarlista(){
	int i, j, cont;
	tabelaSimbolos x; 

	cont = listaEscopo.size()-1;
	for(i = cont; i >=0; i--){
		for(j=0; j<listaEscopo[i].size(); j++){
		x = listaEscopo[i][j];
		//cout << "\t nome: " << x.nome << " "<< "val: "<< x.val << " " <<" tipo: " << x.tipo << '-' << x.endereco << endl;
		}
	}
}
tabelaSimbolos buscarSimbolos(string nome){
	tabelaSimbolos x;
	x.nome = "";
	x.tipo = "";
	x.endereco = "";
	int i, j,cont;

	//cout << "busca por "<< nome <<endl;
	cont = listaEscopo.size()-1;
	for(i = cont; i >=0; i--){
		for(j=0; j<listaEscopo[i].size(); j++){
			//cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
			if(nome.compare(listaEscopo[i][j].nome) == 0  && (i == cont || listaEscopo[i][j].mod == 1)){
				//printf("Achei ");
				x = listaEscopo[i][j];
				//cout<< x.endereco<< endl;	
				
				return x;
			}
			}
	}
	return x;
}
void modatrib(string nome, string tam){
	atributos x;
	x.label = nome;
	x.tam = tam;
	int i, j, k;
	j = 0;
	k = 0;

	//cout << " mudanca de atributo " << nome <<  endl;
	for(i=0; i<listaattr.size(); i++){
		
		if(nome.compare(listaattr[i].label) == 0){
			x.tipo = listaattr[i].tipo;
			listaattr.insert(listaattr.begin()+j, x);
			k = j +1;
			cout << j << " " << k << endl;
			
			listaattr.erase(listaattr.begin() + k);
				return;
		}
		j++;
	}
	
}
atributos buscaEnd(string nome){
	atributos x;
	int i, k;
	x.label = "";
	x.tipo = "";
	x.tam = "";

	
	for(i=0; i<listaattr.size(); i++){
		//cout << i << " simbolo " << listaattr[i].label<< endl;
		if(nome.compare(listaattr[i].label) == 0){
			//printf("Achei ");
			x = listaattr[i];
			//cout<< listaattr[i].tam<< endl;	
				
			return x;
		}
	}
	
	return x;
}

void alterarSimbolos(tabelaSimbolos x){
	int i, j, k, cont;
	cont = listaEscopo.size()-1;
	//cout << "alterando variavel" <<endl;
	for(i = cont; i >=0; i--){
		for(j = 0; j<listaEscopo[i].size(); j++){
			//cout << j << " simbolos " << listaEscopo[i][j].nome<< endl;
			if(x.nome.compare(listaEscopo[i][j].nome) == 0  && (i == cont || listaEscopo[i][j].mod == 1) ){
				listaEscopo[i].insert(listaEscopo[i].begin()+j, x);
				k = j +1;
				listaEscopo[i].erase(listaEscopo[i].begin() + k);
				return;
			}
		}
	
	}
}
bool verificarsimbolos(string nome){
	tabelaSimbolos x; 

	x = buscarSimbolos(nome);
	if(x.endereco.compare("") == 0){
		return false;
	}
	return true;

}
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso, string tamanho, string nDim){
	tabelaSimbolos var; 
	int cont;
	bool v;

	v = verificarsimbolos(nome);
	//cout << v << endl;
	if(v == true){
		checarlista();
		yyerror("Nome de variavel já declarada");
	}
	var.nome = nome;
	var.tipo = tipo;
	var.classe = classe;
	var.val = "";
	var.tam = tamanho;
	var.dim = nDim;
	//if(stoi(tamanho) < 0){
	//	yyerror("Tamanho inválido para uma matriz");
	//}
	if(acesso.compare("global") == 0){
		var.mod = 1;
	}else{
		var.mod = 0;
	}
	//cout << acesso << endl;
	var.endereco = gentempcode(tipo);
	
	cont = listaEscopo.size()-1;
	//cout <<"var "<< var.nome << ' ' << var.tipo << ' ' << var.endereco <<endl;
	listaEscopo[cont].push_back(var);
	//cout << "inseriu: " << listaEscopo[cont].size() <<endl;

	return var;

}
atributos funcString(atributos e1, string operador, atributos e2){
	atributos result;
	
//cout<< e1.tipo << e2.tipo << endl;
	if(e1.tipo.compare(e2.tipo) == 0 && e1.tipo.compare("string") == 0 && operador.compare("=") == 0){
		//cout<< "primeira alternativa" << endl;
		result.tipo=e1.tipo;
		result.label="";	
		result.traducao=e1.traducao+e2.traducao;
		return result;
		
	}else if (((operador.compare("+") == 0) && (e1.tipo.compare(e2.tipo) != 0)  && ((e1.tipo.compare("string")== 0)||(e1.tipo.compare("char")==0)) && ((e2.tipo.compare("string")==0)||(e2.tipo.compare("char")==0))) || ((operador.compare("=") == 0) && (e1.tipo.compare("string") ==0) && (e2.tipo.compare("char")==0))||((operador.compare("+") == 0) && (e1.tipo.compare(e2.tipo) == 0) && (e1.tipo.compare("char") ==0))){
		result.tipo = "string";
		result.label = gentempcode("string");
		string labelx = gentempcode("string");

		//cout<< "segunda alternativa" << result.tipo<< endl;

		if(e1.tipo.compare("char") == 0){
			result.traducao=e1.traducao + e2.traducao+"\t"+labelx+" =  2;\n\t"+result.label+" = (char*)malloc("+labelx+");\n\t"+result.label+"[0] = "+e1.label+";\n";
		}else{
			result.traducao= e1.traducao + e2.traducao+"\t"+labelx+" =  2;\n\t"+result.label+" = (char*)malloc("+labelx+");\n\t"+result.label+"[0] = "+e2.label+";\n";
		}
		modatrib(result.label, labelx);
		//cout <<"label" << result.label  << endl;
		return result;
	}else if((operador=="+"&& e1.tipo.compare(e2.tipo) == 0 && e1.tipo.compare("string") == 0)){
		result.tipo=e1.tipo;
		result.label=e2.label;	
		result.traducao=e1.traducao+e2.traducao;
		//cout<< "ultima alternativa" << endl;
		return result;
	}
	
}
escopo buscarbloco(int k){
	int i, cont;

	cont = listaEscopo.size()-1;
	for(i= cont; i>=0; i--){
		if(infobloco[i].tipo == 1 and k == 1){
			return infobloco[i];
		}

	}
	yyerror("Nenhum bloco de laço existente para essa operação");
}
string imprimirFree(){
	int i, j, cont;
	string declaracao="";
	cont = listaEscopo.size()-1;
	for(i = cont; i >=0; i--){
		for(j=0; j<listaEscopo[i].size(); j++){
			//cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
			if(listaEscopo[i][j].tipo.compare("string") == 0 || listaEscopo[i][j].tam.compare("0") != 0 ){
				declaracao += "\tfree("+listaEscopo[i][j].endereco+");\n";
			}
			}
			return declaracao;
	}
	
}
void limparpilha(){
	listaEscopo.clear();
	infobloco.clear();
	listaattr.clear();
}
int main(int argc, char* argv[])
{
	tabelaSimbolos x;
	escopo y; 
	int i;
	var_temp_qnt = 0;
	y.label = "";
	y.tipo = BLOCO;
	listaEscopo.push_back(listaSimb);
	infobloco.push_back(y);

	yyparse();
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				
