#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (!s2.empty())
        {
            int i = s2.top();
            s2.pop();
            return i;
        }

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return pop();
    }

    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return peek();
    }

    bool empty() { return (s1.empty() && s2.empty()); }
};