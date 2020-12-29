//circular queue
#include<stdio.h>
#define MAX 10
int que[MAX];
int front=-1,rear=-1;
void insert(int );
void delete();
int peek();
void display();
int main()
{
    int option,val;
    do
    {
        printf("\nMenu\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. peek\n");
        printf("4. Display\n");
        printf("5. EXIT\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter a value\n");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                val = peek();
                if(val!=-1)
                    printf("%d\n",val);
                break;
            case 4:
                display();
                break;
        }
    } while (option!=5);
    return 0;
}
void insert(int val)
{
    if(front==0&&rear==MAX-1)
        printf("Overflow\n");
    else if(front==-1 && rear==-1)
    {
        front = 0; rear = 0;
        que[rear]= val;
    }
    else if(rear==MAX-1&&front!=0)
    {
        rear = 0;
        que[rear] = val;
    }
    else
    {
        que[++rear]=val;
    }
}
void delete()
{
    if(front == -1)
        printf("Underflow\n");
    else if(front == rear)
    {
        printf("%d Deleted\n",que[front]);
        front = -1; rear = -1;
    }
    else if(front == MAX-1)
    {
        printf("%d Deleted\n",que[front]);
        front = 0;
    }
    else
    {
         printf("%d Deleted\n",que[front++]);
    }
}
int peek()
{
    if(front==-1&&rear==-1)
    {
        printf("Empty Queue\n");
        return -1;
    }
    else 
        return que[front];
}
void display()
{
    int i;
    if(front == -1 && rear == -1)
        printf("Empty Queue\n");
    else 
    {
        if(front<=rear)
        {
            for(i=front;i<=rear;i++)
                printf("%d\t",que[i]);
        }
        else
        {
            for(i=front;i<MAX;i++)
                printf("%d\t",que[i]);
            for(i=0;i<=rear;i++)
                printf("%d\t",que[i]);
        }
    }
}