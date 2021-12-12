#ifndef QUICKROUTES_TRUCKDRIVER_H
#define QUICKROUTES_TRUCKDRIVER_H

class TruckDriver: public Driver {

public:
    TruckDriver(int ID = 0, double salary = 0.0,
           vector<string> permissions = {
                   "view employees", "view products",
                   "view routes", "view deliveries",
                   "view trucks"
           },
           string name = "", string email = "");

    double getTotalSalary() const;
    void setPermissions(vector<string> &newPerm, vector<string> &validPerm);
};

TruckDriver::TruckDriver(int ID, double salary, vector<string> permissions,
                         string name, string email):
                         Driver(ID, salary,permissions,
                                name, email){}

double TruckDriver::getTotalSalary() const {
    return this->getSalary() + 250;
}

void TruckDriver::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    if(!newPerm.empty() && this->isValidPermission(newPerm, validPerm))

        this->setPermissions(newPerm, validPerm);

}

#endif //QUICKROUTES_TRUCKDRIVER_H
