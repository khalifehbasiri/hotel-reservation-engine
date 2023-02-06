#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include "Room.h"
#include "Date.h"

class Hotel {
  public:
    Hotel();
    ~Hotel();
    bool addRoom(int roomNumber, std::string bedType, int capacity, bool fr);
    bool deleteRoom(int roomNumber);
    bool getRoom(int roomNumber, Room** room);
    bool addReservation(std::string customer, std::string bedType, int capacity, bool fr, Date& date, int duration);
    void updateReservations(Date& currentDate);
    void print();
    void printReservations();

  private:
    Room** rooms;
    int numRooms;
};

#endif