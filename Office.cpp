/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "Office.h"
#include "string.h"
#include "iostream"

using namespace std;

Office::Office() {
    this->Name = new char[81];
    strcpy(this->Name, "Undefined");
    this->floorNum = -1;
    this->type = None;
    this->peopleNum = 0;
}

Office::Office(char *name, int floorNo, officeType type, int peopleNum) {
    this->Name = new char[81];
    strcpy(this->Name, name);
    this->floorNum = floorNo;
    this->type = type;
    this->peopleNum = peopleNum;
}

void Office::settype(officeType typee) {
    this->type = typee;
}

officeType Office::getType() {
    return this->type;
}

void Office::setPeopleNum(int peopleNumm) {
    this->peopleNum = peopleNumm;
}

int Office::getPeopleNum() {
    return this->peopleNum;
}

int Office::getCapacity() {
    switch (this->type) {

        case None:
            return 0;
        case CoordinatorOffice :
            return 1;
        case StandardOffice:
            return 1;
        case SharedOfficeFor2People:
            return 2;
        case SharedOfficeFor3People:
            return 3;
        case SharedOfficeFor10People:
            return 10;
    }
}

int Office::isFull() {
    if (this->getCapacity() - this->getPeopleNum() <= 0) {
        return 1;
    } else return 0;
}


void Office::printRoom() {
    cout << "Office name = " << this->Name << endl;
    cout << "Office floor number = " << this->floorNum << endl;
    cout << "Office type = " << this->type << endl;
    cout << "Number of people in office = " << this->peopleNum << endl;
    cout << "Office capacity = " << this->getCapacity() << endl;
    if (!this->isFull()) {
        cout << "Office is not full" << endl;
    }
    cout<<"\n";
}