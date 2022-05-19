

all: clean parser

parser:lex.yy.cpp y.tab.cpp symbol_table.hpp
	g++ -g -o parser -O y.tab.cpp symbol_table.hpp

lex.yy.cpp:lex.l
	flex -o lex.yy.cpp lex.l

y.tab.cpp:yacc.y
	bison -d yacc.y -o y.tab.cpp

clean:
	rm -f parser lex.yy.* y.tab.*