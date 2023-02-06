#include "Reservation.h"

Reservation::Reservation(std::string customerName, Date& checkIn, int duration){ 
	this->customerName = customerName;
    this->checkIn = checkIn;
    this->duration = duration;
}

void Reservation::setDuration(int duration) {
	if (duration < 1) {
		duration = 1;
	}
	this->duration = duration;
}

bool Reservation::overlaps(Reservation& r) {
	Date r1end = checkIn;
	r1end.addDays(duration - 1);
	Date r2end = r.checkIn;
	r2end.addDays(r.duration - 1);
	return (!(r1end.lessThan(r.checkIn) || r2end.lessThan(checkIn)));
}

bool Reservation::lessThan(Reservation& res) {
	if (overlaps(res)) {
		return false;
	}
	return checkIn.lessThan(res.checkIn);
}

bool Reservation::lessThan(Date& d) {
	Date end = checkIn;
	end.addDays(duration - 1);
	return end.lessThan(d);
}

void Reservation::print() {
	std::cout << "Reservation for " << customerName << " on ";
	checkIn.print();
	std::cout << " for " << duration << " day(s)." << std::endl;
}