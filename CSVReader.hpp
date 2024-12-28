#ifndef CSV_READER_HPP
#define CSV_READER_HPP

#include <string>
#include <vector>

// Define the Record struct
struct Record {
    std::string date;
    int items_completed;

    // Default constructor 
    Record() = default;

    // Constructor to initialize all members
    Record(const std::string& d, int items) : date(d), items_completed(items) {}
};

// Define the CSVReader class
class CSVReader {
public:
    explicit CSVReader(const std::string& filename);

    // Reads the CSV file
    bool readCSV();

    // Retrieves the data
    const std::vector<Record>& getData() const;

private:
    std::string filename_;
    std::vector<Record> data_;
};

#endif // CSV_READER_HPP