#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Expense {
private:
    string date, category, note;
    float amount;

public:
    // Constructor
    Expense() {}
    Expense(string d, string c, float a, string n) {
        date = d;
        category = c;
        amount = a;
        note = n;
    }

    // Getters
    string getDate() { return date; }
    string getCategory() { return category; }
    float getAmount() { return amount; }
    string getNote() { return note; }

    // Convert to file format
    string toFileString() {
        return date + "," + category + "," + to_string(amount) + "," + note;
    }

    // Display
    void display() {
        cout << date << " | " << category << " | " << amount << " | " << note << endl;
    }
};

class BudgetManager {
private:
    vector<Expense> expenses;
    float budget;

    bool validAmount(float amt) {
        return amt > 0;
    }

    bool validCategory(string cat) {
        return !cat.empty();
    }

public:
    // Constructor
    BudgetManager(float b) {
        budget = b;
        loadFromFile();
    }

    // Add Expense
    void addExpense() {
        string date, category, note;
        float amount;

        cout << "Enter Date (DD-MM): ";
        cin >> date;

        cout << "Enter Category: ";
        cin >> category;

        if (!validCategory(category)) {
            cout << "Invalid category!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        if (cin.fail() || !validAmount(amount)) {
            cout << "Invalid amount!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        cout << "Enter Note: ";
        cin.ignore();
        getline(cin, note);

        expenses.push_back(Expense(date, category, amount, note));
        saveToFile();

        cout << "Expense added successfully!\n";
    }

    // View all
    void viewExpenses() {
        if (expenses.empty()) {
            cout << "No expenses found!\n";
            return;
        }

        for (auto &e : expenses)
            e.display();
    }

    // Search by category
    void searchByCategory() {
        string cat;
        cout << "Enter category: ";
        cin >> cat;

        bool found = false;
        for (auto &e : expenses) {
            if (e.getCategory() == cat) {
                e.display();
                found = true;
            }
        }

        if (!found)
            cout << "No matching records!\n";
    }

    // Search by date
    void searchByDate() {
        string date;
        cout << "Enter date (DD-MM): ";
        cin >> date;

        bool found = false;
        for (auto &e : expenses) {
            if (e.getDate() == date) {
                e.display();
                found = true;
            }
        }

        if (!found)
            cout << "No matching records!\n";
    }

    // Monthly total
    void monthlyTotal() {
        float total = 0;
        for (auto &e : expenses)
            total += e.getAmount();

        cout << "Monthly Total: " << total << endl;

        if (total > budget)
            cout << "⚠ Budget exceeded!\n";
    }

    // Category total
    void categoryTotal() {
        string cat;
        cout << "Enter category: ";
        cin >> cat;

        float total = 0;
        for (auto &e : expenses)
            if (e.getCategory() == cat)
                total += e.getAmount();

        cout << "Total for " << cat << ": " << total << endl;
    }

    // Save to file
    void saveToFile() {
        ofstream file("expenses.txt");

        if (!file) {
            cout << "Error opening file!\n";
            return;
        }

        for (auto &e : expenses)
            file << e.toFileString() << endl;

        file.close();
    }

    // Load from file
    void loadFromFile() {
        ifstream file("expenses.txt");

        if (!file)
            return;

        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            string d, c, a, n;

            getline(ss, d, ',');
            getline(ss, c, ',');
            getline(ss, a, ',');
            getline(ss, n, ',');

            if (!d.empty() && !c.empty() && !a.empty())
                expenses.push_back(Expense(d, c, stof(a), n));
        }

        file.close();
    }
};

// Main menu
int main() {
    float budget;
    cout << "Enter Monthly Budget: ";
    cin >> budget;

    BudgetManager bm(budget);

    int choice;

    do {
        cout << "\n--- Monthly Money Coach ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Search by Category\n";
        cout << "4. Search by Date\n";
        cout << "5. Monthly Total\n";
        cout << "6. Category Total\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {
            case 1: bm.addExpense(); break;
            case 2: bm.viewExpenses(); break;
            case 3: bm.searchByCategory(); break;
            case 4: bm.searchByDate(); break;
            case 5: bm.monthlyTotal(); break;
            case 6: bm.categoryTotal(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}