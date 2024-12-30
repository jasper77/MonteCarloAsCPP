#include <gtest/gtest.h> 
#include <random> 
#include "MonteCarloSimulator.hpp"
#include "HistoryRecord.hpp"


// A test fixture class for MonteCarloSimulator
class MonteCarloSimulatorTest : public ::testing::Test {
protected:
    MonteCarloSimulator* simulator;
    std::mt19937 mockGen;

    void SetUp() override {
        // Setup initial historical data for daily completions
        std::vector<HistoryRecord> data = {{"2022-01-01", 5}, {"2022-01-02", 10}, {"2022-01-03", 15}};
        simulator = new MonteCarloSimulator(data);

        // Seed the mock generator with a fixed seed
        mockGen.seed(42);
        simulator->setRandomGenerator(mockGen);
    }

    void TearDown() override {
        delete simulator;
    }
};

TEST_F(MonteCarloSimulatorTest, RunSimulationWithMockedRandomGenerator) {
    int totalItems = 50;
    int numTrials = 3;

    // Run the simulation
    simulator->runSimulation(totalItems, numTrials);

    // Expected results for the seeded generator
    std::vector<int> expectedResults = {4, 5, 4};

    // Check if the simulation results match the expected results
    ASSERT_EQ(simulator->simulationResults_, expectedResults);
}
