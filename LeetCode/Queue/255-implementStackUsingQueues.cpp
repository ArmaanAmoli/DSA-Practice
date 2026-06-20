#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x) {
        if (q1.empty() && q2.empty()) {
            q1.push(x);
            return;
        }
        if (!q1.empty()) {
            q1.push(x);
            return;
        }
        q2.push(x);
    }

    int pop() {
        if (!q1.empty()) {
            while (q1.size() > 1) {
                int i = q1.front();
                q2.push(i);
                q1.pop();
            }
            int j = q1.front();
            q1.pop();
            return j;
        }

        while (q2.size() > 1) {
            int i = q2.front();
            q1.push(i);
            q2.pop();
        }
        int j = q2.front();
        q2.pop();
        return j;
    }

    int top() {
        if (q1.empty()) {
            return q2.back();
        }
        return q1.back();
    }

    bool empty() {
        if (q1.empty() && q2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */