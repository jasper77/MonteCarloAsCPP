#pragma once

#include <string>
#include <vector>

// Define the HistoryRecord struct
struct HistoryRecord {
    std::string date;
    int items_completed;

    // Default constructor. This is needed for emplace_back in CSVReader::readCSV()
    HistoryRecord() = default;

    // Constructor to initialize all members
    HistoryRecord(const std::string& d, int items) : date(d), items_completed(items) {}
};