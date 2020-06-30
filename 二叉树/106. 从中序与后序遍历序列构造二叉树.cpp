/*****************************************************************
 * 问题：
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 解决思路：
 * 后序数组的最后一个元素为根节点，中序数组的开头到根节点为左子树，长度为
 * left_len，根节点到结尾为右子树，长度为right_len;故后序数组的
 * left_len+1~结尾为左子树，left_len+1~结尾为右子树，递归构建子树。
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
    TreeNode* subTree(vector<int>& inorder, vector<int>& postorder,
                      int in_left,int in_right,int po_left,int po_right) {
        if(in_left>in_right)
            return nullptr;
        int in_root = in_left;
        while(inorder[in_root]!=postorder[po_right]) ++in_root;
        int right_len = in_right - in_root;
        TreeNode *root = new TreeNode(postorder[po_right]);
        root->right = subTree(inorder,postorder,in_root+1,in_right,
                                po_right-right_len,po_right-1);
        root->left = subTree(inorder,postorder,in_left,in_root-1,
                                po_left,po_right-right_len-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return subTree(inorder,postorder,
                        0,inorder.size(),0,postorder.size());
    }
};