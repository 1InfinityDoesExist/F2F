#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val):data(val), left(NULL), right(NULL){}
};
class Solution
{
private:
public:
    Solution();
    int height(struct TreeNode *root);
};
Solution::Solution(){}
int Solution::height(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int height (0);
    queue<struct TreeNode *> q;
    q.push(root);
    while(1)
    {
        int len = q.size();
        if(len == 0)
        {
            return height;
        }
        height++;
        while(len--)
        {
            struct TreeNode *node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }
    return height;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    struct TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(18);
    root->right = new TreeNode(28);
    root->left->left = new TreeNode(16);
    root->left->right = new TreeNode(19);
    root->left->left->left = new TreeNode(10);
    root->left->left->right = new TreeNode(17);
    root->right->left = new TreeNode(24);
    root->right->right = new TreeNode(30);
    root->right->left->left = new TreeNode(27);
    root->right->left->right = new TreeNode(26);
    root->right->right->right = new TreeNode(32);
    root->right->right->left = new TreeNode(29);
    int ans = sol.height(root);
    cout << ans << endl;
    return 0;
}
