#ifndef EXTRA_H_
#define EXTRA_H_

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
	union Valor valor;

} Valor_lexico_t;

typedef struct node
{
	char name[60];
	char label[60];
	struct node *firstChild;
	struct node *nextSibling;
} Node;

Node create_node(char* name, char* label);

void add_child(Node *parentNode, Node *childNode);

void print_tree(Node* node);

void exclude_node(Node* node);

#endif
