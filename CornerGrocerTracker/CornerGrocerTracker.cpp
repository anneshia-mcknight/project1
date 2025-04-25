#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Class to encapsulate the grocery tracker functionality
class GroceryTracker {
private:
    map<string, int> itemFrequency;

    // Loads data from input file and fills the map
    void loadItems(const string& filename) {
        ifstream inFile(filename);
        string item;

        if (!inFile.is_open()) {
            cerr << "Error: Unable to open input file." << endl;
            exit(1);
        }

        while (inFile >> item) {
            ++itemFrequency[item];
        }

        inFile.close();
    }

    // Writes frequency data to backup file
    void writeFrequencyFile(const string& filename) {
        ofstream outFile(filename);

        if (!outFile.is_open()) {
            cerr << "Error: Unable to create backup file." << endl;
            exit(1);
        }

        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }

        outFile.close();
    }

public:
    GroceryTracker(const string& inputFile, const string& frequencyFile) {
        loadItems(inputFile);
        writeFrequencyFile(frequencyFile);
    }

    // Option 1: Get frequency of a specific item
    void getItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            cout << item << " was purchased " << it->second << " time(s)." << endl;
        }
        else {
            cout << item << " was not found in today's purchases." << endl;
        }
    }

    // Option 2: Print all items and frequencies
    void printAllFrequencies() const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Option 3: Print histogram
    void printHistogram() const {
        for (const auto& pair : itemFrequency) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// Displays the menu
void displayMenu() {
    cout << "\nCorner Grocer Item Tracker" << endl;
    cout << "1. Find frequency of a specific item" << endl;
    cout << "2. Display frequency of all items" << endl;
    cout << "3. Display histogram of items purchased" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
    int choice;
    string item;

    do {
        displayMenu();
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            cout << "Enter the item name: ";
            cin >> item;
            tracker.getItemFrequency(item);
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}


