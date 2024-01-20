#include "class.h"

int main() {
    double passengerArrivalRate = 0.2;
    double busArrivalRate = 0.1;
    bool isTerminal = false;
    int maxCapacity = 10;

    int simulationTime = 100;

    Simulation simulation(passengerArrivalRate, busArrivalRate, isTerminal, maxCapacity);
    simulation.run(simulationTime);

    return 0;
}