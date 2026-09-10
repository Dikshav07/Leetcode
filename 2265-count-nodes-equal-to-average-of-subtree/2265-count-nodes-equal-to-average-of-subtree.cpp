/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:

    unordered_map<TreeNode *, int> nodeCnt;
    int cnt = 0;
    int dfs(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }

        return nodeCnt[root] = dfs(root->left) + dfs(root->right) + 1;
    }

    int dfs1(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        int sum = dfs1(root->left) + dfs1(root->right) + root->val;
        int avg = sum / nodeCnt[root];
        if(avg == root->val)
        {
            cnt++;
        }
        return sum;
    }

    int averageOfSubtree(TreeNode* root) 
    {
        dfs(root);
        dfs1(root);
        return cnt;   
    }
};