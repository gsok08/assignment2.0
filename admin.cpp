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
void report();
void DisplayreportD();
void DisplayreportM();
void summaryreport();


void staff_function() {
    int option = 0;
    while(true){
    cout << " 1. Generate the report\n";
    cout << " 2. Update the drink's price\n";
    cout << " 3. Exit\n";
    cout << " please enter your option : ";
    while (true) {
        if (cin >> option) {
            if (cin.peek() == '\n' && option >= 1 && option <= 3) {
                break;
            }
            else {
                cout << "Invalid input. Please re-enter :  ";
            }
        }
        else {
            cout << "Invalid input. Please re-enter :  ";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        switch (option) {
        case 1:
            report();
            break;
        case 2:
            update_drink();
            break;
        case 3:
            cout << "thank for using yuki menu\n";
            return;
            break;
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

void report() {
    int option;
    while (true) {
        cout << "1. daily report\n";
        cout << "2. monthly report\n";
        cout << "3. summary report\n";
        cout << "enter your option : ";
        while (true) {
            if (cin >> option) {
                if (cin.peek() == '\n' && option >= 1 && option <= 3) {
                    break;
                }
                else {
                    cout << "Invalid input. Please re-enter :  ";
                }
            }
            else {
                cout << "Invalid input. Please re-enter :  ";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (option) {
        case 0:
            staff_function();
            break;
        case 1:
            DisplayreportD();
            break;
        case 2:
            DisplayreportM();
            break;
        case 3:
            summaryreport();
            break;
        }
    }
}

void DisplayreportD() {
    cout << "======================================\n";
    cout << "|   DAILY REPORT OF YUKIS CAFE       |\n";
    cout << "======================================\n";
    cout << "|Drinks Name|               |Quantity|\n";
    cout << "======================================\n";
    cout << "|1.Green Tea                       13|\n";
    cout << "|2.Earl Grey                        7|\n";
    cout << "|3.Jasmine                          6|\n";
    cout << "|4.Oolong                          10|\n";
    cout << "|5.Pepeprmin                        9|\n";
    cout << "|6.Royal English                    8|\n";
    cout << "|7.Pu - erh                        15|\n";
    cout << "======================================\n";
}
void DisplayreportM() {
    cout << "======================================\n";
    cout << "|   MONTH REPORT OF YUKIS CAFE       |\n";
    cout << "======================================\n";
    cout << "|Drinks Name|               |Quantity|\n";
    cout << "======================================\n";
    cout << "|1.Green Tea                       13|\n";
    cout << "|2.Earl Grey                        7|\n";
    cout << "|3.Jasmine                          6|\n";
    cout << "|4.Oolong                          10|\n";
    cout << "|5.Pepeprmin                        9|\n";
    cout << "|6.Royal English                    8|\n";
    cout << "|7.Pu - erh                        15|\n";
    cout << "======================================\n";
}

void summaryreport() {

}
