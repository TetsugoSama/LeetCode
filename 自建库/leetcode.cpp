#include "leetcode.h"

using namespace std;

ListNode* CreatList(vector<int>& val)
{
    ListNode* head = new ListNode(val[0]);
    ListNode* node = head;
    for (int i = 1; i < val.size(); i++)
    {
        ListNode* n = new ListNode(val[i]);
        node->next = n;
        node = n;
    }
    return head;
}

void coutvv(vector<vector<int>>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << '{';
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j]<<',';
        }
        cout << '}' << endl;
    }
}

template<typename T>
void printvec(std::vector<T>& v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
}

TreeNode* creatTreeNode(int n)
{
    if(n<0)
        return nullptr;
    else
    {
        return new TreeNode(n);
    }
    
}

TreeNode* creatTree(vector<int>& v)
{
    vector<TreeNode*> vt(v.size());
    int amend = 0;
    for(int i=0;i<v.size();i++)
    {
        vt[i] = creatTreeNode(v[i]);
    }
    for(int i=0;i<vt.size();i++)
    {
        if (vt[i] == nullptr)
        {
            amend += 2;                 //如果某节点为空，则该节点无子节点，所以不会在数组中出现
            continue;
        }
        int left = (i+1)*2-1-amend;  //修正因为空节点导致后面节点的子节点索引错误
        int right = (i+1)*2-amend;
        if(left>=vt.size())
        {
            vt[i]->left=nullptr;
            vt[i]->right=nullptr;
        }
        else if(right>=vt.size())
        {
            vt[i]->left = vt[left];
            vt[i]->right = nullptr;
        }
        else
        {
            vt[i]->left = vt[left];
            vt[i]->right = vt[right];
        }
    }
    return vt[0];
}

