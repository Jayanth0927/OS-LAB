#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("enter how many process: \n");
    scanf("%d",&n);
    int bt[n];
    printf("enter burst time for the processes: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    int ct[n];
    int var = 0;
    do
    {
        ct[var] = bt[var];
    }while(var > 0);
    for(int i=1;i<n;i++)//loop runs for 1 2 3
    {
        ct[i] = bt[i] + ct[i-1];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",ct[i]);
    }
    int tat[n];
    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i];
    }
    int wt[n];
    for(int i=0;i<n;i++)
    {
        wt[i] = tat[i] - bt[i];
    }
    float s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        s1 = s1 + tat[i];
        s2 = s2 + wt[i];
    }
    printf("\n");
    printf("average turn around time = %f \n",(s1/n));
    printf("average waiting time = %f \n",(s2/n));
    return 0;
}






















