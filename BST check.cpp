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
    bool isBST(struct TreeNode *root);
    bool BST(struct TreeNode *root, struct TreeNode *minNode, struct TreeNode *maxNode);
};
Solution::Solution(){}
bool Solution::BST(struct TreeNode *root, struct TreeNode *minNode, struct TreeNode *maxNode)
{
    if(root == NULL)
    {
        return true;
    }
    if(minNode && root->data <= minNode->data || maxNode && root->data >= maxNode->data)
    {
        return false;
    }
    return BST(root->left, minNode, root) && BST(root->right, root, maxNode);
}
bool Solution::isBST(struct TreeNode *root)
{
    return BST(root, NULL, NULL);
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

    bool ans = sol.isBST(root);
    if(ans)
    {
        cout << "It's BST" <<endl;
    }
    else
    {
        cout << "No it's not" <<endl;
    }
    return 0;
}
