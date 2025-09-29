#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <iostream>

#include "row.hpp"



class Table{
    // each table must have a name
    std::string name;
    // represents the columns that each row have to have filled out
    std::vector<std::string> columns;
    // stores the actual rows/records that exist in the table
    std::vector<Row> rows;

public:
    Table() = default;
    // constructor that names the table and determines the columns
    Table(const std::string& name, const std::vector<std::string>& columns);

    // function to add records to the table
    // assumes the given vector is already in matching order of the columns
    void insert(const std::vector<std::string>& record);

    void insert(const Row& records);

    // thinking about multiple remove functions for different types of removes
    //void remove();

    // function to print and visualize the current table
    void print() const;

    // where the actual selection
    Table select(const std::string& column, const std::string& condition, const std::string& value);
};



#endif