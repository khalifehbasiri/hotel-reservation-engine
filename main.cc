#include "Hotel.h"
#include <iostream>

int main() {
    Hotel hotel;
    hotel.addRoom(101, "queen", 2, true);
    hotel.addRoom(102, "queen", 2, true);
    hotel.addRoom(201, "king", 3, false);
    Date arrival(2023, 2, 10);
    bool first = hotel.addReservation("Guest A", "queen", 2, true, arrival, 3);
    bool second = hotel.addReservation("Guest B", "queen", 2, true, arrival, 2);
    bool full = hotel.addReservation("Guest C", "queen", 2, true, arrival, 1);
    std::cout << "First booking: " << first << "\nSecond room: " << second
              << "\nThird overlapping booking rejected: " << !full << "\n";
    hotel.printReservations();
    Date checkout(2023, 2, 14);
    hotel.updateReservations(checkout);
    bool reopened = hotel.addReservation("Guest D", "queen", 2, true, checkout, 1);
    std::cout << "Booking after expiry: " << reopened << "\n";
    return first && second && !full && reopened ? 0 : 1;
}
