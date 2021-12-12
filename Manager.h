#ifndef QUICKROUTES_MANAGER_H
#define QUICKROUTES_MANAGER_H

class Manager: public Administrator {

public:
    Manager(int ID = 0, double salary = 0.0,
               vector<string> permissions = {
                "update all"
               },
               string name = "", string email = "");

    double getTotalSalary() const;
    void setPermissions(vector<string> &newPerm, vector<string> &validPerm);
};

Manager::Manager(int ID, double salary,
                 vector<string> permissions,
                 string name, string email):
                 Administrator(ID, salary,permissions,
                               name, email) {}

double Manager::getTotalSalary() const {
    return this->getSalary() + 450;
}

void Manager::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    if(!newPerm.empty() && this->isValidPermission(newPerm, validPerm))

        this->setPermissions(newPerm, validPerm);

}

#endif //QUICKROUTES_MANAGER_H
