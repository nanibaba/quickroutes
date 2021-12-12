#ifndef QUICKROUTES_COMPLAINT_H
#define QUICKROUTES_COMPLAINT_H

class Complaint {

    int ID;
    string title;
    string description;

public:
    Complaint(int ID = 0, string title = "",
            string description = "");

    int getID() const;
    string getTitle() const;
    string getDescription() const;

    void setID(int id);
    void setTitle(string &t);
    void setDescription(string &d);
};

Complaint::Complaint(int ID, string title, string description) {

    this->ID = ID;
    this->title = title;
    this->description = description;

}

int Complaint::getID() const {
    return this->ID;
}

string Complaint::getTitle() const {
    return this->title;
}

string Complaint::getDescription() const {
    return this->description;
}

void Complaint::setID(int id) {

    this->ID = id;

}

void Complaint::setTitle(string &t) {

    this->title = t;

}

void Complaint::setDescription(string &d) {

    this->description = d;

}

#endif //QUICKROUTES_COMPLAINT_H
