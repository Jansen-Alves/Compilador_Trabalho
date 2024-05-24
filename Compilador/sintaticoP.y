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
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso);
tabelaSimbolos buscarSimbolos(string nome);
escopo buscarbloco(int k);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
void limparpilha();

bool traducao(string op);
%}

%token TK_NUM TK_STR TK_REAL TK_CHAR TK_STRING TK_BOOL 
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_ST  TK_GLOBAL TK_LOCAL
%token TK_TIPO_CHAR TK_TIPO_BOOL TK_CONV
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_MAIOR TK_MENOR TK_IGUALDADE TK_DESIGUALDADE
%token TK_CONJUNCAO TK_DISNJUNCAO
%token TK_ALT TK_START
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
				$$.traducao = $1.traducao;
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, vazio " << listaEscopo.size() << endl;
			}

BLOCO		: INIT COMANDOS '}'
			{
				cout << listaEscopo.size();
				/*std::vector<tabelaSimbolos>v1;
				listaEscopo.push_back(v1);
				qtd_tabelas++;
				cout << "quantidade de escopo: "<<  qtd_tabelas << endl;*/
				$$.traducao = $2.traducao;
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo " << listaEscopo.size() << endl;
			}
			;

INIT		: TK_START
			{
				cout << "cheguei" << endl;
				vector<tabelaSimbolos> v1;
				escopo x; 
				x.label = "";
				x.tipo = BLOCO;
				
				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				cout << " tamanho inicio de escopo " << listaEscopo.size() << endl;
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
				cout<< "bloco laço, tamanho pilha "<< listaEscopo.size() << endl;
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
				inserirSimbolos($3.label, "int", "Number", $2.label);
			}
			| TK_TIPO_FLOAT MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "float", "Number", $2.label);
			}
			| TK_TIPO_CHAR MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "char", "Character", $2.label);
			}
			| TK_TIPO_BOOL MODO LISTA_ID ';'
			{
				inserirSimbolos($3.label, "bool", "Boolean", $2.label);
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
				jp = $2.traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+tst.label+";\n";

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
				jp = $2.traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+tst.label+";\n";
				
				tfin.label = gentempcode("bool");
				tfin.traducao = "\tgo to Else-" + tfin.label +";\n";
				
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
				jp =  iniwhile +$2.traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";
				ciclowhile = "\tgo to inicio_"+laco.label +";\n";
				$$.traducao = jp + $4.traducao + ciclowhile + "\tFIM "+laco.label+";\n";
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, while" << listaEscopo.size() << endl;
				
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
				jp = iniwhile +$3.traducao + $6.traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				$$.traducao = jp + ciclowhile + "\tFIM "+laco.label+";\n";

				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, Do while" << listaEscopo.size() << endl;
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
				cicloF = "\tgo to inicio_"+laco.label +";\n";
				jp = $3.traducao + cicloI+ $5.traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";

				$$.traducao = jp + $10.traducao + $7.traducao + cicloF +"\tFIM "+ laco.label + ";\n";
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, for" << listaEscopo.size() << endl;

			}
			| TK_SWITCH REF INIB CASES '}'
			{
				string fim;
			 	escopo laco;

				laco = buscarbloco(1);
				fim = "\tFIM " + laco.label + ";\n";
				$$.traducao = $2.traducao + $4.traducao + fim;

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

				jp = $2.traducao + comp.traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+tst.label+";\n";
				
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
				cout << "incremento da var"<< $$.label <<endl;
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
				cout << $1.label << endl;
				$$.label = gentempcode("string");
				$$.tipo = "string";
				$$.classe = "String";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label +";\n";
			}
			|TK_ID
			{
				tabelaSimbolos flag;
				flag = buscarSimbolos($1.label);
				cout <<"variavel encontrada. " << flag.endereco << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("Variavel não declarada");
				}
				$$.label = flag.endereco;
				$$.val = flag.val;
				$$.tipo = flag.tipo;
				$$.classe = flag.classe;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
				//cout << "Variavel atribuida " << $$.val << endl;

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

				flag = buscarSimbolos($1.label);
				if(flag.endereco.compare("") == 0){
					flag = inserirSimbolos($1.label, $3.tipo, $3.classe, "local");
				}else if(flag.tipo.compare($3.tipo) != 0){
					//checarlista();
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				$$.label = flag.endereco;
				$$.tipo = $3.tipo;
				$$.val = $3.val;
				flag.val = $$.val;
				alterarSimbolos(flag);
				//cout << flag.nome << endl;
				if($3.tipo.compare("string") != 0){
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n";
				}else{
					$$.traducao = $1.traducao + $3.traducao + "\t"+ "strcpy(" + $$.label + ","+ $3.label + ");\n";
				}
			};
C_LOOP		: TK_BREAK
			{
				escopo alvo;
				alvo = buscarbloco(1);

				$$.traducao = "\tgo to FIM " + alvo.label + ";\n";
			}
			| TK_NEXT
			{
				escopo alvo;
				alvo = buscarbloco(1);

				$$.traducao = "\tgo to inicio-" + alvo.label + ";\n";
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
		cout << "\t nome: " << x.nome << " "<< "val: "<< x.val << " " <<" tipo: " << x.tipo << '-' << x.endereco << endl;
		}
	}
}
tabelaSimbolos buscarSimbolos(string nome){
	tabelaSimbolos x;
	x.nome = "";
	x.tipo = "";
	x.endereco = "";
	int i, j,cont;

	cout << "busca por "<< nome <<endl;
	cont = listaEscopo.size()-1;
	for(i = cont; i >=0; i--){
		for(j=0; j<listaEscopo[i].size(); j++){
			cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
			if(nome.compare(listaEscopo[i][j].nome) == 0  && (i == cont || listaEscopo[i][j].mod == 1)){
				printf("Achei ");
				x = listaEscopo[i][j];
				cout<< x.endereco<< endl;	
				
				return x;
			}
			}
	}
	return x;
}
void alterarSimbolos(tabelaSimbolos x){
	int i, j, k, cont;
	cont = listaEscopo.size()-1;
	cout << "alterando variavel" <<endl;
	for(i = cont; i >=0; i--){
		for(j = 0; j<listaEscopo[i].size(); j++){
		//	cout << j << " simbolos " << listaEscopo[i][j].nome<< endl;
			if(x.nome.compare(listaEscopo[i][j].nome) == 0  && (i == cont || listaEscopo[i][j].mod == 1) ){
				listaEscopo[i].insert(listaEscopo[i].begin()+j, x);
				k += j;
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
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso){
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
	if(acesso.compare("global") == 0){
		var.mod = 1;
	}else{
		var.mod = 0;
	}
	cout << acesso << endl;
	var.endereco = gentempcode(tipo);
	
	cont = listaEscopo.size()-1;
	cout <<"var "<< var.nome << ' ' << var.tipo << ' ' << var.endereco <<endl;
	listaEscopo[cont].push_back(var);
	//cout << "inseriu: " << listaEscopo[cont].size() <<endl;

	return var;

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