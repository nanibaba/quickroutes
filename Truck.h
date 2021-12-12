#ifndef QUICKROUTES_TRUCK_H
#define QUICKROUTES_TRUCK_H

class Truck {

    int ID;
    int year;
    double load;
    vector<string> requiredLicenses;
    string make;
    string model;

public:
    Truck(int ID = 0, int year = 0, double load = 0.0,
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

Truck::Truck(int ID, int year, double load,
             vector<string> requiredLicenses,
             string make, string model) {

    this->ID = ID;
    this->year = year;
    this->load = load;
    this->requiredLicenses = requiredLicenses;
    this->make = make;
    this->model = model;

}

int Truck::getID() const {
    return this->ID;
}

int Truck::getYear() const {
    return this->year;
}

double Truck::getLoad() const {
    return this->load;
}

vector<string> Truck::getLicenses() const {
    return this->requiredLicenses;
}

string Truck::getMake() const {
    return this->make;
}

string Truck::getModel() const {
    return this->model;
}

void Truck::setID(int id) {
    this->ID = id;
}

void Truck::setYear(int y) {
    this->year = y;
}

void Truck::setLoad(double l) {
    this->load = l;
}

void Truck::setLicenses(vector<string> &rl) {
    this->requiredLicenses = rl;
}

void Truck::setMake(string &mk) {
    this->make = mk;
}

void Truck::setModel(string &ml) {
    this->model = ml;
}

#endif //QUICKROUTES_TRUCK_H
