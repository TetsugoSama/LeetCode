/*********************************************************
 * 问题：
 * 给定一个二叉树，原地将它按前序遍历展开为一个单链表。
 * 
 * 解决思路：
 * (1)把二叉树用stack进行遍历，如果该节点为左孩子则入栈，并存入
 *    数组；若为右孩子，则栈顶（父节点）出栈（对于栈顶而言，左右
 *    孩子都已经访问，故不再有存在的必要），并将该节点存入数组；
 *    若绝后，则栈顶出栈，并标记下一个栈顶已经访问过左孩子。
 *    将所有的节点访问过后，数组中节点按照先序遍历排列，然后再组
 *    成链表即可。
 * (2)把二叉树用stack进行遍历，如果该节点有左孩子，则:
 *    1.若该节点有右孩子，右孩子入栈；
 *    2.让左孩子变成右孩子。
 *    3.访问右孩子。
 *    若该节点有右孩子，则访问右孩子。
 *    若该节点绝后，则让该节点的右孩子为栈顶，栈顶出栈，访问右孩子。
 * ********************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include "leetcode.h"

using namespace std;

class Solution1 {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;
        vector<TreeNode*> node;
        stack<TreeNode*> tree;
        tree.push(root);
        node.push_back(root);
        bool visited = false;
        while (!tree.empty())
        {
            if (!visited && tree.top()->left != nullptr)
            {
                root = tree.top()->left;
                tree.push(root);
                node.push_back(root);
            }
            else if (tree.top()->right != nullptr)
            {
                root = tree.top()->right;
                tree.pop();
                tree.push(root);
                node.push_back(root);
                visited = false;
            }
            else
            {
                tree.pop();
                visited = true;
            }
        }
        int i=0;
        while(i < node.size() - 1)
        {
            node[i]->right = node[i + 1];
            node[i]->left = nullptr;
            ++i;
        }
    }
};

class Solution2 {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> tree;
        while (true) {
            if (root->left) {
                if(root->right)
                    tree.push(root->right);
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }else if (root->right) {
                root = root->right;
            }else {
                if (tree.empty())
                    break;
                root->right = tree.top();
                tree.pop();
                root = root->right;
            }
        }
    }
};

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &e;
    b.left = &c;
    b.right = &d;
    e.right = &f;
    Solution().flatten(&a);
    TreeNode* res = &a;
    while(res)
    {
        cout << res->val<<' ';
        res = res->right;
    }
}