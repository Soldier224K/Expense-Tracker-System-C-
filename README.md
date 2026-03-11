# 💸 Expense Tracker System
> A lightweight, menu-driven C++ console app to record, categorise, and summarise daily expenses — no external libraries required.

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square)
![Standard](https://img.shields.io/badge/Standard-C%2B%2B11-lightblue?style=flat-square)
![Course](https://img.shields.io/badge/Course-B.Tech%20CSE%20Sem%20II-navy?style=flat-square)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=flat-square)

---

## 📋 Overview

Managing daily expenses manually is tedious and error-prone. This project solves that by offering a simple CLI tool where you can log expenses by category, then instantly view a breakdown and your total spend — all in one session.

---

## ✨ Features

| Feature | Description |
|---|---|
| ➕ Add Expense | Log a category and amount in seconds |
| 📊 View Summary | See spending grouped by category + grand total |
| 🔤 Auto-Formatting | Inputs like `FOOD`, `food`, `Food` → all stored as `Food` |
| 🛡️ Input Validation | Rejects non-numeric and negative values gracefully |
| 🔁 Loop Menu | Keeps running until you choose to exit |

---

## 🚀 Getting Started

### Prerequisites
- Any C++11-compatible compiler (`g++`, `clang++`, MSVC)

### Build & Run

```bash
# Clone / download the file, then:
g++ -std=c++11 tracker.cpp -o tracker
./tracker
```

---

## 🖥️ Sample Output

```
rajrasal@Rajs-MacBook-Air-3 Sem2_FinalProject % ./tracker

--- Menu ---
1. Add Expense
2. View Summary
3. Exit
Enter your choice: 1

Enter Expense Category (e.g., Food, Travel): food
Enter Amount spent: 350
Expense Added Successfully

Enter your choice: 1
Enter Expense Category (e.g., Food, Travel): TRAVEL
Enter Amount spent: -50
[Error] Invalid input. Please enter a positive number: 500
Expense Added Successfully

Enter your choice: 2

--- Category-wise Expenses ---
Food:   Rs.350.00
Travel: Rs.500.00

Total Monthly Expense: Rs.850.00

Enter your choice: 3
Exiting program...
```

---

## 🗂️ Code Structure

```
tracker.cpp
├── formatCategory()   → Normalises input to Title Case
├── addExpense()       → Validates & stores category + amount
├── viewSummary()      → Aggregates totals & displays summary
└── main()             → Menu loop (do-while, runs until Exit)
```

---

## ⚙️ How It Works

```
Start → Menu → [1] Add Expense → Validate Input → Store in Arrays
                ↓
               [2] View Summary → Linear Search → Display Totals
                ↓
               [3] Exit
```

Two parallel arrays (`categories[]`, `amounts[]`) hold up to **100 entries**. `viewSummary()` does a linear scan to group duplicates and accumulate totals.

---

## 📐 Constraints

- Max **100** expense entries per session (compile-time constant)
- Data is **not persisted** — resets on exit
- Amounts must be **positive numbers**

---

## 📚 Concepts Used

`Arrays` · `Functions` · `Loops` · `String Manipulation` · `Input Validation` · `cin / getline`

---

## 👤 Author

**Your Full Name** · Roll No: `XXXXXXXX` · ITM Skills University, B.Tech CSE 2025–29
