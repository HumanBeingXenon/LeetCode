#include <iostream>
#include <vector>
#include "Ex208.hpp"

using namespace std;

template <typename T>
void function_factory(string instruct, vector<string> operand, T &tr);

int main(int argc, char const *argv[])
{
    vector<string> instructs = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<vector<string>> operands = {{}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"}};
    Trie2 tr;
    for (int i = 0; i < instructs.size(); i++)
        function_factory(instructs[i], operands[i], tr);
    return 0;
}

template <typename T>
void function_factory(string instruct, vector<string> operand, T &tr)
{
    if (instruct == "Trie")
        ;
    else if (instruct == "insert")
        tr.insert(operand[0]);
    else if (instruct == "search")
        cout << (tr.search(operand[0]) ? "true" : "false") << endl;
    else if (instruct == "startsWith")
        cout << (tr.startsWith(operand[0]) ? "true" : "false") << endl;
}