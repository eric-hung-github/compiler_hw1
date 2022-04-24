CC = gcc
# SRCFILES = main.c
LEXYACC = b10830020
TARGET = executable

all: $(TARGET)


$(TARGET): lex.yy.c
	$(CC) -o $@ lex.yy.c
# $(TARGET): y.tab.o lex.yy.o ${SRCFILES:.c=.o}
# 	$(CC) -o $@ $>

.c.o:
	$(CC) -c $>

lex.yy.c: $(LEXYACC).l
	flex $(LEXYACC).l

# y.tab.c: $(LEXYACC).y
# 	yacc -d $(LEXYACC).y

clean:
	rm -f $(TARGET) lex.yy.c *.o