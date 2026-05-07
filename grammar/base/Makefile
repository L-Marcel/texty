all: build

build: flex
	gcc lex.yy.c -o lexical

flex: 
	flex lexical.l

run: all
	./lexical

run-pendrive: all
	/lib64/ld-linux-x86-64.so.2 ./lexical


