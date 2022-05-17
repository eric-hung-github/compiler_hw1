all: clean scanner

scanner:lex.yy.cpp y.tab.cpp symbol_table.hpp
	g++ -g -o scanner -O y.tab.cpp symbol_table.hpp

lex.yy.cpp:lex.l
	flex -o lex.yy.cpp lex.l

y.tab.cpp:yacc.y
	bison -d yacc.y -o y.tab.cpp

clean:
	rm -f scanner lex.yy.* y.tab.*