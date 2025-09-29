#include "row.hpp"

Row::Row(std::vector<std::string> value):
    values (value)
{
}

std::string Row::getValue(size_t index) const{
    if (index < values.size()){
        return values[index];
    }
    else{
        throw std::out_of_range("index is too large");
    }
}

void Row::setValue(size_t index, const std::string& value){
    if (index < values.size()){
        values[index] = value;
    }
    else{
        throw std::out_of_range("index is too large");
    }
}