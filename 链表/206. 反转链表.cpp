/***************************************************
 * 问题：
 * 反转一个单链表。
 * 
 * 解决思路：
 * 先判断链表是否为空或者只有一个节点，如果是，返回head;
 * 然后创建三个相邻指针tail,now,next,每次执行下列动作：
 * next = now->next;
 * now->next = tail;
 * tail = now;
 * now = next;
 * 执行到now指向nullptr结束，然后再将head的next指向nullptr，返回last。
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* last = head;
        ListNode* now = last->next;
        while(now)
        {
            ListNode *next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        head->next = nullptr;
        return last;
    }
};