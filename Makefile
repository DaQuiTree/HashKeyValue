all: hash

hash: main.o symtab.o
	g++ -o $@ $^

