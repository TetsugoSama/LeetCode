/*********************************************************************
 * 问题：
 * 用两个栈实现一个,实现它的两个函数push和pop，分别完成在入队和出队，出队时
 * 返回队列头部元素（若队列为空，返回-1）。
 * 
 * 解决思路：
 * 两个栈a,b，队列所有的入栈操作都push进a,所有的出栈操作都从b来pop。当b为空
 * 时，将a的元素全部push入b,同时a执行pop，这样a中的元素正好逆序进入b，即b的
 * 栈顶为最先pop入队列的。
 */

#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> a,b;
    CQueue() {

    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if(b.empty())
        {
            if(a.empty())
                return -1;
            while(!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
        }
        int res = b.top();
        b.pop();
        return res;
    }
};