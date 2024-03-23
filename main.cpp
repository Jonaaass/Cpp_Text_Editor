#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile(const string& filename) {
    ofstream file(filename);
    file.close();
    cout << "File created: " << filename << endl;
}

void openFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Contents of " << filename << ":" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void editFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        string line;
        cout << "Enter text. Press Ctrl+D (Unix) or Ctrl+Z (Windows) to save and exit." << endl;
        while (getline(cin, line)) {
            file << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

int main() {
    string filename;
    cout << "Welcome to Simple Text Editor!" << endl;
    cout << "Enter filename: ";
    getline(cin, filename);

    char choice;
    cout << "Options:" << endl;
    cout << "1. Create new file" << endl;
    cout << "2. Open existing file" << endl;
    cout << "3. Edit existing file" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case '1':
            createFile(filename);
            break;
        case '2':
            openFile(filename);
            break;
        case '3':
            editFile(filename);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}
