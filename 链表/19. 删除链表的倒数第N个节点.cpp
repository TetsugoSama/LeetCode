/***********************************************************
 * 题目：
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 解决思路：
 * （1）双指针法：
 *  准备两个指针pre,last，都指向头节点的前一节点，pre先向后移动
 * n个节点，然后两节点一起移动。当pre到达尾部时，last指向了要删除
 * 的节点。
 * （2）容器法：
 * 将链表所有的节点放入顺序容器中（如vector和stack）
 **********************************************************/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {   
        ListNode *p = new ListNode(NULL);
        p->next = head;
        ListNode *k = p, *s = p;
        int dis = 0;
        while(k->next)
        {
            if(dis<n)
            {
                k = k->next;
                dis++;
            }
            else
            {
                k = k->next;
                s = s->next;
            }
        }
        s->next = s->next->next;
        return p->next;
    };
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        vector<ListNode*> vec;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }
        int lenth = vec.size();
        if(n==lenth)
            return vec[0]->next;
        else
            vec[lenth-n-1]->next = vec[lenth-n-1]->next->next;
        return vec[0];
    }
};

class Solution3 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        stack<ListNode*> s;
        ListNode* res = head;
        while(head)
        {
            s.push(head);
            head = head->next;
        }
        int i=1;
        while(i<=n)
        {
            s.pop();
            ++i;
        }
        if(!s.empty())
        {
            s.top()->next = s.top()->next->next;
            return res;
        }
        else
            return res->next;
    }
};