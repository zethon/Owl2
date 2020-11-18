//#include "boost/format.hpp"
#include "example.h"

namespace owl
{

int add(int x, int y)
{
    auto z = x + y;
    // const output = (boost::format("%1% + %2% = %3%") % x % y % z).str();
    // std::cout << output << '\n';
    return z;
}

int sub(int x, int y)
{
    return x - y;
}

} // namespace
