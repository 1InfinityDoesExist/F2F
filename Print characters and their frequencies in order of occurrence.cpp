#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    Solution();
    void freq(string str);
};
Solution::Solution(){}
void Solution::freq(string str)
{
    map<char , int> mp;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        mp[str[iter]]++;
    }
   for(string::size_type iter = 0; iter < str.length(); iter++)
   {
       if(mp.find(str[iter]) == mp.end())
       {
           continue;
       }
       else
       {
            cout << str[iter] << ""<<mp[str[iter]] << " ";
            mp.erase(str[iter]);
       }
   }
   cout << endl;
   return;
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
        sol.freq(str);
    }
    return 0;
}
