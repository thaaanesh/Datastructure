#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head,*tail;



void insert()
{
    int value;
    struct node *newnode=malloc(sizeof(struct node));
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}




void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}



void pop_at_beg()
{
    struct node *temp;
    temp=head;
    head=temp->next;
    free(temp);
}



void pop_at_end()
{
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    printf("The deleted element in the list is:%d",tail->data);
    free(tail);
    tail=temp;
}



void push_at_beg()
{
    int value;
    struct node *newnode=malloc(sizeof(struct node));
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    struct node *temp=newnode;
    temp->next=head;
    head=temp;
}



void push_at_end()
{
    int value;
    struct node*newnode=malloc(sizeof(struct node));
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}



void push_at_mid()
{
    int value,pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the value:");
    scanf("%d",&value);
    struct node*temp=head;
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;


}
void pop_at_mid()
{
    int pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    struct node*temp=head;
    struct node*prev=NULL;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    prev=temp->next;
    printf("the deleted element is:%d",prev->data);
    temp->next=temp->next->next;
    free(prev);
    
}


void search_element()
{
    int value,count=0;
    printf("Enter the value to search:");
    scanf("%d",&value);
    struct node*temp=head;
    while(temp!=0)
    {
        if(temp->data==value)
        {
           count++;
        }
        temp=temp->next;
       
    }
    if(count>0)
    {
         printf("The element %d is present in the liked list.",value);
    }
    else{
        printf("The element %d is not present in the liked list.",value);

    }

}


void sum_of_list()
{
    struct node*temp=head;
    int count=0;
    while(temp!=0)
    {
        count+=temp->data;
        temp=temp->next;
    }
    printf("The sum of the linked list is : %d",count);
}


void reverse_list()
{
    struct node*temp=head;
    struct node *next=NULL;
    struct node*prev=NULL;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
}



void main()
{
    while(1)
    {
        printf("\n 1.Insert\n 2.push_at_beg\n 3.pop_at_beg\n 4.display\n 5.push_at_mid\n 6.pop_at_end\n 7.pop_at_mid\n 8.search_element\n 9.sum_of_list\n 10.reverse_list\n");
        printf("Enter the choice:");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                printf("Inserted elements in the linked list is:");
                push_at_beg();
                break;
            case 3:
                printf("Deleted elements in the linked list is:");
                pop_at_beg();
                break;
            case 4:
                printf("Elements in the linked list are:");
                display();
                break;
            case 5:
                push_at_mid();
                break;
            case 6:
                push_at_end();
                break;
            case 7:
                pop_at_mid();
                break;
            case 8:
                search_element();
                break;
            case 9:
                sum_of_list();
                break;
            case 10:
                reverse_list();
                break;
            default:
                printf("Invalid choice...");
                break;
        }

    }

}