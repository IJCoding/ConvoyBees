#ifndef UTILITIES_H
#define UTILITIES_H
#include <cmath>
#include <map>
#include <string>
#include <vector>

typedef unsigned short int USI;

using std::abs;
using std::string;
using std::map;
using std::vector;

#ifndef CONSTANTS
#define CONSTANTS

const string RANK = "Rank";
const string SPEED = "Speed";
const string HARDINESS = "Hardiness";
const string SIZE = "Size";
const string AGE = "Age";
const string STRENGTH = "Strength";
const string VISION = "Vision";
const string MEMORY = "Memory";
const string GRACE = "Grace";
const string MINIMUM = "Minimum";
const string CURRENT = "Current";
const string MAXIMUM = "Maximum";

#endif CONSTANTS

inline const vector<string> allAttributes { RANK, SPEED, HARDINESS, SIZE, AGE, STRENGTH, VISION, MEMORY, GRACE };

class BoundValue
{
public:

	BoundValue() : BoundValue(12) {};

	BoundValue(USI value) : BoundValue(value, value, value) {};

	BoundValue(USI _min, USI _cur, USI _max)
	{
		values[MINIMUM] = _min;
		values[CURRENT] = _cur;
		values[MAXIMUM] = _max;
	}

	void bindValues()
	{
		if (values[MAXIMUM] < values[MINIMUM]) values[MAXIMUM] = values[CURRENT];
		if (values[MINIMUM] > values[MAXIMUM]) values[MINIMUM] = values[MAXIMUM];

		if (values[CURRENT] > values[MAXIMUM]) values[CURRENT] = values[MAXIMUM];
		if (values[CURRENT] < values[MINIMUM]) values[CURRENT] = values[MINIMUM];
	}

	map <string, USI> values;

};

#endif //UTILITIES_H