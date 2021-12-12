#ifndef QUICKROUTES_SUPERVISOR_H
#define QUICKROUTES_SUPERVISOR_H

class Supervisor: public Driver {

driverType type;

public:
    Supervisor(int ID = 0, double salary = 0.0,
              vector<string> permissions = {
              "view employees", "view routes",
              "view trucks", "update products",
              "update complaints", "update deliveries"
              },
              string name = "", string email = "",
              driverType type = truckSupervisor);

    driverType getType() const;
    void setType(driverType t);
    double getTotalSalary() const;
    void setPermissions(vector<string> &newPerm, vector<string> &validPerm);
};

Supervisor::Supervisor(int ID, double salary,
                       vector<string> permissions, string name,
                       string email, driverType type):
                       Driver(ID, salary,permissions,
                              name, email){

    this->type = type;

}

driverType Supervisor::getType() const {
    return this->type;
}

void Supervisor::setType(driverType t) {

    this->type = t;

}

double Supervisor::getTotalSalary() const {
    return this->getSalary() + 400;
}

void Supervisor::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    vector<string> validPermissions;

    if (this->type == truckSupervisor)

        validPermissions = validPerm;

    else if (this->type == vanSupervisor) {

        validPermissions = {
        "view employees", "view routes",
        "view vans", "update products",
        "update complaints", "update deliveries"
        };

    }

    if (!newPerm.empty() && this->isValidPermission(newPerm, validPermissions))

        this->setPermissions(newPerm, validPermissions);

}

#endif //QUICKROUTES_SUPERVISOR_H
