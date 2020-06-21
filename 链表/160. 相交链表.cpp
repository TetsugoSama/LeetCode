/***************************************************
 * 问题：
 * 编写一个程序，找到两个单链表相交的起始节点。
 * (注意：两链表可能不相交)
 * 
 * 解决思路：
 * （1）测量两链表长度，然后让较长的链表的头指针向后移动，
 * 直到两链表的长度相同为止。比较两链表的指针，若不相同则
 * 同时向后移动。
 * （2）将两链表的所有节点存在两个数组里，然后两个数组同时
 * 从后向前比较，第一个不同的元素的下一个元素就是结果。
 * （注意：有的链表的头节点就是交点，两数组找不到不同的元素）
 * （3）将第一个链表所有节点放入set中，然后第二个链表将每个
 * 节点都在set中查询，第一个再set中的节点即交点。
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SolutionA {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0;
        ListNode *A = headA;
        while(A) {
            A = A->next;
            ++la;
        }
        int lb = 0;
        ListNode* B = headB;
        while(B) {
            B = B->next;
            ++lb;
        }
        ListNode* longg,*shortt;
        int distance;
        if(la>lb) {
            longg = headA;
            shortt = headB;
            distance = la-lb;
        }else {
            longg = headB;
            shortt = headA;      
            distance = lb-la;
        }
        while(distance) {
            longg = longg->next;
            --distance;
        }
        while(longg&&longg!=shortt) {
            longg = longg->next;
            shortt = shortt->next;
        }
        return longg;
    }
};

class SolutionB {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
            return nullptr;
        vector<ListNode*> sA,sB;
        while(headA) {
            sA.push_back(headA);
            headA =headA->next;
        }
        while(headB) {
            sB.push_back(headB);
            headB = headB->next;
        }
        if(sA.back()!=sB.back())
            return nullptr;
        int a = sA.size()-1,b=sB.size()-1;
        while(a>=0&&b>=0) {
            if(sA[a]!=sB[b])
                return sA[a+1];
            --a;
            --b;
        }
        return a<0?sA[0]:sB[0];
    }
};

class SolutionC {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA)
        {
            s.insert(headA);
            headA =headA->next;
        }
        while(headB&&!s.count(headB))
        {
            headB = headB->next;
        }
        return headB;
    }
};