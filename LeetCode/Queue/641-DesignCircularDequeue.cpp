#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
    vector<int>cq;
    int front , rear;
    int k;
    int filled = 0;
public:
    MyCircularDeque(int k) {
        cq.resize(k+1);
        front = 0;
        rear = 1;
        this->k = k+1;
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        cq[front] = value;
        front = (front -1 + k)%k;
        filled++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        cq[rear] = value;
        rear = (rear + 1)%k;
        filled++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        front = (front+1)%k;
        filled--;
        if(filled==0){
            front = 0 ; rear = 1;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        rear = (rear - 1 + k) % k;
        filled--;
        if(filled==0){
            front = 0 ; rear = 1;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return cq[(front+1)%k];
    }
    
    int getRear() {
        if(isEmpty())return -1;
        return cq[(rear-1 + k)%k];
    }
    
    bool isEmpty() {
        if(front==0 && rear==1) return true;
        return false;
    }
    
    bool isFull() {
        return rear == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(){

}