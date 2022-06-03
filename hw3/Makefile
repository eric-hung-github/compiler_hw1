CC = g++
LEX = flex
YACC = bison

TARGET = exe
PARSER = parser
SCANNER = scanner
SYMBOL = symbol_table


all: clean parser

parser:lex.yy.cpp y.tab.cpp $(SYMBOL).hpp
	g++ -g -o $(TARGET) -O y.tab.cpp $(SYMBOL).hpp

lex.yy.cpp:$(SCANNER).l
	$(LEX) -o lex.yy.cpp $(SCANNER).l

y.tab.cpp:$(PARSER).y
	$(YACC) -d $(PARSER).y -o y.tab.cpp

clean:
	rm -f $(TARGET) lex.yy.* y.tab.*