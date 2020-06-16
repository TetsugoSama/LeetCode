#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
ListNode* CreatList(std::vector<int>& val);
void coutvv(std::vector<std::vector<int>>& v);
template<typename T>
void printvec(std::vector<T>& v);
TreeNode* creatTree(std::vector<int>& v);