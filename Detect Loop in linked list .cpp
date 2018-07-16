
/*The structure of linked list is the following
struct node
{
int data;
node* next;
};*/
int detectloop(struct node *list){
// your code goes here
    struct node *slow = list;
    struct node *fast = list;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
