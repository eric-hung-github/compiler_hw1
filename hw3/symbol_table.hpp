#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

fstream jasm_file;
void jasm(string s)
{
    jasm_file << s << endl;
    cout << "JASM$ " << s << " $" << endl;
}

enum IDType
{
    ID_ERROR = 0,
    ID_CONST,
    ID_VAR,
    ID_ARR,
    ID_PROGRAM,
    ID_FUNC,
    ID_PROCEDURE,
};

enum ValueType
{
    VALUE_NONE = 0,
    VALUE_INT,
    VALUE_FLOAT,
    VALUE_BOOL,
    VALUE_STR,
    VALUE_VOID,

};

string IDTypeToString(int type)
{

    switch (type)
    {
    case ID_ERROR:
        return "ID_ERROR";
        break;
    case ID_CONST:
        return "constant";
        break;
    case ID_VAR:
        return "variable";
        break;
    case ID_ARR:
        return "array";
        break;
    case ID_PROGRAM:
        return "program";
        break;
    case ID_FUNC:
        return "function";
        break;
    case ID_PROCEDURE:
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
    case VALUE_NONE:
        return "VALUE_NONE";
        break;
    case VALUE_INT:
        return "int";
        break;
    case VALUE_FLOAT:
        return "float";
        break;
    case VALUE_BOOL:
        return "boolean";
        break;
    case VALUE_STR:
        return "string";
        break;
    case VALUE_VOID:
        return "void";
        break;
    default:
        return "error type";
        break;
    }
}

struct Value
{
    int value_type = VALUE_NONE;

    int int_value;
    float float_value;
    bool bool_value;
    string string_value;

public:
    string display()
    {
        switch (value_type)
        {
        case VALUE_INT:
            return to_string(int_value);
            break;
        case VALUE_FLOAT:
            return to_string(float_value);
            break;
        case VALUE_BOOL:
            return (bool_value) ? "1" : "0";
            break;
        case VALUE_STR:
            return string_value;
            break;
        case VALUE_VOID:
            return "VALUE_VOID";
            break;
        default:
            return "VALUE_NONE";
        }
    }
};

struct Symbol
{
    string name = "";
    int id_type = ID_ERROR;
    bool init = false;

    Value *value = new Value();
    vector<Symbol *> arguments;
    bool is_global = false;
    int counter = 0;
};

class SymbolTable
{
    string name = "";
    vector<Symbol *> symbols;

public:
    // bool is_global = false;

    SymbolTable(string table_name)
    {
        name = table_name;
        symbols.clear();
    }
    ~SymbolTable() {}

    int size()
    {
        return symbols.size();
    }

    bool insert(Symbol *id)
    {

        if (lookup(id->name) == nullptr)
        {
            symbols.push_back(id);
            // cout << "SymbolTable<" << name << "> insert " << id->name << " <" + IDTypeToString(id->id_type) + "> " << ValueTypeToString(id->value->value_type) << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    Symbol *lookup(string name)
    {
        for (int i = 0; i < symbols.size(); i++)
        {
            if (symbols[i]->name == name)
            {
                return symbols[i];
            }
        }

        return nullptr;
    }

    void dump()
    {
        // cout << "===================================================" << endl;
        // cout << "Table: " << name << endl;
        // cout << setw(20) << "name";
        // cout << setw(20) << "id type" << endl;

        for (int i = 0; i < symbols.size(); i++)
        {
            cout << "<\"" << symbols[i]->name << "\", ";

            cout << IDTypeToString(symbols[i]->id_type) << ", ";

            cout << ValueTypeToString(symbols[i]->value->value_type) << ", ";

            cout << symbols[i]->counter << ">";

            cout << endl;
        }
    }
};

class SymbolTableStack
{
    vector<SymbolTable> tableStack;

public:
    vector<Symbol *> argumentStack;
    vector<Value *> parseStack;
    Symbol *fun_ptr = nullptr;
    string program_name;

    string bool_operator;

    SymbolTableStack()
    {
        tableStack.clear();
    }
    ~SymbolTableStack() {}

    int size()
    {
        return tableStack.size();
    }

    SymbolTable *top()
    {
        return &tableStack[size() - 1];
    }

    void push(string table_name)
    {
        tableStack.push_back(SymbolTable(table_name));
        // if (size() > 1)
        // {
        //      cout << "entering block, next number " << top()->size() << endl;
        // }
        cout << "entering block, next number " << top()->size() << endl;
    }

    void pop()
    {
        SymbolTable table = tableStack[tableStack.size() - 1];

        // if (size() > 1)
        // {
        //     cout << "leaving block, symbol table entries:" << endl;
        // }
        cout << "leaving block, symbol table entries:" << endl;

        table.dump();
        tableStack.pop_back();
    }

    bool insert(Symbol *id)
    {
        if (size() == 1)
        {
            id->is_global = true;
        }

        if (!top()->insert(id))
        {
            return false;
        }

        if (id->id_type == ID_VAR)
        {
            if (id->is_global)
            {
                jasm("field static int " + id->name);
            }
            else
            {
                cout << id->name + " = " + to_string(top()->size() - 1) + ", next number " + to_string(top()->size()) << endl;
                if (id->init)
                {
                    store_value(id);
                }
                id->counter = top()->size() - 1;
            }
        }
        return true;
    }

    Symbol *lookup(string name)
    {
        for (int i = tableStack.size() - 1; i >= 0; i--)
        {
            Symbol *symbol = tableStack[i].lookup(name);
            if (symbol != nullptr)
            {
                return symbol;
            }
        }
        return nullptr;
    }
    //**************************************************
    // function for javaa
    //**************************************************
    void store_value(Symbol *symbol)
    {

        int index = top()->size() - 1;
        switch (symbol->value->value_type)
        {
        case VALUE_INT:
            jasm("sipush " + symbol->value->display());
            jasm("istore " + to_string(index));
            break;
        case VALUE_FLOAT:
            jasm("sipush " + symbol->value->display());
            jasm("istore " + to_string(index));
            break;
            break;
        default:
            break;
        }
    }

    void load_value(Symbol *symbol)
    {
        if (symbol->id_type == ID_VAR)
        {
            switch (symbol->value->value_type)
            {
            case VALUE_INT:
                jasm("iload " + to_string(symbol->counter));
                break;
            case VALUE_FLOAT:
                jasm("iload " + to_string(symbol->counter));
                break;
            default:
                break;
            }
        }
        else if (symbol->id_type == ID_CONST)
        {
            switch (symbol->value->value_type)
            {
            case VALUE_INT:
                jasm("sipush " + symbol->value->display());
                break;
            case VALUE_BOOL:
                jasm("iconst_" + symbol->value->display());
                break;
            case VALUE_FLOAT:
                jasm("sipush " + symbol->value->display());
                break;
            case VALUE_STR:
                jasm("ldc \"" + symbol->value->display() + "\"");
                break;
            default:
                break;
            }
        }
        else
        {
            printf("load value error\n");
        }
    }

    void update_value(Symbol *symbol)
    {
        if (symbol->is_global)
        {
            jasm("putstatic " + ValueTypeToString(symbol->value->value_type) + " " + program_name + "." + symbol->name);
        }
        else
        {
            int index = symbol->counter;
            switch (symbol->value->value_type)
            {
            case VALUE_INT:
                jasm("istore " + to_string(index));
                break;
            case VALUE_FLOAT:
                jasm("istore " + to_string(index));
                break;
                break;
            default:
                break;
            }
        }
    }

    void print(Value *value, bool println)
    {
        string type_name;
        string print_func = (println) ? "println" : "print";
        switch (value->value_type)
        {
        case VALUE_INT:
            type_name = "int";
            break;
        case VALUE_FLOAT:
            type_name = "float";
            break;
        case VALUE_BOOL:
            type_name = "bool";
            break;
        case VALUE_STR:
            type_name = "java.lang.String";
            break;
        default:
            break;
        }
        jasm("getstatic java.io.PrintStream java.lang.System.out");
        jasm("invokevirtual void java.io.PrintStream." + print_func + "(" + type_name + ")");
    }
};
