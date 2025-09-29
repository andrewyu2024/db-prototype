#include "parser.hpp"



ParsedStatement parseSelect(const std::vector<Token>& tokens, int& pos){

}


ParsedStatement parseInsert(const std::vector<Token>& tokens, int& pos){

}


ParsedStatement parseDelete(const std::vector<Token>& tokens, int& pos){

}


ParsedStatement parseCreate(const std::vector<Token>& tokens, int& pos){
    
}


ParsedStatement parseDrop(const std::vector<Token>& tokens, int& pos){

}




ParsedStatement parse(const std::vector<Token> tokens){
    if (tokens.empty()){
        throw std::runtime_error("Empty statement");
    }
    
    int i = 0;

    const std::string& keyword = tokens[i].value;

    if (keyword == "SELECT"){

    }
    else if (keyword == "INSERT"){

    }
    else if (keyword == "DELETE"){

    }
    else if (keyword == "CREATE"){
        
    }
    else if (keyword == "DROP"){

    }

    else{
         throw std::runtime_error("unknown keyword: " + keyword);
    }
}