/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "University.h"
#include "Buliding.h"
#include "string.h"
#include "iostream"
#include "Office.h"
#include "Classroom.h"

using namespace std;

Buliding::Buliding() {
    this->Name = new char[81];
    strcpy(this->Name, "Undefined");
    this->size = -1;
    this->roomNum = 0;
}

Buliding::Buliding(char *name, int size) {
    this->Name = new char[81];
    strcpy(this->Name, name);
    this->size = size;
    this->roomNum = 0;
}
Buliding::~Buliding(){
    cout<<"\nBuliding destuctor has been called\n";
    delete[] this->Name;
}
Buliding::Buliding(const Buliding &buliding) {
    this->Name = new char[81];
    strcpy(this->Name,buliding.Name);
    this->size = buliding.size;
    this->roomNum =buliding.roomNum;
    for (int i = 0; i < this->roomNum; ++i) {
        this->roomNo[i] = buliding.roomNo[i];
    }
}

Buliding & Buliding::operator=(const Buliding &buliding) {
    if (this == &buliding){
        cout<<"Student & operator=()"<<endl;
        return *this;
    }
    delete[] this->Name;
    this->Name = new char[81];
    strcpy(this->Name,buliding.Name);
    this->roomNum = buliding.roomNum;
    for (int i = 0; i < this->roomNum; ++i) {
        this->roomNo[i] = buliding.roomNo[i];
    }

    cout<<"\n Buliding assignment operator is called\n";
    return *this;
}

void Buliding::setName(char *name) {
    if (name != nullptr) {
        strcpy(this->Name, name);
    }
}


void Buliding::setSize(int given_size) {
    this->size = given_size;
}

char *Buliding::getName() {
    return this->Name;
}

int Buliding::getSize() {
    return this->size;
}

int Buliding::getRoomNO() {
    return this->roomNum;
}

void Buliding::addRoom() {
    int roomType, floorNum, officeTypeInt, peopleInOffice, capacity;
    char *roomName;
    officeType officeType;
    roomName = new char[81];
    cout << "Please enter the roomType of room(1: Classroom/ 2: Office): ";
    cin >> roomType;
    cout << "Please enter the name of the new room:";
    cin>>roomName;
    cout << "Please enter the floor number of the new room: ";
    cin >> floorNum;
    if (roomType == 1) {
        cout << "Please enter capacity of classroom: ";
        cin >> capacity;
        Classroom *classroom;
        classroom = new Classroom(roomName, floorNum, capacity);
        classroom->setType(roomType);
        this->roomNo[this->roomNum++] = classroom;
    } else if (roomType == 2) {
        cout << "[1] Coordinator Office\n"
                "[2] Standard Office\n"
                "[3] Shared Office for 2 people\n"
                "[4] Shared Office for 3 people\n"
                "[5] Shared Office for 10 people\n"
                "Please enter roomType of office: ";
        cin >> officeTypeInt;
        switch (officeTypeInt) {
            case 1:
                officeType = CoordinatorOffice;
                break;
            case 2:
                officeType = StandardOffice;
                break;
            case 3:
                officeType = SharedOfficeFor2People;
                break;
            case 4:
                officeType = SharedOfficeFor3People;
                break;
            case 5:
                officeType = SharedOfficeFor10People;
                break;
            default:
                officeType = None;
                break;
        }
        cout << "Please enter number of people in the office: ";
        cin >> peopleInOffice;
        Office *office;
        office = new Office(roomName, floorNum, officeType, peopleInOffice);
        office->setType(roomType);
        this->roomNo[this->roomNum++] = office;
    }
}

void Buliding::printBuilding() {
    cout << "Building name ="
         << this->getName() << endl;
    cout << "Building size = " << this->getSize() << endl;
    cout << "Building number of rooms = " << this->getRoomNO() << endl;
    cout << "\n";
}

void Buliding::printRooms() {
    for (int i = 0; i < this->roomNum; ++i) {
        this->roomNo[i]->printRoom();
    }
}

void Buliding::printRoomsByType(int type) {
    for (int i = 0; i < this->roomNum; ++i) {
        if (type == this->roomNo[i]->getType())
            this->roomNo[i]->printRoom();
    }
}

int Buliding::getNumberOfClassrooms() {
    int count = 0;
    for (int i = 0; i < this->roomNum; ++i) {
        if (this->roomNo[i]->getType() == 1) {
            count++;
        }
    }
    return count;
}

int Buliding::getNumberOfOffices() {
    int count = 0;
    for (int i = 0; i < this->roomNum; ++i) {
        if (this->roomNo[i]->getType() == 2) {
            count++;
        }
    }
    return count;
}

int Buliding::getTotalCapacity() {
    int count = 0;
    for (int i = 0; i < this->roomNum; ++i) {
        if (this->roomNo[i]->getType() == 2) {
            count += this->roomNo[i]->getCapacity();
        }
    }
    return count;
}


void Buliding::printAvailableOffices() {
    for (int i = 0; i < this->roomNum; ++i) {
        if (this->roomNo[i]->getType() == 2) {
            if (!roomNo[i]->isFull()) {
                this->roomNo[i]->printRoom();
            }
        }
    }
}


void Buliding::printSuitableClassrooms(int studentNo) {
    cout << "Available offices in " << this->getName() << " building:\n";
    for (int i = 0; i < this->roomNum; ++i) {
        if (this->roomNo[i]->getType() == 1) {
            if (roomNo[i]->checkSuitability(studentNo)) {
                roomNo[i]->printRoom();
            }
        }
    }
}