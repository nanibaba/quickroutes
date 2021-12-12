#ifndef QUICKROUTES_DRIVER_H
#define QUICKROUTES_DRIVER_H

class Driver: public Employee {

public:
    Driver(int ID = 0, double salary = 0.0,
                  vector<string> permissions = {
                  "view employees", "view products",
                  "view routes", "view deliveries"
                  },
                  string name = "", string email = "");

    double getTotalSalary() const;
    void setPermissions(vector<string> &newPerm, vector<string> &validPerm);
};

Driver::Driver(int ID, double salary,
               vector<string> permissions, string name,
               string email):
               Employee(ID, salary,permissions,
         name, email) {}

double Driver::getTotalSalary() const {
    return this->getSalary() + 150;
}

void Driver::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    if(!newPerm.empty() && this->isValidPermission(newPerm, validPerm))

        this->setPermissions(newPerm, validPerm);

}

#endif //QUICKROUTES_DRIVER_H
