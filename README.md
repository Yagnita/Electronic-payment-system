
# **Electronic Payment System – C Program**

This project demonstrates a **menu-driven electronic payment system** using **polymorphism and inheritance in C**. It supports two payment methods: **Credit Card** and **UPI**. Each method inherits from a base `Payment` structure and implements unique payment behaviors using **function pointers for polymorphism**.

---

## **Table of Contents**
- [Overview](#overview)
- [Features](#features)
- [Modules](#modules)
- [How it Works](#how-it-works)


---

## **Overview**
This system allows users to **simulate payments** using credit cards or UPI and demonstrates key concepts of **inheritance and polymorphism**. The program **dynamically selects the appropriate payment method** at runtime using **function pointers**, simulating real-world scenarios like **card payments** and **UPI transactions**.

---

## **Features**
- **Polymorphism**: Function pointers dynamically call the appropriate payment method at runtime.
- **Inheritance**: Credit Card and UPI inherit common attributes from the `Payment` structure.
- **Receipt Generation**: Displays a transaction receipt with the method name, amount, and timestamp.
- **Balance Management**: Ensures sufficient funds are available before processing payments.

---

## **Modules**
### **1. Payment Module (Base Class):**
- Stores common attributes like `methodName` and `balance`.
- Uses function pointers to enable **polymorphic behavior**.

### **2. CreditCard Module (Derived Class):**
- Inherits from the `Payment` structure.
- Contains attributes like `cardNumber` and `cvv`.
- Implements the **`creditCardPayment()`** function.

### **3. UPI Module (Derived Class):**
- Inherits from the `Payment` structure.
- Contains the **UPI ID** (`upiID`).
- Implements the **`upiPayment()`** function.

### **4. Polymorphic Execution Module:**
- Uses the **`makePayment()`** function to dynamically call the appropriate payment method.

### **5. Receipt Generation Module:**
- Displays the payment receipt with the date using **`ctime()`**.

---

## **How it Works**
1. **Initialization**:
   - A **Credit Card** and a **UPI** object are created and initialized with a balance.

2. **Polymorphic Payment Execution**:
   - The **`makePayment()`** function dynamically selects the correct payment function (`creditCardPayment()` or `upiPayment()`) using **function pointers**.

3. **Receipt Generation**:
   - After a successful payment, a **receipt** is generated showing the method name, amount, and date.

4. **Balance Check**:
   - If the balance is insufficient, the payment is denied.

---

