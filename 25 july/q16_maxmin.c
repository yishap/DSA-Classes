// Write a program in c to return maximum and minimum out of three numbers from one function.

#include<stdio.h>

int maxmin(int x, int y, int z,int *max,int *min){
    *max = (x>y?(x>z?x:z):(y>z?y:z));
    *min = (x<y?(x<z?x:z):(y<z?y:z));
}

int main(){
    int a,b,c;
    int max,min;
    printf("Enter three numbers : ");
    scanf("%d %d %d",&a,&b,&c);
    maxmin(a,b,c,&max,&min);
    printf("The largest number is : %d \n",max);
    printf("The smallest number is : %d",min);
    return 0;
}