#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

#include "CSVReader.hpp"

// Constructor
CSVReader::CSVReader(const std::string& filename) : filename_(filename) {}

// Utility function to trim whitespace from a string
static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

// Reads the CSV file
bool CSVReader::readCSV() {
    std::ifstream file(filename_);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename_ << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines
        std::istringstream stream(line);

        std::string date;
        int items_completed;

        // Parse the line
        if (std::getline(stream, date, ',') && stream >> items_completed) {
            date = trim(date); // Trim whitespace from date
            data_.emplace_back(HistoryRecord{date, items_completed});
        } else {
            std::cerr << "Error: Malformed line: " << line << std::endl;
        }
    }

    file.close();
    return true;
}

// Retrieves the data
const std::vector<HistoryRecord>& CSVReader::getData() const {
    return data_;
}
