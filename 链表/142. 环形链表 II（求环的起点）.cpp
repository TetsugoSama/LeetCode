/****************************************************************************
 * 问题：给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 解决思路：
 * （1）快慢指针法：
 * 设置两个指针指向头节点，然后快指针一次移动两步，慢指针一次移动一步，若两指针能够
 * 相遇，则表示存在环；若到达链表尾，则无环。指向头节点的指针和指向相遇点的指针同时
 * 向后移动，相遇点则为环的起点。
 * （2）set法：一边遍历节点，一边把节点放入set。若到达尾部，则无环；若某节点已经在
 * set内，则为环的起点。
 */

#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head&&!s.count(head))
        {
            s.insert(head);
            head = head->next;
        }
        return head;
    }
};
  
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = nullptr;
        while(fast&&fast->next) {
        
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
            {
                meet = fast;
                break;
            }
        }
        if(!meet)
            return meet;
        while(head!=meet)
        {
            head = head->next;
            meet = meet->next;
        }
        return head;
    }
};