%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;
string Tipagens;
int qtd_simb;

struct tabelaSimbolos{
	string nome;
	string tipo;
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
void inserirSimbolos(string nome, string tipo);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
string buscarSimbolos(string nome);

tabelaSimbolos Listageral[10];
%}

%token TK_NUM TK_STR TK_REAL
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT
%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				string codigo = "/*Compilador FOCA*/\n"
								"#include <iostream>\n"
								"#include<string.h>\n"
								"#include<stdio.h>\n"
								"int main(void) {\n";		
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
				inserirSimbolos($2.label, "int");
			}
			;

E 			: E '+' E
			{
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0){
					if($1.tipo.compare($3.tipo) != 0){
						$1.tipo = "float";
						$3.tipo = "float";
					}
				}
				else{
					if($1.tipo.compare($3.tipo) != 0){
						yyerror("Erro na concatenação tipos diferentes");
					}
				}
				$$.label = gentempcode();
				$$.tipo = $1.tipo;
				$$.classe = $1.classe;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " + " + $3.label + ";\n";
			}
			| E '-' E
			{
				if($1.classe.compare("Number") == 0 and $3.classe.compare("Number") == 0){
					if($1.tipo.compare($3.tipo) != 0){
						$1.tipo = "float";
						$3.tipo = "float";
					}
				}
				else{
					if($1.tipo.compare($3.tipo) != 0){
						yyerror("Erro na concatenação tipos diferentes");
					}
				}
				$$.label = gentempcode();
				$$.tipo = $1.tipo;
				$$.classe = $1.classe;
				
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
						" = " + $1.label + " - " + $3.label + ";\n";
			}
			
			| TK_ID '=' E
			{
				string flag;
				flag = buscarSimbolos($1.label);
				if(flag.compare("") == 0){
					inserirSimbolos($1.label, $3.tipo);
				}else if($1.tipo.compare($3.tipo) != 0){
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
				}
				$$.tipo = $3.tipo;
				$$.val = $3.val;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.label = gentempcode();
				$$.tipo = "int";
				$$.classe = "Number";
				//$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_REAL
			{
				$$.label = gentempcode();
				$$.tipo = "float";
				$$.classe = "Number";
				//$$.val = $1.label;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_ID
			{
				string flag;
				flag = buscarSimbolos($1.label);
				if(flag.compare(" ") == 0){
					yyerror("Variavel não declarada");
				}
				$$.label = flag;
				//$$.val = flag.val;
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";

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
		cout<< "\t nome: " << x.nome << " tipo: " << x.tipo << ' ' << x.endereco << endl;
	}
}
string buscarSimbolos(string nome){
	string x;
	x = "";
	int i;
	for(i = 0; i< qtd_simb; i++){
		if(nome.compare(Listageral[i].nome) == 0){
			//printf("Achei");
			x = Listageral[i].endereco;	
			return x;
		}
	}
	return x;
}
bool verificarsimbolos(string nome){
	tabelaSimbolos x; 

	x.endereco = buscarSimbolos(nome);
	if(x.endereco.compare("") == 0){
		return false;
	}
	return true;

}
void inserirSimbolos(string nome, string tipo){
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
	var.endereco = gentempcode();
	
	cout << var.nome << ' ' << var.tipo << ' ' << var.endereco <<endl;
	Listageral[qtd_simb] = var;
	qtd_simb++;

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
