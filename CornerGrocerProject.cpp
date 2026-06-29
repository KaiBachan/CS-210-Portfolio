#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

public:
    void LoadFile();
    void CreateBackupFile();
    void SearchItem();
    void PrintFrequencies();
    void PrintHistogram();
};

void GroceryTracker::LoadFile() {
    string item;
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

void GroceryTracker::CreateBackupFile() {
    ofstream outputFile("frequency.dat");

    for (auto pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

void GroceryTracker::SearchItem() {
    string item;

    cout << "Enter item to search: ";
    cin >> item;

    if (itemFrequency.count(item) > 0) {
        cout << item << " purchased "
            << itemFrequency[item]
            << " time(s)." << endl;
    }
    else {
        cout << item << " was not found." << endl;
    }
}

void GroceryTracker::PrintFrequencies() {
    for (auto pair : itemFrequency) {
        cout << pair.first << " "
            << pair.second << endl;
    }
}

void GroceryTracker::PrintHistogram() {
    for (auto pair : itemFrequency) {
        cout << pair.first << " ";

        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }

        cout << endl;
    }
}

int main() {
    GroceryTracker tracker;

    tracker.LoadFile();
    tracker.CreateBackupFile();

    int choice = 0;

    while (choice != 4) {
        cout << endl;
        cout << "1. Search Item Frequency" << endl;
        cout << "2. Print All Frequencies" << endl;
        cout << "3. Print Histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tracker.SearchItem();
            break;

        case 2:
            tracker.PrintFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}