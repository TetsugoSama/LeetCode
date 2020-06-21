/***********************************************************************
 * 问题：
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表
 * 的所有节点组成的。
 * 
 * 解决思路：
 * 创建一个临时节点temp指向head,用指针res指向temp，然后对比l1和l2两个节点，
 * 将较小的节点（lmin）放到res后面，然后res和lmin后移，直到一个链表结束为止。
 * 把另一个节点直接放到res后面，返回temp.next。
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp(0);
        ListNode* res = &temp;
        while(l1&&l2)
        {
            if(l1->val>l2->val)
            {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
            else
            {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            }
        }
        if(l1)
            res->next = l1;
        else if(l2)
            res->next = l2;
        return temp.next;
        
    }
};