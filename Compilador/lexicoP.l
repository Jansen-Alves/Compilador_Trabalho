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
STRING \"({LETRA}({LETRA}|{DELIM})*)\"
VARI {LETRA}({LETRA}|{NUM})*
ALT ("++"|"--")
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

"if"        {yylval.label = yytext; return TK_IF;}

"else"      {yylval.label = yytext; return TK_ELSE;}

"{"         {yylval.label = yytext; return TK_START;}

":"         {yylval.label = yytext; return TK_START;}   

"do"        {yylval.label = yytext; return TK_DO;}

"while"     {yylval.label = yytext; return TK_WHILE;}

"for"       {yylval.label = yytext; return TK_FOR;}

"break"     {yylval.label = yytext; return TK_BREAK;}

"continue"  {yylval.label = yytext; return TK_NEXT;}

"switch"  {yylval.label = yytext; return TK_SWITCH;}

"case"  {yylval.label = yytext; return TK_CASE;}

"default"  {yylval.label = yytext; return TK_DEFAULT;}

"global"    {return TK_GLOBAL;}

"local"     {return TK_LOCAL;}

[(){}[\];,]	{ return *yytext; }

[+\-*/!%^]		{ return *yytext; }


"="		    { return '='; }


{NUM}		{ yylval.label = yytext; return TK_NUM; }

{REAL}      { yylval.label = yytext; return TK_REAL;}

{CHAR}      {yylval.label = yytext; return TK_CHAR;}

{STRING}    {yylval.label = yytext; return TK_STRING;}

{ALT}       {yylval.label = yytext; return TK_ALT;}

{VARI}		{yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
