#!/bin/bash
rm -f e4.log
ETAPA_ATUAL=`cat Makefile | grep "ETAPA_ATUAL =" | awk '{print $3}'`
if [ -z "$1" ]; then
	TESTES=0
	for i in {00..99};
	do
	if [ -f "tests-e4/w$i" ]; then
		TESTES=$((TESTES+1))
		NOME_ERRO=`cat tests-e4/w$i | grep "//" | sed 's/\/\///g'`
		echo "#############################"
		echo "## Resultado do Teste w$i: ##"
		echo "#############################"; echo;
		echo "Output: "
		./$ETAPA_ATUAL < tests-e4/w$i
		SAIDA=$?
		if [ ! -z $NOME_ERRO ]; then
			COD_ERRO=`cat tests-e4/errors.h | grep $NOME_ERRO | awk '{ print $3 }'`
			if [ "$COD_ERRO" = "$SAIDA" ]; then
				echo "---> Código CORRETO! Valor: $COD_ERRO ($NOME_ERRO)"; echo;
			else
				echo "---> Código ERRADO!! Valor obtido: $SAIDA, Gabarito: $COD_ERRO ($NOME_ERRO)"; echo;
				echo "Erro! w$i: [Obtido: $SAIDA, Gabarito: $COD_ERRO ($NOME_ERRO)]" >> e4.log 
			fi
		elif [ $SAIDA -ne 0 ]; then 
			# No gabarito não era para dar erro. Se tiver dado, nosso código está errado.
	                echo "---> Código ERRADO!! Valor obtido: $SAIDA, Gabarito: 0 (SEM ERRO)"; echo;
			echo "Erro! w$i: [Obtido: $SAIDA, Gabarito: $COD_ERRO ($NOME_ERRO)]" >> e4.log
		else
			# O Gabarito é zero e nosso código é zero também.
			echo "---> Código CORRETO! Valor obtido: $SAIDA, Gabarito: 0 (SEM ERRO)"; echo;
		fi
	fi
	done
	TESTES_ERRADOS=`wc -l e4.log | awk '{ print $1 }'`
	echo "" >> e4.log; echo "Resumo:" >> e4.log
	echo "---> Testes ERRADOS: $TESTES_ERRADOS" >> e4.log
	echo "---> Testes TOTAIS: $TESTES" >> e4.log
	ACERTO=`echo "scale = 2; 100*(($TESTES-$TESTES_ERRADOS)/$TESTES)" | bc`
	echo "---> Porcentagem de acerto: $ACERTO %" >> e4.log
	echo "____________________________________________________"; echo;
	cat e4.log
else
	NOME_ERRO=`cat tests-e4/$1 | grep "//" | sed 's/\/\///g'`
	echo "#############################"
	echo "## Resultado do Teste $1: ##"
	echo "#############################"; echo;
	echo "Output: "
	./$ETAPA_ATUAL < tests-e4/$1
	SAIDA=$?
	if [ ! -z $NOME_ERRO ]; then
		COD_ERRO=`cat tests-e4/errors.h | grep $NOME_ERRO | awk '{ print $3 }'`
		if [ "$COD_ERRO" = "$SAIDA" ]; then
			echo "---> Código CORRETO! Valor: $COD_ERRO ($NOME_ERRO)"; echo;
		else
			echo "---> Código ERRADO!! Valor obtido: $SAIDA, Gabarito: $COD_ERRO ($NOME_ERRO)"; echo;
			echo "Erro! Obtido: $SAIDA, Gabarito: $COD_ERRO ($NOME_ERRO)" >> e4.log 
		fi
	elif [ $SAIDA -ne 0 ] ; then
		# No gabarito não era para dar erro. Se tiver dado, nosso código está errado.
                echo "---> Código ERRADO!! Valor obtido: $SAIDA, Gabarito: 0 (SEM ERRO)"; echo;
		echo "Erro! Obtido: $SAIDA, Gabarito: $COD_ERRO ($NOME_ERRO)" >> e4.log
	else
		# O Gabarito é zero e nosso código é zero também.
		echo "---> Código CORRETO! Valor obtido: $SAIDA, Gabarito: 0 (SEM ERRO)"; echo;
	fi
			
fi
