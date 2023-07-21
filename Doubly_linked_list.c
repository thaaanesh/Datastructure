#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*head,*tail;


void insert()
{
    int value;
    struct node *newnode=malloc(sizeof(struct node));
    scanf("%d",&value);
    newnode->prev=NULL;
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
        newnode->prev=tail;
        tail=newnode;
    }
}


void push_at_beg()
{
    int value;
    struct node *newnode=malloc(sizeof(struct node));
    scanf("%d",&value);
    newnode->prev=NULL;
    newnode->data=value;
    newnode->next=NULL;
    struct node *temp=newnode;
    temp->next=head;
    head->prev=temp;
    head=temp;
}



void push_at_end()
{
    int value;
    struct node*newnode=malloc(sizeof(struct node));
    scanf("%d",&value);
    newnode->prev=NULL;
    newnode->data=value;
    newnode->next=NULL;
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    tail=newnode;
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
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next->prev=newnode;

}

void pop_at_beg()
{
    struct node*temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    free(temp);
}
 
void pop_at_end()
{
    struct node*temp=tail;
    tail=temp->prev;
    temp->prev->next=NULL;
    free(temp);
}

void pop_at_mid()
{
    int pos;
    printf("Enter the position:");  
    scanf("%d",&pos);
    struct node*temp=head;
    struct node*next=NULL;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    next=temp->next;
    printf("the deleted element is:%d",next->data);
    temp->next=temp->next->next;
    temp->next->prev=temp;
    free(next);
    
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


void main()
{
    while(1)
    {
        printf("\n 1.Insert\n 2.push_at_beg\n 3.display\n 4.pushA_at_end\n 5.push_at_mid\n 6.pop_at_beg\n 7.pop_at_end\n 8.pop_at_mid\n");
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
                printf("Elements in the linked list are:");
                display();
                break;
            case 4:
                printf("Inserted elements in the linked list at last:");
                push_at_end();
                break;
            case 5:
                push_at_mid();
                break;
            case 6:
                pop_at_beg();
                break;
            case 7:
                pop_at_end();
                break;
            case 8:
                pop_at_mid();
                break;
            
        
        }
    }
}