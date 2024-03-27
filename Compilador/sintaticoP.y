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
};
struct atributos
{
	string label;
	string traducao;
	string tipo;
};

int yylex(void);
void yyerror(string);
string gentempcode();
void inserirSimbolos(string nome, string tipo);
bool verificarsimbolos(string nome);
tabelaSimbolos buscarSimbolos(string nome);

tabelaSimbolos Listageral[10];
%}

%token TK_NUM TK_STR
%token TK_MAIN TK_ID TK_TIPO_INT TK_FLOAT
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
			| TK_TIPO_INT TK_ID";"
			{
				inserirSimbolos($1.label, $2.label);
			}
			;

E 			: E '+' E
			{
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
					" = " + $1.label + " + " + $3.label + ";\n";
			}
			| E '-' E
			{
				$$.label = gentempcode();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + 
					" = " + $1.label + " - " + $3.label + ";\n";
			}
			
			| TK_ID '=' E
			{
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.tipo = "int";
				$$.label = gentempcode();
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_ID
			{
				$$.label = gentempcode();
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
tabelaSimbolos buscarSimbolos(string nome){
	tabelaSimbolos x;
	x.nome = "";
	x.tipo = "";
	x.endereco = "";
	int i, v;
	for(i = 0; i< qtd_simb; i++){
		if(nome.compare(Listageral[i].nome) == 0){
			x.nome = Listageral[i].nome;
			x.tipo = Listageral[i].tipo;
			x.endereco = Listageral[i].endereco;	
		}
	}
	return x;
}
bool verificarsimbolos(string nome){

}
void inserirSimbolos(string nome, string tipo){
	tabelaSimbolos var; 
	var.nome = nome;
	var.tipo = tipo;
	var.endereco = gentempcode();

	printf("aqui");
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
