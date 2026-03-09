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
using std::pair;

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

#endif //CONSTANTS

inline const vector<string> allAttributes { RANK, SPEED, HARDINESS, SIZE, AGE, STRENGTH, VISION, MEMORY, GRACE };

class BoundValue
{
public:

	BoundValue() : BoundValue(12) {}

	BoundValue(USI value) : BoundValue(value, value, value) {}

	BoundValue(USI _min, USI _cur, USI _max)
	{
		values[MINIMUM] = _min;
		values[CURRENT] = _cur;
		values[MAXIMUM] = _max;
		bindValues();
	}

	void bindValues()
	{
		if (values[MINIMUM] > values[MAXIMUM])
			values[MAXIMUM] = values[MINIMUM];

		if (values[CURRENT] > values[MAXIMUM])
			values[CURRENT] = values[MAXIMUM];

		if (values[CURRENT] < values[MINIMUM])
			values[CURRENT] = values[MINIMUM];
	}

	bool isAtMax() const { return values.at(CURRENT) == values.at(MAXIMUM); }
	bool isAtMin() const { return values.at(CURRENT) == values.at(MINIMUM); }
	USI remainingToMax() const { return values.at(MAXIMUM) - values.at(CURRENT); }

	BoundValue operator+(USI _alterAmount) const
	{
		BoundValue result = *this;

		USI current = result.values.at(CURRENT);
		USI maximum = result.values.at(MAXIMUM);

		if (_alterAmount > maximum - current)
			result.values.at(CURRENT) = maximum;
		else
			result.values.at(CURRENT) = current + _alterAmount;

		result.bindValues();
		return result;
	}

	BoundValue operator-(USI _alterAmount) const
	{
		BoundValue result = *this;

		if (_alterAmount >= result.values.at(CURRENT))
			result.values.at(CURRENT) = result.values.at(MINIMUM);
		else
			result.values.at(CURRENT) -= _alterAmount;

		result.bindValues();
		return result;
	}

	BoundValue& operator++()
	{
		if (values.at(CURRENT) < values.at(MAXIMUM))
			values.at(CURRENT) += 1;

		bindValues();
		return *this;
	}

	BoundValue operator++(int)
	{
		BoundValue temp = *this;
		++(*this);
		return temp;
	}

	BoundValue& operator--()
	{
		if (values.at(CURRENT) > values.at(MINIMUM))
			values.at(CURRENT) -= 1;

		bindValues();
		return *this;
	}

	BoundValue operator--(int)
	{
		BoundValue temp = *this;
		--(*this);
		return temp;
	}

	map<string, USI> values;
};

#endif //UTILITIES_H