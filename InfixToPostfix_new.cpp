#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string infixtoPostfix(string str);
        bool isOperand(char c);
        bool isOperator(char c);
        int higherPriority(char x, char y);
};
Solution::Solution(){}
string Solution::infixtoPostfix(string str)
{
    stack<char> s;
    string postfix = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == ' ' && str[iter] == ',')
        {
            continue;
        }
        else if(isOperator(str[iter]))
        {
            while(!s.empty() && s.top() != '(' && higherPriority(str[iter], s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(str[iter]);
        }
        else if(isOperand(str[iter]))
        {
            postfix += str[iter];
        }
        else if(str[iter] == '(')
        {
            s.push(str[iter]);
        }
        else if(str[iter] == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
bool Solution::isOperand(char c)
{
    if(c >= '0' && c <= '9')
    {
        return true;
    }
    if(c >= 'a' && c <= 'z')
    {
        return true;
    }
    if(c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}
bool Solution::isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    return false;
}
int calculateOptWeight(char opt)
{
    int weight = -1;
    switch(opt)
    {
        case '+':
        case '-':
            weight = 1;
        case '*':
        case '/':
            weight = 2;
        case '^':
            weight = 3;
    }
    return weight;
}
bool isRightAssociative(char c)
{
    if(c == '^')
    {
        return true;
    }
    return false;
}
int Solution::higherPriority(char x, char y)
{
    int opt1Weight = calculateOptWeight(x);
    int opt2Weight = calculateOptWeight(y);
    if(opt1Weight == opt2Weight)
    {
        if(isRightAssociative(x))
        {
            return false;
        }
        else
        {
             return true;
        }
    }
    return opt1Weight > opt2Weight ? true : false;
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
        string postfix = sol.infixtoPostfix(str);
        cout << postfix << endl;
    }
    return 0;
}
