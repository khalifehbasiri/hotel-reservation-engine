# Hotel reservation engine

A small C++ model for assigning guests to rooms and tracking date-based reservations.

## Features

- Register and remove rooms, with duplicate room-number checks.
- Match bed type, guest capacity and refrigerator requirements.
- Reject overlapping reservations and try another matching room when one is booked.
- Remove expired stays and print room/reservation summaries.

## Build and run

Requires a C++11 compiler. From the repository root:

```sh
g++ -std=c++11 Date.cc Hotel.cc Reservation.cc Room.cc main.cc -o hotel-demo
./hotel-demo
```

On Windows use `hotel-demo.exe`. GNU Make (`make run`) and CMake (`cmake -S . -B build`, `cmake --build build`) are also supported. The demo uses fictional guests, fills two matching rooms, checks that a third overlapping booking is rejected, then books again after expiry. It exits nonzero if that scenario fails.

## Repository contents

| Component | Responsibility |
| --- | --- |
| Hotel | Room ownership, matching and booking operations |
| Room | Room attributes and reservation collection |
| Reservation | Guest name, arrival and length of stay |
| Date | Calendar comparisons and day arithmetic |
| main.cc | Reproducible booking demonstration |

This is an in-memory prototype with fixed collection limits, no persistence, payments, authentication or concurrent booking guarantees. Historical source was retained in a separate private archive; this presentation includes a booking fallback fix and a new demo. See [provenance](PROVENANCE.md) for import context.

## Validation

The demonstration and `tests/bookings.cpp` cover duplicate room numbers, selecting an alternative available room, overlapping reservations, capacity, expiry and room removal. Build the checks with `g++ -std=c++11 -I. Date.cc Hotel.cc Reservation.cc Room.cc tests/bookings.cpp -o booking-tests`, then run the resulting executable.

## Historical snapshots

Related files and saved edits from the same day are grouped into a single repository snapshot. Repeated editor saves within a day are consolidated; the latest preserved file state for that day is retained. Dates follow surviving file or editor records. These are retrospective imports, not claims that the original work was pushed to GitHub on those dates. Existing contributor Git histories remain intact. See [HISTORY.md](HISTORY.md) for the grouping policy.
