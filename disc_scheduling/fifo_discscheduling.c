#include<stdio.h>
#include<stdlib.h>

int check_schedule(int a, int b){
    if(a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}

void fifo_discschedule(int queue[100],int middle_el,int n){
    int current_state=middle_el,i,total_distance=0;
    
    for(i=0;i<n;i++)
    {
        total_distance += check_schedule(current_state,queue[i]);
        current_state = queue[i];
    }
    
    printf("\nThus the total distance required to cover the disc requests by fifo is %d",total_distance);
    
}


void main(){
    int queue[100],i,n,middle_el;
    
    printf("Enter the number of disc disc request: ");
    scanf("%d",&n);
    
    printf("Enter the discs request queue: ");
    for(i=0;i<n;i++){
        scanf("%d",&queue[i]);
    }
    
    printf("Enter the current disc element: ");
    scanf("%d",&middle_el);
    
    fifo_discschedule(queue,middle_el,n);
}



