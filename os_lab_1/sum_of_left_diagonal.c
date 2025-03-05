#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m;
    printf("enter the dimensions : ");
    scanf("%d %d",&n,&m);
    int a[n][m];
    printf("enter elements :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += a[i][i];
    }
    printf("sum of left diagonal = %d",sum);
    return 0;
}