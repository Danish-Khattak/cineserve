# Automated Vending Machine for Cinema

An object-oriented C++ project that automates the process of purchasing cinema tickets, selecting seats, and buying snacks, with support for credit card payments and a vending mechanism for food items. This system improves user convenience by eliminating the need to carry cash and reducing the time spent waiting in queues.

## Problem Statement
The current manual system of buying cinema tickets and snacks involves:
- Long queues for tickets and snacks.
- A requirement to always carry cash.
- Time and energy wastage for customers.

## Solution
The **Automated Vending Machine for Cinema** provides an efficient solution by automating the following tasks:
1. **Ticket Selection:**
   - Select available movies, show dates, and timings.
   - Reserve seats in your preferred row and column.
   - A ticket is generated after successful selection.
   
2. **Seat Reservation:**
   - Displays available seats.
   - Allows users to choose their preferred seats and reserve them.

3. **Food Vending:**
   - Choose from different flavors of drinks and popcorns.
   - Automatic decrement of stock quantity after vending.

4. **Card Management:**
   - Supports user ID and password management.
   - Users can pay via stored balance in their credit card.
   
5. **Restocking Mode (for admins):**
   - Stores and manages prices and quantities for restocking the machine.

6. **Cash Handling:**
   - Cash can also be managed, including change distribution with 1000, 500, and 100 rupee notes.

## Features
- **Movie Ticketing Mode:** Displays available movies, dates, and show timings.
- **Seat Reservation:** Lets users reserve seats of their choice.
- **Food Vending:** Allows the purchase of popcorn and drinks.
- **Admin Mode:** Enables restocking and cash handling for the machine.

## Technologies Used
- **C++ Programming:** The project uses object-oriented programming principles.
- **Credit Card Simulation:** Manages user account balance for transactions.
- **Admin Interface:** Separate mode for managing the vending machine's inventory and cash.

## How to Run the Project
1. Clone the repository.
2. Compile the C++ code using a C++ compiler.
3. Run the executable to start the vending machine simulation.

