#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 5

typedef struct {
    int id;
    int period;
    int execution_time;
    int remaining_time;
} Task;

void rate_monotonic(Task tasks[], int n, int hyperperiod) 
{
    printf("\nRate Monotonic Scheduling\n");
    
    for (int time = 0; time < hyperperiod; time++) 
    {
        int highest_priority = -1;
        
        
        for (int i = 0; i < n; i++) 
        {
            if (time % tasks[i].period == 0) 
            {
                tasks[i].remaining_time = tasks[i].execution_time; 
            }
        }

        
        for (int i = 0; i < n; i++) 
        {
            if (tasks[i].remaining_time > 0 && (highest_priority == -1 || tasks[i].period < tasks[highest_priority].period)) 
            {
                highest_priority = i;
            }
        }

       
        if (highest_priority != -1) 
        {
            printf("Time %d: Task %d\n", time, tasks[highest_priority].id);
            tasks[highest_priority].remaining_time--; 
        }
    }
}

int main() {
    Task tasks[MAX_TASKS] = {
        {1, 5, 2, 0},
        {2, 10, 3, 0},
        {3, 15, 5, 0}
    };
    
    int num_tasks = 3;
    int hyperperiod = 30;  
    
    rate_monotonic(tasks, num_tasks, hyperperiod);
    
    return 0;
}
