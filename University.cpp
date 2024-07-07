/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "University.h"
#include "Buliding.h"
#include "string.h"
#include "cstring"
#include "iostream"

using namespace std;

University::University() {
    this->Name = new char[81];
    strcpy(this->Name, "Undefined");
    this->buildingNo = 0;

}

University::~University() {
    cout << "\n University destuctor has been called\n";
    delete[] this->Name;
}


University::University(const University &uni) {
    this->Name = new char[81];
    strcpy(this->Name, uni.Name);
    this->buildingNo = uni.buildingNo;
    int count = this->buildingNo;
    for (int i = 0; i < count; ++i) {
        this->bulidingArr[i] = uni.bulidingArr[i];
    }
    cout << "Student(const Student& std) has been called!" << endl;
}

University::University(char *name) {
    this->Name = new char[81];
    strcpy(this->Name, name);
    this->buildingNo = 0;
}

University &University::operator=(const University &uni) {
    if (this == &uni){
        cout<<"Student & operator=()"<<endl;
        return *this;
    }
    delete[] this->Name;
    this->Name = new char[81];
    strcpy(this->Name,uni.Name);
    this->buildingNo = uni.buildingNo;
    for (int i = 0; i < this->buildingNo; ++i) {
        this->bulidingArr[i] = uni.bulidingArr[i];
    }

    cout<<"\nUniveristy assignment operator is called\n";
    return *this;
}

void University::setName(char *name) {
    if (name != nullptr) {
        strcpy(this->Name, name);
    }
}

char *University::getName() {
    return this->Name;
}

int University::getBuildingNo() {
    return this->buildingNo;
}

void University::addBuliding() {
    int bulidingSize;
    char *buildingName;
    buildingName = new char[81];
    cout << "Please enter name of building: ";
    cin >> buildingName;
    cout << "Please enter size of building: ";
    cin >> bulidingSize;
    this->bulidingArr[this->buildingNo] = new Buliding(buildingName, bulidingSize);
    this->buildingNo++;
}

void University::addRoom() {
    int BuildingNumber;
    cout << "Buildings in METU NCC university: " << endl;
    printBuildings();
    cout << "Please enter the number of building to which the room should be added: " << endl;
    cin >> BuildingNumber;
    bulidingArr[BuildingNumber - 1]->addRoom();
}

void University::printBuildings() {
    for (int i = 0; i < this->buildingNo; ++i) {
        cout << "[" << i + 1 << "] ";
        this->bulidingArr[i]->printBuilding();
    }
}

void University::printRooms() {
    cout << "Rooms in METU NCC university: " << endl;
    for (int i = 0; i < this->buildingNo; ++i) {
        cout << "All rooms in " << this->bulidingArr[i]->getName() << " building:" << endl;
        this->bulidingArr[i]->printRooms();
        cout << "\n";
    }
}

void University::printRoomsByType(int type) {
    if (type == 1) {
        cout << "Classrooms in METU NCC university: " << endl;
        for (int i = 0; i < this->buildingNo; ++i) {
            cout << "All Classrooms in " << this->bulidingArr[i]->getName() << " building:" << endl;
            this->bulidingArr[i]->printRoomsByType(1);
        }
    } else if (type == 2) {
        cout << "Offices in METU NCC university: " << endl;
        for (int i = 0; i < this->buildingNo; ++i) {
            cout << "All Offices in " << this->bulidingArr[i]->getName() << " building:" << endl;
            this->bulidingArr[i]->printRoomsByType(2);
        }
    } else {
        cout << "the number given is invalid" << endl;
    }

}

void University::printRoomTypeStatistics() {
    int officesNo = 0;
    int classroomsNo = 0;
    cout << "Room Type statistics for METU NCC university:" << endl;
    for (int i = 0; i < this->buildingNo; ++i) {
        officesNo += this->bulidingArr[i]->getNumberOfOffices();
        classroomsNo += this->bulidingArr[i]->getNumberOfClassrooms();
    }
    cout << "Number of offices = " << officesNo << endl;
    cout << "Number of classrooms = " << classroomsNo << endl;
}

void University::printAvailableOffices() {
    cout << "Available offices in METU NCC university: " << endl;
    for (int i = 0; i < this->buildingNo; ++i) {
        cout << "Available offices in " << this->bulidingArr[i]->getName() << " building:\n";
        this->bulidingArr[i]->printAvailableOffices();
    }
}

void University::printTotalCapacityOfOffices() {
    cout << "Office capacity in METU NCC university: " << endl;
    for (int i = 0; i < this->buildingNo; ++i) {
        cout << "Office capacity in " << this->bulidingArr[i]->getName() << " building = "
             << this->bulidingArr[i]->getTotalCapacity() << endl;
    }

}

void University::printSuitableClassrooms(int studentNo) {
    cout << "Suitable classes in METU NCC university for " << studentNo << " students: " << endl;
    for (int i = 0; i < this->buildingNo; ++i) {
        cout << "Classrooms which are suitable for " << studentNo << " students in " << this->bulidingArr[i]->getName()
             << " building: "
             << endl;
        this->bulidingArr[i]->printSuitableClassrooms(studentNo);
        cout << "\n";
    }
}