#ifndef QUICKROUTES_CLERK_H
#define QUICKROUTES_CLERK_H

class Clerk: public Administrator {

public:
    Clerk(int ID = 0, double salary = 0.0,
          vector<string> permissions = {
                "view employees", "update products",
                "update complaints", "update deliveries"
            },
            string name = "", string email = "");

    double getTotalSalary() const;
    void setPermissions(vector<string> &newPerm, vector<string> &validPerm);

};

Clerk::Clerk(int ID, double salary,
             vector<string> permissions,
             string name, string email):
             Administrator(ID, salary,permissions,
                           name, email) {}

double Clerk::getTotalSalary() const {
    return this->getSalary() + 300;
}

void Clerk::setPermissions(vector<string> &newPerm, vector<string> &validPerm) {

    if(!newPerm.empty() && this->isValidPermission(newPerm, validPerm))

        this->setPermissions(newPerm, validPerm);

}

#endif //QUICKROUTES_CLERK_H
