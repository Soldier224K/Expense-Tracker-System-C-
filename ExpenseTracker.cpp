#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

const int MAX_EXPENSES = 100;

string formatCategory(string category) {
    if (category.empty()) return category;
    category[0] = toupper(category[0]);
    for (int i = 1; i < category.length(); i++) {
        category[i] = tolower(category[i]);
    }
    return category;
}

void addExpense(string categories[], double amounts[], int& count) {
    if (count >= MAX_EXPENSES) {
        cout << "\n[Error] Storage full! Cannot add more expenses.\n";
        return;
    }
    
    cout << "\nEnter Expense Category (e.g., Food, Travel): ";
    cin >> ws; 
    getline(cin, categories[count]);
    categories[count] = formatCategory(categories[count]);
    
    cout << "Enter Amount spent: ";
    

    while (!(cin >> amounts[count]) || amounts[count] < 0) {
        cout << "[Error] Invalid input. Please enter a positive number: ";
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }

    cout << "Expense Added Successfully\n";
    count++;
}

void viewSummary(const string categories[], const double amounts[], int count) {
    if (count == 0) {
        cout << "\n[Info] No expenses recorded yet. Please add an expense first.\n";
        return;
    }

    double totalExpense = 0.0;
    string uniqueCategories[MAX_EXPENSES];
    double categoryTotals[MAX_EXPENSES] = {0.0};
    int uniqueCount = 0;

    for (int i = 0; i < count; i++) {
        totalExpense += amounts[i];
        
        bool found = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueCategories[j] == categories[i]) {
                categoryTotals[j] += amounts[i];
                found = true;
                break;
            }
        }
        
        if (!found) {
            uniqueCategories[uniqueCount] = categories[i];
            categoryTotals[uniqueCount] = amounts[i];
            uniqueCount++;
        }
    }
    cout << fixed; 
    cout.precision(2);

    cout << "\n--- Category-wise Expenses ---\n";
    for (int i = 0; i < uniqueCount; i++) {
        cout << uniqueCategories[i] << ": ₹" << categoryTotals[i] << "\n";
    }
    
    cout << "\nTotal Monthly Expense: ₹" << totalExpense << "\n";
    
   
    cout.unsetf(ios::fixed);
    cout.precision(6);
}

int main() {
    string categories[MAX_EXPENSES];
    double amounts[MAX_EXPENSES];
    int expenseCount = 0; 
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View Summary\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        while (!(cin >> choice)) {
            cout << "[Error] Invalid input. Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1: 
                addExpense(categories, amounts, expenseCount); 
                break;
            case 2: 
                viewSummary(categories, amounts, expenseCount); 
                break;
            case 3: 
                cout << "\nExiting program...\n"; 
                break;
            default: 
                cout << "\n[Error] Invalid choice. Please select 1, 2, or 3.\n";
        }
    } while (choice != 3);
    

    return 0;
}
