#include <iostream>
#include <fstream>
using namespace std;

struct Expense {
    float amount;
    string category;
};

// 🔹 Add Expense
void addExpense() {
    Expense e;
    ofstream file("expenses.txt", ios::app);

    cout << "Enter amount: ";
    cin >> e.amount;

    if (e.amount < 0) {
        cout << "Invalid amount!\n";
        return;
    }

    cout << "Enter category (food/travel/shopping/etc): ";
    cin >> e.category;

    file << e.amount << " " << e.category << endl;
    file.close();

    cout << "Expense added successfully!\n";
}

// 🔹 View Expenses
void viewExpenses() {
    Expense e;
    ifstream file("expenses.txt");

    cout << "\n---- Expense Records ----\n";

    while (file >> e.amount >> e.category) {
        cout << "Amount: " << e.amount
             << " | Category: " << e.category << endl;
    }

    file.close();
}

// 🔹 Total Expense + Message
float totalExpense() {
    Expense e;
    ifstream file("expenses.txt");
    float total = 0;

    while (file >> e.amount >> e.category) {
        total += e.amount;
    }

    cout << "Total Expense: " << total << endl;

    if (total < 500) {
        cout << "Good saving! 👍" << endl;
    } else if (total <= 1000) {
        cout << "Try to control your expenses ⚠️" << endl;
    } else {
        cout << "Too much spending! 🚨" << endl;
    }

    file.close();
    return total;
}

// 🔹 Add Income
void addIncome() {
    float income;
    ofstream file("income.txt", ios::app);

    cout << "Enter income: ";
    cin >> income;

    file << income << endl;
    file.close();

    cout << "Income added successfully!\n";
}

// 🔹 Calculate Savings
void calculateSavings() {
    Expense e;
    ifstream expFile("expenses.txt");
    float totalExpense = 0;

    while (expFile >> e.amount >> e.category) {
        totalExpense += e.amount;
    }
    expFile.close();

    ifstream incFile("income.txt");
    float income, totalIncome = 0;

    while (incFile >> income) {
        totalIncome += income;
    }
    incFile.close();

    float savings = totalIncome - totalExpense;

    cout << "\nTotal Income: " << totalIncome << endl;
    cout << "Total Expense: " << totalExpense << endl;
    cout << "Savings: " << savings << endl;

    if (savings > 0) {
        cout << "Great! You are saving money 👍" << endl;
    } else if (savings == 0) {
        cout << "No savings. Try to reduce expenses ⚠️" << endl;
    } else {
        cout << "Loss! Spending is more than income 🚨" << endl;
    }
}

// 🔹 Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Total Expense\n";
        cout << "4. Add Income\n";
        cout << "5. Savings\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalExpense(); break;
            case 4: addIncome(); break;
            case 5: calculateSavings(); break;
        }

    } while(choice != 6);

    return 0;
}
