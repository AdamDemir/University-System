/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "Room.h"
#include "string.h"
#include "iostream"

using namespace std;

Room::Room() {
    this->Name = new char[81];
    strcpy(this->Name, "Undefined");
    this->floorNum = -1;
    this->roomType = 0;
}

Room::Room(char *name, int floor, int given_type) {
    this->Name = new char[81];
    strcpy(this->Name, name);
    this->floorNum = floor;
    if (given_type == 1 || given_type == 2) {
        this->roomType = given_type;
    } else {
        this->roomType = 0;
    }
}

Room::~Room() {
    cout << "\n Room destuctor has been called\n";
    delete[] this->Name;
}

Room::Room(const Room &room) {
    this->Name = room.Name;
    this->roomType =room.roomType;
    this->floorNum =room.floorNum;
}

int Room::getCapacity() {
    return 0;
}

int Room::isFull() {
    cout << "original isFull() is called" << endl;
    return 0;
}

int Room::checkSuitability(int capacity) {}


void Room::setName(char *name) {
    if (name != nullptr) {
        strcpy(this->Name, name);
    }
}

void Room::setType(int type) {
    this->roomType = type;
}

char *Room::getName() {
    return this->Name;
}

int Room::getType() {
    return this->roomType;
}

void Room::setFloorNum(int floorNumm) {
    this->floorNum = floorNumm;
}


void Room::printRoom() {
    cout << "The general printRoom() has been called" << endl;
}