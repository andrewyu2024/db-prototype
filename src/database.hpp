#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <unordered_map>
#include "table.hpp"



class Database{
    // a map to store all tables in the database schema
    std::unordered_map<std::string, Table> tables;

public:
    // default constructor to create an empty database schema
    Database();

    // function to create a table given a name and ordered columns
    void create_table(const std::string& name, const std::vector<std::string>& columns);

    // function to delete a table based on name
    void delete_table(const std::string& name);

    // allows you to insert a tuple into a specified table
    void insert(const std::string& name, const std::vector<std::string>& records);

    // prints a specific table to visualize the data inside
    void print_table(const std::string& name);

    // allows you to select records based on a condition
    Table select(const std::string& name, const std::string& column, const std::string& condition, const std::string& value);

    // allows you to copy over a table
    void import_table(const std::string& name, Table copy_table);
};



#endif