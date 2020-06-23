/******************************************************************
 * 问题：
 * 使用队列实现栈的下列操作：
 * push(x) -- 元素x入栈
 * pop() -- 移除栈顶元素并返回
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 解决思路：
 * （1）单队列法：一个队列，入栈时直接push入队列，出栈时把队列头一个个push
 * 进队列尾并pop，直到原队列尾在队列头部为止。
 * （2）双队列出栈整理：将元素优先push入不为空的队列，出栈时把不为空的队列
 * push入另一个队列，直到只剩队列尾。
 * （3）双队列入栈整理：将元素优先push入空队列，然后把另一个队列push入该队列，
 * 出栈时直接pop不为空的队列。
 */

#include <queue>

using namespace std;

class MyStack1 {
public:
    /** Initialize your data structure here. */
    queue<int> a;
    MyStack1() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int lenth = a.size();
        while(lenth>1) {
            a.push(a.front());
            a.pop();
            --lenth;
        }
        int res = a.front();
        a.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int lenth = a.size();
        while(lenth>1) {
            a.push(a.front());
            a.pop();
            --lenth;
        }
        int res = a.front();
        a.push(a.front());
        a.pop();
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};

class MyStack2 {
public:
    /** Initialize your data structure here. */
    queue<int> a,b;
    MyStack2() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(b.empty()) {
            a.push(x);
        }else {
            b.push(x);
        }   
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if(!a.empty()) {
            while(a.size()>1) {
                b.push(a.front());
                a.pop();
            }
            res = a.front();
            a.pop();
        }else {
            while(b.size()>1) {
                a.push(b.front());
                b.pop();
            }
            res = b.front();
            b.pop();            
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res;
        if(!a.empty()) {
            while(a.size()>1) {
                b.push(a.front());
                a.pop();
            }
            res = a.front();
            b.push(a.front());
            a.pop();
        }else {
            while(b.size()>1) {
                a.push(b.front());
                b.pop();
            }
            res = b.front();
            a.push(b.front());
            b.pop();            
        }
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty()&&b.empty();
    }
};

class MyStack3 {
public:
    /** Initialize your data structure here. */
    queue<int> a,b;
    MyStack3() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(a.empty()) {
            a.push(x);
            while(!b.empty()) {
                a.push(b.front());
                b.pop();
            }
        }else {
            b.push(x);
            while(!a.empty()) {
                b.push(a.front());
                a.pop();
            }
        }   
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if(a.empty()) {
            res = b.front();
            b.pop();
        }else {
            res = a.front();
            a.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return a.empty()?b.front():a.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty()&&b.empty();
    }
};