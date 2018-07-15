#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    vector<int> infirstButsecond(vector<int> &A, vector<int> &B);
};
Solution::Solution(){}
vector<int> Solution::infirstButsecond(vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    int lenA = A.size();
    int lenB = B.size();
    map<int, int> mp;
    for(vector<int>::iterator iter = B.begin(); iter != B.end(); iter++)
    {
        mp[*iter]++;
    }
    for(int iter =0; iter < A.size(); iter++)
    {
        if(mp.find(A[iter]) == mp.end())
        {
            ans.push_back(A[iter]);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> B;
        for(int iter = 0; iter < m; iter++)
        {
            int data;
            cin >> data;
            B.push_back(data);
        }
        vector<int> ans = sol.infirstButsecond(A, B);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
