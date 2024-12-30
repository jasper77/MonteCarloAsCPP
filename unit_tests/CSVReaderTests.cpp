#include <gtest/gtest.h>

#include "CSVReader.hpp"

TEST(CSVReader, reports_invalid_file) {

    // Arrange
    CSVReader reader("invalid.csv");

    // Act
    bool result = reader.readCSV();

    // Assert
    EXPECT_FALSE(result);
}

TEST(CSVReader, ReadsCSVFile) {

    // Arrange
    CSVReader reader("test_data/small_data.csv");

    // Act
    bool result = reader.readCSV();

    // Assert
    EXPECT_TRUE(result);
    EXPECT_EQ(reader.getData().size(), 4);
}

TEST(CSVReader, fillsVectorOfRecords) {

    // Arrange
    CSVReader reader("test_data/small_data.csv");
    reader.readCSV();

    // Act
    const std::vector<Record>& data = reader.getData();

    // Assert
    EXPECT_EQ(data[0].date, "2024-02-11");
    EXPECT_EQ(data[0].items_completed, 1);
    EXPECT_EQ(data[1].date, "2024-03-15");
    EXPECT_EQ(data[1].items_completed, 1);
    EXPECT_EQ(data[2].date, "2024-02-26");
    EXPECT_EQ(data[2].items_completed, 3); 
    EXPECT_EQ(data[3].date, "2024-02-11");
    EXPECT_EQ(data[3].items_completed, 5);

}

TEST(CSVReader, ignores_whitespace) {

    // Arrange
    CSVReader reader("test_data/csv_with_whitespace.csv");
    reader.readCSV();

    // Act
    const std::vector<Record>& data = reader.getData();

    // Assert
    EXPECT_EQ(data[0].date, "2024-02-11");
    EXPECT_EQ(data[0].items_completed, 1);
    EXPECT_EQ(data[1].date, "2024-03-15");
    EXPECT_EQ(data[1].items_completed, 1);
    EXPECT_EQ(data[2].date, "2024-02-26");
    EXPECT_EQ(data[2].items_completed, 3);
    EXPECT_EQ(data[3].date, "2024-02-11");
    EXPECT_EQ(data[3].items_completed, 5);
}

TEST(CSVReader, ignores_empty_lines) {
    // Arrange
    CSVReader reader("test_data/data_with_empty_lines.csv");
    reader.readCSV();

    // Act
    const std::vector<Record>& data = reader.getData();

    // Assert
    EXPECT_EQ(data[0].date, "2024-02-11");
    EXPECT_EQ(data[0].items_completed, 1);
    EXPECT_EQ(data[1].date, "2024-03-15");
    EXPECT_EQ(data[1].items_completed, 1);
    EXPECT_EQ(data[2].date, "2024-02-26");
    EXPECT_EQ(data[2].items_completed, 3);
    EXPECT_EQ(data[3].date, "2024-02-11");
    EXPECT_EQ(data[3].items_completed, 5);
}



