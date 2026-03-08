#ifndef BEES_H
#define BEES_H

#include <map>
#include <string>
#include "Utilities.h"

using std::map;
using std::string;

class Bee
{
public:
	Bee()
	{
		for (const auto& attribute : allAttributes)
		{
			attributes.emplace(attribute, BoundValue(12));
		}
	}

	virtual ~Bee() {}

	void updateAttribute(string _attributeName, USI _minimum = 0, USI _current = 0, USI _maximum = 0)
	{
		if (_minimum == 0) attributes[_attributeName].values[MINIMUM] = getMinimum(_attributeName);
		else attributes[_attributeName].values[MINIMUM] = _minimum;

		if (_current == 0) attributes[_attributeName].values[CURRENT] = getCurrent(_attributeName);
		else attributes[_attributeName].values[CURRENT] = _current;

		if (_maximum == 0) attributes[_attributeName].values[MAXIMUM] = getMaximum(_attributeName);
		else attributes[_attributeName].values[MAXIMUM] = _maximum;

		attributes[_attributeName].bindValues();
	}

	USI getMinimum(string _attributeName) const { return attributes.at(_attributeName).values.at(MINIMUM); }
	USI getCurrent(string _attributeName) const { return attributes.at(_attributeName).values.at(CURRENT); }
	USI getMaximum(string _attributeName) const { return attributes.at(_attributeName).values.at(MAXIMUM); }

	const map<string, BoundValue>& getAttributes() const { return attributes; }

private:
	map<string, BoundValue> attributes;
};

class Drone : public Bee
{
public:
	Drone()
	{
		updateAttribute(RANK, 1, 1, 3);
	}

	~Drone() {}
};

class Worker : public Bee
{
public:
	Worker()
	{
		updateAttribute(RANK, 1, 2, 3);
	}

	~Worker() {}
};

class Queen : public Bee
{
public:
	Queen()
	{
		updateAttribute(RANK, 1, 3, 3);
	}

	~Queen() {}
};

#endif // BEES_H