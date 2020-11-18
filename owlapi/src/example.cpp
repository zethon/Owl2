//#include "boost/format.hpp"
#include "example.h"

namespace example
{

int example::add(int x, int y)
{
    auto z = x + y;
    // const output = (boost::format("%1% + %2% = %3%") % x % y % z).str();
    // std::cout << output << '\n';
    return z;
}

int example::sub(int x, int y)
{
    return x - y;
}

} // namespace
