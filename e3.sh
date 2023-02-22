#!/bin/bash
rm -f temp.dot
rm -f temp1.dot
./etapa3 < tests/$1 | sed 's/, 0x/ -> 0x/g' | sed 's/0x/x/g' > temp.dot
(echo "digraph {" && echo "label=\"Ref\"" && cat temp.dot && echo "}") > temp1.dot
rm -f temp.dot
mv temp1.dot temp.dot
xdot temp.dot &
xdot tests/$1.ref.dot &
cat tests/$1
echo
valgrind -v --leak-check=full ./etapa3 < tests/$1
