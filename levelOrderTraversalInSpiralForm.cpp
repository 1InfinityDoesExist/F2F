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
    void levelOrderTraversalSpiral(struct TreeNode *root);
};
Solution::Solution(){}
void Solution::levelOrderTraversalSpiral(struct TreeNode *root)
{
   if(root == NULL)
   {
       return;
   }
   vector<vector<int> > ans;
   stack<struct TreeNode *> q1;
   stack<struct TreeNode *> q2;
   q1.push(root);
   while(!q1.empty() || !q2.empty())
   {
       vector<int> temp1;
       int count1 (0);
       while(!q1.empty())
       {
           count1++;
           struct TreeNode *node1 = q1.top();
           q1.pop();
           temp1.push_back(node1->data);
           if(node1->left)
           {
               q2.push(node1->left);
           }
           if(node1->right)
           {
               q2.push(node1->right);
           }

       }
       if(count1 != 0)
       {
           ans.push_back(temp1);
       }

       vector<int> temp2;
       int count2 (0);
       while(!q2.empty())
       {
           count2++;
           struct TreeNode *node2 = q2.top();
           q2.pop();
           temp2.push_back(node2->data);
           if(node2->right)
           {
               q1.push(node2->right);
           }
           if(node2->left)
           {
               q1.push(node2->left);
           }

       }
       if(count2 != 0)
       {
           ans.push_back(temp2);
       }
   }
   for(int iter = 0; iter < ans.size(); iter++)
   {
        for(int jter = 0; jter < ans[iter].size(); jter++)
        {
            cout <<ans[iter][jter] << " ";
        }
        cout << endl;
    }
    cout << endl;
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

    sol.levelOrderTraversalSpiral(root);
    return 0;
}
