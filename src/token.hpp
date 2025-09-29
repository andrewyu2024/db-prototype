#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>


// an enumerated class to identify what kind of token each token is
enum class TokenType{
    Keyword,
    Identifier,
    Operator,
    StringLiteral,
    NumberLiteral,
    Symbol
};

// all the reserved words that will identify keywords, operators, and symbols
std::unordered_set<std::string> keywords = {"CREATE", "TABLE", "INSERT",
    "SELECT", "WHERE", "FROM", "DELETE", "UPDATE"};

std::unordered_set<std::string> operators = {"=", "!=", "<", ">", "<=", ">="};

std::unordered_set<char> symbols = {',', ';', '(', ')'};

// functions to identify literals an identifiers
bool isStringLiteral(const std::string& word);

bool isNumberLiteral(const std::string& word);

bool isIdentifier(const std::string& word);

// the token class that will just hold a type and value and a constructor
struct Token{
    TokenType type;
    std::string value;

    Token(TokenType type, std::string value);
};


// the function that does all the work, tokenizes input from the user
std::vector<Token> tokenize(const std::string& input);