#include<bits/stdc++.h>
using namespace std;

struct List{
    int data;
    struct List *next;
    List(int val) : data(val), next(NULL){}
};

class Solution
{
private:
public:
    Solution();
    bool isCyclic(struct List *hed);
};
Solution::Solution(){}
bool Solution::isCyclic(struct List *head)
{
    struct List *ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    struct List *slow = head;
    struct List *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct List *head = new List(2);
    head->next = new List(4);
    head->next->next = new List(14);
    head->next->next->next = new List(19);
    head->next->next->next->next = new List(24);
    head->next->next->next->next->next = new List(35);

    Solution sol;
    bool ans = sol.isCyclic(head);
    if(ans)
    {
        cout << "Yes there is cycle" << endl;
    }
    else{
        cout << "No there is no any cycle" <<endl;
    }
    return 0;
}
