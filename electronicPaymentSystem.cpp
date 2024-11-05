#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Base class: Payment
class Payment {
protected:
    string methodName;   // Payment method name
    double balance;      // Balance for the payment method

public:
    Payment(const string& methodName, double balance)
        : methodName(methodName), balance(balance) {}

    virtual ~Payment() {}  // Virtual destructor

    virtual void pay(double amount) = 0; // Pure virtual function

    // Helper to generate a receipt
    void generateReceipt(double amount) const {
        cout << "\n--- Transaction Receipt ---\n";
        cout << "Payment Method: " << methodName << endl;
        cout << "Amount Paid: $" << amount << endl;
        time_t now = time(0);
        cout << "Date: " << ctime(&now);
        cout << "---------------------------\n\n";
    }
};

// Derived class: CreditCard
class CreditCard : public Payment {
    string cardNumber;  // 16-digit card number
    int cvv;            // Security code (CVV)

public:
    CreditCard(const string& cardNumber, int cvv, double balance)
        : Payment("Credit Card", balance), cardNumber(cardNumber), cvv(cvv) {}

    // Override pay function for CreditCard-specific payment
    void pay(double amount) override {
        if (balance >= amount) {
            cout << "Processing payment using Credit Card (" << cardNumber << ")...\n";
            balance -= amount;
            generateReceipt(amount);
        } else {
            cout << "Insufficient funds on Credit Card (" << cardNumber << ").\n";
        }
    }
};

// Derived class: UPI
class UPI : public Payment {
    string upiID;  // UPI ID (e.g., user@upi)

public:
    UPI(const string& upiID, double balance)
        : Payment("UPI", balance), upiID(upiID) {}

    // Override pay function for UPI-specific payment
    void pay(double amount) override {
        if (balance >= amount) {
            cout << "Processing payment using UPI (" << upiID << ")...\n";
            balance -= amount;
            generateReceipt(amount);
        } else {
            cout << "Insufficient balance for UPI (" << upiID << ").\n";
        }
    }
};

// Function to execute payment (demonstrates polymorphism)
void makePayment(Payment* payment, double amount) {
    cout << "\nInitiating payment of $" << amount << " using " << typeid(*payment).name() << "...\n";
    payment->pay(amount);  // Dynamically calls the appropriate payment function
}

int main() {
    // Create and configure payment methods
    CreditCard myCard("1234567812345678", 123, 500.0);
    UPI myUPI("user@upi", 300.0);

    // Make payments using polymorphism
    makePayment(&myCard, 100.0);  // Successful Credit Card payment
    makePayment(&myUPI, 350.0);   // Failed UPI payment (insufficient balance)
    makePayment(&myUPI, 150.0);   // Successful UPI payment

    return 0;
}

