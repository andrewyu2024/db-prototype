#include "database.hpp"

Database::Database():
    tables ()
{
}

void Database::create_table(const std::string& name, const std::vector<std::string>& columns){
    tables.emplace(name, Table(name, columns));
}

void Database::delete_table(const std::string& name){
    if (tables.find(name) != tables.end()){
        tables.erase(name);
    }
    else{
        throw std::out_of_range("the table \'" + name + "\' does not exist");
    }
}

void Database::insert(const std::string& name, const std::vector<std::string>& records){
    if (tables.find(name) != tables.end()){
        tables[name].insert(records);
    }
    else{
        throw std::out_of_range("the table \'" + name + "\' does not exist");
    }
}

void Database::print_table(const std::string& name){
    if (tables.find(name) != tables.end()){
        tables[name].print();
    }
    else{
        throw std::out_of_range("the table \'" + name + "\' does not exist");
    }
}

Table Database::select(const std::string& name, const std::string& column, const std::string& condition, const std::string& value){
    if (tables.find(name) != tables.end()){
        return tables[name].select(column, condition, value);
    }
    else{
        throw std::out_of_range("the table \'" + name + "\' does not exist");
    }
}

void Database::import_table(const std::string& name, Table copy_table){
    tables.emplace(name, copy_table);
}