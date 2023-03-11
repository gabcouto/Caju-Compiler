#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extra.h"


void v_ERR_UNDECLARED(Tabela* myTable, Content* conteudo)
{
	
}

void v_ERR_DECLARED(Tabela* myTable, Content* conteudo)
{
	while(myTable->conteudo != NULL)
	{
		if(strcmp(myTable->conteudo->dados, conteudo->dados) == 0)
			exit(ERR_DECLARED);

		if (myTable->nextElement!= NULL) myTable = myTable->nextElement;
		else break;
	}
}

void v_ERR_ARRAY(Tabela* myTable, Content* conteudo)
{

}

void v_ERR_FUNCTION(Tabela* myTable, Content* conteudo)
{

}

void v_ERR_CHAR_TO_INT(Tabela* myTable, Content* conteudo)
{

}

void v_ERR_CHAR_TO_FLOAT(Tabela* myTable, Content* conteudo)
{

}

void v_ERR_CHAR_TO_BOOL(Tabela* myTable, Content* conteudo)
{

}

void v_ERR_CHAR_VECTOR(Tabela* myTable, Content* conteudo)
{

}

void v_ERR_X_TO_CHAR(Tabela* myTable, Content* conteudo)
{

}