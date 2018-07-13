#include<bits/stdc++.h>
using namespace std;

class LRUCache{
private:
    int cap;
    vector<int> v;
    map<int, int> mp;
public:
    LRUCache(int N);
    int getLRU(int data);
    void setLRU(int x, int y);
};
LRUCache::LRUCache(int N)
{
    cap = N;
    v.clear();
    mp.clear();
}
void LRUCache::setLRU(int x, int y)
{
    vector<int>::iterator iter = find(v.begin(), v.end(), x);
    if(iter != v.end())
    {
        if(mp[x] != y)
        {
            mp[x] = y;
        }
        int temp = *iter;
        v.erase(iter);
        v.push_back(temp);
    }
    else
    {
        if(cap == v.size())
        {
            vector<int>::iterator jter = v.begin();
            v.erase(jter);
        }
         v.push_back(x);
          mp[x] = y;
    }
    return;
}
int LRUCache::getLRU(int data)
{
    vector<int>::iterator iter = find(v.begin(), v.end(), data);
    if(iter != v.end())
    {
        int temp = *iter;
        v.erase(iter);
        v.push_back(temp);
        return mp[temp];
    }
    else{
        return -1;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    LRUCache sol(n);
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int u, v;
            cin >> u >> v;
            sol.setLRU(u,v);
        }
        else if(x == 2)
        {
            int u;
            cin >> u;
            int ans = sol.getLRU(u);
            cout << ans << endl;
        }
    }
    return 0;
}
