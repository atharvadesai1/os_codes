#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 100

int check_now(int a,int b){
    if(a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}

void sstf_discschedule(int queue[MAX],int root_ele,int n)
{
    int i,j,min_ele,min_index,current_position=root_ele,total_distance=0,min_dist;
    bool visited[MAX]= {false};
    min_dist=9999;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            if(!visited[j] && check_now(queue[j],current_position)<min_dist){
                min_index = j;
                min_dist = check_now(queue[j],current_position);
                min_ele = queue[j];
            }  
        }
        
        visited[min_index]=true;
        total_distance += min_dist;
        current_position = min_ele;
        min_dist=9999;
        
    }
    
    printf("The total distance required to cover the disc requests by sstf is %d",total_distance);
    
}

void main()
{
    int i,n,queue[MAX],root_ele;
    printf("Enter the number of disc requests: ");
    scanf("%d",&n);
    
    printf("Enter the disc requests queue: ");
    for(i=0;i<n;i++){
        scanf("%d",&queue[i]);
    }
    
    printf("Enter the current disc request: ");
    scanf("%d",&root_ele);
    
    sstf_discschedule(queue,root_ele,n);
    
}



