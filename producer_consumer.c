#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#define MAX 5
int mutex = 1;
int n =0 ;
int full=0;
int empty = MAX;
int buffer[MAX];

void Signal()
{
    mutex++;
}

void wait()
{
    mutex--;
}

void Producer()
{  
   
    if (mutex==1 && full == 0)
    {
        wait();    
        do
        {
            buffer[n]=rand()%100 + 1;
            printf("The producer produces data %d\n",buffer[n]);
            n++;
            full++;
        }while(n!=MAX);
    printf("\nThe producer is done producing\n");
    }
    else
    {
        wait();    
        printf("Producer cannot be run now\n");
    }
    Signal();
}

void Consumer()
{
    if(mutex==1 && empty == MAX)
    {
        wait();
        while(n!=0)
        {
            n--;
            printf("The consumer consumes data %d\n",buffer[n]);
            empty--;
        }
    printf("\nThe consumer is done consuming\n");
    Signal();
    }
     else
    {
        printf("consumer cannot be run now\n");
    }
}

void main()
{
    int choose;
    
    do{
        printf("\nWhat do you want to perform ?\n1.Produce\n2.Consume\n3.Exit\n-> ");
        scanf("%d",&choose);
        
        switch(choose){
            case 1: Producer();
                    break;
                    
            case 2: Consumer();
                    break;
                    
        }
        
    }while(choose!=3);

}

