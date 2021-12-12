#ifndef QUICKROUTES_PRODUCT_H
#define QUICKROUTES_PRODUCT_H

class Product {

    int ID;
    double price;
    Condition condition;
    string name;
    string deliveryTime;

public:
    Product(int ID = 0, Condition condition = isNew,
            string name = "", string deliveryTime = "");

    int getID() const;
    double getPrice() const;
    double getTotalPrice() const;
    Condition getCondition() const;
    string getName() const;
    string getDeliveryTime() const;

    void setID(int id);
    void setPrice(double p);
    void setCondition(Condition c);
    void setName(string &n);
    void setDeliveryTime(string &dt);
};

Product::Product(int ID, Condition condition,
                 string name, string deliveryTime) {

    this->ID = ID;
    this->condition = condition;
    this->name = name;
    this->deliveryTime = deliveryTime;

}

int Product::getID() const {
    return this->ID;
}

double Product::getPrice() const {
    return this->price;
}

double Product::getTotalPrice() const {

    if (this->getCondition() == isNew)

        return this->getPrice();

    return this->getPrice() * 0.5;

}

Condition Product::getCondition() const {
    return this->condition;
}

string Product::getName() const {
    return this->name;
}

string Product::getDeliveryTime() const {
    return this->deliveryTime;
}

void Product::setID(int id) {
    this->ID = id;
}

void Product::setPrice(double p) {
    this->price = p;
}

void Product::setCondition(Condition c) {
    this->condition = c;
}

void Product::setName(string &n) {
    this->name = n;
}

void Product::setDeliveryTime(string &dt) {
    this->deliveryTime = dt;
}

#endif //QUICKROUTES_PRODUCT_H
