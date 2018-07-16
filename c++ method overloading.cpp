// all these changes doest allow you to overload the method...
//const, static, int y[] == int *y, int y == int y = 10, int func() == static int func(), similar for const,

#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    const int func(const int x, int y[])
    {
        cout << "Hi " <<endl;
    }
    static int func(int y= 50, int *d)
    {
        cout << "Bye "<<endl;
    }
};
Solution::Solution(){}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    sol.func(10);
    return 0;
}
