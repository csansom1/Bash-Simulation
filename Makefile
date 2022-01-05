all: myshell

myshell: myshell.o lex.yy.o
	gcc -o myshell myshell.o lex.yy.o -lfl
 
myshell.o: myshell.c myshell.h
	gcc -Wall -std=c11 -g -c myshell.c

lex.yy.o: lex.yy.c
	gcc -Wall -g -c lex.yy.c

lex.yy.c: lex.c
	flex lex.c
clean:
	rm -f *.o
	rm -f lex.yy.c
	rm -f myshell

	