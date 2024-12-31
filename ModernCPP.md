## What is "modern" about this C++?

### Default constructor in a struct (C++11)
Where: HistoryRecord.hpp
```
 HistoryRecord() = default;
```

This default constructor is needed because in CSVReader.cpp, after reading in a new line from the CSV file, the
line's data is added to the vector with "emplace_back". "emplace_back" constructs a new element in place at the 
end of the vector, and since it's using an initializer list, the compiler needs to create a temporary object.

In CSVReader.cpp, HistoryRecord is itialized using uniform initialization (see the curly braces) to help the
compiler, and the human, know this isn't a function declaration.
```
data_.emplace_back(HistoryRecord{date, items_completed});
```

## 'auto' type specifier (C++11)
Where: MonteCarloSimulator.cpp
```
    for (const auto& record : data) {
                ^^^^

    for (const auto& [percentile, label] : percentiles) {
               ^                
```

The 'auto' type specifier tells the compiler to deduce the type of the variable based on the type of its 
initializer.

## Range-based for loops (C++11)
Where: MonteCarloSimulator.cpp
```
    for (const auto& record : data) {
                            ^
```

```
   for (const auto& [percentile, label] : percentiles) {
                                        ^
```

Range-based for loops abstract away the complexity of using iterators or indexing.

## Decomposition declarations (C++17)            
Where: MonteCarloSimulator.cpp
```
for (const auto& [percentile, label] : percentiles) {
                 ^~~~~~~~~~~~~~~~~~~
        size_t index = (percentile / 100.0) * sortedResults.size();
        index = std::min(index, sortedResults.size() - 1);
        std::cout << label << ": " << sortedResults[index] << " days" << std::endl;
}
```
Decomposing the "percentiles" pair map into its elements simplifies syntax for iterating and printing.

