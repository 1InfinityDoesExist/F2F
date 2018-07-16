#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    Solution();
    int equilibriumPoint(vector<int> &A);
};
Solution::Solution(){}
int Solution::equilibriumPoint(vector<int> &A)
{
    int len = A.size();
    int sum (0);
    int leftSum (0);
    for(int iter = 0; iter < len; iter++)
    {
        sum = sum + A[iter];
    }
    for(int iter = 0; iter < len; iter++)
    {
        sum = sum - A[iter];
        if(leftSum == sum)
        {
            return iter+1;
        }
         leftSum = leftSum + A[iter];
    }
    return -1;
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
        int n;
        cin >> n;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.equilibriumPoint(A);
        cout << ans << endl;
    }
    return 0;
}
