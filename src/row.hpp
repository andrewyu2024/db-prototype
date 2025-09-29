#ifndef ROW_HPP
#define ROW_HPP

#include <string>
#include <vector>


class Row{
    // represents a tuple or record and the values that it stores
    std::vector<std::string> values;

public:
    // constructor that takes in values
    Row(std::vector<std::string> values);

    // function to retrieve the value at a specific index
    // index determination happens in the table class
    std::string getValue(size_t index) const;

    // function to change the value at a specific index
    void setValue(size_t index, const std::string& value);
};



#endif