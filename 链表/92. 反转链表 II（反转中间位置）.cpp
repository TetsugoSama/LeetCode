/***************************************************
 * 问题：
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 解决思路：
 * 预备一个指针pre，指向m节点的前驱（为防止m=1,创建一个临时节点h成为head的前驱）
 * 然后创建三个相邻指针tail,now,next,每次执行下列动作：
 * next = now->next;
 * now->next = tail;
 * tail = now;
 * now = next;
 * 执行到now指向n节点结束，然后再将反转过的链表与剩余部分拼接。
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode  h(0);
        h.next = head;
        ListNode* pre = &h;
        int i = 1;
        while(i<m)
        {
            pre = pre->next;
            ++i;
        }
        ListNode* tail = pre->next;
        ListNode* now = tail->next;
        i = m+1;
        while(i<=n)
        {
            ListNode *next = now->next;
            now->next = tail;
            tail = now;
            now = next;
            ++i;
        }
        pre->next->next = now;
        pre->next = tail;
        return h.next;        
    }
};