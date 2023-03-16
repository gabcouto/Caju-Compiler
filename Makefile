# Gabriel Couto & Felippo Stédile: Dupla 
ETAPA_ATUAL = etapa5
FILES_TO_TAR = extra.c main.c scanner.l parser.y extra.h Makefile
OUT = etapa4
LINUXCC  = gcc
LINUXFLEX = flex
LINUXBISON = bison
OSXCC = /usr/local/Cellar/gcc/12.2.0/bin/*-gcc-12 -g -fsanitize=address
OSXFLEX = /usr/local/opt/flex/bin/flex
OSXBISON = /usr/local/opt/bison/bin/bison
OBJ_FOLDER = mkdir -p obj
TEMP_FOLDER = mkdir -p temp
UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CC = $(LINUXCC)
		FLEX = $(LINUXFLEX)
		BISON = $(LINUXBISON)
	endif
	ifeq ($(UNAME_S),Darwin)
		CC = $(OSXCC)
		FLEX = $(OSXFLEX)
		BISON = $(OSXBISON)
		SPECIFIC_FLAGS = -L /usr/local/opt/flex/lib/
	endif
all: clean parser scanner main
	$(CC) obj/parser.tab.o obj/lex.yy.o obj/main.o obj/extra.o $(SPECIFIC_FLAGS) -lfl -o $(OUT)
main: main.c
	$(OBJ_FOLDER)
	$(CC) extra.c -c -o obj/extra.o
	cp temp/parser.tab.h .
	$(CC) main.c -c -o obj/main.o
	rm parser.tab.h
scanner: scanner.l
	$(OBJ_FOLDER)
	$(FLEX) -o temp/lex.yy.c scanner.l
	$(CC) -c temp/lex.yy.c -o obj/lex.yy.o
	$(CC) -c temp/parser.tab.c -o obj/parser.tab.o
parser:
	$(TEMP_FOLDER)
	$(BISON) -d -o temp/parser.tab.c parser.y
package:
	tar cvzf $(ETAPA_ATUAL).tgz $(FILES_TO_TAR)
clean:
	rm -rf obj
	rm -rf temp
	rm -f parser
	rm -f *.tgz
	rm -f $(ETAPA_ATUAL)
