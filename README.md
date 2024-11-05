# Payment Processing System

This C++ program demonstrates an object-oriented approach to a simple payment processing system using inheritance and polymorphism. The program allows users to create different types of payment methods, such as Credit Card and UPI, and process payments using those methods.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Classes](#classes)


## Overview

The program defines a base class `Payment` and derived classes `CreditCard` and `UPI`. Each derived class overrides the `pay` function to provide payment-specific logic. Polymorphism is used to dynamically call the correct `pay` function depending on the payment type.

## Features

- Supports different payment types: **Credit Card** and **UPI**.
- Generates a transaction receipt upon successful payment.
- Handles insufficient balance for each payment type.
- Demonstrates object-oriented principles, including inheritance and runtime polymorphism.

## Classes

### 1. `Payment` (Abstract Base Class)
   - **Attributes**: `methodName`, `balance`
   - **Methods**:
     - `pay(double amount)`: Pure virtual function to be implemented by derived classes.
     - `generateReceipt(double amount)`: Generates a receipt showing the method, amount, and date.

### 2. `CreditCard` (Derived Class)
   - **Attributes**: `cardNumber`, `cvv`
   - **Methods**:
     - Overrides `pay` to process payments specifically for credit cards.

### 3. `UPI` (Derived Class)
   - **Attributes**: `upiID`
   - **Methods**:
     - Overrides `pay` to process payments specifically for UPI.

### Prerequisites

To compile and run this program, you need:
- A C++ compiler supporting C++11 or later (e.g., `g++`).




