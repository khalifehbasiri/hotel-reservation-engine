#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "Reservation.h"
#include "defs.h"

using namespace std;

class Room {
  public:
    Room(int roomNumber, std::string bedType, int capacity, bool hasFridge);
    ~Room();
    int getRoomNumber();
    bool isMatch(std::string bt, int cap, bool f);
    bool lessThan(Room& r);
    bool addReservation(std::string customerName, Date& d, int duration);
    void updateReservations(Date& currentDate);
    void print();
    void printReservations();

  private:
    int roomNumber;
    std::string bedType;
    int capacity;
    bool hasFridge;
    Reservation* reservations[MAX_RES];
    int numReservations;
};

#endif
