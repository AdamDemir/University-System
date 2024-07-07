/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "Classroom.h"
#include "string.h"
#include "iostream"

using namespace std;

Classroom::Classroom() {
    this->Name = new char[81];
    strcpy(this->Name, "Undefined");
    this->floorNum = -1;
    this->Capacity = -1;

}

Classroom::Classroom(char *name, int floor, int capacity) {
    this->Name = new char[81];
    strcpy(this->Name, name);
    this->floorNum = floor;
    this->Capacity = capacity;

}

void Classroom::setCapacity(int capacity) {
    this->Capacity = capacity;
}

int Classroom::getCapacity() {
    return this->Capacity;
}

int Classroom::checkSuitability(int capacity){
    if (this->Capacity >= capacity){
        return 1;
    } else{
        return 0;
    }
}

void Classroom::printRoom() {
    cout << "Classroom name = " << this->Name << endl;
    cout << "Classroom floor number = " << this->floorNum << endl;
    cout << "Classroom capacity = " << this->Capacity << endl;
    cout<<"\n";


}