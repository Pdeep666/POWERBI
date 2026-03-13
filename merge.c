#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int i, value;

    for(i=1;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d",&value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp->next = head;  // make circular
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    if(head == NULL)
    return;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);
}

struct node* mergeList(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;

    if(head1 == NULL)
    return head2;

    if(head2 == NULL)
    return head1;

    while(temp1->next != head1)
        temp1 = temp1->next;

    while(temp2->next != head2)
        temp2 = temp2->next;

    temp1->next = head2;
    temp2->next = head1;

    return head1;
}

int main()
{
    struct node *head1, *head2, *merged;
    int n1, n2;

    printf("Enter size of first circular list: ");
    scanf("%d",&n1);

    head1 = createList(n1);

    printf("Enter size of second circular list: ");
    scanf("%d",&n2);

    head2 = createList(n2);

    merged = mergeList(head1, head2);

    printf("Merged Circular Linked List:\n");
    display(merged);

    return 0;
}
