/* Gabriel Couto & Felippo Stédile: Dupla */
/*
Função principal para realização da análise sintática.

Este arquivo será posterioremente substituído, não acrescente nada.
*/
#include <stdio.h>
#include "extra.h"
#include "parser.tab.h" //arquivo gerado com bison -d parser.y
/*
  Função principal para realização da E3.
  Não modifique este arquivo.
*/
extern int yyparse(void);
extern int yylex_destroy(void);

Pilha* myStack;
void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);

int main (int argc, char **argv)
{
  //yydebug = 1;
  Tabela* myTable = create_simbolo();
  myStack = create_stack(myTable);
  int ret = yyparse(); 
  Content* resultado = top_stack(myStack)->elemento_pilha->conteudo;
  printf("Linha: %d, Coluna: %d, Tamanho: %d, Dados: [%s], Outros: [%s]\n", resultado->localizacao->linha, resultado->localizacao->coluna, resultado->tamanho, resultado->dados, resultado->outros);

  exporta(arvore);
  libera(arvore);
  arvore = NULL;
  yylex_destroy();
  return ret;
}

