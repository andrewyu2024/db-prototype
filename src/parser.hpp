#include "token.hpp"
#include "database.hpp"


struct ParsedStatement{
    enum class Type{
        SELECT,
        INSERT,
        DELETE,
        CREATE,
        DROP,
        UNKNONW,
    };

    std::string tableName;
    std::vector<std::string> columns;
    std::vector<std::string> values;

    struct Condition{
        std::string column;
        std::string op;
        std::string value;
    };
    std::optional<Condition> where;
};



ParsedStatement parseSelect(const std::vector<Token>& tokens, int& pos);

ParsedStatement parseInsert(const std::vector<Token>& tokens, int& pos);

ParsedStatement parseDelete(const std::vector<Token>& tokens, int& pos);

ParsedStatement parseCreate(const std::vector<Token>& tokens, int& pos);

ParsedStatement parseDrop(const std::vector<Token>& tokens, int& pos);



ParsedStatement parse(const std::vector<Token>& tokens);