#include <string>

namespace owl
{

struct ParserInfo
{
    std::string     _id;
    std::string     _name;
    std::uint32_t   _verion;
};

class Board
{
    std::string     _id;
    std::string     _name;
    std::string     _url;

    ParserInfo      _parserInfo;
};

}