#include "Board.h"

namespace owl
{

Board::Board(std::string_view id)
    : Board(id, std::string_view{}, std::string_view{})
{
}

Board::Board(std::string_view id, std::string_view name)
    : Board(id, name, std::string_view{})
{
}

Board::Board(std::string_view id, std::string_view name, std::string_view url)
    : _id{ id }, _name { name }, _url { url }
{
}

} // namespace owl
