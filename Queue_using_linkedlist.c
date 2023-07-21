#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*front=NULL,*rear=NULL;


void enqueue()
{
    int value;
    struct node*newnode=malloc(sizeof(struct node));
    scanf("%d",&value);
    newnode->next=NULL;
    newnode->data=value;
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }

}


void dequeue()
{
    struct node*temp=front;
    printf("The deleted element is:%d",temp->data);
    front=front->next;
    free(temp);
}

void display()
{
    struct node*temp=front;
    if(temp==NULL)
    {
        printf("\nThe stack is empty...");
    }
    else{
        while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    } 

    }

}



void main()
{
    int choice;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Please enter a correct choice!\n");
            break;
        }
    }
}