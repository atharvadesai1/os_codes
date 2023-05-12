#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

int check_now(int a,int b){
    if(a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}

void scan_discschedule(int queue[MAX],int root_ele,int n){
    int i,j,current_position=root_ele,min_index,total_distance,min_dist;
    bool visited[MAX]={false};
    
    
    for(i=0;i<n+1;i++)
    {
        min_dist=9999;
        min_index=333;
        for(j=0;j<n+1;j++)
        {
            if(!visited[j] && queue[j]>root_ele && check_now(queue[j],current_position)<min_dist){
                min_dist = check_now(queue[j],current_position);
                min_index = j;
            }
            
        }
        if(min_index!=333){
            visited[min_index]=true;
            total_distance += min_dist;
            current_position = queue[min_index];
        }
    }
    
    if(visited[n]==true){
        current_position = queue[n];
        for(i=0;i<n+1;i++)
        {
            min_dist=9999;
            min_index=333;
            for(j=0;j<n+1;j++)
            {
                if(!visited[j] && queue[j]<root_ele && check_now(queue[j],current_position)<min_dist){
                    min_dist = check_now(queue[j],current_position);
                    min_index = j;
                }
                
            }
            if(min_index!=333){
                visited[min_index]=true;
                total_distance += min_dist;
                current_position = queue[min_index];
            }
        }
    }
    
    printf("The total distance required to cover the disc requests by scan is %d",total_distance);
}

void main()
{
    int i,n,queue[MAX],root_ele,last_req;
    printf("Enter the number of disc requests: ");
    scanf("%d",&n);
    
    printf("Enter the last request of disc: ");
    scanf("%d",&last_req);
    
    printf("Enter the disc requests queue: ");
    for(i=0;i<n;i++){
        scanf("%d",&queue[i]);
    }
    queue[n] = last_req;
    
    printf("Enter the current disc request: ");
    scanf("%d",&root_ele);
    
    scan_discschedule(queue,root_ele,n);
}
