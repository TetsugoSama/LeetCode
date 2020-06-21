/************************************************************
 * 问题：
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指
 * 向链表中的任何节点或空节点。要求返回这个链表的深拷贝。 
 * 
 * 解决思路：
 * 将原链表遍历，以原节点为key,深拷贝节点为value存入map,同时将
 * 深拷贝节点的next绑定，再将原链表遍历，以
 * map[key]->random = map[key->random]的形式把深拷贝的random
 * 关系构造好。
 */

#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> nmap;
        Node* h = head;
        Node temp(0);
        Node *n = &temp;
        nmap.insert({nullptr,nullptr});
        while(head)
        {
            n->next = new Node(head->val);
            n = n->next;
            nmap.insert({head,n});
            head = head->next;
        }
        while(h)
        {
            nmap[h]->random = nmap[h->random];
            h = h->next;
        }
        return temp.next;
    }
};