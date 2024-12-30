#pragma once

#include <string>
#include <vector>

#include "HistoryRecord.hpp"

// Define the CSVReader class
class CSVReader {
public:
    explicit CSVReader(const std::string& filename);

    // Reads the CSV file
    bool readCSV();

    // Retrieves the data
    const std::vector<HistoryRecord>& getData() const;

private:
    std::string filename_;
    std::vector<HistoryRecord> data_;
};

