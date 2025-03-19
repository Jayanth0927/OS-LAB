#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
} Process;

void fcfs(Process queue[], int n)
{
    int wait_time[MAX], turn_around_time[MAX], completion_time[MAX];
    float total_wt = 0, total_tat = 0;

    completion_time[0] = queue[0].arrival_time + queue[0].burst_time;
    wait_time[0] = 0;
    turn_around_time[0] = queue[0].burst_time;

    for (int i = 1; i < n; i++)
    {
        if (completion_time[i - 1] < queue[i].arrival_time)
            completion_time[i] = queue[i].arrival_time + queue[i].burst_time;
        else
            completion_time[i] = completion_time[i - 1] + queue[i].burst_time;

        wait_time[i] = completion_time[i - 1] - queue[i].arrival_time;
        if (wait_time[i] < 0) wait_time[i] = 0;

        turn_around_time[i] = queue[i].burst_time + wait_time[i];
    }
    for(int i=0;i<n;i++)
    {
        total_wt += wait_time[i];
        total_tat += turn_around_time[i];
    }

    printf("PID  Arrival  Burst  Completion  TurnAround  Waiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d      %d        %d       %d            %d          %d\n", queue[i].pid, queue[i].arrival_time,
               queue[i].burst_time, completion_time[i], turn_around_time[i], wait_time[i]);
    }
    printf("average waiting time = %f",(total_wt)/n);
    printf("\n");
    printf("average turn around time = %f",(total_tat)/n);
}

int main() {
    int n, sys_count = 0, user_count = 0;
    Process system_queue[MAX], user_queue[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int type;
        Process p;
        printf("Enter Process ID, Arrival Time, Burst Time, and Type : ");
        scanf("%d %d %d %d", &p.pid, &p.arrival_time, &p.burst_time, &type);
        
        if (type == 0)
            system_queue[sys_count++] = p;
        else
            user_queue[user_count++] = p;
    }

    printf("\nExecuting System Processes (Higher Priority)\n");
    fcfs(system_queue, sys_count);

    printf("\nExecuting User Processes (Lower Priority)\n");
    fcfs(user_queue, user_count);
    
    return 0;
}
