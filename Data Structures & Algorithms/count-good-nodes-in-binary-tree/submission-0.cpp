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
    int goodNodes(TreeNode* root) {

        if(root -> left == NULL && root -> right == NULL) return 1;
        
        int maximum = INT_MIN;
        int cnt = 0;

        dfs(root, maximum, cnt);
        return cnt;

    }

    void dfs(TreeNode* root, int maximum, int &cnt){

        if(root == NULL) return;

        if(root -> val >= maximum){
            maximum = root->val;
            cnt++;
        }

        dfs(root -> left, maximum, cnt);
        dfs(root -> right, maximum, cnt);

    }

};
