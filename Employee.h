#ifndef QUICKROUTES_EMPLOYEE_H
#define QUICKROUTES_EMPLOYEE_H

class Employee {

    int ID;
    double salary;
    vector<string> permissions;
    string name;
    string email;

public:
    Employee(int ID = 0, double salary = 0.0,
             vector<string> permissions = {
            "view employees"
            },
             string name = "", string email = "");

    int getID() const;
    double getSalary() const;
    virtual double getTotalSalary() const;
    vector<string> getPermissions() const;
    string getName() const;
    string getEmail() const;
    static bool isValidPermission(vector<string> &newPerm, vector<string> &validPerm);
    void setID(int id);
    void setSalary(double s);
    virtual void setPermissions(vector<string> &newPerm, vector<string> &validPerm);
    void setName(string n);
    void setEmail(string e);

};

Employee::Employee(int ID, double salary,
                   vector<string> permissions,
                   string name, string email) {

    this->ID = ID;
    this->salary = salary;
    this->permissions = permissions;
    this->name = name;
    this->email = email;

}

int Employee::getID() const {
    return this->ID;
}

double Employee::getSalary() const {
    return this->salary;
}

double Employee::getTotalSalary() const {
    return this->salary + 150;
}

vector<string> Employee::getPermissions() const {
    return this->permissions;
}

string Employee::getName() const {
    return this->name;
}

string Employee::getEmail() const {
    return this->email;
}

bool Employee::isValidPermission(vector<string> &newPerm, vector<string> &validPerm) {

    for (int i = 0; i < validPerm.size(); i++) {

        if (!count(newPerm.begin(), newPerm.end(), validPerm[i]))

            return false;

    }

    return true;

}

void Employee::setID(int id) {
    this->ID = id;
}

void Employee::setSalary(double s) {
    this->salary = s;
}

void Employee::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    if (count(newPerm.begin(), newPerm.end(), "view employees"))

        this->permissions = newPerm;

}

void Employee::setName(string n) {
    this->name = n;
}

void Employee::setEmail(string e) {
    this->email = e;
}

#endif //QUICKROUTES_EMPLOYEE_H
