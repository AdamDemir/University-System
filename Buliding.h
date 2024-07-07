/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#ifndef ASSIGNMENT2_BULIDING_H
#define ASSIGNMENT2_BULIDING_H

#include "Room.h"

class Buliding {
private:
    char *Name;
    Room *roomNo[100];
    int size;
    int roomNum;

public:
    Buliding();

    Buliding(char *name, int size);
    ~Buliding();
    Buliding(const Buliding& buliding);
    Buliding &operator=(const Buliding &buliding) ;

    void setName(char *name);

    char *getName();

    void setSize(int size);

    int getSize();

    int getRoomNO();


    void addRoom();

    void printBuilding();

    void printRooms();

    void printRoomsByType(int type);

    int getNumberOfClassrooms();

    int getTotalCapacity();

    int getNumberOfOffices();

    void printAvailableOffices();

    void printSuitableClassrooms(int studentNo);
};

#endif //ASSIGNMENT2_BULIDING_H
