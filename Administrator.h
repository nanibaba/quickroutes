#ifndef QUICKROUTES_ADMINISTRATOR_H
#define QUICKROUTES_ADMINISTRATOR_H

class Administrator: public Employee {

public:
Administrator(int ID = 0, double salary = 0.0,
                  vector<string> permissions = {
                  "view employees"
                  },
                  string name = "", string email = "");

    double getTotalSalary() const;
    void setPermissions(vector<string> &newPerm, vector<string> &validPerm);
};

Administrator::Administrator(int ID, double salary,
                             vector<string> permissions, string name,
                             string email):
                             Employee(ID, salary,permissions,
                                      name,email){}

double Administrator::getTotalSalary() const {
    return this->getSalary() + 150;
}

void Administrator::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    if (!newPerm.empty() && this->isValidPermission(newPerm, validPerm))

        this->setPermissions(newPerm, validPerm);

}

#endif //QUICKROUTES_ADMINISTRATOR_H
