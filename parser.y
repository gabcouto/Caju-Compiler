
/* Gabriel Couto & Felippo Stédile: Dupla */

/*
	Aviso ao professor sobre a ETAPA 5:
	Optamos pela geração de código em 1 passagem.

	
*/

%{
	#include <stdio.h>
	#include <string.h>
	#include "../extra.h"
	extern int yylineno;
	extern void *arvore;
	extern int contador;
	extern Pilha *myStack;
	extern Tabela *rfp, *rbss;
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
	$$->codigo = $3->codigo;
	$$->rotulo = $3->rotulo;
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
	
	char* string_temp;
	string_temp = (char*) malloc(sizeof(char));
	
	//tem q pegar o lugar que exp deixou seu resultado
	// if exp == literal { sprintf(string_temp, "%d", exp->label) ou se for char sla
	// else catar o local
	// talvez essa funfe:
	// int deslocExp = encontra_endereço(myStack, $4->label, 0); //tem q garantir q o $4->label retorna o identificador msm
	// sprintf(string_temp, "%d", deslocExp);
	int desloc = encontra_endereco_ref(myStack, $1->label, 0);
	char* temp_pointer;
	temp_pointer = (char*) malloc(sizeof(char));
	if (desloc<0) {
		sprintf(temp_pointer, "rfp"); 
		desloc +=1;
		desloc *=-1;	
	}	else 
	sprintf(temp_pointer, "rbss");

	char *desloc_temp;
	desloc_temp = (char*) malloc(sizeof(char));
	sprintf(desloc_temp, "%d", desloc);

	sprintf(string_temp, "temporario%d", $4->rotulo);
	$$->codigo = create_lista_iloc();
	$$->codigo = $4->codigo;
	add_to_l_iloc($$->codigo, new_instruction(NULL, "storeAI", string_temp, temp_pointer, desloc_temp));

	print_iloc($$->codigo);

	//obter endereço da tabela
	// em qual tabela/ escopo foi declarado
	// precisamos saber o temporario onde se encontra o resultado da exp
	// 	isso encontra-se em um campo de $4
	// if tabela global
	//	gera storeAI temporario => rbss, deslocamento
	//else 
	//	gera storeAI temporario => rfp, deslocamento
	// concatenar o code da exp ($4.code) com o storeAI gerado
	// coloca o resultado da concat em AST $$

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
	// para cada expressao em lista de expressao faz um load para um reg
	// dps concat os loads com jumpI $1.label
	$$ = create_node_from_token("CHAMA_FUNCAO", $1); 
	add_child($$, $3);
	analisa_uso(top_stack(myStack)->elemento_pilha, $$);
	free($1.valor.cadeia); 
};

chamada_funcao: TK_IDENTIFICADOR  '(' ')' {
	//jumpI $1.label
	$$ = create_node_from_token("CHAMA_FUNCAO", $1);
	analisa_uso(top_stack(myStack)->elemento_pilha, $$);
	free($1.valor.cadeia); 
	}; 
lista_expressoes_funcao: expressao ',' lista_expressoes_funcao {
	//strconcat($1.code,  ###############
	$$ = $1;
	add_child($$, $3);
};
lista_expressoes_funcao: expressao {
	//$$.code = load ##############
	$$ = $1;
};

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

multidimensional_: IDENTIFICADOR lista_de_expressoes {
	if ($2==NULL){
		$$=$1;
	//obter endereço da tanela de simbolos
	//   em qual tabela/escopo foi declarado
		int deslocamento = encontra_endereco_ref(myStack, $1->label, 0);
		char* temp_pointer;
		temp_pointer = (char*) malloc(sizeof(char));
	if (deslocamento<0) {
		sprintf(temp_pointer, "rfp"); 
		deslocamento +=1;
		deslocamento *=-1;	
	}	else 
	sprintf(temp_pointer, "rbss");
		char *desloc_temp;
		desloc_temp = (char*) malloc(sizeof(char));
		sprintf(desloc_temp, "%d", deslocamento);

	// gera temp
		char* string_temp;
		string_temp = (char*) malloc(sizeof(char));
		$$->rotulo = gera_rotulo();
		sprintf(string_temp, "temporario%d", $$->rotulo);
	// if tabela global
	//	gera loadAI rbss, deslocamento => temporario
	// else 
	//	gera loadAI rfp, deslocamento => temporario
	//coloca instrução na ast em $$ (acho que quer dizer o $$.code = code gerado
	//add_to_l_iloc($$->codigo, new_instruction(NULL, "loadAI", "rfp" , desloc_temp, string_temp));
	$$->codigo = create_lista_iloc();
	$$->codigo->instruction =  new_instruction(NULL, "loadAI", temp_pointer , desloc_temp, string_temp);

	} 
	else {$$=$2; add_child($$, $1);}};

operandos: literal { $$ = $1;} ;
operandos: multidimensional_ { $$ = $1; } ;
operandos: chamada_funcao { $$ = $1; } ;

expressao: expressao TK_OC_OR exp1 {
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gera or $1.temp, $3.temp => temporario
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// concat $1.code, $3.code, a instrução que geramos
	// atribuimos a concacetnação em $$.code

	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "or", string_temp1, string_temp3, string_temp));
	$$ = create_node("OR", "||" );
	add_child($$, $1);
	free($2.valor.cadeia);
	add_child($$, $3);
}; 
expressao: exp1 { $$ = $1; } ;

exp1: exp1 TK_OC_AND exp2 {
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gera and $1.temp, $3.temp => temporario
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// concat $1.code, $3.code, a instrução que geramos
	// atribuimos a concacetnação em $$.code

	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "and", string_temp1, string_temp3, string_temp));
	
	$$ = create_node("AND", "&&" );
	add_child($$, $1);
	free($2.valor.cadeia);
	add_child($$, $3);
};
exp1: exp2  { $$ = $1; } ;

exp2: exp2 TK_OC_EQ exp3 {
//cmp_EQ

	// gerar temporario  int temp = gera_rotulo()
	// $$.temp = temporario
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gerar label_true
	char *label_true;
	label_true = (char*) malloc(sizeof(char));
	sprintf(label_true, "labelT%d", gera_label());
	// gerar label_false
	char *label_false;
	label_false = (char*) malloc(sizeof(char));
	sprintf(label_false, "labelF%d", gera_label());
	// gerar label_depois
	char *label_dps;
	label_dps = (char*) malloc(sizeof(char));
	sprintf(label_dps, "labelDps%d", gera_label());
	// $$.code = o concat das coisas
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	// gerar code disso: {
	// gerar iloc cmp_EQ $1.temp, $3.temp => temporario	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cmp_EQ", string_temp1, string_temp3, string_temp));
	// gerar iloc cbr temporario => label_true label_false 
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cbr", string_temp, label_true, label_false));
	// gerar iloc com label_verdade: loadI 1 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_true, "loadI", "1", NULL, string_temp));
	// gerar iloc jumpI label_depois
	add_to_l_iloc($$->codigo, new_instruction(NULL, "jumpI", NULL, NULL, label_dps));
	// gerar iloc com label_false: loadI 0 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_false, "loadI", 0, NULL, string_temp));
	// gerar iloc com label label_depois concat nop }
	add_to_l_iloc($$->codigo, new_instruction(label_dps, "nop", NULL, NULL, NULL));
	$$ = create_node("EQ", "==" );
	add_child($$, $1);
	free($2.valor.cadeia);
	add_child($$, $3);
};
exp2: exp2 TK_OC_NE exp3 {
//cmp_NE
	// gerar temporario  int temp = gera_rotulo()
	// $$.temp = temporario
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gerar label_true
	char *label_true;
	label_true = (char*) malloc(sizeof(char));
	sprintf(label_true, "labelT%d", gera_label());
	// gerar label_false
	char *label_false;
	label_false = (char*) malloc(sizeof(char));
	sprintf(label_false, "labelF%d", gera_label());
	// gerar label_depois
	char *label_dps;
	label_dps = (char*) malloc(sizeof(char));
	sprintf(label_dps, "labelDps%d", gera_label());
	// $$.code = o concat das coisas
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	// gerar code disso: {
	// gerar iloc cmp_NE $1.temp, $3.temp => temporario	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cmp_NE", string_temp1, string_temp3, string_temp));
	// gerar iloc cbr temporario => label_true label_false 
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cbr", string_temp, label_true, label_false));
	// gerar iloc com label_verdade: loadI 1 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_true, "loadI", "1", NULL, string_temp));
	// gerar iloc jumpI label_depois
	add_to_l_iloc($$->codigo, new_instruction(NULL, "jumpI", NULL, NULL, label_dps));
	// gerar iloc com label_false: loadI 0 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_false, "loadI", 0, NULL, string_temp));
	// gerar iloc com label label_depois concat nop }
	add_to_l_iloc($$->codigo, new_instruction(label_dps, "nop", NULL, NULL, NULL));
	
	$$ = create_node("NE", "!=" );
	add_child($$, $1);
	free($2.valor.cadeia);
	add_child($$, $3);
};
exp2: exp3 { $$ = $1; } ;

exp3: exp3 '<' exp4 {
//cmp_LT
	// gerar temporario  int temp = gera_rotulo()
	// $$.temp = temporario
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gerar label_true
	char *label_true;
	label_true = (char*) malloc(sizeof(char));
	sprintf(label_true, "labelT%d", gera_label());
	// gerar label_false
	char *label_false;
	label_false = (char*) malloc(sizeof(char));
	sprintf(label_false, "labelF%d", gera_label());
	// gerar label_depois
	char *label_dps;
	label_dps = (char*) malloc(sizeof(char));
	sprintf(label_dps, "labelDps%d", gera_label());
	// $$.code = o concat das coisas
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	// gerar code disso: {
	// gerar iloc cmp_LT $1.temp, $3.temp => temporario	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cmp_LT", string_temp1, string_temp3, string_temp));
	// gerar iloc cbr temporario => label_true label_false 
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cbr", string_temp, label_true, label_false));
	// gerar iloc com label_verdade: loadI 1 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_true, "loadI", "1", NULL, string_temp));
	// gerar iloc jumpI label_depois
	add_to_l_iloc($$->codigo, new_instruction(NULL, "jumpI", NULL, NULL, label_dps));
	// gerar iloc com label_false: loadI 0 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_false, "loadI", 0, NULL, string_temp));
	// gerar iloc com label label_depois concat nop }
	add_to_l_iloc($$->codigo, new_instruction(label_dps, "nop", NULL, NULL, NULL));
	$$ = create_node("LT", "<" );
	add_child($$, $1);
	add_child($$, $3);
};

exp3: exp3 '>' exp4 {
//cmp_GT
	// gerar temporario  int temp = gera_rotulo()
	// $$.temp = temporario
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gerar label_true
	char *label_true;
	label_true = (char*) malloc(sizeof(char));
	sprintf(label_true, "labelT%d", gera_label());
	// gerar label_false
	char *label_false;
	label_false = (char*) malloc(sizeof(char));
	sprintf(label_false, "labelF%d", gera_label());
	// gerar label_depois
	char *label_dps;
	label_dps = (char*) malloc(sizeof(char));
	sprintf(label_dps, "labelDps%d", gera_label());
	// $$.code = o concat das coisas
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	// gerar code disso: {
	// gerar iloc cmp_GT $1.temp, $3.temp => temporario	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cmp_GT", string_temp1, string_temp3, string_temp));
	// gerar iloc cbr temporario => label_true label_false 
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cbr", string_temp, label_true, label_false));
	// gerar iloc com label_verdade: loadI 1 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_true, "loadI", "1", NULL, string_temp));
	// gerar iloc jumpI label_depois
	add_to_l_iloc($$->codigo, new_instruction(NULL, "jumpI", NULL, NULL, label_dps));
	// gerar iloc com label_false: loadI 0 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_false, "loadI", 0, NULL, string_temp));
	// gerar iloc com label label_depois concat nop }
	add_to_l_iloc($$->codigo, new_instruction(label_dps, "nop", NULL, NULL, NULL));

	$$ = create_node("GT", ">" );
	add_child($$, $1);
	add_child($$, $3);
};
exp3: exp3 TK_OC_LE exp4 {
//cmp_LE
	// gerar temporario  int temp = gera_rotulo()
	// $$.temp = temporario
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gerar label_true
	char *label_true;
	label_true = (char*) malloc(sizeof(char));
	sprintf(label_true, "labelT%d", gera_label());
	// gerar label_false
	char *label_false;
	label_false = (char*) malloc(sizeof(char));
	sprintf(label_false, "labelF%d", gera_label());
	// gerar label_depois
	char *label_dps;
	label_dps = (char*) malloc(sizeof(char));
	sprintf(label_dps, "labelDps%d", gera_label());
	// $$.code = o concat das coisas
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	// gerar code disso: {
	// gerar iloc cmp_LE $1.temp, $3.temp => temporario	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cmp_LE", string_temp1, string_temp3, string_temp));
	// gerar iloc cbr temporario => label_true label_false 
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cbr", string_temp, label_true, label_false));
	// gerar iloc com label_verdade: loadI 1 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_true, "loadI", "1", NULL, string_temp));
	// gerar iloc jumpI label_depois
	add_to_l_iloc($$->codigo, new_instruction(NULL, "jumpI", NULL, NULL, label_dps));
	// gerar iloc com label_false: loadI 0 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_false, "loadI", 0, NULL, string_temp));
	// gerar iloc com label label_depois concat nop }
	add_to_l_iloc($$->codigo, new_instruction(label_dps, "nop", NULL, NULL, NULL));
	
	$$ = create_node("LE", "<=" );
	add_child($$, $1);
	free($2.valor.cadeia); 
	add_child($$, $3);
};
exp3: exp3 TK_OC_GE exp4 {
// gerar temporario  int temp = gera_rotulo()
	// $$.temp = temporario
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gerar label_true
	char *label_true;
	label_true = (char*) malloc(sizeof(char));
	sprintf(label_true, "labelT%d", gera_label());
	// gerar label_false
	char *label_false;
	label_false = (char*) malloc(sizeof(char));
	sprintf(label_false, "labelF%d", gera_label());
	// gerar label_depois
	char *label_dps;
	label_dps = (char*) malloc(sizeof(char));
	sprintf(label_dps, "labelDps%d", gera_label());
	// $$.code = o concat das coisas
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	// gerar code disso: {
	// gerar iloc cmp_GE $1.temp, $3.temp => temporario	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cmp_GE", string_temp1, string_temp3, string_temp));
	// gerar iloc cbr temporario => label_true label_false 
	add_to_l_iloc($$->codigo, new_instruction(NULL, "cbr", string_temp, label_true, label_false));
	// gerar iloc com label_verdade: loadI 1 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_true, "loadI", "1", NULL, string_temp));
	// gerar iloc jumpI label_depois
	add_to_l_iloc($$->codigo, new_instruction(NULL, "jumpI", NULL, NULL, label_dps));
	// gerar iloc com label_false: loadI 0 => temporario
	add_to_l_iloc($$->codigo, new_instruction(label_false, "loadI", 0, NULL, string_temp));
	// gerar iloc com label label_depois concat nop }
	add_to_l_iloc($$->codigo, new_instruction(label_dps, "nop", NULL, NULL, NULL));
	
	$$ = create_node("GE", ">=" ); 
	add_child($$, $1); 
	free($2.valor.cadeia);
	add_child($$, $3);
};
exp3: exp4 { $$ = $1;  } ;


exp4: exp4 '+' exp5 {//e se a exp é um literal? acho q daria ruim no sprintf lá
	$$ = create_node("SOMA", "+" ); 
	add_child($$, $1);
	add_child($$, $3);
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	// gera add $1.temp, $3.temp => temporario
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// concat $1.code, $3.code, a instrução que geramos
	// atribuimos a concacetnação em $$.code

	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	
	add_to_l_iloc($$->codigo, new_instruction(NULL, "add", string_temp1, string_temp3, string_temp));
	print_iloc($$->codigo->next_instruction);
};
exp4: exp4 '-' exp5 { //e se a exp é um literal?
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	//gera um temporario para guardar o resultado
	// gera sub $1.temp, $3.temp => temporario
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// concat $1.code, $3.code, a instrução que geramos
	// atribuimos a concacetnação em $$.code
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	add_to_l_iloc($$->codigo, new_instruction(NULL, "sub", string_temp1, string_temp3, string_temp));
	
	$$ = create_node("SUB", "-" );
	add_child($$, $1);
	add_child($$, $3);
};
exp4: exp5 { $$ = $1; } ;

exp5: exp5 '*' exp6 {
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	//gera um temporario para guardar o resultado
	// gera mult $1.temp, $3.temp => temporario
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// concat $1.code, $3.code, a instrução que geramos
	// atribuimos a concacetnação em $$.code
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	add_to_l_iloc($$->codigo, new_instruction(NULL, "mult", string_temp1, string_temp3, string_temp));
	$$ = create_node("MULT", "*" );
	add_child($$, $1);
	add_child($$, $3);
};
exp5: exp5 '/' exp6 {
	$$->rotulo = gera_rotulo();
	$$->codigo = create_lista_iloc();
	char *string_temp; 
	char *string_temp1;
	char *string_temp3;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	string_temp3 = (char*) malloc(sizeof(char));
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "temporario%d", $1->rotulo);
	sprintf(string_temp3, "temporario%d", $3->rotulo);
	//gera um temporario para guardar o resultado
	// gera div $1.temp, $3.temp => temporario
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// concat $1.code, $3.code, a instrução que geramos
	// atribuimos a concacetnação em $$.code
	$$->codigo->next_instruction = $1->codigo;
	$1->codigo->next_instruction = $3->codigo;
	add_to_l_iloc($$->codigo, new_instruction(NULL, "div", string_temp1, string_temp3, string_temp));
	$$ = create_node("DIV", "/" );
	add_child($$, $1);
	add_child($$, $3);
};
exp5: exp5 '%' exp6 {
// n precisa
	$$ = create_node("RESTO", "%" );
	add_child($$, $1);
	add_child($$, $3);
};
exp5: exp6 { $$ = $1; } ;

exp6: '-' exp7 {
// n precisa mas ta aqui:
	//gera um temporario para guardar o resultado
	// gera subI 0, $1.temp=> temporario
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// atribuimos o code em $$.code
	$$ = create_node("SUB_UNARIO", "-");
	add_child($$, $2);
};
exp6: '!' exp7 {
// n precisa mas ta aqui:
	//gera um temporario para guardar o resultado
	// gera subI 1, $1.temp=> temporario         //Considerando que true = 1 e false = 0
	// salvar o nome desse temporario
	// salvar o nome desse temporario gerado em $$.temp
	// gerar code
	// atribuimos o code em $$.code
	$$ = create_node("NOT", "!");
	add_child($$, $2);
};

exp6: exp7 { $$ = $1; } ;

exp7: '(' expressao ')' { $$ = $2;  };
exp7: operandos { $$ = $1; } ;


tipo: TK_PR_INT {$$=create_node("int", "i"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_INT", $1);};
tipo: TK_PR_FLOAT {$$=create_node("float", "f"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_FLOAT", $1);} ;
tipo: TK_PR_CHAR {$$=create_node("char", "c"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_CHAR", $1);} ;
tipo: TK_PR_BOOL {$$=create_node("bool", "b"); free($1.valor.cadeia);}; //{$$ = create_node_from_token("TK_PR_BOOL", $1);} ;
literal: TK_LIT_INT {
	$$ = create_node_from_token("TK_LIT_INT", $1);
	$$->codigo = create_lista_iloc();
	char *string_temp; 
	char *string_temp1;
	string_temp = (char*) malloc(sizeof(char));
	string_temp1 = (char*) malloc(sizeof(char));
	$$->rotulo = gera_rotulo();
	sprintf(string_temp, "temporario%d", $$->rotulo);
	sprintf(string_temp1, "%d", $1.valor.inteiro);
	//$$->temp = $1.valor.inteiro; //acho q isso já ta na create_node no label de $$
	add_to_l_iloc($$->codigo, new_instruction(NULL, "loadI", string_temp1, string_temp, NULL));
	} ;
literal: TK_LIT_FLOAT {$$ = create_node_from_token("TK_LIT_FLOAT", $1);};
literal: TK_LIT_CHAR {$$ = create_node_from_token("TK_LIT_CHAR", $1);}; 
literal: TK_LIT_TRUE {$$ = create_node_from_token("TK_LIT_TRUE", $1);}; 
literal: TK_LIT_FALSE {$$ = create_node_from_token("TK_LIT_FALSE", $1);};
IDENTIFICADOR: TK_IDENTIFICADOR {
	$$ = create_node_from_token("TK_IDENTIFICADOR", $1); 
	free($1.valor.cadeia);
};


%%
void yyerror(const char *mensagem){
	printf("Erro Sintático: [%s] na linha %d\n", mensagem, yylineno);
	return;
}


