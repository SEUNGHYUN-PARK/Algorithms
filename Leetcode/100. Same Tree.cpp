/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        flag = true;
        go(p,q);
        return flag;
    }
    void go(TreeNode* p, TreeNode* q)
    {
        if(p!=NULL&&q!=NULL)
        {
            if(p->val!=q->val)
            {
                flag=false;
                return;
            }
            go(p->left,q->left);
            go(p->right,q->right);
        }
        else if((p&&q==NULL)||(p==NULL&&q))
        {
            flag=false;
            return;
        }
    }
};