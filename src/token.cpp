#include "token.hpp"


Token::Token(TokenType type, std::string value):
    type(type), value(value)
{
}



bool isStringLiteral(const std::string& word){
    return (word.size() >= 2 && 
    (word.front() == '\'' && word.back() == '\'') ||
    (word.front() == '"' && word.back() == '"'));
}

bool isNumberLiteral(const std::string& word){
    bool hasDecimal = false;
    size_t start = 0;
    if(word.empty()){
        return false;
    }
    // takes care of the situation where the number is negative
    if (word[0] == '-'){
        start = 1;
    }

    for (size_t i = start; i < word.size(); ++i){
        // ensures the number only has one decimal, multiple dots not allowed
        if (word[i] == '.'){
            if (hasDecimal){
                return false;
            }
            else{
                hasDecimal = true;
            }
        }
        // checks if the word is a digit or not
        if (!isdigit(word[i])){
            return false;
        }
    }
    return true;
}

// bool isIdentifier(const std::string& word){

// }



std::vector<Token> tokenize(const std::string& input){
    std::vector<Token> tokens;
    std::istringstream iss(input);
    std::string word;
    // the loop that deals with each word, words are separated by spaces
    while(iss >> word){
        // this part just deals with potential symbols within a word, such as commas
        std::vector<std::string> words;
        std::string current;
        // iterate through each character in the word to look for symbols
        for (char c : word){
            std::string stringified(1, c);
            // if a symbol is found, and current is not empty, then add current
            // and the symbol to the words vector to be processed later
            if (symbols.find(c) != symbols.end() || operators.find(stringified) != operators.end()){
                if (!current.empty()){
                    words.push_back(current);
                    current.clear();
                    words.push_back(stringified);
                }
            }
            // if the character is not a symbol, add it to current to potentially be
            // added to words later
            else{
                current += c;
            }
        }
        // if there's anything left in current, add it to words
        if (!current.empty()){
            words.push_back(current);
        }
        // if words has nothing in it, that means there were no symbols in the word
        // so just add the whole word to words to be processed later
        if (words.size() == 0){
            words.push_back(word);
        }

        // adds tokens based on what token type each word is
        for (std::string w : words){
            if (keywords.find(w) != keywords.end()){
                tokens.push_back(Token(TokenType::Keyword, w));
            }
            // operators should just be a string with one operator in it
            else if (operators.find(w) != operators.end()){
                tokens.push_back(Token(TokenType::Operator, w));
            }
            // symbols should also just be a string with one char in it
            else if (symbols.find(w[0]) != symbols.end()){
                tokens.push_back(Token(TokenType::Symbol, w));
            }
            else if (isStringLiteral(w)){
                tokens.push_back(Token(TokenType::StringLiteral, w));
            }
            else if(isNumberLiteral(w)){
                tokens.push_back(Token(TokenType::NumberLiteral, w));
            }
            else{
                tokens.push_back(Token(TokenType::Identifier, w));
            }
        }
    }
    return tokens;
}