/*
 * ATM Simulation System
 * Team 1
 * Concepts: Switch Case, Loops, Functions
 */
#include <stdio.h>

double balance = 5000.00;
int pin = 1234;

void checkBalance() {
    printf("\n>> Your Current Balance is: $%.2f\n", balance);
}

void depositMoney() {
    double amount;
    printf("\nEnter amount to deposit: $");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("[Error] Invalid deposit amount!\n");
    } else {
        balance += amount;
        printf(">> $%.2f deposited successfully! New Balance: $%.2f\n", amount, balance);
    }
}

void withdrawMoney() {
    double amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("[Error] Amount must be positive!\n");
    } else if (amount > balance) {
        printf("[Error] Insufficient balance! Current Balance: $%.2f\n", balance);
    } else {
        balance -= amount;
        printf(">> Please collect your cash: $%.2f\nRemaining Balance: $%.2f\n", amount, balance);
    }
}

void changePin() {
    int oldPin, newPin;
    printf("\nEnter current PIN: ");
    scanf("%d", &oldPin);
    if (oldPin == pin) {
        printf("Enter new 4-digit PIN: ");
        scanf("%d", &newPin);
        pin = newPin;
        printf(">> PIN updated successfully!\n");
    } else {
        printf("[Error] Incorrect PIN!\n");
    }
}

int main() {
    int enteredPin, choice, attempts = 0;
    printf("=== WELCOME TO SECURE ATM ===\n");
    while (attempts < 3) {
        printf("Enter 4-digit PIN: ");
        scanf("%d", &enteredPin);
        if (enteredPin == pin) break;
        attempts++;
        printf("Incorrect PIN. Attempts remaining: %d\n", 3 - attempts);
    }
    if (attempts == 3) {
        printf("Card blocked due to 3 invalid PIN attempts.\n");
        return 1;
    }

    while (1) {
        printf("\n------- ATM SERVICES -------\n");
        printf("1. Check Balance\n2. Deposit Cash\n3. Withdraw Cash\n4. Change PIN\n5. Exit\n");
        printf("Select option (1-5): ");
        if (scanf("%d", &choice) != 1 || choice == 5) {
            printf("\nThank you for banking with us. Please take your card!\n");
            break;
        }
        switch (choice) {
            case 1: checkBalance(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: changePin(); break;
            default: printf("Invalid choice! Please select 1 to 5.\n");
        }
    }
    return 0;
}
