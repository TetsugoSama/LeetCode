/********************************************************
 * 问题：
 * 对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个
 * 结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点
 * 也可以是它自己的祖先）
 * 
 * 解决思路：
 * （1）把p和q的路径保存在数组里，再从后向前查找。
 * （2）把p的路径先保存在stack里，然后再保存在set里，把q的路径
 * 保存再stack里，再一个个的把q的栈顶和p的set比对（慢）
 * *****************************************************/

// 算法题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include "leetcode.h"

using namespace std;

class Solution1 {
public:
    bool found(TreeNode* root, TreeNode* t, stack<TreeNode*>& s)
    {
        if (root == t)
        {
            s.push(root);
            return true;
        }
        else if (!root)
            return false;

        s.push(root);
        if (found(root->left, t, s) || found(root->right, t, s))
            return true;
        else
        {
            s.pop();
            return false;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> pset;
        stack<TreeNode*> pstack, qstack;
        TreeNode* node = root;
        found(root, p, pstack);
        found(root, q, qstack);
        while (!pstack.empty())
        {
            pset.insert(pstack.top());
            pstack.pop();
        }
        while (pset.find(qstack.top()) == pset.end())
            qstack.pop();
        return qstack.top();
    }
};

class Solution2 {
public:
    bool found(TreeNode* root, TreeNode* t, vector<TreeNode*>& v)
    {
        if (root == t)
        {
            v.push_back(root);
            return true;
        }
        else if (!root)
            return false;

        v.push_back(root);
        if (found(root->left, t, v) || found(root->right, t, v))
            return true;
        else
        {
            v.pop_back();
            return false;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>vp,vq;
        TreeNode* node = root;
        found(root, p, vp);
        found(root, q, vq);
        int i = min(vp.size(),vq.size())-1;
        while (vp[i] != vq[i])
            --i;
        return vp[i];
    }
};

// int main()
// {
//     vector<int> v = { 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4 };
//     TreeNode a(3);
//     TreeNode b(5);
//     TreeNode c(1);
//     TreeNode d(6);
//     TreeNode e(2);
//     TreeNode f(0);
//     TreeNode g(8);
//     TreeNode h(7);
//     TreeNode i(4);
//     a.left = &b;
//     a.right = &c;
//     b.left = &d;
//     b.right = &e;
//     c.left = &f;
//     c.right = &g;
//     e.left = &h;
//     e.right = &i;
//     TreeNode* res = VectorSolution().lowestCommonAncestor(&a, &b, &i);
//     cout << res->val;
// }