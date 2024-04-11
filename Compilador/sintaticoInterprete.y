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
string gentempcode();
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
tabelaSimbolos buscarSimbolos(string nome);

bool traducao(string op);

tabelaSimbolos Listageral[10];
%}

%token TK_NUM TK_STR TK_REAL TK_CHAR TK_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT
%token TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_MAIOR TK_MENOR TK_IGUALDADE TK_DESIGUALDADE
%token TK_CONJUNCAO TK_DISNJUNCAO
%token TK_FIM TK_ERROR

%start S

%left TK_DISNJUNCAO
%left TK_CONJUNCAO

%left TK_IGUALDADE TK_DESIGUALDADE
%left TK_MENOR TK_MENOR_IGUAL TK_MAIOR TK_MAIOR_IGUAL

%left '+' '-'
%left '*' '/'
%left '^'


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
				for(i=0; i<qtd_simb; i++){
					codigo += "\t" + Listageral[i].tipo +" "+ Listageral[i].nome + ";\n";
				};
				codigo+= "\n";
				codigo += $5.traducao;
								
				codigo += 	"\treturn 0;"
							"\n}";
				
				cout << codigo << endl;
				checarlista();
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

E 			: E '+' E
			{
				int r1;
				float r2;
				if($1.tipo.compare($3.tipo) != 0 ){
					atributos conv;
					int x;
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						r2 = stof($1.val) + stof($3.val);
						$$.val = to_string(r2);
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						r2= stof($1.val) + stof($3.val);
						cout<< r2 << endl;
						$$.val = to_string(r2);
						x = 1;

					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("char") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(int) " + $3.label + ";\n"; 
						$3.tipo = "int";
						r1 = stoi($1.val) + stoi($3.val);
						$$.val = to_string(r1);
						x = 1;

					}else if($1.tipo.compare("char") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(int) " + $1.label + ";\n"; 
						$1.tipo = "int";
						r1 = stoi($1.val) + stoi($3.val);
						$$.val = to_string(r1);
						x = 0;
						
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
					if($1.tipo.compare("int") == 0){
						r1 = stoi($1.val) + stoi($3.val);
						$$.val = to_string(r1);
					}else if($1.tipo.compare("float") == 0){
						r2 = stof($1.val) + stof($3.val);
						$$.val = to_string(r2);
					}else if($1.tipo.compare("char") == 0){
						$$.val = $1.val + $2.val;
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						r2 = stof($1.val) - stof($3.val);
						$$.val = to_string(r2);
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						r2= stof($1.val) - stof($3.val);
						$$.val = to_string(r2);
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
					if($1.tipo.compare("int") == 0){
						r1 = stoi($1.val) - stoi($3.val);
						$$.val = to_string(r1);
					}else if($1.tipo.compare("float") == 0){
						r2 = stof($1.val) - stof($3.val);
						$$.val = to_string(r2);
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " - " + $3.label + ";\n";
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
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						r2 = stof($1.val) / stof($3.val);
						$$.val = to_string(r2);
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						r2= stof($1.val) / stof($3.val);
						$$.val = to_string(r2);
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
					if($1.tipo.compare("int") == 0){
						r1 = stoi($1.val) / stoi($3.val);
						$$.val = to_string(r1);
					}else if($1.tipo.compare("float") == 0){
						r2 = stof($1.val) / stof($3.val);
						$$.val = to_string(r2);
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " / " + $3.label + ";\n";
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
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						r2 = stof($1.val) * stof($3.val);
						$$.val = to_string(r2);
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						r2= stof($1.val) * stof($3.val);
						$$.val = to_string(r2);
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
					if($1.tipo.compare("int") == 0){
						r1 = stoi($1.val) * stoi($3.val);
						$$.val = to_string(r1);
					}else if($1.tipo.compare("float") == 0){
						r2 = stof($1.val) * stof($3.val);
						$$.val = to_string(r2);
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " * " + $3.label + ";\n";
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
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						double dividend = stof($1.val);
            			double divisor = stof($3.val);
            			r2 = dividend - static_cast<int>(dividend / divisor) * divisor;
						$$.val = to_string(r2);
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						double dividend = stof($1.val);
            			double divisor = stof($3.val);
            			r2 = dividend - static_cast<int>(dividend / divisor) * divisor;
						$$.val = to_string(r2);
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
					if($1.tipo.compare("int") == 0){
						r1 = stoi($1.val) % stoi($3.val);
						$$.val = to_string(r1);
					}else if($1.tipo.compare("float") == 0){
						double dividend = stof($1.val);
            			double divisor = stof($3.val);
            			r2 = dividend - static_cast<int>(dividend / divisor) * divisor;
						$$.val = to_string(r2);
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + "=" + "(float) " + $1.label + ";\n"; 
						$1.tipo = "float";
						for (int i = 0; i < stoi($3.val); ++i) 
						{
							
                			r2 = stof($1.val) * r2;
							cout << r2 << endl;
            			}	
						$$.val = to_string(r2);
						x = 0;

					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						conv.label = gentempcode();
						conv.traducao = "\t" + conv.label + " = " + "(float) " + $3.label + ";\n"; 
						$3.tipo = "float";
						for (int i = 0; i < stoi($3.val); ++i) 
						{
                			r2 *= stof($1.val);
            			}	
						$$.val = to_string(r2);
						cout << r2 << endl;
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
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
					if($1.tipo.compare("int") == 0){
						for (int i = 0; i < stoi($3.val); ++i) 
						{
                			r1 *= stoi($1.val);
            			}	
						$$.val = to_string(r1);
					}else if($1.tipo.compare("float") == 0){
						for (int i = 0; i < stoi($3.val); ++i) 
						{
                			r2 *= stof($1.val);
            			}	
						$$.val = to_string(r2);
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					$$.label = gentempcode();
					$$.tipo = $1.tipo;
					$$.classe = $1.classe;
				
				
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " ^ " + $3.label + ";\n";
				}
				
			}
			| E TK_MAIOR_IGUAL E
			{
				bool x; 
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0 ){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("int") == 0){
						x = stoi($1.val) >= stoi($3.val);
					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = stoi($1.val) >= stof($3.val);
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = stof($1.val) >= stoi($3.val);
					}
					else{
						x = stof($1.val) >= stof($3.val);
					}

					if(x){
						$$.val = "TRUE";
					}else{
						$$.val = "FALSE";
					}
					$$.label = gentempcode();
					$$.tipo = "bool";
					$$.classe = "Boolean";
				}else{
					yyerror("Tipo incompativel para operações lógicas");
				}
				
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " >= " + $3.label + ";\n";
			}
			| E TK_MENOR_IGUAL E
			{
				bool x; 
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0 ){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("int") == 0){
						x = stoi($1.val) <= stoi($3.val);
					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = stoi($1.val) <= stof($3.val);
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = stof($1.val) <= stoi($3.val);
					}
					else{
						x = stof($1.val) <= stof($3.val);
					}

					if(x){
						$$.val = "TRUE";
					}else{
						$$.val = "FALSE";
					}
					$$.label = gentempcode();
					$$.tipo = "bool";
					$$.classe = "Boolean";
				}else{
					yyerror("Tipo incompativel para operações lógicas");
				}
				//cout << "valor da operação " << $$.val <<endl;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " <= " + $3.label+ ";\n";
			}
			| E TK_MAIOR E
			{
				bool x; 
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0 ){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("int") == 0){
						x = stoi($1.val) > stoi($3.val);
					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = stoi($1.val) > stof($3.val);
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = stof($1.val) > stoi($3.val);
					}
					else{
						x = stof($1.val) > stof($3.val);
					}

					if(x){
						$$.val = "TRUE";
					}else{
						$$.val = "FALSE";
					}
					$$.label = gentempcode();
					$$.tipo = "bool";
					$$.classe = "Boolean";
				}else{
					yyerror("Tipo incompativel para operações lógicas");
				}
				//cout << "valor da operação " << $$.val <<endl;

				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " > " + $3.label  + ";\n";
			}
			| E TK_MENOR E
			{
				bool x; 
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0 ){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("int") == 0){
						x = stoi($1.val) < stoi($3.val);
					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = stoi($1.val) < stof($3.val);
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = stof($1.val) < stoi($3.val);
					}
					else{
						x = stof($1.val) < stof($3.val);
					}

					if(x){
						$$.val = "TRUE";
					}else{
						$$.val = "FALSE";
					}
					$$.label = gentempcode();
					$$.tipo = "bool";
					$$.classe = "Boolean";
				}else{
					yyerror("Tipo incompativel para operações lógicas");
				}
				//cout << "valor da operação " << $$.val <<endl;

				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " < " + $3.label + ";\n";
			}
			| E TK_IGUALDADE E
			{
				bool x; 
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0 ){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("int") == 0){
						x = stoi($1.val) == stoi($3.val);
					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = stoi($1.val) == stof($3.val);
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = stof($1.val) == stoi($3.val);
					}
					else{
						x = stof($1.val) == stof($3.val);
					}

				}else if($1.classe.compare("Character") == 0 && $3.classe.compare("Character") == 0){
					x = $1.val == $3.val;
				}

				if(x){
						$$.val = "TRUE";
					}else{
						$$.val = "FALSE";
					}
					$$.label = gentempcode();
					$$.tipo = "bool";
					$$.classe = "Boolean";

				//cout << "valor da operação " << $$.val <<endl;

				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " == " + $3.label + ";\n";
			}
			| E TK_DESIGUALDADE E
			{
				bool x; 
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0 ){
					if($1.tipo.compare("int") == 0 && $3.tipo.compare("int") == 0){
						x = stoi($1.val) != stoi($3.val);
					}else if($1.tipo.compare("int") == 0 && $3.tipo.compare("float") == 0){
						x = stoi($1.val) != stof($3.val);
					}else if($1.tipo.compare("float") == 0 && $3.tipo.compare("int") == 0){
						x = stof($1.val) != stoi($3.val);
					}
					else{
						x = stof($1.val) != stof($3.val);
					}

				}else if($1.classe.compare("Character") == 0 && $3.classe.compare("Character") == 0){
					x = $1.val != $3.val;
				}

				if(x){
						$$.val = "TRUE";
					}else{
						$$.val = "FALSE";
					}
					$$.label = gentempcode();
					$$.tipo = "bool";
					$$.classe = "Boolean";

				//cout << "valor da operação " << $$.val <<endl;

				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " != " + $3.label + ";\n";
			}
			| E TK_CONJUNCAO E
			{
				bool x;
				if($1.tipo.compare("bool") == 0 && $3.tipo.compare("bool") == 0){
					x = traducao($1.val) && traducao($3.val);
				}else{
					yyerror("Tipos incompativeis para essa operação");
				}
				if(x){
					$$.val = "TRUE";
				}else{
					$$.val = "FALSE";
				}
				$$.label = gentempcode();
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
				if(x){
					$$.val = "TRUE";
				}else{
					$$.val = "FALSE";
				}
				$$.label = gentempcode();
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
				if(x){
					$$.val = "TRUE";
				}else{
					$$.val = "FALSE";
				}
				$$.label = gentempcode();
				$$.tipo = "bool";
				$$.classe = "Boolean";

				$$.traducao = $2.traducao + "\t" + $$.label + 
						" = " +"!"+ $2.label +"("+ $$.val+ ")"+ ";\n";
			}
			| TK_ID '=' E
			{
				tabelaSimbolos flag;
				flag = buscarSimbolos($1.label);
				//cout << $1.label << " primeira verificação"<< endl;
				if(flag.endereco.compare("") == 0){
					flag = inserirSimbolos($1.label, $3.tipo, $3.classe);
				}else if(flag.tipo.compare($3.tipo) != 0){
					checarlista();
					cout << $1.tipo << " comp" << $3.tipo << endl;
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				$$.label = $1.label;
				$$.tipo = $3.tipo;
				$$.val = $3.val;
				flag.val = $$.val;
				alterarSimbolos(flag);
				cout << flag.nome << endl;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.label = gentempcode();
				$$.tipo = "int";
				$$.classe = "Number";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";

				cout << "Variavel atribuida " << $$.val << endl;
			}
			| TK_REAL
			{
				$$.label = gentempcode();
				$$.tipo = "float";
				$$.classe = "Number";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_CHAR
			{
				$$.label = gentempcode();
				$$.tipo = "char";
				$$.classe = "String";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			|TK_BOOL{
				$$.label = gentempcode();
				$$.tipo = "bool";
				$$.classe = "Boolean";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label +";\n";
			}
			| TK_ID
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
			;

%%

#include "lex.yy.c"

int yyparse();

string gentempcode()
{
	var_temp_qnt++;
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
	var.endereco = gentempcode();
	
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
