#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n,m;
    printf("enter the dimensions: ");
    scanf("%d%d",&n,&m);
    int a[n][m];
    printf("\nenter elements:");
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        int rsum = 0;
        for(int j = 0;j<m;j++)
        {
            rsum += a[i][j];
        }
        printf("sum of row %d is %d\n",i+1,rsum);
    }
    for(int i=0;i<n;i++)
    {
        int csum = 0;
        for(int j=0;j<m;j++)
        {
           csum += a[j][i];
        }
        printf("sum of colum %d is %d\n",i+1,csum);
    }
}