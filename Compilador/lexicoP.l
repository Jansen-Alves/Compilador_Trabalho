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

[(){}[\];,]	{ return *yytext; }

[+\-*/!]		{ return *yytext; }


"="		    { return '='; }


{NUM}		{ yylval.label = yytext; return TK_NUM; }

{REAL}      { yylval.label = yytext; return TK_FLOAT;}

{VARI}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
