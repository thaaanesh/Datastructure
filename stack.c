#include<stdio.h>
//#include<stdlib.h>
int top=-1;
#define a 5
int arr[a];

void push()
{
   
    if(top== a -1)
    {
        printf("Stack Overflow\n");
    }
    else{
        top++;
        int value;
        scanf("%d",&value);
        arr[top]=value;

    }

}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    else{
        printf("%d",arr[top]);
        top--;

    }

}

void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d",arr[i]);
    }

}





void main()
{
     while(1)
    {
        printf("\n 1.push\n 2.pop\n 3.display\n ");
        printf("Enter the choice:");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;

        }
    }

}