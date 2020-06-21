/*************************************************************
 * 问题：
 * 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是
 * 按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。如果，
 * 我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 解决思路：
 * 把链表按顺序遍历，计算结果和进位。循环结束条件为两个链表都到头且
 * 进位为0
*************************************************************/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* root = res;
        int jw = 0;
        while(jw||l1||l2)
        {
            int node = 0;
            if(l1)
                node += l1->val;
            if(l2)
                node += l2->val;
            node += jw;
            jw = node/10;
            node %= 10;
            root->next = new ListNode(node);
            root = root->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        return res->next;
    }
};