/* Gabriel Couto & Felippo Stédile: Dupla  */

%{

#include <stdio.h>
#include "parser.tab.h"
int line_number = 1;

%}


%option noyywrap
%x comment
%x barrabarra
%option yylineno
espaco [ \t\r]

%%

"int" { return TK_PR_INT; }
"float" { return TK_PR_FLOAT; }
"bool" { return TK_PR_BOOL; }
"char" { return TK_PR_CHAR; }
"if" { return TK_PR_IF; }
"then" { return TK_PR_THEN; }
"else" { return TK_PR_ELSE; }
"while" { return TK_PR_WHILE; }
"input" { return TK_PR_INPUT; }
"output" { return TK_PR_OUTPUT; }
"return" { return TK_PR_RETURN; }
"for" { return TK_PR_FOR; }
"false" { return TK_LIT_FALSE; }
"true" { return TK_LIT_TRUE; }
{espaco} {};
[\n] { ++line_number; }

"//" BEGIN(barrabarra);

<barrabarra>.* {};
<barrabarra>\n { ++line_number; BEGIN(INITIAL);}

[,;:(){}+\-*/%^<>=!\[\]] { return yytext[0]; }

"<="   { return TK_OC_LE; }
">="   { return TK_OC_GE; }
"=="   { return TK_OC_EQ; }
"!="   { return TK_OC_NE; }
"&&"  { return TK_OC_AND; }
"||"    { return TK_OC_OR; }

[a-zA-Z]+ { return TK_IDENTIFICADOR; }
[\-|+]?[0-9]+ { return TK_LIT_INT; }
[\-|+]?[0-9]+\.([0-9]+E)?[0-9]+ { return TK_LIT_FLOAT; }
'[^'\n]' { return TK_LIT_CHAR; } 

"/*"         BEGIN(comment);

<comment>[^*\n]*        
<comment>"*"+[^*/\n]*   
<comment>\n             { ++line_number; }
<comment>"*"+"/"        BEGIN(INITIAL); // retirado do manual fornecido.


. { return TK_ERRO; } //talvez aqui tb,
%%

