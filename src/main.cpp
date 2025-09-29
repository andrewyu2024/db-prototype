#include <iostream>
#include <string>
#include "database.hpp"


int main() {
    Database db;

    // db.create_table("students", {"name", "year", "major"});
    // db.insert("students", {"andrew", "sophomore", "computer science"});
    // db.insert("students", {"sean", "sophomore", "computer science"});
    // db.insert("students", {"brandon", "sophomore", "computer engineering"});
    // db.insert("students", {"harish", "sophomore", "aerospace engineering"});
    // db.print_table("students");
    
    // std::cout << "\n";

    // // db.select("students", "major", "=", "computer science").print();
    // db.import_table("result_table", db.select("students", "major", "=", "computer science"));
    // db.print_table("result_table");
    

    std::string input;
    while (true){
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit"){
            break;
        }
        
        if (input.empty()){
            continue;
        }
        
    }
}