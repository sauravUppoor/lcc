CC = cc
CFLAGS = -std=c99 -O3 -Wall -Wno-unused-result

lexer: main.c lexer.c parser.c
			$(CC) -o lexer -g main.c lexer.c parser.c $(CFLAGS)