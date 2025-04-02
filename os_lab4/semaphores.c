#include<stdio.h>
#include<stdlib.h>
#define BUFFER 5
int buffer[BUFFER];
int in=0;
int out=0;
int mutex=1;
int full=0;
int empty=BUFFER;
void wait(int *sem)
{
while(*sem<=0);
(*sem)--;
}
void signal(int *sem)
{
(*sem)++;
}
int main()
{
int choice;
while(1)
{
printf("1.Produce\n2.Consume\n");
scanf("%d",&choice);
if(choice==1)
{
 if (empty > 0) {
                wait(&empty);
                wait(&mutex);
                int item = rand() % 100;
                buffer[in] = item;
                printf("Producer has produced: %d\n", item);
                in = (in + 1) % BUFFER;
                signal(&mutex);
                signal(&full);
            } else {
                printf("Buffer is full! Producer cannot produce.\n");
            }


}

else if (choice == 2) {
            if (full > 0) {
                wait(&full);
                wait(&mutex);
                int item = buffer[out];
                printf("Consumer has consumed: %d\n", item);
                out = (out + 1) % BUFFER;
                signal(&mutex);
                signal(&empty);
            } else {
                printf("Buffer is empty! Consumer cannot consume.\n");
            }
        }
        else {
            printf("Invalid choice. Please enter 1 to produce or 2 to consume.\n");
        }
}


}
