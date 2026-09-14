#include "Hotel.h"
#include "defs.h"

Hotel::Hotel() {
  rooms = new Room*[MAX_ROOMS];
  numRooms = 0;
}

Hotel::~Hotel() {
  for (int i = 0; i < numRooms; i++) {
    delete rooms[i];
  }
  delete[] rooms;
}

bool Hotel::addRoom(int roomNumber, std::string bedType, int capacity, bool fr) {
  if (numRooms == MAX_ROOMS){
    return false;
  }

  for (int i = 0; i < numRooms; i++) {
    if (rooms[i]->getRoomNumber() == roomNumber) {
      return false;
    }
  }

  Room* newRoom = new Room(roomNumber, bedType, capacity, fr);
  rooms[numRooms] = newRoom;
  numRooms++;

  Room *temp;
  for(int i=0; i < numRooms; i++)
	{		
		for(int j=i+1; j < numRooms; j++)
		{
			if(rooms[j]->lessThan(*rooms[i])){
				temp = rooms[i];
				rooms[i] = rooms[j];
				rooms[j] = temp;
			}
		}
	}

  return true;
}

bool Hotel::deleteRoom(int roomNumber) {
  for (int i = 0; i < numRooms; i++) {
    if (rooms[i]->getRoomNumber() == roomNumber) {
      delete rooms[i];
      for (int j = i; j < numRooms - 1; j++) {
        rooms[j] = rooms[j + 1];
      }
      numRooms--;
      return true;
    }
  }
  return false;
}

bool Hotel::getRoom(int roomNumber, Room** room) {
  for (int i = 0; i < numRooms; i++) {
    if (rooms[i]->getRoomNumber() == roomNumber) {
      *room = rooms[i];
      return true;
    }
  }
  return false;
}

bool Hotel::addReservation(std::string customer, std::string bedType, int capacity, bool fr, Date& date, int duration) {
  for (int i = 0; i < numRooms; i++) {
    if (rooms[i]->isMatch(bedType, capacity, fr) &&
        rooms[i]->addReservation(customer, date, duration)) {
      return true;
    }
  }
  return false;
}

void Hotel::updateReservations(Date& currentDate) {
  for (int i = 0; i < numRooms; i++) {
    rooms[i]->updateReservations(currentDate);
  }
}

void Hotel::print() {
    for (int i = 0; i < numRooms; i++) {
        rooms[i]->print();
    }
}

void Hotel::printReservations() {
    print();
    for (int i = 0; i < numRooms; i++) {
        rooms[i]->printReservations();
    }
}