#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll, marks;
    char name[20];
    struct student *next;
};

struct student *create(int n)
{
    struct student *head=NULL,*temp=NULL,*newnode;
    int i;

    for(i=1;i<=n;i++)
    {
        newnode=(struct student*)malloc(sizeof(struct student));

        printf("\nEnter Roll No: ");
        scanf("%d",&newnode->roll);

        printf("Enter Name: ");
        scanf("%s",newnode->name);

        printf("Enter Marks: ");
        scanf("%d",&newnode->marks);

        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    return head;
}

void display(struct student *head)
{
    struct student *temp=head;

    while(temp!=NULL)
    {
        printf("\nRoll:%d Name:%s Marks:%d",
        temp->roll,temp->name,temp->marks);

        temp=temp->next;
    }
}

struct student* insert_begin(struct student *head)
{
    struct student *newnode;

    newnode=(struct student*)malloc(sizeof(struct student));

    printf("Enter Roll No: ");
    scanf("%d",&newnode->roll);

    printf("Enter Name: ");
    scanf("%s",newnode->name);

    printf("Enter Marks: ");
    scanf("%d",&newnode->marks);

    newnode->next=head;
    head=newnode;

    return head;
}

struct student* insert_end(struct student *head)
{
    struct student *newnode,*temp=head;

    newnode=(struct student*)malloc(sizeof(struct student));

    printf("Enter Roll No: ");
    scanf("%d",&newnode->roll);

    printf("Enter Name: ");
    scanf("%s",newnode->name);

    printf("Enter Marks: ");
    scanf("%d",&newnode->marks);

    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        return head;
    }

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;

    return head;
}

struct student* insert_after_even(struct student *head)
{
    struct student *temp=head,*newnode;

    while(temp!=NULL)
    {
        if(temp->roll%2==0)
        {
            newnode=(struct student*)malloc(sizeof(struct student));

            printf("Enter Roll No: ");
            scanf("%d",&newnode->roll);

            printf("Enter Name: ");
            scanf("%s",newnode->name);

            printf("Enter Marks: ");
            scanf("%d",&newnode->marks);

            newnode->next=temp->next;
            temp->next=newnode;

            return head;
        }

        temp=temp->next;
    }

    printf("No even roll number found");
    return head;
}

void even_roll(struct student *head)
{
    struct student *temp=head;

    printf("\nEven Roll Number Students\n");

    while(temp!=NULL)
    {
        if(temp->roll%2==0)
        printf("\nRoll:%d Name:%s Marks:%d",
        temp->roll,temp->name,temp->marks);

        temp=temp->next;
    }
}

void max_marks(struct student *head)
{
    struct student *temp=head,*max=head;

    if(head==NULL)
    {
        printf("List Empty");
        return;
    }

    while(temp!=NULL)
    {
        if(temp->marks>max->marks)
        max=temp;

        temp=temp->next;
    }

    printf("\nStudent with Max Marks");
    printf("\nRoll:%d Name:%s Marks:%d",
    max->roll,max->name,max->marks);
}

void search(struct student *head)
{
    int r;
    struct student *temp=head;

    printf("Enter roll number to search: ");
    scanf("%d",&r);

    while(temp!=NULL)
    {
        if(temp->roll==r)
        {
            printf("\nRecord Found");
            printf("\nRoll:%d Name:%s Marks:%d",
            temp->roll,temp->name,temp->marks);
            return;
        }

        temp=temp->next;
    }

    printf("Record not found");
}

int main()
{
    struct student *head=NULL;
    int n,ch;

    printf("Enter number of students: ");
    scanf("%d",&n);

    head=create(n);

    while(1)
    {
        printf("\n1.Insert Begin");
        printf("\n2.Insert End");
        printf("\n3.Insert After Even Roll");
        printf("\n4.Display");
        printf("\n5.Display Even Roll Students");
        printf("\n6.Max Marks");
        printf("\n7.Search Record");
        printf("\n8.Exit");

        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: head=insert_begin(head); break;
            case 2: head=insert_end(head); break;
            case 3: head=insert_after_even(head); break;
            case 4: display(head); break;
            case 5: even_roll(head); break;
            case 6: max_marks(head); break;
            case 7: search(head); break;
            case 8: exit(0);
            default: printf("Invalid choice");
        }
    }
}
