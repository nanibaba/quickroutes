#ifndef QUICKROUTES_ROUTE_H
#define QUICKROUTES_ROUTE_H

class Route {

    int ID;
    double distanceKM;
    string startingPoint;
    string finalDestination;
    string colorCode;

public:
    Route(int ID = 0, double distanceKM = 0.0,
          string startingPoint = "",
          string finalDestination = "",
          string colorCode = "");

    int getID() const;
    double getDistanceKM() const;
    string getStartingPoint() const;
    string getFinalDestination() const;
    string getColorCode() const;

    void setID(int id);
    void setDistanceKM(double km);
    void setStartingPoint(string &sp);
    void setFinalDestination(string &fd);
    void setColorCode(string &cc);

};

Route::Route(int ID, double distanceKM,
             string startingPoint, string finalDestination,
             string colorCode) {

    this->ID = ID;
    this->distanceKM = distanceKM;
    this->startingPoint = startingPoint;
    this->finalDestination = finalDestination;
    this->colorCode = colorCode;

}

int Route::getID() const {
    return this->ID;
}

double Route::getDistanceKM() const {
    return this->distanceKM;
}

string Route::getStartingPoint() const {
    return this->startingPoint;
}

string Route::getFinalDestination() const {
    return this->finalDestination;
}

string Route::getColorCode() const {
    return this->colorCode;
}

void Route::setID(int id) {
    this->ID = id;
}

void Route::setDistanceKM(double km) {
    this->distanceKM = km;
}

void Route::setStartingPoint(string &sp) {
    this->startingPoint = sp;
}

void Route::setFinalDestination(string &fd) {
    this->finalDestination = fd;
}

void Route::setColorCode(string &cc) {
    this->colorCode = cc;
}

#endif //QUICKROUTES_ROUTE_H
