CC = gcc
LEXYACC = b10830020
TARGET = compiler

all: $(TARGET)


$(TARGET): lex.yy.c
	$(CC) -o $@ lex.yy.c
# $(TARGET): y.tab.o lex.yy.o ${SRCFILES:.c=.o}
# 	$(CC) -o $@ $>

.c.o:
	$(CC) -c $>

lex.yy.c: $(LEXYACC).l
	lex $(LEXYACC).l

# y.tab.c: $(LEXYACC).y
# 	yacc -d $(LEXYACC).y

clean:
	rm -f $(TARGET) lex.yy.c *.o