/* Gabriel Couto & Felippo Stédile: Dupla  */

%{

#include <stdio.h>
#include "parser.tab.h"
#include "extra.h"
int line_number = 1;

%}


%option noyywrap
%x comment
%x barrabarra
%option yylineno

%union {
	valor_lexico_t valor_lexico;	
}

espaco [ \t\r]

%%

"int" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_INT; }
"float" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_FLOAT; }
"bool" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_BOOL; }
"char" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_CHAR; }
"if" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_IF; }
"then" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_THEN; }
"else" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_ELSE; }
"while" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_WHILE; }
"input" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_INPUT; }
"output" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_OUTPUT; }
"return" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_RETURN; }
"for" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_PR_FOR; }
"false" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_LIT_FALSE; }
"true" { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = palavra_reservada; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_LIT_TRUE; }
{espaco} {};
[\n] { ++line_number; }

"//" BEGIN(barrabarra);

<barrabarra>.* {};
<barrabarra>\n { ++line_number; BEGIN(INITIAL);}

[,;:(){}+\-*/%^<>=!\[\]] { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = caractere_especial; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return yytext[0]; }

"<="   { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_OC_LE; }
">="   { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_OC_GE; }
"=="   { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_OC_EQ; }
"!="   { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_OC_NE; }
"&&"  { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_OC_AND; }
"||"    { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = operador_composto; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_OC_OR; }

[a-zA-Z]+ { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = identificador; yylval.valor_lexico.valor.cadeia = strdup(yytext[0]); return TK_IDENTIFICADOR; }
[0-9]+ { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = literal; yylval.valor_lexico.valor.inteiro = atoi(yytext[0]); return TK_LIT_INT; } //////////////////////////
[0-9]+\.([0-9]+E)?[0-9]+ { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = literal; yylval.valor_lexico.valor.flutuante = atof(yytext[0]); return TK_LIT_FLOAT; } ////////////////////
'[^'\n]' { yyval.valor_lexico.line_no = line_number; yyval.valor_lexico.tipo = literal; yylval.valor_lexico.valor.caractere = yytext[0]; return TK_LIT_CHAR; } ////////////////////////

"/*"         BEGIN(comment);

<comment>[^*\n]*        
<comment>"*"+[^*/\n]*   
<comment>\n             { ++line_number; }
<comment>"*"+"/"        BEGIN(INITIAL); // retirado do manual fornecido.


. { return TK_ERRO; } //talvez aqui tb,
%%

