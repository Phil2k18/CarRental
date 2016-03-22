#pragma once
#include <sstream>

//This patch is to fix some of the g++ version unable to support to_string function
namespace patch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}
class StringHandler
{
public:
	StringHandler();
	~StringHandler();
};


