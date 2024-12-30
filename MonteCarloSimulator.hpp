#pragma once

#include <vector>
#include <random>
#include <map>

#include "CSVReader.hpp"

class MonteCarloSimulator {
public:
    explicit MonteCarloSimulator(const std::vector<HistoryRecord>& data);

    // Run the simulation
    void runSimulation(int totalItems, int numTrials);

    // Display the results
    void displayResults() const;

    // Method to set a custom random number generator so the
    // simulation can be tested deterministically
    void setRandomGenerator(std::mt19937 gen) {
        gen_ = gen;
    }

    std::vector<int> simulationResults_;

private:
    std::vector<int> dailyCompletions_;
    std::random_device rd_;
    std::mt19937 gen_;
};

