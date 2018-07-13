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
    void levelOrderTraversal(struct TreeNode *root);
};
Solution::Solution(){}
void Solution::levelOrderTraversal(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    queue<struct TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        struct TreeNode *node = q.front();
        q.pop();
        cout <<  node->data << " ";
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }
    }
    return;
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

    sol.levelOrderTraversal(root);
    return 0;
}
