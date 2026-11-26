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
class Solution {
public:
    map<pair<int,int>, vector<TreeNode*> >trees;
    vector<TreeNode*> go(int l,int r){
        vector<TreeNode*>ret;
        if(l>r){
            ret.push_back(nullptr);
            return ret;
        }
        if(l == r){
            TreeNode* cur = new TreeNode(l,nullptr,nullptr);
            ret.push_back(cur);
            return ret;
        }
        if(trees.find({l,r}) != trees.end()){
            return trees[{l,r}];
        }
        for(int i = l;i<=r;i++){
            vector<TreeNode*>lft = go(l,i-1);
            vector<TreeNode*>rit = go(i+1,r);
            for(auto x: lft){
                for(auto y: rit){
                    TreeNode* cur = new TreeNode(i,nullptr,nullptr);
                    cur->left = x;
                    cur->right = y;
                    ret.push_back(cur);
                }
            }
        }
        trees[{l,r}] = ret;
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        return go(1,n);
    }
};