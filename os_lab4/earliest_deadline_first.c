#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 5

typedef struct {
    int id;
    int period;
    int execution_time;
    int remaining_time;
    int deadline;
} Task;


void earliest_deadline_first(Task tasks[], int n, int hyperperiod) {
    printf("\nEarliest Deadline First Scheduling\n");
    for (int time = 0; time < hyperperiod; time++) {
        int earliest_deadline = -1;
        for (int i = 0; i < n; i++) {
            if (time % tasks[i].period == 0) {
                tasks[i].remaining_time = tasks[i].execution_time;
                tasks[i].deadline = time + tasks[i].period;
            }
            if (tasks[i].remaining_time > 0 && (earliest_deadline == -1 || tasks[i].deadline < tasks[earliest_deadline].deadline)) {
                earliest_deadline = i;
            }
        }
        if (earliest_deadline != -1) {
            printf("Time %d: Task %d\n", time, tasks[earliest_deadline].id);
            tasks[earliest_deadline].remaining_time--;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS] = {
        {1, 5, 2, 0, 0},
        {2, 10, 3, 0, 0},
        {3, 15, 5, 0, 0}
    };
    int num_tasks = 3;
    int hyperperiod = 30; 
    
    earliest_deadline_first(tasks, num_tasks, hyperperiod);
    
    return 0;
}