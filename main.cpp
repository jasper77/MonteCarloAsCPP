#include <argparse/argparse.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    argparse::ArgumentParser program("run_mc_simulation");

    program.add_argument("-f", "--file")
        .required()
        .help("Specify the name of the CSV file.");
    program.add_argument("-s", "--simulations")
        .required()
        .scan<'i', int>()
        .help("Specify an integer value for the number of simulations to run");
    program.add_argument("-i", "--items")
        .required()
        .scan<'i', int>()
        .help("Specify an integer value for the number of items to forecast");

    try {
        program.parse_args(argc, argv);

        std::string filename = program.get<std::string>("-f");
        int numSimulations = program.get<int>("-s");
        int numItems = program.get<int>("-i");

        std::cout << "Filename: " << filename << "\n";
        std::cout << "Simulations: " << numSimulations << "\n";
        std::cout << "Items: " << numItems << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        //         std::cerr << "Error: Invalid input. Please provide the required arguments.\n";

        std::cerr << program;
        return 1;
    }

    return 0;
}