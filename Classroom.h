/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "Room.h"

#ifndef ASSIGNMENT2_CLASSROOM_H
#define ASSIGNMENT2_CLASSROOM_H

class Classroom : public Room {
private:
    int Capacity;
public:
    Classroom();

    Classroom(char *name,int floor, int capacity);

    void setCapacity(int capacity);

    int getCapacity() override;
    int checkSuitability(int capacity) override;

    void printRoom() override;
};

#endif //ASSIGNMENT2_CLASSROOM_H
