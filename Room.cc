#include "Room.h"
#include "defs.h"

Room::Room(int roomNumber, std::string bedType, int capacity, bool hasFridge){
  this->roomNumber = roomNumber;
  this->bedType = bedType;
  this->capacity = capacity;
  this->hasFridge = hasFridge;
  numReservations = 0;

  // Initialize all Reservation pointers to nullptr
  for (int i = 0; i < MAX_RES; i++) {
    reservations[i] = nullptr;
  }
}

Room::~Room() {
    for (int i = 0; i < numReservations; i++) {
        delete reservations[i];
    }
}

int Room::getRoomNumber() {
  return roomNumber;
}

bool Room::isMatch(std::string bt, int cap, bool f) {
  if (bedType != bt) {
    return false;
  }
  if (capacity < cap) {
    return false;
  }
  if (f && !hasFridge) {
    return false;
  }
  return true;
}

bool Room::lessThan(Room& r) {
  return roomNumber < r.roomNumber;
}

bool Room::addReservation(std::string customerName, Date& d, int duration) {
  if (numReservations == MAX_RES) {
    return false;
  }
  Reservation* newReservation = new Reservation(customerName, d, duration);
  for (int i = 0; i < numReservations; i++) {
    if (newReservation->overlaps(*reservations[i])) {
      delete newReservation;
      return false;
    }
  }
  int i = 0;
  while (i < numReservations && reservations[i]->lessThan(*newReservation)) {
    i++;
  }
  for (int j = numReservations; j > i; j--) {
    reservations[j] = reservations[j - 1];
  }
  reservations[i] = newReservation;
  numReservations++;
  return true;
}

void Room::updateReservations(Date& currentDate) {
  int i = 0;
  while (i < numReservations) {
    if (reservations[i]->lessThan(currentDate)) {
      // Shift all remaining reservations to fill the gap left by the deleted reservation
      for (int j = i; j < numReservations - 1; j++) {
        reservations[j] = reservations[j + 1];
      }
      numReservations--;
    } else {
      i++;
    }
  }
}

void Room::print() {
  cout << "Room " << roomNumber << ": " << bedType << ", " << capacity << ", " << hasFridge << endl;
}

void Room::printReservations() {
  print();
  cout << "Reservations:" << endl;
  for (int i = 0; i < numReservations; i++) {
    cout << "  ";
    reservations[i]->print();
  }
}