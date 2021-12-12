#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

enum Condition {isNew, refurbished};
enum driverType {truckSupervisor, vanSupervisor};

#include "Product.h"
#include "Complaint.h"
#include "Route.h"
#include "Van.h"
#include "Truck.h"
#include "Employee.h"
#include "Administrator.h"
#include "SuperAdmin.h"
#include "Manager.h"
#include "Clerk.h"
#include "Driver.h"
#include "Delivery.h"
#include "Supervisor.h"
#include "TruckDriver.h"
#include "VanDriver.h"

template <class Entity>

void mergeSort(vector<Entity *>& a, vector<Entity *>& tmpArray,
               int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

template <class Entity>

void mergeSort(vector<Entity *>& a) {
    vector<Entity *> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

template <class Entity>

void merge(vector<Entity *>& a, vector<Entity *>& tmpArray,
           int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd)   // Main loop

        if (a[leftPos]->getTotalSalary() >= a[rightPos]->getTotalSalary())
            tmpArray[tmpPos++] = a[leftPos++];
        else
            tmpArray[tmpPos++] = a[rightPos++];

    while (leftPos <= leftEnd)   // Copy rest of first half
        tmpArray[tmpPos++] = a[leftPos++];

    while (rightPos <= rightEnd)   // Copy rest of right half
        tmpArray[tmpPos++] = a[rightPos++];

    for (int i = 0; i < numElements; i++, rightEnd--)   // Copy tmpArray back
        a[rightEnd] = tmpArray[rightEnd];
}

// A utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(const char *str, int size, int badchar[256]) {
    int i;

// Initialize all occurrences as -1
    for (i = 0; i < 256; i++)
        badchar[i] = -1;

// Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

int search(const char *txt, const char *pat) {

    int count = 0;

    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[256];

    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {

            count ++;

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }

// Returns the number of times the pattern appears in the text

    return count;

}

void fetchEntity (const vector<string> &text, const char entity[],
                  vector<string> &entities) {

    int i = 0, count = 0;
    const char *pat = entity;
    string objects;
    string object;

    while (count == 0) {

        if (i < text.size()) {

            const char *txt = text[i].c_str();

            count = search(txt, pat);

            if (count == 0) i++;

        }

        else count = -1;

    }

    if (count > 0) {

        objects = text[i].substr(text[i].find('[') + 1);

        for (int j = 0; j < objects.length(); j++) {

            if (objects[j] != ';' && objects[j] != ']')

                object += objects[j];

            else {

                entities.push_back(object);

                object = "";

                if (objects[j] == ';') j++;

            }

        }

    }

    else cout << "No such entity found" << endl;
}

void resetDBText(ifstream &ins, vector<string> &text, string &line) {

    if (!text.empty()) text.clear();

    while (getline(ins, line)) {

        text.push_back(line);

    }

}

void displayEntities (string &currentPage) {

    vector <Employee*> employees;

    if (currentPage == "employees") {

       auto *superAdmin = new SuperAdmin;

       auto *vanDriver = new VanDriver;

        superAdmin->setSalary(5000);

        superAdmin->setName("Martin Mitev");

        superAdmin->setEmail("admin@admin.quickroutes.com");

        vanDriver->setSalary(3000);

        vanDriver->setName("John Smith");

        vanDriver->setEmail("john.smith@vdriver.quickroutes.com");

        employees.push_back(superAdmin);
        employees.push_back(vanDriver);

        vector <Employee*> sorted(employees.size());

        mergeSort(employees, sorted, 0, employees.size() - 1);

        for (int i = 0; i < sorted.size(); i++) {

            cout << sorted[i]->getName() << endl;

        }

        delete superAdmin;
        delete vanDriver;

    }

}

void viewCategory(string &viewPage, string &updatePage,
                  string &updateAll, string &currentPage,
                  vector<string> &userPermissions, vector<string> &categories,
                  vector<string> &text, vector <string> &entities) {

    string selectedPage;

    cout << "Enter a page in the format <page>:";

    cin >> selectedPage;

    viewPage = "view ";

    updatePage = "update ";

    viewPage += selectedPage;

    updatePage += selectedPage;

    if (count(userPermissions.begin(), userPermissions.end(),
              viewPage) ||
        count(userPermissions.begin(), userPermissions.end(),
              updatePage) ||
        count(userPermissions.begin(), userPermissions.end(),
              updateAll) || selectedPage == "home") {

        if (count(categories.begin(), categories.end(),
                  selectedPage)) {

            currentPage = selectedPage;

            string category = "Category(" + currentPage + ")";

            char *selection = new char[category.length() + 1];

            strcpy(selection, category.c_str());

            fetchEntity(text, selection, entities);

            displayEntities(currentPage);

            delete[] selection;

        }

        else cout << "This page doesn't exist" << endl;

    }

    else cout << "Not Authorized To Access This Page" << endl;

}

template <class Object>
void selectAction (ifstream &ins, vector<string> &text,
                   string &line, bool &isLoggedIn,
                   Object *user) {

    string currentPage = "home";
    string selectedAction;
    string viewPage = "view ";
    string updatePage = "update ";
    string updateAll = "update all";
    vector<string> categories;
    vector<string> entities;
    vector<string> userPermissions = user->getPermissions();

    fetchEntity(text, "Categories", categories);

    do {

        cout << "This is the " << currentPage << " page. To continue, "
             << "type an action (view, logout)" << endl;

        cout << "Action:"; cin >> selectedAction;

        if (selectedAction == "logout") {

            isLoggedIn = false;

            ins.close();

        }

        else if (selectedAction == "view")

            viewCategory(viewPage, updatePage,
                         updateAll, currentPage,
                         userPermissions, categories,
                         text, entities);

        else cout << "Invalid action!" << endl;

    }

    while (isLoggedIn);

    delete user;

}

int main() {

    ifstream ins;
    vector<string> text;
    vector<string> users;
    bool isLoggedIn = false;
    string line;
    string username;

    ins.open("../db.txt");

    if (ins.fail()) {

        cout << "Error opening file" << endl;

        return -1;

    }

    resetDBText(ins, text, line);

    fetchEntity(text, "Users", users);

    do {

        cout << "Enter your username:";
        cin >> username;

        isLoggedIn = count(users.begin(),  users.end(), username);

        if (isLoggedIn)

            cout << "Welcome, " << username << endl;

        else

            cout << "Wrong username!" << endl;

    }

    while (!isLoggedIn);

    if (username.find("@admin") != string::npos){

        auto *loggedUser = new SuperAdmin;

        selectAction(ins, text, line, isLoggedIn, loggedUser);

    }

    else if (username.find("@clerk") != string::npos){

        auto *loggedUser = new Clerk;

        selectAction(ins, text, line, isLoggedIn, loggedUser);

    }

    else if (username.find("@manager") != string::npos){

        auto *loggedUser = new Manager;

        selectAction(ins, text, line, isLoggedIn, loggedUser);

    }

    else if (username.find("@supervisor") != string::npos){

        auto *loggedUser = new Supervisor;

        selectAction(ins, text, line, isLoggedIn, loggedUser);

    }

    else if (username.find("@tdriver") != string::npos){

        auto *loggedUser = new TruckDriver;

        selectAction(ins, text, line, isLoggedIn, loggedUser);

    }

    else if (username.find("@vdriver") != string::npos){

        auto *loggedUser = new VanDriver;

        selectAction(ins, text, line, isLoggedIn, loggedUser);

    }

    else {

        auto *loggedUser = new Employee;

        selectAction(ins, text, line, isLoggedIn, loggedUser);

    }

    return 0;
}
