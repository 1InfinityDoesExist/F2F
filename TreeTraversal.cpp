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
    void preOrderTraversal(struct TreeNode *root);
    void inOrderTraversal(struct TreeNode *root);
    void postOrderTraversal(struct TreeNode *root);
};
Solution::Solution(){}
void Solution::inOrderTraversal(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<struct TreeNode *> s;
    struct TreeNode *ptr = root;
    while(!s.empty() || ptr)
    {
        if(ptr)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
        else{
            struct TreeNode *node = s.top();
            s.pop();
            cout << node->data << " ";
            ptr = node->right;
        }
    }
    cout << endl;
    return;
}
void Solution::preOrderTraversal(struct TreeNode *root)
{
    if(root == NULL)
    {
       return;
    }
    stack<struct TreeNode *> s;
    s.push(root);
    while(!s.empty())
    {
        struct TreeNode *node = s.top();
        s.pop();
        cout << node->data << " ";
        if(node->right)
        {
            s.push(node->right);
        }
        if(node->left)
        {
            s.push(node->left);
        }
    }
    cout << endl;
    return;
}
void Solution::postOrderTraversal(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<struct TreeNode *> s;
    stack<struct TreeNode *> output;
    s.push(root);
    while(!s.empty())
    {
        struct TreeNode *node = s.top();
        s.pop();
        output.push(node);
        if(node->left)
        {
            s.push(node->left);
        }
        if(node->right)
        {
            s.push(node->right);
        }
    }
    while(!output.empty())
    {
        cout << output.top()->data << " ";
        output.pop();
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
    sol.preOrderTraversal(root);
    sol.inOrderTraversal(root);
    sol.postOrderTraversal(root);

    return 0;
}
