// Write a program to store book details such as bookno, title, price using structure and print the book details
//  with highest price using the technique of passing structure to function.

#include<stdio.h>

struct book
{
    int bookno;
    char title[20];
    float price;
} b[3];
int count  = 0;
float max(struct book b[])
{
    int i;
    float max = b[0].price;
    for(i=0; i<3; i++)
    {
        if(b[i].price > max)
        {
            max = b[i].price;
        }
    }
    return max;
    count = i;
}
int main(){
    int i;
    for(i=0; i<3; i++){
        printf("Enter bookno : ");
        scanf("%d", &b[i].bookno);
        printf("Enter title : ");
        scanf("%s", b[i].title);
        printf("Enter price : ");
        scanf("%f", &b[i].price);
    }
    printf("\nHighest price : %f\n", max(b));
    printf("\nBookno of highest price : %d\n", b[count].bookno);
    printf("\nTitle of highest price : %s\n", b[count].title);
    return 0;
}
