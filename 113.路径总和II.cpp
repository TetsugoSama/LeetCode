/********************************************************
 * 问题：给定一个二叉树和一个目标和，找到所有从根节点到叶子节点
 * 路径总和等于给定目标和的路径。
 * 
 * 解决思路：递归法，把每个节点的左右孩子都访问一遍 
 * *****************************************************/
#include <iostream>
#include "leetcode.h"
#include <vector>

using namespace std;

class Solution {
public:
    void fun(TreeNode* root, vector<vector<int>>& res, vector<int>& vec, int sum, int add)
    {
        if ((root->left == nullptr) && (root->right == nullptr))      //若该节点同时没有左右孩子，则为叶子
        {
            if (add == sum)                 //如果现在的路径总和与目标相同
            {
                vec.push_back(root->val);   //将本节点的值放入vec中
                res.push_back(vec);         //将该路径放入res中
                vec.pop_back();             //将本节点的值取出，转入下一条路径
            }
        }
        else if (root->right == nullptr)    //该节点无右孩子
        {
            vec.push_back(root->val);       //将本节点的值放入vec中
            fun(root->left, res, vec, sum, add + root->left->val);       //进入左孩子
            vec.pop_back();                 //将本节点的值取出，转入下一条路径
        }
        else if (root->left == nullptr)     //该节点无左孩子
        {
            vec.push_back(root->val);       //将本节点的值放入vec中
            fun(root->right, res, vec, sum, add + root->right->val);    //进入右孩子
            vec.pop_back();                 //将本节点的值取出，转入下一条路径
        }
        else                                //该节点既有左孩子，又有右孩子
        {
            vec.push_back(root->val);       //将本节点的值放入vec中
            fun(root->left, res, vec, sum, add + root->left->val);  //进入左孩子
            fun(root->right, res, vec, sum, add + root->right->val);//进入右孩子
            vec.pop_back();                 //将本节点的值取出，转入下一条路径
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> vec;
        fun(root, res, vec, sum, root->val);
        return res;
    }
};

int main()
{
    vector<int> tree = { 2,-1,3};
    TreeNode* root = creatTree(tree);
    vector<vector<int>> res = Solution().pathSum(root, 2);
    coutvv(res);
}

