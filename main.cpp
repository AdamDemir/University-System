/* Mohamad.h Ibrahim – 2643344
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include <iostream>
#include "University.h"

using namespace std;

int main() {
    int input = 0;
    University university;
    university.setName("METU NCC");
    university.getName();
    do {
        int option = 0;
        cout << "\n[1] Add a new building to the university\n"
                "[2] Add a new room to a selected building\n"
                "[3] Print the buildings in the university\n"
                "[4] Print the rooms in each building in the university\n"
                "[5] Print the rooms in each building in the university based on type\n"
                "[6] Print the total number of classrooms and offices in the university\n"
                "[7] Print the available offices in each building in the university\n"
                "[8] Print the total capacity of all the offices\n"
                "[9] Print the suitable classrooms in the university based on the given number\n"
                "of students\n"
                "[0] Exit\n"
                "Please enter your choice: ";
        cin >> input;
        switch (input) {
            case 0:
                cout << "Thank you for using the university campus management system" << endl;
                break;
            case 1:
                university.addBuliding();
                break;
            case 2:
                university.addRoom();
                break;
            case 3:
                university.printBuildings();
                break;
            case 4:
                university.printRooms();
                break;
            case 5:
                cout << "Please enter type of room to display:\n"
                        "[1] Classrooms\n"
                        "[2] Offices" << endl;
                cin >> option;
                university.printRoomsByType(option);
                break;
            case 6:
                university.printRoomTypeStatistics();
                break;
            case 7:
                university.printAvailableOffices();
                break;
            case 8:
                university.printTotalCapacityOfOffices();
                break;
            case 9:
                cout << "Please enter number of students: ";
                cin >> option;
                university.printSuitableClassrooms(option);
                break;
            default:
                break;
        }
    } while (input != 0);
    return 0;
}
