
/* Gabriel Couto & Felippo Stédile: Dupla */

%{
	#include <stdio.h>
	#include <string.h>
	#include "../extra.h"
	extern int yylineno;
	extern void *arvore;
	extern Pilha *myStack;
	int yylex(void);
	void yyerror(const char *);
%}

%define parse.error verbose
%define parse.trace

%union {
	Valor_lexico_t valor_lexico;
	Node *node;
}

//////////////////////////////////////////////////////////
%token <valor_lexico> TK_PR_INT
%token <valor_lexico> TK_IDENTIFICADOR
%token <valor_lexico> TK_PR_FLOAT
%token <valor_lexico> TK_PR_CHAR
%token <valor_lexico> TK_PR_IF
%token <valor_lexico> TK_PR_THEN
%token <valor_lexico> TK_PR_ELSE
%token <valor_lexico> TK_PR_WHILE
%token <valor_lexico> TK_PR_INPUT
%token <valor_lexico> TK_PR_OUTPUT
%token <valor_lexico> TK_PR_RETURN
%token <valor_lexico> TK_PR_FOR
%token <valor_lexico> TK_PR_BOOL
%token <valor_lexico> TK_OC_LE
%token <valor_lexico> TK_OC_GE
%token <valor_lexico> TK_OC_EQ
%token <valor_lexico> TK_OC_NE
%token <valor_lexico> TK_OC_AND
%token <valor_lexico> TK_OC_OR
%token <valor_lexico> TK_LIT_FALSE
%token <valor_lexico> TK_LIT_TRUE
%token <valor_lexico> TK_LIT_INT
%token <valor_lexico> TK_LIT_FLOAT
%token <valor_lexico> TK_LIT_CHAR
%token TK_ERRO

%type<node> IDENTIFICADOR literal tipo PS PSblock
%type<node> operandos expressao
%type<node> exp7 exp6 exp5 exp4 exp3 exp2 exp1
%type<node> chamada_funcao chamada_retorno chamada_ctrl_fluxo
%type<node> multidimensional variavel_local multidimensional_
%type<node> declaracao_local declaracao atribuicao_local
%type<node> cabecalho_funcao programa
%type<node> comandos_simples bloco_comandos
%type<node> ctrl_repeticao ctrl_condicional cond_else
%type<node> lista_literais lista_de_nome_de_variaveis lista_de_elementos lista_parametros lista_comandos_simples lista_de_nome_de_variaveis_locais lista_de_expressoes lista_de_expressoes_ lista_expressoes_funcao
%start programa

%%

programa: lista_de_elementos {if($1!=NULL){$$=$1;  arvore = $$; }};
programa: {$$=NULL;};
lista_de_elementos: cabecalho_funcao lista_de_elementos { if($2!=NULL) {add_child($$, $2); } else {$$=$1; }};
lista_de_elementos: declaracao ';' lista_de_elementos {$$ = $3; if($3!=NULL) {add_child($$, $1);} };
lista_de_elementos: cabecalho_funcao {$$=$1; };
lista_de_elementos: declaracao ';'{$$=$1;};
/*
	Declaração de Variáveis Globais
*/


declaracao: tipo lista_de_nome_de_variaveis 
{
	$$=NULL; 
	Pilha* temp = top_stack(myStack); 
	analisa_e_insere(temp->elemento_pilha, $2, $1); 
	exclude_node($2); 
	free($1);
};

lista_de_nome_de_variaveis: lista_de_nome_de_variaveis ',' multidimensional 
{
	$$=create_node("PROX_VARG", ",");
	add_child($$, $1); 
	add_child($$, $3);
}; 

lista_de_nome_de_variaveis: multidimensional 
{
	$$=$1;
};

multidimensional: IDENTIFICADOR '[' lista_literais ']' 
{
	$$=create_node("LISTA_LIT", "[]"); 
	add_child($$, $1); 
	add_child($$, $3);
};

lista_literais: TK_LIT_INT '^' lista_literais 
{
	$$=create_node("PROX_LIT", "^"); 
	add_child($$, create_node_from_token("TK_LIT_INT", $1)); 
	add_child($$, $3);
};

lista_literais: TK_LIT_INT 
{
	$$=create_node_from_token("TK_LIT_INT", $1); 
}; 

multidimensional: IDENTIFICADOR 
{
	$$=$1;
}; 

/*
	Definição de Função
*/
cabecalho_funcao: tipo TK_IDENTIFICADOR PS lista_parametros ')' '{' bloco_comandos 
{
	$$ = create_node_from_token("FuncaoL", $2); 
	free($2.valor.cadeia); 
	add_child($$, $4); 
	if($7!=NULL) 
	{
		add_child($$, $7); 
	}
	Pilha* temp = top_stack(myStack);  
	pop_stack(myStack);
	temp = top_stack(myStack);

	// Esta linha abaixo serve para adicionar foo ao escopo imediatamente anterior.
	analisa_e_insere(temp->elemento_pilha, $$, $1);
	free($1);
};

cabecalho_funcao: tipo TK_IDENTIFICADOR PS ')' '{' bloco_comandos 
{
	$$ = create_node_from_token("Funcao", $2); 
	free($2.valor.cadeia); 
	if($6!=NULL)
	{
		add_child($$, $6); 
	}  
	pop_stack(myStack);
	Pilha* temp = top_stack(myStack);
	analisa_e_insere(temp->elemento_pilha, $$, $1);
	free($1);
};

lista_parametros: tipo IDENTIFICADOR ',' lista_parametros 
{
	$$=create_node("LIST_PARAM", ",");
	add_child($$, $1); 
	add_child($$, $4); 
	Pilha* temp = top_stack(myStack); 
	analisa_e_insere(temp->elemento_pilha, $2, $1); 
	free($2);
};

lista_parametros: tipo IDENTIFICADOR 
{
	$$=$1; 
	Pilha* temp = top_stack(myStack);
	analisa_e_insere(temp->elemento_pilha, $2, $1); 
	free($2);
};

bloco_comandos: lista_comandos_simples '}' 
{
	$$ = $1; 
};

PSblock: '{' 
{
	$$=NULL; 
	Tabela* temptable = create_simbolo();
	push_stack(temptable, myStack);
}

bloco_comandos: '}' 
{
	$$=NULL; 
};

PS: '(' 
{
	$$=NULL; 
	Tabela* temptable = create_simbolo();
	push_stack(temptable, myStack);
};




lista_comandos_simples: comandos_simples ';' lista_comandos_simples 
{
	if ($1!=NULL)  
		if($3!=NULL) 
		{
			$$=$1;  
			if(!strcmp($1->label, "<=")) 
			{
				$1=ultimaInit($1);
			}
			add_child($1, $3); 
		} 
		else 
		{
			$$=$1; 
		} 
	else 
	{
		$$=$3; 
	}
};

lista_comandos_simples: comandos_simples ';' 
{
	$$=$1;
};

comandos_simples: declaracao_local 
{
	$$=$1; 
};

comandos_simples: atribuicao_local 
{
	$$=$1; 
};

comandos_simples: chamada_funcao 
{
	$$=$1; 
};

comandos_simples: chamada_retorno 
{
	$$=$1; 
};

comandos_simples: chamada_ctrl_fluxo 
{
	$$=$1; 
};

comandos_simples: PSblock bloco_comandos 
{
	$$=$2; 
};

/*
	Declaração de Variável Local
*/
declaracao_local: tipo lista_de_nome_de_variaveis_locais 
{
	$$ = $2; 
	Pilha* temp = top_stack(myStack); 
	analisa_e_insere(temp->elemento_pilha, $2, $1); 
	free($1);
};

lista_de_nome_de_variaveis_locais: variavel_local ',' lista_de_nome_de_variaveis_locais 
{ 
	$$=create_node("PROX_VARL", ","); 
	add_child($$, $1); 
	add_child($$, $3); 
};

lista_de_nome_de_variaveis_locais: variavel_local 
{
	$$ = $1; 
};

variavel_local: IDENTIFICADOR TK_OC_LE literal 
{
	$$ = create_node("TK_OC_LE", "<="); 
	add_child($$, $1); 
	free($2.valor.cadeia); 
	add_child($$, $3); 
};

variavel_local: IDENTIFICADOR 
{
	$$=$1;
};

/*
	Atribuição local
*/

atribuicao_local: IDENTIFICADOR  lista_de_expressoes '=' expressao 
{
	$$ = create_node("ATRIBUICAO", "="); 
	if ($2!= NULL) 
	{ 
		add_child($2, $1);  
		add_child($$, $2);
		enum Tipo tipoLeft;
		enum Tipo tipoRight;
		tipoLeft = analisa_uso(top_stack(myStack)->elemento_pilha, $2);
		tipoRight = analisa_uso(top_stack(myStack)->elemento_pilha, $4);
		compareTypes(tipoLeft, tipoRight);
	}
	else 
	{ 
		add_child($$, $1);
		enum Tipo tipoLeft;
		enum Tipo tipoRight;
		tipoLeft = analisa_uso(top_stack(myStack)->elemento_pilha, $1);
		tipoRight = analisa_uso(top_stack(myStack)->elemento_pilha, $4);
		compareTypes(tipoLeft, tipoRight);
	} 
	add_child($$, $4);
	};

lista_de_expressoes: '[' lista_de_expressoes_ expressao ']' 
{
	$$ = create_node("ARRANJO", "[]");  
	if ($2!= NULL) 
	{ 
		add_child($2, $3); 
		add_child($$, $2);
	} 
	else 
		add_child($$, $3); 
};

lista_de_expressoes_: lista_de_expressoes_ expressao '^' 
{
	$$ = create_node("LISTA_EXP", "^");  
	if ($1!=NULL) 
	{
		add_child($1, $2);
		add_child($$, $1);
	} 
	else 
		add_child($$, $2); 
};

lista_de_expressoes_: 
{
	$$=NULL;
};

lista_de_expressoes: 
{
	$$=NULL;
};

/*
	Chamada de Função
*/
chamada_funcao: TK_IDENTIFICADOR  '(' lista_expressoes_funcao ')' {
	$$ = create_node_from_token("CHAMA_FUNCAO", $1); 
	add_child($$, $3);
	analisa_uso(top_stack(myStack)->elemento_pilha, $$);
	free($1.valor.cadeia); 
	};
chamada_funcao: TK_IDENTIFICADOR  '(' ')' {
	$$ = create_node_from_token("CHAMA_FUNCAO", $1);
	analisa_uso(top_stack(myStack)->elemento_pilha, $$);
	free($1.valor.cadeia); 
	}; 
lista_expressoes_funcao: expressao ',' lista_expressoes_funcao {$$ = $1;  add_child($$, $3); };
lista_expressoes_funcao: expressao {$$ = $1; };

/*
	Chamada de retorno
*/
chamada_retorno: TK_PR_RETURN expressao {$$ = create_node("TK_PR_RETURN", "return"); add_child($$, $2); free($1.valor.cadeia); };

/*
	Controle de Fluxo
*/
chamada_ctrl_fluxo: ctrl_condicional {$$ = $1; };
chamada_ctrl_fluxo: ctrl_repeticao {$$ = $1; };
ctrl_repeticao: TK_PR_WHILE PS expressao ')' '{' bloco_comandos {
	$$ = create_node("TK_PR_WHILE", "while");
	add_child($$, $3);
	free($1.valor.cadeia);
	add_child($$, $6);
	
	Pilha* temp = top_stack(myStack); 
	pop_stack(myStack);
	};
ctrl_condicional: TK_PR_IF PS expressao ')' TK_PR_THEN '{' bloco_comandos cond_else {
	$$ = create_node("TK_PR_IF", "if"); 
	add_child($$, $3); 
	add_child($$, $7); 
	free($1.valor.cadeia);
	free($5.valor.cadeia); 
	if($8 != NULL){add_child($$, $8); } 
	Pilha* temp = top_stack(myStack);
	pop_stack(myStack);
	};
cond_else: TK_PR_ELSE PSblock bloco_comandos { //botar no else o PS trocar o TK+PR po só ELSE e o ELSE ser o TKpr com o push
	$$ = $3; 
	free($1.valor.cadeia);};
cond_else: {$$=NULL;};



/*
	Expressão

*/

multidimensional_: IDENTIFICADOR lista_de_expressoes {if ($2==NULL) $$=$1; else {$$=$2; add_child($$, $1);}};

operandos: literal { $$ = $1; } ;
operandos: multidimensional_ { $$ = $1; } ;
operandos: chamada_funcao { $$ = $1; } ;

expressao: expressao TK_OC_OR exp1 {$$ = create_node("OR", "||" );  add_child($$, $1); free($2.valor.cadeia);  add_child($$, $3);  }; 
expressao: exp1 { $$ = $1; } ;

exp1: exp1 TK_OC_AND exp2 {$$ = create_node("AND", "&&" );  add_child($$, $1); free($2.valor.cadeia); add_child($$, $3);  };
exp1: exp2  { $$ = $1; } ;

exp2: exp2 TK_OC_EQ exp3 {$$ = create_node("EQ", "==" );  add_child($$, $1); free($2.valor.cadeia);  add_child($$, $3); };
exp2: exp2 TK_OC_NE exp3 {$$ = create_node("NE", "!=" );  add_child($$, $1); free($2.valor.cadeia);  add_child($$, $3); };
exp2: exp3 { $$ = $1; } ;

exp3: exp3 '<' exp4 {$$ = create_node("LT", "<" );  add_child($$, $1);   add_child($$, $3); };
exp3: exp3 '>' exp4 {$$ = create_node("GT", ">" );  add_child($$, $1);  add_child($$, $3); };
exp3: exp3 TK_OC_LE exp4 {$$ = create_node("LE", "<=" );  add_child($$, $1);  free($2.valor.cadeia); add_child($$, $3);  };
exp3: exp3 TK_OC_GE exp4 {$$ = create_node("GE", ">=" );  add_child($$, $1);  free($2.valor.cadeia); add_child($$, $3);  };
exp3: exp4 { $$ = $1;  } ;


exp4: exp4 '+' exp5 {$$ = create_node("SOMA", "+" );  add_child($$, $1);  add_child($$, $3);  };
exp4: exp4 '-' exp5 {$$ = create_node("SUB", "-" );  add_child($$, $1);  add_child($$, $3);  };
exp4: exp5 { $$ = $1; } ;

exp5: exp5 '*' exp6 {$$ = create_node("MULT", "*" );  add_child($$, $1);  add_child($$, $3);  } ;
exp5: exp5 '/' exp6 {$$ = create_node("DIV", "/" );  add_child($$, $1);   add_child($$, $3);  } ;
exp5: exp5 '%' exp6 {$$ = create_node("RESTO", "%" );  add_child($$, $1);  add_child($$, $3); } ;
exp5: exp6 { $$ = $1; } ;

exp6: '-' exp7 { $$ = create_node("SUB_UNARIO", "-"); add_child($$, $2); } ;
exp6: '!' exp7 { $$ = create_node("NOT", "!"); add_child($$, $2); } ;
exp6: exp7 { $$ = $1; } ;

exp7: '(' expressao ')' { $$ = $2;  };
exp7: operandos { $$ = $1; } ;


tipo: TK_PR_INT {$$=create_node("int", "i"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_INT", $1);};
tipo: TK_PR_FLOAT {$$=create_node("float", "f"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_FLOAT", $1);} ;
tipo: TK_PR_CHAR {$$=create_node("char", "c"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_CHAR", $1);} ;
tipo: TK_PR_BOOL {$$=create_node("bool", "b"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_BOOL", $1);} ;
literal: TK_LIT_INT {$$ = create_node_from_token("TK_LIT_INT", $1); } ;
literal: TK_LIT_FLOAT {$$ = create_node_from_token("TK_LIT_FLOAT", $1); } ;
literal: TK_LIT_CHAR {$$ = create_node_from_token("TK_LIT_CHAR", $1);  }; 
literal: TK_LIT_TRUE {$$ = create_node_from_token("TK_LIT_TRUE", $1); }; 
literal: TK_LIT_FALSE {$$ = create_node_from_token("TK_LIT_FALSE", $1); };
IDENTIFICADOR: TK_IDENTIFICADOR { $$ = create_node_from_token("TK_IDENTIFICADOR", $1); free($1.valor.cadeia); };


%%
void yyerror(const char *mensagem){
	printf("Erro Sintático: [%s] na linha %d\n", mensagem, yylineno);
	return;
}


