#include<stdio.h>
#include<stdlib.h>
#define a 20
int front=-1,rear=-1;
int arr[a];

void enqueue()
{
    if(rear==a-1)
    {
        printf("The queue is full:");
    }
    else{
        int value;
        scanf("%d",&value);
        if(front==-1)
        {
            front++;
        }
        rear++;
        arr[rear]=value;
    }

}

void dequeue()
{
    int index=0;
    for(int i=front+1;i<=rear;i++)
    {
        arr[index]=arr[i];
        index++;
    }
    rear--;
}

void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",arr[i]);
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