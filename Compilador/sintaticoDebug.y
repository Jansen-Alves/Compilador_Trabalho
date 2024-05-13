%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define bool int
#define TRUE 1
#define FALSE 0
#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;
string Tipagens;
int qtd_simb;
int qtd_tabelas;

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

std::vector <atributos> listaattr;
std::vector <tabelaSimbolos> listaSimb;
std::vector<vector<tabelaSimbolos>>listaEscopo;



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

%token TK_NUM TK_STR TK_REAL TK_CHAR TK_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT
%token TK_TIPO_CHAR TK_TIPO_BOOL TK_CONV
%token TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_MAIOR TK_MENOR TK_IGUALDADE TK_DESIGUALDADE
%token TK_CONJUNCAO TK_DISNJUNCAO
%token TK_IF TK_ELSE TK_WHILE
%token TK_FIM TK_ERROR

%start S

%right TK_DISNJUNCAO
%right TK_CONJUNCAO 

%right TK_IGUALDADE  TK_DESIGUALDADE
%left TK_MENOR TK_MENOR_IGUAL TK_MAIOR TK_MAIOR_IGUAL

%right '-' '+'
%right '*' '/' '%'
%right '^'
%right '(' ')'
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
				for(i = 0 ; i < listaattr.size(); i++){
					codigo += "\t" + listaattr[i].tipo +" "+ listaattr[i].label + ";\n";
				};
				codigo+= "\n";
				codigo += $5.traducao;
								
				codigo += 	"\treturn 0;"
							"\n}";
				
				cout << codigo << endl;
				checarlista();
				listaattr.clear();
				listaSimb.clear();
				listaEscopo.clear();
			}
			
			;

BLOCO		: '{' COMANDOS '}'
			{
				cout<< "alou" << endl;
				/*std::vector<tabelaSimbolos>v1;
				listaEscopo.push_back(v1);
				qtd_tabelas++;
				cout << "quantidade de escopo: "<<  qtd_tabelas << endl;*/
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

COMANDO 	: EXP ';'
			{
				$$ = $1;
			}
			| CONTROLES{
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

CONTROLES	: TK_IF EXP BLOCO
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
			|TK_IF EXP  BLOCO TK_ELSE BLOCO
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
			|TK_WHILE EXP BLOCO
			{
				string jp, ciclowhile, iniwhile;
				atributos tst;
				if($2.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				tst.traducao = "\t"+tst.label + " = " +"!"+ $2.label+";\n";
				iniwhile = "\tinicio_"+tst.label+";\n" ;
				jp = $2.traducao + iniwhile + tst.traducao+"\tif("+ tst.label+") go to FIM "+tst.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label;
				$$.traducao = jp + $3.traducao + ciclowhile + "\t FIM "+tst.label+";\n";

			};

EXP 		: EXP '+' EXP
			{
				int r1;
				float r2;
				if($1.tipo.compare("bool")==0){
					yyerror("Tipos incompativeis para essa operação");
				}
				$$.label = gentempcode($1.tipo);
				$$.tipo = $1.tipo;
				$$.classe = $1.classe;
				
				
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " + " + $3.label + "(chegou aqui +) ;\n";
				cout << "tocou folha +" << $$.val << endl;
			}			
			| EXP '-' EXP
			{
				int r1;
				float r2;
				
			
				if($1.tipo.compare("bool")==0 || $1.tipo.compare("char") == 0){
					yyerror("Tipos incompativeis para essa operação");
				}
				$$.label = gentempcode($1.tipo);
				$$.tipo = $1.tipo;
				$$.classe = $1.classe;
				
				
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " - " + $3.label + "(chegou aqui - ) ;\n";
				
				cout << "tocou folha -" << $$.val << endl;
			}
			| EXP '*' EXP
			{
				int r1;
				float r2;
				
			
				if($1.tipo.compare("bool")==0 || $1.tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
				$$.label = gentempcode($1.tipo);
				$$.tipo = $1.tipo;
				$$.classe = $1.classe;
				
				
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " * " + $3.label + "(chegou aqui *) ;\n";
				
				cout << "tocou folha *" << $$.val << endl;
			}
			| EXP '/' EXP
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
			| EXP '%' EXP
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
			| EXP '^' EXP
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
			| EXP TK_MAIOR EXP
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
					$$.val = $1.label +">"+ $3.label;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " > " + $3.label + ";\n";
				}
			}
			
			| TK_ID '=' EXP
			{
				tabelaSimbolos flag;
				flag = buscarSimbolos($1.label);
				if(flag.endereco.compare("") == 0){
					cout<< "variavel não encontrada" << endl;
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
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.label = gentempcode("int");
				$$.tipo = "int";
				$$.classe = "Number";
				$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";

				
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

	listaattr.push_back(x);
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

	for(i=0; i<listaSimb.size(); i++){
		x = listaSimb[i];
		cout<< "\t nome: " << x.nome << " "<< "val: "<< x.val << " " <<" tipo: " << x.tipo << '-' << x.endereco << endl;
	}
}
tabelaSimbolos buscarSimbolos(string nome){
	tabelaSimbolos x;
	x.nome = "";
	x.tipo = "";
	x.endereco = "";
	int i, j,cont;

	cont = qtd_tabelas-1;
	for(i = 0; i < listaSimb.size(); i){
		
			if(nome.compare(listaSimb[i].nome) == 0){
				printf("Achei ");
				x = listaSimb[i];
				cout<< x.endereco<< endl;	
				
				return x;
			}
	}
	return x;
}
void alterarSimbolos(tabelaSimbolos x){
	int i, j, k, cont;
	cont = qtd_tabelas-1;
	for(i = cont; i >=0; i--){
		for(j = 0; j<listaEscopo[i].size(); j++){
			if(x.nome.compare(listaEscopo[i][j].nome) == 0){
				listaEscopo[i].insert(listaEscopo[i].begin()+i, x);
				k += i;
				listaEscopo[i].erase(listaEscopo[i].begin() + k);
			}
		}
	
	}
	//cout <<"alterou:" << listaSimb.size() <<endl;
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
	var.endereco = gentempcode(tipo);
	
	cont = qtd_tabelas-1;
	cout << var.nome << ' ' << var.tipo << ' ' << var.endereco <<endl;
	cout << cont << endl;
	listaSimb.push_back(var);
	cout << "inseriu: " << listaEscopo[cont].size() <<endl;
	qtd_simb++;

	return var;

}
int main(int argc, char* argv[])
{
	tabelaSimbolos x;
	int i;
	var_temp_qnt = 0;
	qtd_simb = 0;
	qtd_tabelas = 1;
	listaEscopo.push_back(listaSimb);

	yyparse();
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				