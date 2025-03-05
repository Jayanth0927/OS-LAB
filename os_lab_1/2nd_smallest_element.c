#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int max(int a,int b)
{
    return a>b ? a : b;
}
int min(int a,int b)
{
    return a<b ? a : b;
}
int main()
{
    int a[] = {1,3,4,2,5};
    // largest element = 5
    // smalles element = 1
    // 2nd largest element = 4
    int n = sizeof(a)/sizeof(*a);
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i = 1;i<n;i++)
    {
        largest = max(largest,a[i]);
    }
    for(int i = 1;i<n;i++)
    {
        if(a[i] != largest)
        {
            second_largest = max(second_largest,a[i]);
        }
    }
    printf("second largest = %d",second_largest);
    return 0;
}
