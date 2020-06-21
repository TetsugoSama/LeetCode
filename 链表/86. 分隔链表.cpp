/********************************************************************
 * 问题：给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点、
 * 在大于或等于 x 的节点之前。保留两个分区中每个节点的初始相对位置。
 * 
 * 解决思路：
 * （1）双临时头节点：
 * 创建两个头节点A,B;然后遍历链表，把小于x的放入A链表中，大于等于x的放入B链表中;
 * 最后把两个链表拼接起来（注意：B的尾部的next要指向nullptr）。
 * （2）单临时头节点：
 * 先判断head是否为nullptr或者只有一个节点，若是，则返回head；
 * 创建一个临时头节点，指向head节点，然后移动指针，一直移动到不小于x的点为止。
 * 该点的前驱记录为node;然后判断后面的点，若小于x，则放入node->next,node后移。
 * 最后把两张表拼接起来。
 */
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode tempA(0),tempB(0);
        ListNode *less_ptr = &tempA,*more_ptr = &tempB;
        while(head) {
            if(head->val<x) {
                less_ptr->next = head;
                less_ptr = less_ptr->next;
            }else {
                more_ptr->next = head;
                more_ptr = more_ptr->next;
            }
            head = head->next;
        }
        less_ptr->next = tempB.next;
        more_ptr->next = nullptr;
        return tempA.next;
    }
};

class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)
            return head;
        ListNode temp(0);
        temp.next = head;
        ListNode* node = &temp;
        while(node->next&&node->next->val<x)
        {
            node = node->next;
        }
        ListNode *right = node;
        ListNode *right_head = node->next;
        while(right->next)
        {
            if(right->next->val<x)
            {
                ListNode *target = right->next;
                node->next = target;
                node = target;
                right->next = target->next;
            }
            else
                right = right->next;
        }
        node->next = right_head;
        return temp.next;
    }
};