#include <stdio.h>

#define MAX 5

int state[MAX] = {0};
int done[MAX] = {0};

int can_eat(int p, int n) {
    int left = (p + n - 1) % n;
    int right = (p + 1) % n;
    return state[left] != 1 && state[right] != 1;
}

int main() {
    int n, h, choice;
    int hungry_pos[MAX];

    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &h);

    for (int i = 0; i < h; i++) {
        printf("Enter philosopher %d position (0 to %d): ", i, n - 1);
        scanf("%d", &hungry_pos[i]);
    }

    do {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        for (int i = 0; i < MAX; i++)
            done[i] = 0;

        if (choice == 1) {
            printf("Allow one philosopher to eat at any time\n");

            int completed = 0;
            while (completed < h) {
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < h; j++) {
                        int p = hungry_pos[j];
                        if (state[p] == 0 && done[p] == 0)
                            printf("P %d is waiting\n", p);
                    }

                    int p = hungry_pos[i];
                    if (state[p] == 0 && can_eat(p, n) && done[p] == 0) {
                        state[p] = 1;
                        printf("P %d is granted to eat\n", p);
                        printf("P %d has finished eating\n", p);
                        state[p] = 0;
                        done[p] = 1;
                        completed++;
                        break;
                    }
                }
            }

        } else if (choice == 2) {
            printf("Allow two philosophers to eat at any time\n");

            int completed = 0;
            while (completed < h) {
                for (int j = 0; j < h; j++) {
                    int p = hungry_pos[j];
                    if (state[p] == 0 && done[p] == 0)
                        printf("P %d is waiting\n", p);
                }

                int eating_now = 0;
                for (int i = 0; i < h && eating_now < 2; i++) {
                    int p = hungry_pos[i];
                    if (state[p] == 0 && can_eat(p, n) && done[p] == 0) {
                        state[p] = 1;
                        printf("P %d is granted to eat\n", p);
                        printf("P %d has finished eating\n", p);
                        state[p] = 0;
                        done[p] = 1;
                        eating_now++;
                        completed++;
                    }
                }
            }

        } else if (choice != 3) {
            printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
