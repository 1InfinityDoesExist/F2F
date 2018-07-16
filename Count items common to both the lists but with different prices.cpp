#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    Solution();
    int diffPriceSameItem(vector<pair<string, int> > list1, vector<pair<string, int> > list2);
};
Solution::Solution(){}
int Solution::diffPriceSameItem(vector<pair<string, int> > list1, vector<pair<string, int> > list2)
{
    int count (0);
    map<string, int> mp;
    for(int iter = 0; iter < list1.size(); iter++)
    {
        pair<string, int> p = list1[iter];
        mp[p.first] = p.second;
    }
    for(int iter = 0; iter < list2.size(); iter++)
    {
        pair<string, int> p = list2[iter];
        if(mp.find(p.first) != mp.end())
        {
            if(mp[p.first] != p.second)
            {
                count++;
            }
        }
    }
    return count;
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
        vector<pair<string, int> > list1;
        vector<pair<string, int> > list2;
        for(int iter = 0; iter < n; iter++)
        {
            string item;
            cin >> item;
            int cost;
            cin >> cost;
            list1.push_back(make_pair(item, cost));
        }
        for(int iter = 0; iter < n; iter++)
        {
            string item;
            cin >> item;
            int cost;
            cin >> cost;
            list2.push_back(make_pair(item, cost));
        }
        int ans = sol.diffPriceSameItem(list1, list2);
        cout << ans << endl;
    }
    return 0;
}
