#include <string>
#include <string_view>
#include <memory>

namespace owl
{

class Board;
using BoardPtr = std::shared_ptr<Board>;

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

public:
    Board() = default;
    Board(std::string_view id);
    Board(std::string_view id, std::string_view name);
    Board(std::string_view id, std::string_view name, std::string_view url);
    
    std::string id() const noexcept { return _id; }
    std::string name() const noexcept { return _name; }
    std::string url() const noexcept { return _url; }

    const ParserInfo& parserInfo() const { return _parserInfo; }
};

}