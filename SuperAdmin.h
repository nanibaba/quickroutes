#ifndef QUICKROUTES_SUPERADMIN_H
#define QUICKROUTES_SUPERADMIN_H

class SuperAdmin: public Administrator {

public:
    SuperAdmin(int ID = 0, double salary = 0.0,
                  vector<string> permissions = {
                          "update all",
                          "define permissions"
                  },
                  string name = "", string email = "");

    double getTotalSalary() const;
};

SuperAdmin::SuperAdmin(int ID, double salary,
                       vector<string> permissions,
                       string name, string email):
                       Administrator(ID, salary,
                                     permissions,
                                     name,email) {}

double SuperAdmin::getTotalSalary() const {
    return this->getSalary() + 550;
}

#endif //QUICKROUTES_SUPERADMIN_H
