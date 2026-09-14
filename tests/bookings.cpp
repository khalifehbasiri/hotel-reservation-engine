#include "Hotel.h"
#include <iostream>

int main() {
    Hotel h;
    if (!h.addRoom(101, "queen", 2, true)) return 1;
    if (h.addRoom(101, "queen", 2, true)) return 2;
    if (!h.addRoom(102, "queen", 2, true)) return 3;
    Date arrival(2023, 2, 10), overlap(2023, 2, 11), later(2023, 2, 15);
    if (!h.addReservation("Guest A", "queen", 2, true, arrival, 3)) return 4;
    if (!h.addReservation("Guest B", "queen", 2, true, overlap, 2)) return 5;
    if (h.addReservation("Guest C", "queen", 2, true, overlap, 1)) return 6;
    if (h.addReservation("Too many guests", "queen", 4, true, arrival, 1)) return 7;
    h.updateReservations(later);
    if (!h.addReservation("Guest D", "queen", 2, true, later, 1)) return 8;
    if (!h.deleteRoom(102) || h.deleteRoom(102)) return 9;
    std::cout << "PASS: duplicate rooms, alternative-room booking, overlap, capacity, expiry, deletion\n";
    return 0;
}
