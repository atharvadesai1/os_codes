#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void main(){
    int n,m,avail[100],max[100][100],alloc[100][100],need[100][100],i,finish[100],work[100],j,l,k,flag=0,p=0,safety[100];
    bool visited[100]={false};
    printf("Enter the number of processes in the system: ");
    scanf("%d",&n);
    printf("Enter the number of resources in the system: ");
    scanf("%d",&m);
    
    for(i=0;i<m;i++)
    {
        safety[n]=100;
    }
    
    printf("Enter the value of available resources:\n");   
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
        work[i] = avail[i];
    }
    
    printf("Enter the value of maximum resources:\n");   
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
       {
           scanf("%d",&max[i][j]);
       }
    }   
    
    printf("Enter the value of allocated resources:\n");    
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
       {
           scanf("%d",&alloc[i][j]);
       }
    }   
    
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
       {    
           need[i][j] = max[i][j] - alloc[i][j];
       }
    }
    
    i=0;
    
    while(p!=n)
    {
        // printf("kaa")
        if(visited[i]==false)
        {
            for(j=0;j<m;j++)
            {
                if(need[i][j]<=work[j])
                {
                    flag+=1;
                }
                if(flag==3){
                    for(l=0;l<m;l++)
                    {
                        work[l]+=alloc[i][l]; 
                    }
                    safety[p]=i;
                    p++;
                    visited[i]=true;
                }
            }
        }
        i = (i+1)%n;
        flag=0;
    }
    printf("\nFinal sequence of process to prevent deadlock:\n");
    for(k=0;k<n;k++)
    {
        printf("P%d ",safety[k]+1);
    }
}
