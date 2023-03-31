#!/bin/bash
rm -f tests-e5/results/generated/*.sim
rm -f tests-e5/results/generated/*.iloc
ETAPA_ATUAL=`cat Makefile | grep "ETAPA_ATUAL =" | awk '{print $3}'`
if [ -z "$1" ]; then
	TESTES=0
	for i in {00..31};
	do
	if [ -f "tests-e5/ijk$i" ]; then
		TESTES=$((TESTES+1))
		STACK=`cat tests-e5/results/src/gp.csv | grep ijk$i | cut -d "," -f5 | head -1`
		DATA=`cat tests-e5/results/src/gp.csv | grep ijk$i | cut -d "," -f6 | head -1`
		echo "#############################"
		echo "## Resultado do Teste ijk$i: ##"
		echo "#############################"; echo;
		echo "Output: "
		timeout 3 ./$ETAPA_ATUAL < tests-e5/ijk$i > tests-e5/results/generated/ijk$i.iloc
		timeout 3 python3 ilocsim.py \
		--stack $STACK \
		--data $DATA \
		-s \
		-x < tests-e5/results/generated/ijk$i.iloc > tests-e5/results/generated/ijk$i.sim
		for j in $(seq 1 `cat tests-e5/results/src/gp.csv | grep "ijk$i" | wc -l`);
		do
			CORRECT_ADDRESS=`cat tests-e5/results/src/gp.csv | grep "ijk$i" | sed -n -e "$j"p | cut -d "," -f7`
			VALUE=`cat tests-e5/results/src/gp.csv | grep "ijk$i" | sed -n -e "$j"p | cut -d "," -f3`
			if [ $VALUE -gt -1 ]; then
				FOUND_ADDRESS=`cat tests-e5/results/generated/ijk$i.sim | sed '1,/memory    value/d' | sed '$d' | grep $VALUE | awk '{print $1}'`
			else
				VALTEMP=`echo "$VALUE * -1" | bc`
				FOUND_ADDRESS=`cat tests-e5/results/generated/ijk$i.sim | sed '1,/memory    value/d' | sed '$d' | grep $VALTEMP | awk '{print $1}'`
			fi
			if [ -z "$FOUND_ADDRESS" ]; then
				echo "VALOR NÃO ENCONTRADO! Esperava encontrar $VALUE próximo ao endereço $CORRECT_ADDRESS."
			else
				DISTANCE=`echo "$FOUND_ADDRESS - $CORRECT_ADDRESS" | bc | cut -d "-" -f2`
				if [ $DISTANCE -lt 512 ]; then
					echo "Resultado em endereço correto!"
				else
					echo "Resultado em endereço INCORRETO! (distância entre $CORRECT_ADDRESS e $FOUND_ADDRESS > 512)"
				fi
			fi
		done
	fi
	done
fi

# STACK=$(($RANDOM + 100000))
# DATA=$(($STACK / 2))

# timeout 3 ./etapa5 < $test > /tmp/saida.iloc

# timeout 3 ${ILOCSIM} \
# --stack $STACK \
# --data $DATA \
# -s \
# -x < /tmp/saida.iloc > /tmp/saida.sim

# cat /tmp/saida.sim | \
# awk ’/ memory value/,0’ | \
# grep -v memory | \
# awk ’{print $1 "|" $2}’
