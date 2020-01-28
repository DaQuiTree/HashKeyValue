all: hash

hash: main.o symtab.o iterator.o
	g++ -o $@ $^

