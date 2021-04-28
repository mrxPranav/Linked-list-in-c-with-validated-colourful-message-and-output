#include <stdio.h>
#include <stdlib.h>
void red()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[1;32m");
}
void yellow()
{
    printf("\033[1;33m");
}
void purple()
{
    printf("\033[1;35m");
}
void reset()
{
    printf("\033[0m");
}
struct linklist
{
    int data;
    struct linklist *next;
};
struct linklist *head = NULL;
struct linklist *temp = NULL;
void insertAtBegin(int);
void insertAtEnd(int);
void insertAtPosition(int,int);
void traverse();
void deleteFromBegining();
void deleteFromEnd();
void deleteAtPosition(int);
int count = 0;
void main()
{ struct linklist *node1;
    int i, n,pos;
    while (1)
    {
        printf("------------------------------------------------\n");
        purple();
        printf("1.Insert at Begining.\n2.Insert at End.\n3.Insert at certain position\n");
      printf("4.Delete from Begining\n5.Delete from end\n6.Delete from certain position\n7.Traverse\n0.Exit\nEnter your choice.\n");
       reset();
        scanf("%d", &i);
        if (i == 0)
            exit(1);
        else if (i == 1 || i == 2 || i==3 )
        {
            printf("Enter the value\n");
            scanf("%d", &n);
            if (i == 1)
                insertAtBegin(n);
            if (i == 2)
                insertAtEnd(n);
                if(i==3)
                {
                    printf("Enter Position\n");
                    scanf("%d",&pos);
                    insertAtPosition(n,pos);
                }
        }
        else if(i==4)
        deleteFromBegining();
        else if(i==5)
        deleteFromEnd();
        else if (i == 6)
        {
            printf("Enter position\n");
            scanf("%d",&pos);
            deleteAtPosition(pos);

        }
        else if(i==7)
            traverse();
            else
            printf("Not a valid choice\n");
    }
}
void insertAtBegin(int n)
{
    green();
    temp = (struct linklist *)malloc(sizeof(struct linklist));
    temp->data = n;
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    printf("%d added successfully at Begining.\n", n);
    count++;
    reset();
}
void traverse()
{
    if (head == NULL)
    {
        red();
        printf("LinkedList is empty!\n");
        reset();
        return;
    }
    else
    {
        printf("------------------------------------------------\n");
        yellow();
        printf("There are %d elements in the linkedlist.\n", count);
        temp = head;
        while (temp->next != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
        reset();
    }
}
void insertAtEnd(int n)
{
    green();
    struct linklist *temp1;
    temp1 = (struct linklist *)malloc(sizeof(struct linklist));
    temp1->data = n;
    if (head == NULL)
    {
        head = temp1;
        head->next = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = temp1;
        temp1->next = NULL;
    }
    printf("%d added successfully at End.\n", n);
    count++;
    reset();
}
void insertAtPosition(int n,int pos)
{
    int i=1;
    struct linklist *new;
    new = (struct linklist *)malloc(sizeof(struct linklist));
    new->data = n;
    if (pos > count)
    {
        red();
        printf("Warning!Entered Position is greater than the size of linkedList.\n");
        reset();
        return;
    }
    else if(pos==1)
    {
        new->next=head;
        head=new;
    }
    else
    {
        temp = head;
        while(i<pos-1 && temp->next!=NULL)
        {
            temp = temp->next;
            i++;
        }
        new->next = temp->next;
        temp->next = new;
    }
    green();
    printf("%d added successfully at %d position.\n", n,pos);
    reset();
    count++;
}
void deleteFromBegining()
{
    int n;
    if(head==NULL)
    {
        red();
        printf("LinkedList is Empty!");
        reset();
    }
    else
    {
       n= head->data;
       temp=head->next;
        free(head);
        head=temp;
        count--;
        green();
        printf("%d deleted from the Beginning of linkedlist successfully\n",n);
        reset();
    }
}
void deleteFromEnd()
{
  int n;
  struct linklist *t;
    if(head==NULL)
    {
        red();
        printf("LinkedList is Empty!\n");
        reset();
        return;
    }
    else if(head->next==NULL)
    {
        n=head->data;
        free(head);
        head=NULL;
        
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            t=temp;
        temp=temp->next;
        }
        n=temp->data;
        free(temp);
        t->next=NULL;
        
    }
    count--;
         green();
        printf("%d deleted from the End of linkedlist successfully\n",n);
        reset();
}
void deleteAtPosition(int pos)
{
int n,i=1;

 if(head==NULL)
    {
        red();
        printf("LinkedList is Empty!\n");
        reset();
        return;
    }
    struct linklist *del;
    if (pos > count)
    {
        red();
        printf("Warning!Entered Position is greater than the size of linkedList.\n");
        reset();
        return;
    }
    else if(pos==1 )
    {
        n=head->data;
        if(head!=NULL)
        {
        del=head->next;
        free(head);
        head=del;
        }
        else
        {
        free(head);
        head=NULL;
        }
    }
    else
    {
        temp = head;
        while(i<pos-1 && temp->next!=NULL)
        {
            temp = temp->next;
            i++;
        }
        del = temp->next;
        temp->next = del->next;
        n=del->data;
        free(del);
    }
    green();
    printf("%d deleted successfully from position %d .\n", n,pos);
    reset();
    count--;
}