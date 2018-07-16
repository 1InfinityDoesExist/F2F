#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int val) : data(val), next(NULL){}
};
class Solution
{
private:
public:
    Solution();
    void reverseList(struct node *head);
};
Solution::Solution(){}
void Solution::reverseList(struct node *head)
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << " After reversing the list " <<endl;
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    struct node *p = head;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }


    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    struct node *head = new node(2);
    head->next = new node(4);
    head->next->next = new node(24);
    head->next->next->next = new node(14);
    head->next->next->next->next = new node(40);
    head->next->next->next->next->next = new node(47);
    head->next->next->next->next->next->next = new node(84);
    head->next->next->next->next->next->next->next = new node(94);
    sol.reverseList(head);
    return 0;
}
