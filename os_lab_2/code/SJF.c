#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
 {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], ct[n], tat[n], wt[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }


    for (int i = 0; i < n - 1; i++)
  {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
             {
                swap(&bt[j], &bt[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }


    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }


    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }


    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
