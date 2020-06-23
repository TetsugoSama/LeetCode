/*****************************************************************
 * 问题：
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 解决思路：
 * 前序数组的第一个元素为根节点，中序数组的开头到根节点为左子树，长度为
 * left_len，根节点到结尾为右子树，长度为right_len;故前序数组的
 * 1~left_len为左子树，left_len+1~结尾为右子树，递归构建子树。
 * 当传递的子树为空时，返回nullptr。
 */

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
    TreeNode* creatTree(int val)
    {
        return new TreeNode(val);
    }
    
    TreeNode* subTree(vector<int>& preorder, vector<int>& inorder,
                        int pre_left,int pre_right,int in_left,
                        int in_right) /*(vector<int>& preorder, vector<int>& inorder,
                        int& pre_root,int in_left,
                        int in_right)*/
    {
        if(in_left>in_right)
            return nullptr;
        int in_root = in_left;
        int pre_root = pre_left;
        while(inorder[in_root]!=preorder[pre_root]) ++in_root;
        int left_len = in_root-in_left;
        TreeNode* root = creatTree(preorder[pre_root]);
        //pre_root++;
        root->left = subTree(preorder,inorder,
                            pre_left+1,pre_left+left_len,//pre_root,
                            in_left,in_root-1);
        root->right = subTree(preorder,inorder,
                              pre_left+left_len+1,pre_right,//pre_root,
                              in_root+1,in_right);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, 
                        vector<int>& inorder) {
        /*int pre_root = 0;*/                    
        return subTree(preorder,inorder,
                        0,preorder.size()-1,//pre_root,
                        0,inorder.size()-1);
    }
};