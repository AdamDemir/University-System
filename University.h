/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#ifndef ASSIGNMENT2_UNIVERSITY_H
#define ASSIGNMENT2_UNIVERSITY_H

#include "Buliding.h"

class University {
private:
    char *Name;
    Buliding *bulidingArr[20];
    int buildingNo;
public:
    University();

    University(char *name);

    University(const University &uni);

    ~University();
    University &operator =(const University& uni);

    void setName(char *name);

    char *getName();

    int getBuildingNo();

    void addBuliding();

    void addRoom();

    void printBuildings();

    void printRooms();

    void printRoomsByType(int type);

    void printRoomTypeStatistics();

    void printAvailableOffices();

    void printTotalCapacityOfOffices();

    void printSuitableClassrooms(int studentNo);
};

#endif //ASSIGNMENT2_UNIVERSITY_H
