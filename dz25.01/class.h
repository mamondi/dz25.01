#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Passenger {
public:
    Passenger(double arrivalRate) : arrivalRate(arrivalRate) {}

    bool isArrived() const {
        return (rand() % 100) < (arrivalRate * 100);
    }

private:
    double arrivalRate;
};

class BusStop {
public:
    BusStop(double busArrivalRate, bool isTerminal) : busArrivalRate(busArrivalRate), isTerminal(isTerminal), passengers(0) {}

    bool isBusArrived() const {
        return (rand() % 100) < (busArrivalRate * 100);
    }

    void addPassenger() {
        passengers++;
    }

    void removePassenger() {
        passengers--;
    }

    bool isFull(int maxCapacity) const {
        return passengers >= maxCapacity;
    }

    int getPassengerCount() const {  
        return passengers;
    }

private:
    double busArrivalRate;
    bool isTerminal;
    int passengers;
};

class Simulation {
public:
    Simulation(double passengerArrivalRate, double busArrivalRate, bool isTerminal, int maxCapacity)
        : passengerGenerator(passengerArrivalRate), busStop(busArrivalRate, isTerminal), maxCapacity(maxCapacity) {}

    void run(int simulationTime) {
        srand(static_cast<unsigned>(time(nullptr)));

        for (int time = 0; time < simulationTime; ++time) {
            if (passengerGenerator.isArrived()) {
                busStop.addPassenger();
                cout << "Passenger arrived at time " << time << endl;
            }

            if (busStop.isBusArrived()) {
                if (!busStop.isFull(maxCapacity)) {
                    int passengersInBus = rand() % (maxCapacity - busStop.getPassengerCount() + 1);
                    for (int i = 0; i < passengersInBus; ++i) {
                        busStop.removePassenger();
                    }

                    cout << "Bus arrived at time " << time << " with " << passengersInBus << " passengers." << endl;
                }
                else {
                    cout << "Bus arrived at time " << time << " but could not board passengers (bus stop is full)." << endl;
                }
            }
        }
    }

private:
    Passenger passengerGenerator;
    BusStop busStop;
    int maxCapacity;
};