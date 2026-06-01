#include <stdio.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Account a;
    int choice;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);

    printf("Enter Name: ");
    scanf("%s", a.name);

    a.balance = 0;

    while(1) {
        printf("\n1.Deposit\n2.Withdraw\n3.Balance Enquiry\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount: ");
                scanf("%f", &amount);
                a.balance += amount;
                break;

            case 2:
                printf("Enter amount: ");
                scanf("%f", &amount);

                if(amount <= a.balance)
                    a.balance -= amount;
                else
                    printf("Insufficient Balance!\n");
                break;

            case 3:
                printf("Current Balance = %.2f\n", a.balance);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!");
        }
    }
}
