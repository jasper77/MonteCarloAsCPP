#ifndef MONTE_CARLO_SIMULATOR_HPP
#define MONTE_CARLO_SIMULATOR_HPP

#include <vector>
#include <random>
#include <map>

#include "CSVReader.hpp"

class MonteCarloSimulator {
public:
    explicit MonteCarloSimulator(const std::vector<Record>& data);

    // Run the simulation
    void runSimulation(int totalItems, int numTrials);

    // Display the results
    void displayResults() const;

private:
    std::vector<int> dailyCompletions_;
    std::vector<int> simulationResults_;
    std::random_device rd_;
    std::mt19937 gen_;
};

#endif // MONTE_CARLO_SIMULATOR_HPP