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
std::vector <escopo> infobloco;
std::vector<vector<tabelaSimbolos>>listaEscopo;



int yylex(void);
void yyerror(string);
string gentempcode(string tipo);
string gentemplabel();
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe);
tabelaSimbolos buscarSimbolos(string nome);
escopo buscarbloco(int k);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);

void checarlista();
void tipagem();



bool traducao(string op);

tabelaSimbolos Listageral[20];
atributos Listaatributos[50];

%}

%token TK_NUM TK_STR TK_REAL TK_CHAR TK_BOOL TK_STRING
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
				cout << "bumbo" << endl;
				listaattr.clear();
				listaSimb.clear();
				listaEscopo.clear();
			}
			
			;

BLOCO		: INIT COMANDOS '}'
			{
				cout << listaEscopo.size();
				/*std::vector<tabelaSimbolos>v1;
				listaEscopo.push_back(v1);
				qtd_tabelas++;
				cout << "quantidade de escopo: "<<  qtd_tabelas << endl;*/
				$$.traducao = $2.traducao;
				listaEscopo.pop_back();
				qtd_tabelas--;
				cout << " tamanho final de escopo " << listaEscopo.size() << endl;
			}
			;

INIT		: '{'
			{
				vector<tabelaSimbolos> v1;
				escopo x; 
				x.label = "";
				x.tipo = BLOCO;
				
				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				cout << " tamanho inicio de escopo " << listaEscopo.size() << endl;
				qtd_tabelas++;
			}
			;

INIB		: '{'
			{
				escopo x;
				vector<tabelaSimbolos> v1;
				x.label = gentemplabel();
				x.tipo = LACO;

				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				cout<< "bloco laço, tamanho pilha "<< listaEscopo.size() << endl;
				qtd_tabelas++;
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
				string jp, marco;
				atributos tst;
				if($2.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				tst.traducao = "\t"+tst.label + " = " +"!"+ $2.label+";\n";
				marco = gentemplabel();
				jp = $2.traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+marco+";\n";

				$$.traducao = jp + $3.traducao +"\tIF-"+ marco + ";\n";


			}
			|TK_IF EXP  BLOCO TK_ELSE BLOCO
			{
				string jp, Lif, Lelse;
				atributos tst;
				atributos tfin;
				if($2.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				tst.traducao = "\t"+tst.label + " = " +"!"+ $2.label+";\n";
				Lif = gentemplabel();
				Lelse = gentemplabel();


				jp = $2.traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+Lif+";\n";
				tfin.label = gentempcode("bool");
				tfin.traducao= "\tgo to Else-" + Lelse +";\n";
				$$.traducao = jp + $3.traducao + tfin.traducao +"\tIF-"+ Lif +";\n" + $5.traducao +"\tElse-" + Lelse +";\n";

			}
			|TK_WHILE EXP INIB COMANDOS '}'
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

				laco = buscarbloco(1);

				iniwhile = "\tinicio_"+laco.label+";\n" ;
				jp = $2.traducao + iniwhile + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";
				ciclowhile = "\tgo to inicio_"+laco.label +";\n";
				$$.traducao = jp + $4.traducao + ciclowhile + "\tFIM "+laco.label+";\n";
				listaEscopo.pop_back();
				cout << " tamanho final do while " << listaEscopo.size() << endl;
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
			
			| ATB
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
ATB			: TK_ID '=' EXP
			{
				tabelaSimbolos flag;
				flag = buscarSimbolos($1.label);
				if(flag.endereco.compare("") == 0){
					cout<< "variavel não encontrada: " << $1.label << endl;
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
void tipagem(){
	int i;
	tabelaSimbolos x;

	for(i=0; i<qtd_simb; i++){
		x = Listageral[i];
		cout<< "\t" << x.tipo << " " << x.nome << endl;
	}
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

	cont = listaEscopo.size()-1;
	cout << "acesso a busca " << cont << endl;
	for(i = cont; i >=0; i--){
		cout << i << " tabela" << endl;
		for(j=0; j<listaEscopo[i].size(); j++){
			cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
			if(nome.compare(listaEscopo[i][j].nome) == 0){
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
	for(i = cont; i >=0; i--){
		cout << "tabela" << i << endl;
		for(j = 0; j<listaEscopo[i].size(); j++){
			cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
			if(x.nome.compare(listaEscopo[i][j].nome) == 0){
				listaEscopo[i].insert(listaEscopo[i].begin()+j, x);
				k += j;
				listaEscopo[i].erase(listaEscopo[i].begin() + k);
				return;
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
	cout << "acesso a inserção" << endl;
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
	listaEscopo[cont].push_back(var);
	cout << "inseriu: " << listaEscopo[cont].size() <<endl;
	qtd_simb++;

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
int main(int argc, char* argv[])
{
	tabelaSimbolos x;
	int i;
	var_temp_qnt = 0;
	qtd_simb = 0;
	qtd_tabelas = 0;
	qtd_laco = 0;

	yyparse();
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				