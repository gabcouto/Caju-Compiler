/* Gabriel Couto & Felippo Stédile: Dupla  */

%{

#include <stdio.h>
#include "../extra.h"
#include "parser.tab.h"
int line_number = 1;

%}


%option noyywrap
%x comment
%x barrabarra
%option yylineno

espaco [ \t\r]

%%

"int" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_INT; }
"float" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_FLOAT; }
"bool" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_BOOL; }
"char" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_CHAR; }
"if" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_IF; }
"then" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_THEN; }
"else" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_ELSE; }
"while" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_WHILE; }
"input" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_INPUT; }
"output" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_OUTPUT; }
"return" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_RETURN; }
"for" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_PR_FOR; }
"false" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_LIT_FALSE; }
"true" { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_LIT_TRUE; }
{espaco} {};
[\n] { ++line_number; }

"//" BEGIN(barrabarra);

<barrabarra>.* {};
<barrabarra>\n { ++line_number; BEGIN(INITIAL);}

[,;:(){}+\-*/%^<>=!\[\]] { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = caractere_especial; yylval.valor_lexico.valor.cadeia = strdup(yytext); return yytext[0]; }

"<="   { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_OC_LE; }
">="   { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_OC_GE; }
"=="   { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_OC_EQ; }
"!="   { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_OC_NE; }
"&&"  { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_OC_AND; }
"||"    { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_OC_OR; }

[a-zA-Z]+ { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = identificador; yylval.valor_lexico.valor.cadeia = strdup(yytext); return TK_IDENTIFICADOR; }
[0-9]+ { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = literal; yylval.valor_lexico.valor.inteiro = atoi(yytext); return TK_LIT_INT; } //////////////////////////
[0-9]+\.([0-9]+E)?[0-9]+ { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = literal; yylval.valor_lexico.valor.flutuante = atof(yytext); return TK_LIT_FLOAT; } ////////////////////
'[^'\n]' { yylval.valor_lexico.line_no = line_number; yylval.valor_lexico.tipo = literal; yylval.valor_lexico.valor.caractere = yytext[0]; return TK_LIT_CHAR; } ////////////////////////

"/*"         BEGIN(comment);

<comment>[^*\n]*        
<comment>"*"+[^*/\n]*   
<comment>\n             { ++line_number; }
<comment>"*"+"/"        BEGIN(INITIAL); // retirado do manual fornecido.


. { return TK_ERRO; } //talvez aqui tb,
%%

