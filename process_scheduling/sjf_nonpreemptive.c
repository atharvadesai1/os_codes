#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void main(){
    int at[MAX],bt[MAX],ct[MAX],tat[MAX],wt[MAX],n,i,timer=0,j,temp,pr[MAX];
    float total_tat=0,total_wt=0;
    
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    printf("\nEnter the Arrival time and Burst Time of processes:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        pr[i]=i+1;
    }
    
    int min_index;
    
    for(i=0;i<n-1;i++){
        min_index= i;
        
        for(j=i+1;j<n;j++){
            if(at[min_index]>at[j]){
               min_index = j;
            }
            else if(at[min_index]==at[j] && bt[j]<bt[min_index]){
                min_index = j;
            }
        }
        
        if(min_index!=i){
            temp= at[i];
            at[i]= at[min_index];
            at[min_index]=temp;
            temp= bt[i];
            bt[i]= bt[min_index];
            bt[min_index]=temp;
            temp= pr[i];
            pr[i]= pr[min_index];
            pr[min_index]=temp;
        }
    }
    
    for(i=0;i<n;i++){
        if(at[i]<=timer){
            ct[i]= timer + bt[i];
            timer += bt[i];
        }
        else{
           ct[i]= timer + bt[i] + (at[i]-timer);
            timer += bt[i] + (at[i]-timer) ;
        }
    }
    
    for(i=0;i<n;i++){
        tat[i] = ct[i]-at[i];
    }
    
    for(i=0;i<n;i++){
        wt[i] = tat[i]-bt[i];
    }
    
    printf("\n\t\t\t********Results********\n\n");
    printf("Process\tArrival Time\tBurst Time\tTurnAround Time\tWaiting Time\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pr[i],at[i],bt[i],tat[i],wt[i]);
    }
    
    for(i=0;i<n;i++){
        total_tat += tat[i];
        total_wt += wt[i];
    }
    
    printf("\nThe Average TurnAround Time is %f",total_tat/n);
    printf("\nThe Average Waiting Time is %f",total_wt/n);

    
    
}
