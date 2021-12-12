#ifndef QUICKROUTES_DELIVERY_H
#define QUICKROUTES_DELIVERY_H

class Delivery {

    int ID;
    vector<Product *> products;
    vector<Route *> routes;
    vector<Complaint *> complaints;
    Driver* driver;
    string title;
    string description;
    string rating;

public:
    Delivery(int ID = 0, vector<Product *> products = {},
             vector<Route *> routes = {},
             vector<Complaint *> complaints = {},
             Driver* driver = new Driver(),
             string title = "", string description = "",
             string rating = "");

    int getID() const;
    vector<Product *> getProducts() const;
    vector<Route *> getRoutes() const;
    vector<Complaint *> getComplaints() const;
    string getDriver() const;
    string getTitle() const;
    string getDescription() const;
    string getRating() const;

    void setID(int id);
    void setProducts(vector<Product *> &p);
    void setRoutes(vector<Route *> &r);
    void setComplaints(vector<Complaint *> &c);
    void setDriver(Driver* dr);
    void setTitle(string &t);
    void setDescription(string &d);
    void setRating(string &rg);
};

Delivery::Delivery(int ID, vector<Product *> products,
                   vector<Route *> routes, vector<Complaint *> complaints,
                   Driver *driver, string title,
                   string description, string rating) {

    this->ID = ID;
    this->products = products;
    this->routes = routes;
    this->complaints = complaints;
    this->driver = driver;
    this->title = title;
    this->description = description;
    this->rating = rating;

}

int Delivery::getID() const {
    return this->ID;
}

vector<Product *> Delivery::getProducts() const {
    return this->products;
}

vector<Route *> Delivery::getRoutes() const {
    return this->routes;
}

vector<Complaint *> Delivery::getComplaints() const {
    return this->complaints;
}

string Delivery::getDriver() const {
    return this->driver->getName();
}

string Delivery::getTitle() const {
    return this->title;
}

string Delivery::getDescription() const {
    return this->description;
}

string Delivery::getRating() const {
    return this->rating;
}

void Delivery::setID(int id) {
    this->ID = id;
}

void Delivery::setProducts(vector<Product *> &p) {
    this->products = p;
}

void Delivery::setRoutes(vector<Route *> &r) {
    this->routes = r;
}

void Delivery::setComplaints(vector<Complaint *> &c) {
    this->complaints = c;
}

void Delivery::setDriver(Driver *dr) {
    this->driver = dr;
}

void Delivery::setTitle(string &t) {
    this->title = t;
}

void Delivery::setDescription(string &d) {
    this->description = d;
}

void Delivery::setRating(string &rg) {
    this->rating = rg;
}

#endif //QUICKROUTES_DELIVERY_H
