#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Base class: Payment
struct Payment {
    char methodName[20];                     // Payment method name
    double balance;                          // Balance for the payment method
    void (*pay)(struct Payment*, double);    // Polymorphic function pointer
};

// Derived class: CreditCard
struct CreditCard {
    struct Payment base;  // Inherits Payment
    char cardNumber[17];   // 16-digit card number + null terminator
    int cvv;               // Security code (CVV)
};

// Derived class: UPI
struct UPI {
    struct Payment base;  // Inherits Payment
    char upiID[30];        // UPI ID (e.g., user@upi)
};

// Function to generate a receipt
void generateReceipt(const char* method, double amount) {
    printf("\n--- Transaction Receipt ---\n");
    printf("Payment Method: %s\n", method);
    printf("Amount Paid: $%.2f\n", amount);
    printf("Date: %s", ctime(&(time_t){time(NULL)}));
    printf("---------------------------\n\n");
}

// CreditCard-specific payment function (polymorphic)
void creditCardPayment(struct Payment* p, double amount) {
    struct CreditCard* card = (struct CreditCard*)p;  // Cast to derived class
    if (p->balance >= amount) {
        printf("Processing payment using Credit Card (%s)...\n", card->cardNumber);
        p->balance -= amount;
        generateReceipt(p->methodName, amount);
    } else {
        printf("Insufficient funds on Credit Card (%s).\n", card->cardNumber);
    }
}

// UPI-specific payment function (polymorphic)
void upiPayment(struct Payment* p, double amount) {
    struct UPI* upi = (struct UPI*)p;  // Cast to derived class
    if (p->balance >= amount) {
        printf("Processing payment using UPI (%s)...\n", upi->upiID);
        p->balance -= amount;
        generateReceipt(p->methodName, amount);
    } else {
        printf("Insufficient balance for UPI (%s).\n", upi->upiID);
    }
}

// Function to execute payment (demonstrates polymorphism)
void makePayment(struct Payment* p, double amount) {
    printf("\nInitiating payment of $%.2f using %s...\n", amount, p->methodName);
    p->pay(p, amount);  // Dynamically calls the appropriate payment function
}

// Helper function to create a CreditCard object
struct CreditCard createCreditCard(const char* cardNumber, int cvv, double balance) {
    struct CreditCard card;
    strcpy(card.base.methodName, "Credit Card");
    strcpy(card.cardNumber, cardNumber);
    card.cvv = cvv;
    card.base.balance = balance;
    card.base.pay = creditCardPayment;  // Assign polymorphic function
    return card;
}

// Helper function to create a UPI object
struct UPI createUPI(const char* upiID, double balance) {
    struct UPI upi;
    strcpy(upi.base.methodName, "UPI");
    strcpy(upi.upiID, upiID);
    upi.base.balance = balance;
    upi.base.pay = upiPayment;  // Assign polymorphic function
    return upi;
}

int main() {
    // Create and configure payment methods
    struct CreditCard myCard = createCreditCard("1234567812345678", 123, 500.0);
    struct UPI myUPI = createUPI("user@upi", 300.0);

    // Make payments using polymorphism
    makePayment((struct Payment*)&myCard, 100.0);  // Successful Credit Card payment
    makePayment((struct Payment*)&myUPI, 350.0);   // Failed UPI payment (insufficient balance)
    makePayment((struct Payment*)&myUPI, 150.0);   // Successful UPI payment

    return 0;
}
