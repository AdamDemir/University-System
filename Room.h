/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#ifndef ASSIGNMENT2_ROOM_H
#define ASSIGNMENT2_ROOM_H

class Room {
protected:
    char *Name;
    int floorNum;
    int roomType;
public:
    Room();

    Room(char *name, int floor, int type);
    ~Room();
    Room(const Room& room);

    void setName(char *name);

    char *getName();

    void setType(int type);

    int getType();

    void setFloorNum(int floorNumm);

    virtual int getCapacity();

    virtual int isFull();

    virtual void printRoom();

    virtual int checkSuitability(int capacity);
};

#endif //ASSIGNMENT2_ROOM_H
