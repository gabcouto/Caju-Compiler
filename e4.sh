#!/bin/bash
rm -f temp.dot
rm -f temp1.dot
ETAPA_ATUAL=`cat Makefile | grep "ETAPA_ATUAL =" | awk '{print $3}'`
./$ETAPA_ATUAL < tests/$1 | sed 's/, 0x/ -> 0x/g' | sed 's/0x/x/g' > temp.dot
(echo "digraph {" && echo "label=\"Ref\"" && cat temp.dot && echo "}") > temp1.dot
rm -f temp.dot
mv temp1.dot w$1.dot
xdot w$1.dot &
xdot tests/$1.ref.dot &
cat tests/$1
echo
valgrind -v --leak-check=full ./$ETAPA_ATUAL < tests/$1
