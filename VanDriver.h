#ifndef QUICKROUTES_VANDRIVER_H
#define QUICKROUTES_VANDRIVER_H

class VanDriver: public Driver {

public:
    VanDriver(int ID = 0, double salary = 0.0,
              vector<string> permissions = {
                "view employees", "view products",
                "view routes", "view deliveries",
                "view vans"
                },
              string name = "", string email = "");

    double getTotalSalary() const;
    void setPermissions(vector<string> &newPerm, vector<string> &validPerm);
};

VanDriver::VanDriver(int ID, double salary,
                     vector<string> permissions,
                     string name, string email):
                     Driver(ID, salary,permissions,
                            name,email){}

double VanDriver::getTotalSalary() const {
    return this->getSalary() + 250;
}

void VanDriver::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    if(!newPerm.empty() && this->isValidPermission(newPerm, validPerm))

        this->setPermissions(newPerm, validPerm);

}

#endif //QUICKROUTES_VANDRIVER_H
