#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue
{
private:
    stack<int> s1, s2;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while (!s1.empty())
        {
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        s1.push(x);
        while (!s2.empty())
        {
            int top = s2.top();
            s2.pop();
            s1.push(top);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int top = s1.top();
        s1.pop();
        return top;
    }

    /** Get the front element. */
    int peek()
    {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};

void function_factory(string instruct, vector<int> &operand, MyQueue &s);

int main(int argc, char const *argv[])
{
    /*MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->peek() << endl;
    obj->pop();
    cout << (obj->empty() ? "true" : "false") << endl;*/
    vector<string> instructs = {"MyQueue", "push", "push", "peek", "pop", "empty"};
    vector<vector<int>> operands = {{}, {1}, {2}, {}, {}, {}};
    MyQueue q;

    for (int i = 0; i < instructs.size(); i++)
        function_factory(instructs[i], operands[i], q);
    return 0;
}

void function_factory(string instruct, vector<int> &operand, MyQueue &s)
{
    if (instruct == "MyQueue")
        ;
    else if (instruct == "push")
        s.push(operand[0]);
    else if (instruct == "pop")
        cout << s.pop() << endl;
    else if (instruct == "peek")
        cout << s.peek() << endl;
    else if (instruct == "empty")
        cout << (s.empty() ? "true" : "false") << endl;
}