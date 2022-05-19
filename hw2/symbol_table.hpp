#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum ID_TYPE
{
    ID_error = 0,
    ID_constant,
    ID_variable,
    ID_array,
    ID_program,
    ID_function,
    ID_procedure,
};

enum VALUE_TYPE
{
    Value_error = 0,
    Value_int,
    Value_float,
    Value_boolean,
    Value_string,
    nullType,

};

string IDTypeToString(int type)
{

    switch (type)
    {
    case 0:
        return "ID error";
        break;
    case 1:
        return "constant";
        break;
    case 2:
        return "variable";
        break;
    case 3:
        return "array";
        break;
    case 4:
        return "program";
        break;
    case 5:
        return "function";
        break;
    case 6:
        return "procedure";
        break;

    default:
        return "error type";
        break;
    }
}

string ValueTypeToString(int type)
{

    switch (type)
    {
    case 0:
        return "Value error";
        break;
    case 1:
        return "int";
        break;
    case 2:
        return "float";
        break;
    case 3:
        return "boolean";
        break;
    case 4:
        return "string";
        break;
    case 5:
        return "void";
        break;
    default:
        return "error type";
        break;
    }
}

struct Value
{
    int valueType = Value_error;

    int int_num;
    bool bool_num;
    string str_num;
};

struct Symbol
{
    string name = "";
    int type = ID_error;

    int array_type;
    int array_size;
    int return_type;
    int local_no = -1;

    Value *value = new Value();
    vector<Value *> elements;
    vector<Value *> params;
};

class SymbolTable
{
public:
    SymbolTable() { symbols.clear(); }
    ~SymbolTable() {}

    string name = "";
    vector<Symbol *> symbols;
    int local_no = 0;
    int insert(Symbol *ID)
    {
        if (lookup(ID->name) == NULL)
        {
            symbols.push_back(ID);
        }
        return 1;
    }

    Symbol *lookup(string name)
    {

        if (symbols.size() < 1)
        {
            return NULL;
        }
        for (int i = 0; i < symbols.size(); i++)
        {
            if (symbols[i]->name == name)
            {
                return symbols[i];
            }
        }

        return NULL;
    }

    void dump()
    {
    }
};

class SymbolTableStack
{
public:
    SymbolTableStack()
    {
        tableStack.clear();
    }
    ~SymbolTableStack() {}

    vector<SymbolTable> tableStack;

    void push()
    {
        tableStack.push_back(SymbolTable());
    }

    void pop()
    {
        dump();
        tableStack.pop_back();
    }

    Symbol *lookup(string name)
    {
        Symbol *symbol = new Symbol();

        if (tableStack.size() < 1)
        {
            return symbol;
        }

        for (int i = tableStack.size() - 1; i >= 0; i--)
        {
            symbol = tableStack[i].lookup(name);
            if (symbol == NULL)
            {
                continue;
            }
            if (symbol->type != ID_error)
            {
                return symbol;
            }
        }
        return symbol;
    }

    void dump()
    {
        if (tableStack.size() > 0)
        {
            tableStack[tableStack.size() - 1].dump();
        }
    }

    Symbol *getSymbolOfProcedure()
    {
        return tableStack[0].symbols[tableStack[0].symbols.size() - 1];
    }
};
