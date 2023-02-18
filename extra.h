#ifndef EXTRA_H_
#define EXTRA_H_

#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_ARRAY 21 //2.3
#define ERR_FUNCTION 22 //2.3
#define ERR_CHAR_TO_INT 31 //2.4
#define ERR_CHAR_TO_FLOAT 32 //2.4
#define ERR_CHAR_TO_BOOL 33 //2.4
#define ERR_CHAR_VECTOR 34 //2.4
#define ERR_X_TO_CHAR 35 //2.4

enum token_type {caractere_especial, palavra_reservada, operador_composto, identificador, literal};

union Valor {
	int inteiro;
	float flutuante;
	char caractere;
	int booleano;
	char *cadeia;
};

typedef struct valor_lexico_t
{
	int line_no;
	enum token_type tipo;
	int genero;
	union Valor valor;

} Valor_lexico_t;

typedef struct node
{
	char name[60];
	char label[60];
	struct node *firstChild;
	struct node *nextSibling;
} Node;

enum Natureza {Literal, Variavel, Arranjo, Funcao};

enum Tipo {inteiro, flutuante, booleano, caractere};

typedef struct location
{
	int linha;
	int coluna;
} Location;

typedef struct content
{
	struct location localizacao;
	enum Natureza natureza;
	enum Tipo tipo;
	int tamanho;
	int dados;
	int outros;
} Content;

typedef struct tabela
{
	int chave;
	struct content conteudo;
	struct tabela *nextElement;

} Tabela;

typedef struct pilha
{
	struct pilha *top;
	struct tabela *elemento_pilha;
} Pilha;


Pilha * create_stack(Tabela* tabela);

Pilha * top_stack(Pilha* pilha);

void push_stack(Tabela* tabela, Pilha* pilha);

Pilha* pop_stack(Pilha* pilha);

Node * create_node(char* name, char* label);

Node * create_node_from_token(char* name, Valor_lexico_t valor_lexico);

void add_child(Node *parentNode, Node *childNode);

void print_tree(Node* node);

void print_node(Node *node);

void exclude_node(Node* node);

#endif
