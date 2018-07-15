#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int LCM(vector<int> A);
    int HCF(vector<int> A);
};
Solution::Solution(){}
int HCFgcd(int a, int b)
{
    if(a == 0)
    {
        return b;
    }
    return HCFgcd(b%a, a);
}
int LCMgcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return LCMgcd(b, a%b);
}
int Solution::LCM(vector<int> A)
{
    int result = A[0];
    for(int iter = 1; iter < A.size(); iter++)
    {
        result = (A[iter] * result)/LCMgcd(A[iter], result);
    }
    return result;
}
int Solution::HCF(vector<int> A)
{
    int result = A[0];
    for(int iter = 1; iter < A.size(); iter++)
    {
        result = HCFgcd(A[iter], result);
    }
    return result;
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
        vector<int> A;
        for(int iter = 0; iter < 2; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int lcm = sol.LCM(A);
        int hcf = sol.HCF(A);
        cout << lcm << " "<<hcf <<endl;
    }
    return 0;
}
