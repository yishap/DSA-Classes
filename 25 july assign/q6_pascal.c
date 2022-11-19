// Write a program in c to display pascal triangle.

#include <stdio.h>
int main() {
    int n,a,i,j,k;
    printf("enter the number of rows : ");
    scanf("%d",&n);
    a=1;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(k=0;k<=i;k++)
        {
            if(k==0||j==0)
            {
                a=1;
            }
            else
            {
                a=a*(i-k+1)/k;
            }
            printf("%2d ",a);
        }
        printf("\n");
    }
    return 0;
}

