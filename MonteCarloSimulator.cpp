#include <iostream>
#include <algorithm>

#include "MonteCarloSimulator.hpp"

/*
How It Works

1.	Input Data:
	•	The MonteCarloSimulator class takes a vector of Record structs, which contain dates 
        and daily completion counts.
2.	Simulation Logic:
	•	The simulation randomly selects completion counts from historical data and accumulates 
        them until the target number of items is reached.
	•	The number of days required for each trial is recorded.
3.	Percentile Results:
	•	After running all trials, the simulation results are sorted.
	•	Percentiles (e.g., 50th, 85th, 95th) are calculated and displayed.
4.	Random Sampling:
	•	A std::uniform_int_distribution is used to randomly sample daily completion rates 
        from historical data.
*/

// Constructor: Extracts daily completions from the vector of records
MonteCarloSimulator::MonteCarloSimulator(const std::vector<HistoryRecord>& data) 
    : dailyCompletions_(), gen_(std::random_device{}()) {
    for (const auto& record : data) {
        dailyCompletions_.push_back(record.items_completed);
    }
}

// Run the Monte Carlo simulation
void MonteCarloSimulator::runSimulation(int totalItems, int numTrials) {
    std::uniform_int_distribution<size_t> dist(0, dailyCompletions_.size() - 1);

    for (int trial = 0; trial < numTrials; ++trial) {
        int itemsCompleted = 0;
        int days = 0;

        while (itemsCompleted < totalItems) {
            // Randomly pick a daily completion rate from historical data
            itemsCompleted += dailyCompletions_[dist(gen_)];
            ++days;
        }

        simulationResults_.push_back(days);
    }
}

// Display the simulation results
void MonteCarloSimulator::displayResults() const {
    if (simulationResults_.empty()) {
        std::cerr << "No simulation results to display." << std::endl;
        return;
    }

    // Sort the results to calculate percentiles
    std::vector<int> sortedResults = simulationResults_;
    std::sort(sortedResults.begin(), sortedResults.end());

    // Calculate and display percentiles
    const std::map<int, std::string> percentiles = {
        {50, "Median (50th percentile)"},
        {85, "85th percentile"},
        {95, "95th percentile"}
    };

    std::cout << "Simulation Results:" << std::endl;
    for (const auto& [percentile, label] : percentiles) {
        size_t index = (percentile / 100.0) * sortedResults.size();
        index = std::min(index, sortedResults.size() - 1);
        std::cout << label << ": " << sortedResults[index] << " days" << std::endl;
    }
}