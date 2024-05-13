%{
#include <iostream>
#include <string>
#include <sstream>
#define bool int
#define TRUE 1
#define FALSE 0
#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;
string Tipagens;
int qtd_simb;

struct tabelaSimbolos{
	string nome;
	string tipo;
	string classe;
	string endereco;
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

int yylex(void);
void yyerror(string);
string gentempcode(string tipo);
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
tabelaSimbolos buscarSimbolos(string nome);

bool traducao(string op);

tabelaSimbolos Listageral[20];
atributos Listaatributos[50];
%}

%token TK_NUM TK_STR TK_REAL TK_CHAR TK_STRING TK_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT
%token TK_TIPO_CHAR TK_TIPO_BOOL TK_CONV
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_MAIOR TK_MENOR TK_IGUALDADE TK_DESIGUALDADE
%token TK_CONJUNCAO TK_DISNJUNCAO
%token TK_ALT
%token TK_IF TK_ELSE TK_DO TK_WHILE TK_FOR TK_SWITCH
%token TK_FIM TK_ERROR

%start S

%right TK_DISNJUNCAO
%right TK_CONJUNCAO 

%right TK_IGUALDADE  TK_DESIGUALDADE
%right TK_MENOR TK_MENOR_IGUAL TK_MAIOR TK_MAIOR_IGUAL

%right '+' '-'
%right '*' '/' '%'
%right '^'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
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
				for(i=1; i<=var_temp_qnt; i++){
					codigo += "\t" + Listaatributos[i].tipo +" "+ Listaatributos[i].label + ";\n";
				};
				codigo+= "\n";
				codigo += $5.traducao;
								
				codigo += 	"\treturn 0;"
							"\n}";
				
				cout << codigo << endl;
				//checarlista();
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
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
			|CONTROLES{
				$$ = $1;
			}
			| TK_TIPO_INT TK_ID ';'
			{
				inserirSimbolos($2.label, "int", "Number");
			}
			| TK_TIPO_FLOAT TK_ID ';'
			{
				inserirSimbolos($2.label, "float", "Number");
			}
			| TK_TIPO_CHAR TK_ID ';'
			{
				inserirSimbolos($2.label, "char", "Character");
			}
			|TK_TIPO_BOOL TK_ID ';'
			{
				inserirSimbolos($2.label, "bool", "Boolean");
			}
			;
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
			|TK_IF E  BLOCO TK_ELSE BLOCO
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
			|TK_WHILE E BLOCO
			{
				string jp, ciclowhile, iniwhile;
				atributos tst;
				if($2.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				iniwhile = "\tinicio_"+tst.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ $2.label+";\n";
				jp = iniwhile +$2.traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+tst.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				$$.traducao = jp + $3.traducao + ciclowhile + "\tFIM "+tst.label+";\n";

			}
			|TK_DO BLOCO TK_WHILE E ';'
			{
				string jp, ciclowhile, iniwhile;
				atributos tst;
				if($4.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				iniwhile = "\tinicio_"+tst.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ $4.label+";\n";
				jp = iniwhile +$2.traducao + $4.traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+tst.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				$$.traducao = jp + ciclowhile + "\tFIM "+tst.label+";\n";

			}
			|TK_FOR '(' TK_ID '=' E ';' E ';' E')' BLOCO
			{
				/*string jp, E1;
				atributos tst, vari;
				if($7.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tabelaSimbolos flag;
				flag = buscarSimbolos($3.label);
				if(flag.endereco.compare("") == 0){
					flag = inserirSimbolos($3.label, $5.tipo, $5.classe);
				}else if(flag.tipo.compare($5.tipo) != 0){
					//checarlista();
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				vari.label = flag.
				flag.val = vari.val;
				alterarSimbolos(flag);
				//cout << flag.nome << endl;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n";
				tst.label = gentempcode("bool");
				iniwhile = "\tinicio_"+tst.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ $4.label+";\n";
				jp = iniwhile +$2.traducao + $4.traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+tst.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				$$.traducao = jp + ciclowhile + "\tFIM "+tst.label+";\n";*/
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
				$$.label = gentempcode($2.tipo);
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
						" = " +"!"+ $2.label +"("+ $$.val+ ")"+ ";\n";
			}
			| E TK_ALT
			{
				string x;
				if($1.classe.compare("Number") != 0){
					yyerror("Tipo incompativeis para essa operação");
				}
				$$.label = gentempcode($1.tipo);
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
				yyerror("Tipo de expressão incompativel para a conversão");
			}
			| TK_ID '=' E
			{
				tabelaSimbolos flag;

				flag = buscarSimbolos($1.label);
				if(flag.endereco.compare("") == 0){
					flag = inserirSimbolos($1.label, $3.tipo, $3.classe);
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

%%

#include "lex.yy.c"

int yyparse();

string gentempcode(string tipo)
{
	atributos x;
	var_temp_qnt++;
	x.label = "t" + to_string(var_temp_qnt);
	x.tipo = tipo;

	Listaatributos[var_temp_qnt] = x;
	return "t" + to_string(var_temp_qnt);
}
using namespace std;
bool traducao(string op){
	bool resp;
	if(op.compare("TRUE") ==0){
		resp = TRUE;
	}else{
		resp = FALSE;
	}
	return resp;
}
void tipagem(){
	int i;
	tabelaSimbolos x;

	for(i=0; i<qtd_simb; i++){
		x = Listageral[i];
		cout<< "\t" << x.tipo << " " << x.nome << endl;
	}
}
void checarlista(){
	int i;
	tabelaSimbolos x;

	for(i=0; i<qtd_simb; i++){
		x = Listageral[i];
		cout<< "\t nome: " << x.nome << " "<< "val: "<< x.val << " " <<" tipo: " << x.tipo << '-' << x.endereco << endl;
	}
}
tabelaSimbolos buscarSimbolos(string nome){
	tabelaSimbolos x;
	x.nome = "";
	x.tipo = "";
	x.endereco = "";
	int i;
	for(i = 0; i< qtd_simb; i++){
		if(nome.compare(Listageral[i].nome) == 0){
			//printf("Achei");
			x = Listageral[i];	
			return x;
		}
	}
	return x;
}
void alterarSimbolos(tabelaSimbolos x){
	int i;
	for(i = 0; i< qtd_simb; i++){
		if(x.nome.compare(Listageral[i].nome) == 0){
			Listageral[i] = x;
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
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe){
	tabelaSimbolos var; 
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
	var.endereco = gentempcode(tipo);
	
	//cout << var.nome << ' ' << var.tipo << ' ' << var.endereco <<endl;
	Listageral[qtd_simb] = var;
	qtd_simb++;

	return var;

}
int main(int argc, char* argv[])
{
	tabelaSimbolos x;
	int i;
	var_temp_qnt = 0;
	qtd_simb = 0;

	yyparse();
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				