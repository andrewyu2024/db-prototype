#include "table.hpp"

#include <functional>
#include <unordered_map>



std::unordered_map<std::string, std::function<bool(const std::string&, const std::string&)>> ops = {
    {"=",  [](const std::string& a, const std::string& b){ return a == b; }},
    {"!=", [](const std::string& a, const std::string& b){ return a != b; }},
    {"<",  [](const std::string& a, const std::string& b){ return a <  b; }},
    {">",  [](const std::string& a, const std::string& b){ return a >  b; }},
    {"<=", [](const std::string& a, const std::string& b){ return a <= b; }},
    {">=", [](const std::string& a, const std::string& b){ return a >= b; }}
};





Table::Table(const std::string& name, const std::vector<std::string>& columns):
    name (name), columns(columns)
{
}

void Table::insert(const std::vector<std::string>& records){
    rows.push_back(Row(records));
}

void Table::insert(const Row& records){
    rows.push_back(records);
}

void Table::print() const{
    std::unordered_map<int, int> max_pads;
    int num_cols = columns.size();

    // first sets the max pad for each column as the length of the column title
    for (int i = 0; i < num_cols; ++i){
        max_pads[i] = columns[i].length();
    }

    // goes through each column to find the longest string to make the max pad
    // that string
    for (const Row& row : rows){
        for(int i = 0; i < num_cols; ++i){
            int len = row.getValue(i).length();
            if (len > max_pads[i]){
                max_pads[i] = len;
            }
        }
    }

    // prints the column title row
    for (int i = 0; i < num_cols; ++i){
        std::cout << std::left << std::setw(max_pads[i] + 2) << columns[i];
    }
    std::cout << "\n";

    // prints all other rows
    int num_rows = rows.size();
    for (int i = 0; i < num_rows; ++i){
        for (int j = 0; j < num_cols; ++j){
            std::cout << std::left << std::setw(max_pads[j] + 2) << rows[i].getValue(j);
        }
        std::cout << "\n";
    }
}

Table Table::select(const std::string& column, const std::string& condition, const std::string& value){
    int num_cols = columns.size();
    Table new_table = Table("temp_return", columns);

    int i = 0;
    for (; i < num_cols; ++i){
        if (columns[i] == column){
            break;
        }
    }
    if (i == num_cols){
        throw std::out_of_range("the column \'" + column + "\' does not exist");
    }

    int num_rows = rows.size();
    for (int j = 0; j < num_rows; ++j){
        if (ops[condition](rows[j].getValue(i), value)) {
            new_table.insert(rows[j]);
        }
    }
    return new_table;
}