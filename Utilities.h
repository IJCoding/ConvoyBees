#ifndef UTILITIES_H
#define UTILITIES_H
#include <cmath>
#include <map>
#include <string>

using std::abs;
using std::string;
using std::map;
typedef unsigned short int USI;


class BoundValue
{
public:

	BoundValue() : BoundValue(12) {};

	BoundValue(USI value) : BoundValue(value, value, value) {};

	BoundValue(USI _min, USI _cur, USI _max)
	{
		values["Minimum"] = _min;
		values["Current"] = _cur;
		values["Maximum"] = _max;
	}

	map <string, USI> values;

};

#endif //UTILITIES_H