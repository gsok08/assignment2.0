#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "user.h"
using namespace std;

void staff_login();
void staff_function();
void update_drink();

void staff_function() {
    int option = 0;
    cout << " 1. Generate the report\n";
    cout << " 2. Update the drink's price\n";
    cout << "3. Exit\n";
    cout << "please enter your option : ";
    cin >> option;
    while (true) {
        switch (option) {
        case 1:
            break;
        case 2:
            update_drink();
            break;
        case 3:
            return;
            break;
        default:
            cout << "invalid enter\n";
            cout << "please re-enter : ";
            cin >> option;
        }
    }
}

void staff_login() {
    int attempt = 0;
    string inID;
    string enteredPassword;
    const string staffid = "S001";
    const string staffPassword = "staff123";
    cout << "Pleae Enter your Staff ID :";
    cin >> inID;
    cout << "Pleae Enter your Staff Password :";
    cin >> enteredPassword;

    while (true) {
        if (enteredPassword == staffPassword && inID == staffid)
        {
            cout << "\nAccess granted." << endl;
            cout << "\n";
            staff_function();
            exit(0);
        }
        else {
            attempt++;
            if (attempt == 3) {
                cout << "\nYou already cannot login system ";
                exit(0);
            }
            else
                cout << "\nAccess denied.";
            cout << "\nAttempt left : " << 3 - attempt;
            cout << "\n\nPlease re-enter ID :";
            cin >> inID;
            cout << "Please re-enter Password :";
            cin >> enteredPassword;
        }
    }
}

