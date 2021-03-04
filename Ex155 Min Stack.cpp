#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
private:
    vector<int> v, v_min;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        v.push_back(x);
        if (v_min.empty() || x <= v_min.back())
            v_min.push_back(x);
    }

    void pop()
    {
        int top = v.back();
        if (top == v_min.back())
            v_min.pop_back();
        v.pop_back();
    }

    int top()
    {
        return v.back();
    }

    int getMin()
    {
        return v_min.back();
    }
};

void function_factory(string instruct, vector<int> &operand, MinStack &s);

int main(int argc, char const *argv[])
{
    //vector<string> instructs = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    //vector<vector<int>> operands = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};
    vector<string> instructs = {"MinStack", "push", "push", "push", "getMin", "pop", "getMin"};
    vector<vector<int>> operands = {{}, {0}, {1}, {0}, {}, {}, {}};
    MinStack s;
    for (int i = 0; i < instructs.size(); i++)
        function_factory(instructs[i], operands[i], s);
    return 0;
}

void function_factory(string instruct, vector<int> &operand, MinStack &s)
{
    if (instruct == "MinStack")
        ;
    else if (instruct == "push")
        s.push(operand[0]);
    else if (instruct == "pop")
        s.pop();
    else if (instruct == "top")
        cout << s.top() << endl;
    else if (instruct == "getMin")
        cout << s.getMin() << endl;
}
