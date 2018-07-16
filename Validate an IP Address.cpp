#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    bool validIporNot(string str);
};
Solution::Solution(){}
bool isValid(string str)
{
    int num = stoi(str);
    if(num >= 0 && num <= 255)
    {
        return true;
    }
    return false;
}
bool Solution::validIporNot(string str)
{
    int count (0);
    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == '.')
        {
            if(s.length() == 0)
            {
                continue;
            }
            else
            {
                if(isValid(s))
                {
                    count++;
                    s = "";
                }
            }
        }
        else
        {
            s = s + str[iter];
            if(iter == str.length()-1)
            {
                if(isValid(s))
                {
                    count++;
                }
            }
        }
    }
    if(count == 4)
    {
        return true;
    }
    return false;
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
        string str;
        cin >> str;
        bool ans = sol.validIporNot(str);
        if(ans)
        {
            cout << "Valid Ip Address" <<endl;
        }
        else
        {
            cout << "Not Valid Ip Address "<<endl;
        }
    }
    return 0;
}
