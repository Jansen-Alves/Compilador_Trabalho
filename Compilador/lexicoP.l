%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
TIPO ("interger"|"float"|"char"|"bool")
DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
VARI {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"float"     {return TK_TIPO_FLOAT;}

"char"      {return TK_TIPO_CHAR;}

"bool"      {return TK_TIPO_BOOL;}

">="        {return TK_MAIOR_IGUAL;}

"<="        {return TK_MENOR_IGUAL;}

">"         {return TK_MAIOR;}

"<"         {return TK_MENOR;}

"=="        {return TK_IGUALDADE;}

"!="        {return TK_DESIGUALDADE;}

"&&"        {return TK_CONJUNCAO;}

"||"        {return TK_DISNJUNCAO;}

"TRUE"      {yylval.label = yytext; return TK_BOOL;}

"FALSE"     {yylval.label = yytext; return TK_BOOL;}

[(){}[\];,]	{ return *yytext; }

[+\-*/!%^]		{ return *yytext; }


"="		    { return '='; }


{NUM}		{ yylval.label = yytext; return TK_NUM; }

{TIPO}      { yylval.label = yytext; return TK_CONV; }

{REAL}      { yylval.label = yytext; return TK_REAL;}

{CHAR}      {yylval.label = yytext; return TK_CHAR;}

{VARI}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
