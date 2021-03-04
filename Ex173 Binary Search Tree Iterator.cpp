#include <iostream>
#include <vector>
#include "data_structure.hpp"
#include "Ex173.hpp"

using namespace std;

void function_factory(string instruct, BSTIterator &it);

int main(int argc, char const *argv[])
{
    vector<string> instructs = {"BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"};
    vector<int> v = {7, 3, 15, null, null, 9, 20};
    TreeNode *root = init_tree(v);
    BSTIterator it(root);
    for (int i = 0; i < instructs.size(); i++)
        function_factory(instructs[i], it);
    return 0;
}

void function_factory(string instruct, BSTIterator &it)
{
    if (instruct == "BSTIterator")
        ;
    else if (instruct == "next")
        cout << it.next() << endl;
    else if (instruct == "hasNext")
        cout << (it.hasNext() ? "true" : "false") << endl;
}