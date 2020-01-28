all: hash

hash: command.o symtab.o iterator.o
	g++ -o $@ $^

