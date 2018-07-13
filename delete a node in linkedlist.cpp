#include<bits/stdc++.h>
using namespace std;

struct List{
    int data;
    struct List *next;
    List(int val) : data(val), next(NULL){}
};
class Solution{
private:
public:
    Solution();
    void deleteList(struct List *head, const int del);
    void displayList(struct List *head);
};
Solution::Solution(){}
void Solution::displayList(struct List *head)
{
    struct List *ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    return;
}
void Solution::deleteList(struct List *head, const int del)
{
    displayList(head);
    struct List *ptr = head;
    while(ptr->next != NULL)
    {
        if(ptr->next->data == del)
        {
            struct List *cp = ptr->next;
            if(cp->next != NULL)
            {
                ptr->next = cp->next;
            }
            else
            {
                ptr->next = NULL;
            }
            free(cp);
            break;
        }
        ptr = ptr->next;
    }
    displayList(head);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    struct List *head = new List(2);
    head->next = new List(4);
    head->next->next = new List(14);
    head->next->next->next = new List(19);
    head->next->next->next->next = new List(24);
    head->next->next->next->next->next = new List(35);

    sol.deleteList(head, 14);

    return 0;
}
