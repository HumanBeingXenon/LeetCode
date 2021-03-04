#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q1;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
        int n = q1.size();
        for (int i = 0; i < n - 1; i++)
        {
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

void function_factory(string instruct, vector<int> &operand, MyStack &s);

int main(int argc, char const *argv[])
{
    vector<string> instructs = {"MyStack", "push", "push", "top", "pop", "empty"};
    vector<vector<int>> operands = {{}, {1}, {2}, {}, {}, {}};
    MyStack ms;
    for (int i = 0; i < instructs.size(); i++)
        function_factory(instructs[i], operands[i], ms);
    return 0;
}

void function_factory(string instruct, vector<int> &operand, MyStack &s)
{
    if (instruct == "MyStack")
        ;
    else if (instruct == "push")
        s.push(operand[0]);
    else if (instruct == "pop")
        cout << s.pop() << endl;
    else if (instruct == "top")
        cout << s.top() << endl;
    else if (instruct == "empty")
        cout << (s.empty() ? "true" : "false") << endl;
}