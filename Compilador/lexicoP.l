%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

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

[(){}[\];,]	{ return *yytext; }

[+\-*/!]		{ return *yytext; }


"="		    { return '='; }


{NUM}		{ yylval.label = yytext; return TK_NUM; }

{REAL}      { yylval.label = yytext; return TK_REAL;}

{VARI}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
