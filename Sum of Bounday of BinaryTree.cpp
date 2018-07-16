#include<bits/stdc++.h>
using namespace std;

int sum = 0;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL){}
};

class Solution
{
private:
public:
    Solution();
    int sumOfBounday(struct TreeNode *root);
    void addLeftBoundary(struct TreeNode *root);
    void addRootBoundary(struct TreeNode *root);
    void addRightBounday(struct TreeNode *root);
};

Solution::Solution(){}

void Solution::addLeftBoundary(struct TreeNode *root)
{
    if(root)
    {
        if(root->left)
        {
            sum = sum + root->data;
           // cout << root->data << " ";
            addLeftBoundary(root->left);
        }
        else if(root->right)
        {
            sum = sum + root->data;
          //  cout << root->data << " ";
            addLeftBoundary(root->right);
        }
    }
    return;
}

void Solution::addRootBoundary(struct TreeNode *root)
{
    if(root)
    {
        addRootBoundary(root->left);
        if(root->left == NULL && root->right == NULL)
        {
            sum = sum + root->data;
          //  cout << root->data << " ";
        }
        addRootBoundary(root->right);
    }
    return;
}

void Solution::addRightBounday(struct TreeNode *root)
{
    if(root)
    {
        if(root->right)
        {
            addRightBounday(root->right);
            sum = sum + root->data;
           // cout << root->data << " ";
        }
        else if(root->left)
        {
            addRightBounday(root->left);
            sum = sum + root->data;
           // cout << root->data << " ";
        }
    }
    return;
}

int Solution::sumOfBounday(struct TreeNode *root)
{
    if(root)
    {
        sum += root->data;
      //  cout << root->data << " ";
        addLeftBoundary(root->left);
        addRootBoundary(root->left);
        addRootBoundary(root->right);
        addRightBounday(root->right);
    }
    return sum;
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
    int ans = sol.sumOfBounday(root);
    cout << ans << endl;
    return 0;
}
