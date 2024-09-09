#include <iostream>
#include <iomanip>
#include "user.h"
#include "admin.h"
using namespace std;

void displayMenu();
void login_system();
void logo();

void logo() {
    cout << endl;
    cout << fixed;
    cout << right;
    cout << setfill(' ');
    cout << setw(53) << "__" << setw(5) << "__" << setw(5) << "__" << setw(3) << "__" << setw(4) << "__" << setw(5) << "__" << setw(4) << "__" << "\n";
    cout << setw(60) << "\\ \\  / / " << setw(2) << "| | | |" << setw(5) << " | |/ /" << setw(5) << "| |" << "\n";
    cout << setw(58) << "\\ \\/ /" << setw(9) << "| | | |" << setw(5) << " | ' / " << setw(5) << "| |" << "\n";
    cout << setw(57) << "\\  /" << setw(11) << "| | | | " << setw(4) << "|  <" << setw(7) << "| |" << "\n";
    cout << setw(56) << "/ /" << setw(11) << "| |_| |" << setw(4) << "| |" << setw(3) << "\\ \\" << setw(5) << "| |" << "\n";
    cout << setw(55) << "/_/" << setw(12) << "  \\_____/" << setw(4) << "|_|" << setw(5) << "\\_\\ " << setw(3) << "|_|" << "\n";
    cout << setw(60) << "\n";
}

void displayMenu() {
    cout << left << setw(30) << setfill('*') << "" << endl;
    cout << left << setw(30) << setfill(' ') << "*Welcome to Yuki Cafe*" << endl;
    cout << left << setw(30) << setfill('*') << "" << endl;
    cout << left << setw(30) << setfill(' ') << "* 1. User" << endl;
    cout << left << setw(30) << setfill(' ') << "* 2. Staff" << endl;
    cout << left << setw(30) << setfill(' ') << "* 3. Exit" << endl;
    cout << left << setw(30) << setfill('*') << "" << endl;
}

void login_system() {
    displayMenu();
    cout << "Enter your choice (1-3): ";
    int option = 0;
    cin >> option;

    while (true) {
        switch (option) {
        case 1:
            user_login();
            break;
        case 2:
            staff_login();
            break;
        case 3:
            cout << "Existing the main page" << "\n";
            cout << "Thanks for Looking at Yuki's cafe menu" << "\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 3 : ";
            cin >> option;
            break;
        }
    }
}