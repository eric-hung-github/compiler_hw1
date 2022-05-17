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

string id_type_to_str(int type)
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
        return "procedure";
        break;

    default:
        return "error type";
        break;
    }
}

string val_type_to_str(int type)
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
    int insert(Symbol *id)
    {
        if (lookup(id->name) == NULL)
        {
            // cout << "insert " << id->name << endl;
            symbols.push_back(id);
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
        cout << "===================================================" << endl;
        cout << "Table: " << name << endl;
        // cout << "<type>name" << endl;

        for (int i = 0; i < symbols.size(); i++)
        {
            cout << "\t";
            if (symbols[i]->type == ID_program)
            {
                cout << "<" << id_type_to_str(symbols[i]->type) << ">";
            }

            if (symbols[i]->type == ID_constant)
            {
                cout << "<" << val_type_to_str(symbols[i]->value->valueType) << ">";
            }

            if (symbols[i]->type == ID_variable)
            {
                cout << "<" << val_type_to_str(symbols[i]->value->valueType) << ">";
            }

            if (symbols[i]->type == ID_array)
            {
                cout << "<" << val_type_to_str(symbols[i]->array_type) << ">";
            }

            if (symbols[i]->type == ID_procedure)
            {
                cout << "<" << id_type_to_str(symbols[i]->type) << ">";
            }
            cout << symbols[i]->name << endl;
        }
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
