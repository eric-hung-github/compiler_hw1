CC      = gcc
LEX     = lex
YACC    = Yacc

SCANNER = scanner
PARSER  = parser
OBJECT	= compiler

$(OBJECT): y.tab.c y.tab.h lex.yy.c
	$(CC) -o $(OBJECT) y.tab.c y.tab.h lex.yy.c

y.tab.c y.tab.h: $(PARSER).y
	$(YACC)  $(PARSER).y -H

lex.yy.c: $(SCANNER).l
	$(LEX) $(SCANNER).l

clean:
	rm *.c *.h *.gch $(OBJECT).exe