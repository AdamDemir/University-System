/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */


#include "Room.h"

#ifndef ASSIGNMENT2_OFFICE_H
#define ASSIGNMENT2_OFFICE_H
enum officeType {
    None,
    CoordinatorOffice,
    StandardOffice,
    SharedOfficeFor2People,
    SharedOfficeFor3People,
    SharedOfficeFor10People
};
class Office : public Room {

private:
    officeType type;
    int peopleNum;
public:
    Office();

    Office(char *name, int floorNo, officeType type, int peopleNum);

    void settype(officeType typee);

    officeType getType();

    void setPeopleNum(int peopleNumm);

    int getPeopleNum();

    int isFull() override;

    int getCapacity() override;
    void printRoom() override;
};

#endif //ASSIGNMENT2_OFFICE_H
