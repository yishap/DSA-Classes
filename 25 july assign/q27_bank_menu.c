// Write a program in c to add money to the account (account no, name, balance), or withdraw money from the account through. a menu driven program.
#include<stdio.h>
#include<stdlib.h>

struct bank{
    int accno;
    char name[20];
    float balance;
};

int add(struct bank *b){
    int n;
    printf("\nEnter the amount to be added: ");
    scanf("%d",&n);
    b->balance += n;
    printf("\nSuccessfully added %d\n",n);
    printf("\nNew Balance: %f",b->balance);
    return 0;
}

int withdraw(struct bank *b){
    int n;
    printf("\nEnter the amount to be withdrawn: ");
    scanf("%d",&n);
    b->balance -= n;
    printf("\nSuccessfully withdrawn %d\n",n);
    printf("\nNewBalance: %f",b->balance);
    return 0;
}

int main(){
    struct bank b;
    int choice;
    printf("\nEnter the account number: ");
    scanf("%d", &b.accno);
    printf("Enter the name: ");
    scanf("%s", b.name);
    printf("Enter the balance: ");
    scanf("%f", &b.balance);
    printf("\n1. Add money\n2. Withdraw money\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
if (choice == 1)
    add(&b);
else if (choice == 2)
    withdraw(&b);
else
    exit(0);
    return 0;
}
