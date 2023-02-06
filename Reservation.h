#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Reservation {
	
	public:
		Reservation(std::string customerName, Date& checkIn, int duration);
		void setDuration(int duration);
		bool overlaps(Reservation& r);
		bool lessThan(Reservation& res);
		bool lessThan(Date& d);
		void print();
	
	private:
		std::string customerName;
		Date checkIn;
		int duration;
};

#endif

