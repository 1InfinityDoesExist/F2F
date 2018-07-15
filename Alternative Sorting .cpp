#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    vector<int> alternativeSorting(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::alternativeSorting(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<int> ans;
    if(A.size()%2  == 0)
    {
        int iter = 0;
        int jter = A.size()-1;
        for(int kter = 0; kter < A.size()/2; kter++)
        {
            ans.push_back(A[jter--]);
            ans.push_back(A[iter++]);
        }
    }
    else
    {
        int iter = 0;
        int jter = A.size()-1;
        for(int kter = 0; kter < A.size()/2; kter++)
        {
            ans.push_back(A[jter--]);
            ans.push_back(A[iter++]);
        }
        ans.push_back(A[jter]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.alternativeSorting(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
