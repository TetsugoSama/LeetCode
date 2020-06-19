/**********************************************
 * 问题：
 * 给定一棵二叉树，想象自己站在它的右侧，按照
 * 从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 解决思路：
 * 准备两个队列，一个存放节点，另一个存放节点的深度，
 * 每次取出一个节点和深度，将该节点的左右孩子及其深度
 * 分别存入两个队列。若某节点为同一深度最后一个节点，
 * 则将节点的值存入数组。（或者将节点和深度组成一个
 * pair）
***********************************************/


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> level;
        vector<int> res;
        q.push(root);
        level.push(1);
        int i = 1;
        while (!q.empty())
        {
            while (!q.empty()&&(level.front() == i))
            {
                root = q.front();
                if (root->left)
                {
                    q.push(root->left);
                    level.push(i+1);
                }
                if (root->right)
                {
                    q.push(root->right);
                    level.push(i+1);
                }
                q.pop();
                level.pop();
            }
            res.push_back(root->val);
            ++i;
        }
        return res;
    }
};

// int main()
// {
//     TreeNode a(1);
//     TreeNode b(2);
//     TreeNode c(3);
//     TreeNode d(4);
//     TreeNode e(5);

//     a.left = &b;
//     a.right = &c;
//     b.right = &e;
//     c.right = &d;

//     vector<int> v = Solution().rightSideView(&a);
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i]<<' ';
//     }
// }