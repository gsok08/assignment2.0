//ordering beverages
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "home_page.h"
#include "admin.h"
using namespace std;
//variables
int option = 0;
const int colWidth2 = 15;
const int colWidth = 25;
const int numCols = 2;
int c = 0;//categories
double total = 0;//the total price of drink]
char choose = ' ';//yes or no
int drt = 0;//drink number for tea
int qty = 0;//quantity of drink
const int numCol = 50;
int numDrinks = 0;
int num = 0;
const int MAX_DRINKS = 100; // Maximum number of drinks in the cart
const int MAX_TEAS = 7;
const int MAX_SODAS = 4;
const int MAX_COFFEES = 5;

int drtea[MAX_DRINKS]; // record tea
int qtytea[MAX_DRINKS]; // record qty of tea
int drsoda[MAX_DRINKS]; // record soda
int qtysoda[MAX_DRINKS]; // record qty of soda
int drcoffee[MAX_DRINKS]; // record coffee
int qtycoffee[MAX_DRINKS]; // record qty of coffee

int teaCount = 0;
int sodaCount = 0;
int coffeeCount = 0;

int teaSize = 7;
int coffeeSize = 5;
int sodaSize = 4;

//storage drink and price

string nameTea[MAX_TEAS + 1] = { "", "green tea", "earl grey", "jasmine", "oolong", "peppermint", "royal english", "pu-erh" };
int priceTea[MAX_TEAS + 1] = { 0, 2, 3, 4, 5, 6, 7, 8 };

string nameSoda[MAX_SODAS + 1] = { "", "Strawberry", "Lychee", "Yuzu", "Melon" };
int priceSoda[MAX_SODAS + 1] = { 0, 11, 11, 12, 10 };

string nameCoffee[MAX_COFFEES + 1] = { "", "Latte", "Cappuccino", "Mocha", "Americano", "Espresso" };
double priceCoffee[MAX_COFFEES + 1] = { 0, 10.90, 10.90, 11.90, 9.90, 8.90 };

//function
void printLine(int colWidth, int numCols);
void user_home();
void menu();
void cart();
void cart_result();
void receipt();
void rg();
void login();
void tea();
void coffee();
void soda();
void user_login();
void update_drink();

//table's line
void printLine(int colWidth, int numCols) {
    for (int i = 0; i < numCols; ++i) {
        cout << string(colWidth, '-');
    }
    cout << endl;
}

void user_login() {
        cout << "\nNew user? Register (y/n): ";
        while(true){
        cin >> choose;

        if (choose == 'y' || choose == 'Y') {
            rg();
            break;
        }
        else if (choose == 'n' || choose == 'N') {
            login();
            break;
        }
        else if (isdigit(choose)) {
            cout << "\nNumbers are not allowed. Please enter 'y' or 'n' : ";
        }
        else {
            cout << "\nInvalid choice. Please enter 'y' or 'n' : ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
}


void rg() {
    ofstream g("data.txt");
    if (!g.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string userid, userPassword;
    cout << "";
    getline(cin, userid);
    cout << "New Username: ";
    getline(cin, userid);
    userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
    cout << "New Password: ";
    getline(cin, userPassword);
    userPassword.erase(remove_if(userPassword.begin(), userPassword.end(), ::isspace), userPassword.end());

    g << userid << '\n' << userPassword;
    g.close();
    cout << "Account created successfully.\nWelcome to yuki cafe , " << userid;
    user_home();
}

void login() {
    int attempt = 0;
    ifstream f("data.txt");
    if (!f.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string id, password;
    getline(f, id);
    getline(f, password);
    f.close();

    string inID, inPassword, empty;
    while (true) {
        cout << " ";
        getline(cin, empty);
        cout << "Enter Username: ";
        getline(cin, inID);
        inID.erase(remove_if(inID.begin(), inID.end(), ::isspace), inID.end());
        cout << "Enter Password: ";
        getline(cin, inPassword);
        inPassword.erase(remove_if(inPassword.begin(), inPassword.end(), ::isspace), inPassword.end());

        if (inID == id && inPassword == password) {
            cout << "Login Successful\nWelcome, " << inID << endl;
            user_home();
            break;
        }
        else {
            attempt++;
            if (attempt == 3) {
                cout << "You already cannot login\n\n";
                exit(0);
            }
            else
                cout << "Incorrect username or password. Try again.\n";
            cout << "Attempt left :" << 3 - attempt << "\n";
            cout << "or want to register new member (Y/N) : ";
            while (true) {
                cin >> choose;

                if (choose == 'y' || choose == 'Y') {
                    rg();
                    break;
                }
                else if (choose == 'n' || choose == 'N') {
                    login();
                    break;
                }
                else if (isdigit(choose)) {
                    cout << "\nNumbers are not allowed. Please enter 'y' or 'n' : ";
                }
                else {
                    cout << "\nInvalid enter. Please enter 'y' or 'n' : ";
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

void cart_result() {

    for (int i = 0; i < teaCount; ++i) {
        cout << '|' << left << setw(6) << i + 1 << '|' << setw(colWidth2) << nameTea[drtea[i]] << '|' << setw(colWidth) << qtytea[i] << '|' << setw(colWidth2) << priceTea[drtea[i]] << '|' << setw(colWidth2) << qtytea[i] * priceTea[drtea[i]] << endl;
        total += qtytea[i] * priceTea[drtea[i]];
    }

    for (int i = 0; i < sodaCount; ++i) {
        cout << '|' << left << setw(6) << i + 1 + teaCount << '|' << setw(colWidth2) << nameSoda[drsoda[i]] << '|' << setw(colWidth) << qtysoda[i] << '|' << setw(colWidth2) << priceSoda[drsoda[i]] << '|' << setw(colWidth2) << qtysoda[i] * priceSoda[drsoda[i]] << endl;
        total += qtysoda[i] * priceSoda[drsoda[i]];
    }

    for (int i = 0; i < coffeeCount; ++i) {
        cout << '|' << left << setw(6) << i + 1 + teaCount + sodaCount << '|' << setw(colWidth2) << nameCoffee[drcoffee[i]] << '|' << setw(colWidth) << qtycoffee[i] << '|' << setw(colWidth2) << priceCoffee[drcoffee[i]] << '|' << setw(colWidth2) << qtycoffee[i] * priceCoffee[drcoffee[i]] << endl;
        total += qtycoffee[i] * priceCoffee[drcoffee[i]];
    }
}

void cart() {
    printLine(44, numCols);
    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "quantity" << setw(30) << '|' << "Price(RM)" << setw(20) << '|' << endl;
    printLine(44, numCols);
    cart_result();
    printLine(44, numCols);
    cout << setw(50) << '|' << fixed << setprecision(2) << setw(40) << total << '|' << endl;
    cout << "wanna place order (Y/N)";
    while (true) {
        cin >> choose;
        if (choose == 'y' || choose == 'Y') {
            if (sodaCount == 0 && teaCount == 0 && coffeeCount == 0) {
                cout << "your cart is empty " << "\n";
                cout << "you wanna continue using yuki menu (Y/N) : ";
                cin >> choose;
                while (true) {
                    if (choose == 'Y' || choose == 'y') {
                        user_home();
                    }
                    else if (choose == 'N' || choose == 'n') {
                        cout << "Thank for using yuki menu ";
                        return;
                    }
                    else if (isdigit(choose)) {
                        cout << "\nNumbers are not allowed. Please enter 'y' or 'n' : ";
                    }
                    else {
                        cout << "\nInvalid choice. Please enter 'y' or 'n' : ";
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            else receipt();
        }
        else if (choose == 'n' || choose == 'N') {
            user_home();
            break;
        }
        else if (isdigit(choose)) {
            cout << "\nNumbers are not allowed. Please enter 'y' or 'n' : ";
        }
        else {
            cout << "\nInvalid choice. Please enter 'y' or 'n' : ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void user_home() {
    logo();
    while (true) {
        cout << "Our YUKI cafe is make at" << endl;//introduction to the cafe
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1.MENU" << endl;
    cout << "2.CART" << endl;
    cout << "3.QUIT" << endl;
    cout << "ENTER YOUR OPTION = ";
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
            menu();
            break;
            
        case 2:
            cart();
            break;

        case 3:
            cout << "THANK FOR USING YUKI MENU";
            return;
        }
    }
}

void menu() {
    logo();
    while (true) {
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "MENU" << endl;
        cout << "1.TEA" << endl;
        cout << "2.SODA" << endl;
        cout << "3.COFFEE" << endl;
        cout << "Which drink will you like to choose : ";
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
        case 0 :
            user_home();
            break;
        case 1:
            tea();
            break;
            //soda
        case 2:
            soda();
            break;
        case 3:
            coffee();
            break;
        }
    }
}

void tea() {
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 7; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameTea[i] << '|' << setw(colWidth) << priceTea[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink
    cout << "Enter the number drink you want : ";
    while (true) {
        if (cin >> drt) {
            if (cin.peek() == '\n' && drt >= 0 && option <= MAX_TEAS) {
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
    if (drt == 0) {
        menu();
    }
    else if (drt >= 1 && drt <= MAX_TEAS) {
        if (teaCount < MAX_DRINKS) {
            drsoda[teaCount] = drt;
            cout << "Enter the quantity of drink: ";
            cin >> qty;
            qtysoda[teaCount] = qty;
            teaCount++;
        }
        else {
            cout << "Cart is full.\n";
        }
    }
    cout << "\nYou wanna order more drink (Y/N) : ";//choose wanna order more or no
    while (true) {
        cin >> choose;

        if (choose == 'y' || choose == 'Y') {
            menu();
            break;
        }
        else if (choose == 'n' || choose == 'N') {
            cout << "PLACE ORDER (Y/N) : ";
            while (true) {
                cin >> choose;
                if (choose == 'Y' || choose == 'y') {
                    cart();
                }
                else if (choose == ' N' || choose == 'n') {
                    menu();
                    break;
                }
                else if (isdigit(choose)) {
                    cout << "\nNumbers are not allowed. Please enter 'y' or 'n'.";
                }
                else {
                    cout << "\nInvalid choice. Please enter 'y' or 'n'.";
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (isdigit(choose)) {
            cout << "\nNumbers are not allowed. Please enter 'y' or 'n'.";
        }
        else {
            cout << "\nInvalid choice. Please enter 'y' or 'n'.";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void soda() {
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 4; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameSoda[i] << '|' << setw(colWidth) << priceSoda[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink
 
        cout << "Enter the number drink you want : ";
        while (true) {
            if (cin >> drt) {
                if (cin.peek() == '\n' && drt >= 0 && option <= MAX_SODAS) {
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
        if (drt == 0) {
            menu();
        }
        else if (drt >= 1 && drt <= MAX_SODAS) {
            if (sodaCount < MAX_DRINKS) {
                drsoda[sodaCount] = drt;
                cout << "Enter the quantity of drink: ";
                cin >> qty;
                qtysoda[sodaCount] = qty;
                sodaCount++;
            }
            else {
                cout << "Cart is full.\n";
            }
        }
    cout << "\nYou wanna order more drink (Y/N) : ";//choose wanna order more or no
    while (true) {
        cin >> choose;

        if (choose == 'y' || choose == 'Y') {
            menu();
            break;
        }
        else if (choose == 'n' || choose == 'N') {
            cout << "PLACE ORDER (Y/N) : ";
            while (true) {
                cin >> choose;
                if (choose == 'Y' || choose == 'y') {
                    cart();
                }
                else if (choose == ' N' || choose == 'n') {
                    menu();
                    break;
                }
                else if (isdigit(choose)) {
                    cout << "\nNumbers are not allowed. Please enter 'y' or 'n'.";
                }
                else {
                    cout << "\nInvalid choice. Please enter 'y' or 'n'.";
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (isdigit(choose)) {
                cout << "\nNumbers are not allowed. Please enter 'y' or 'n'.";
        }
        else {
                cout << "\nInvalid choice. Please enter 'y' or 'n'.";
        }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

void coffee() {
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 5; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameCoffee[i] << '|' << setw(colWidth)<<fixed << setprecision(2) << priceCoffee[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink
    cout << "Enter the number drink you want : ";
    while (true) {
        if (cin >> drt) {
            if (cin.peek() == '\n' && drt >= 0 && option <= MAX_COFFEES) {
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
    if (drt == 0) {
        menu();
    }
    else if (drt >= 1 && drt <= MAX_COFFEES) {
        if (coffeeCount < MAX_DRINKS) {
            drsoda[coffeeCount] = drt;
            cout << "Enter the quantity of drink: ";
            cin >> qty;
            qtysoda[coffeeCount] = qty;
            coffeeCount++;
        }
        else {
            cout << "Cart is full.\n";
        }
    }
    cout << "\nYou wanna order more drink (Y/N) : ";//choose wanna order more or no
    while (true) {
        cin >> choose;

        if (choose == 'y' || choose == 'Y') {
            menu();
            break;
        }
        else if (choose == 'n' || choose == 'N') {
            cout << "PLACE ORDER (Y/N) : ";
            while (true) {
                cin >> choose;
                if (choose == 'Y' || choose == 'y') {
                    cart();
                }
                else if (choose == ' N' || choose == 'n') {
                    menu();
                    break;
                }
                else if (isdigit(choose)) {
                    cout << "\nNumbers are not allowed. Please enter 'y' or 'n'.";
                }
                else {
                    cout << "\nInvalid choice. Please enter 'y' or 'n'.";
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (isdigit(choose)) {
            cout << "\nNumbers are not allowed. Please enter 'y' or 'n'.";
        }
        else {
            cout << "\nInvalid choice. Please enter 'y' or 'n'.";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void receipt() {
    double src = total * 0.10;
    double tax = total * 0.06;
    double total_2 = total * 1.16;
    cout << "Cash,Credit Card or TNG(C,D,T) : ";
    while(true){
    cin >> choose;
    printLine(colWidth, numCols);
    cart_result();
    printLine(colWidth, numCols);
    if (choose == 'c' || choose == 'C') {
        cout << "Payment Method : Cash\n";
    }
    else if (choose == 'D' || choose == 'd') {
        cout << "Payment Method : Credit Card\n";
    }
    else if (choose == 't' || choose == 'T') {
        cout << "Payment Method : TNG\n";
    }
    else if (isdigit(choose)) {
        cout << "\nNumbers are not allowed. Please re-enter : ";
    }
    else {
        cout << "\nInvalid enter. Please re-enter : ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    cout << "Service charge(10%) : " << setprecision(2) << fixed << src << "\n";
    cout << "Tax (6%)            : " << setprecision(2) << fixed << tax << "\n";
    cout << "total payable       : " << setprecision(2) << fixed << total_2 << "\n";
    return;
}

void update_drink() {
    int option = 0;
    int price = 0;
    while (true) {
        cout << "1.tea\n";
        cout << "2.soda\n";
        cout << "3.coffee\n";
        cout << "which type of drink want to update price";
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
            printLine(colWidth, numCols);

            cout << setfill(' ') << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

            printLine(colWidth, numCols);
            for (int i = 1; i <= 7; i++) {

                cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameTea[i] << '|' << setw(colWidth) << priceTea[i] << '|' << endl;
            }

            printLine(colWidth, numCols);

            //calculate the total of the drink
            while (true) {
                cout << "Enter the number drink you want to change: ";
                while (true) {
                    if (cin >> drt) {
                        if (cin.peek() == '\n' && drt >= 1 && drt <= MAX_TEAS) {
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
                cin >> drt;
                if (drt == 0) {
                    menu();
                }
                else if (drt >= 1 && drt <= MAX_TEAS) {
                    cout << "enter the price : ";
                    cin >> price;
                    priceTea[drt] = price;
                }
            }
            break;
        case 2:
            break;
        }
    }
}

