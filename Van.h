#ifndef QUICKROUTES_VAN_H
#define QUICKROUTES_VAN_H

class Van {

    int ID;
    int year;
    double load;
    vector<string> requiredLicenses;
    string make;
    string model;

public:
    Van(int ID = 0, int year = 0, double load = 0.0,
          vector<string> requiredLicenses = {},
          string make = "", string model = "");

    int getID() const;
    int getYear() const;
    double getLoad() const;
    vector<string> getLicenses() const;
    string getMake() const;
    string getModel() const;

    void setID(int id);
    void setYear(int y);
    void setLoad(double l);
    void setLicenses(vector<string> &rl);
    void setMake(string &mk);
    void setModel(string &ml);


};

Van::Van(int ID, int year, double load,
         vector<string> requiredLicenses, string make, string model) {

    this->ID = ID;
    this->year = year;
    this->load = load;
    this->requiredLicenses = requiredLicenses;
    this->make = make;
    this->model = model;

}

int Van::getID() const {
    return this->ID;
}

int Van::getYear() const {
    return this->year;
}

double Van::getLoad() const {
    return this->load;
}

vector<string> Van::getLicenses() const {
    return this->requiredLicenses;
}

string Van::getMake() const {
    return this->make;
}

string Van::getModel() const {
    return this->model;
}

void Van::setID(int id) {
    this->ID = id;
}

void Van::setYear(int y) {
    this->year = y;
}

void Van::setLoad(double l) {
    this->load = l;
}

void Van::setLicenses(vector<string> &rl) {
    this->requiredLicenses = rl;
}

void Van::setMake(string &mk) {
    this->make = mk;
}

void Van::setModel(string &ml) {
    this->model = ml;
}

#endif //QUICKROUTES_VAN_H
