#include<stdio.h>
#include<stdlib.h>
int countDuplicate(int a[],int n)
{
    int count = 0;
    int freq_count[100] = {0};
    for(int i = 0;i<n;i++)
    {
        freq_count[a[i]]++;
    }
    for(int i = 0;i<n;i++)
    {
        if(freq_count[i] > 1)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int a[] = {1, 2, 4, 6, 2, 4, 3, 5, 1, 7, 4};
    int n = sizeof(a)/sizeof(*a);
    int result = countDuplicate(a,n);
    printf("duplicate elements = %d",result);
}