#include <argparse/argparse.hpp>
#include <iostream>

#include "CSVReader.hpp"
#include "MonteCarloSimulator.hpp"

int main(int argc, char* argv[]) {

    // Parse the command-line arguments
    argparse::ArgumentParser program("run_mc_simulation");

    program.add_argument("-f", "--file")
        .required()
        .help("Specify the name of the CSV file.");
    program.add_argument("-t", "--trials")
        .default_value(1000)
        .scan<'i', int>()
        .help("Specify an integer value for the number of trials to run");
    program.add_argument("-i", "--items")
        .required()
        .scan<'i', int>()
        .help("Specify an integer value for the number of items to forecast");

    try {
        program.parse_args(argc, argv);

        std::string filename = program.get<std::string>("-f");
        int numTrials = program.get<int>("-t");
        int numItems = program.get<int>("-i");

        std::cout << "Filename: " << filename << "\n";
        std::cout << "Trials: " << numTrials << "\n";
        std::cout << "Items: " << numItems << "\n";

        // Read the CSV file into a vector of records
        CSVReader reader(filename);
        
        std::vector<Record> data; 

        if (reader.readCSV()) {
            data = reader.getData();
            for (const auto& record : data) {
                std::cout << "Date: " << record.date << ", Items Completed: " << record.items_completed << std::endl;
            }
        }

        // Run the Monte Carlo simulation
        MonteCarloSimulator simulator(data);
        simulator.runSimulation(numItems, numTrials);
        simulator.displayResults();

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n"; 
        std::cerr << program;
        return 1;
    }



    return 0;
}