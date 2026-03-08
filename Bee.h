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
		for (int i = 0; i < allAttributes.size(); i++)
		{
			attributes.emplace(allAttributes[i], BoundValue(12));
		}
	};
	virtual ~Bee() {};

	string outputAllAttributes();

	void updateAttribute(string _attributeName, USI _minimum = 0, USI _current = 0, USI _maximum = 0)
	{
		if (_minimum == 0) attributes[_attributeName].values[MINIMUM] = getMinimum(_attributeName);
		else attributes[_attributeName].values[MINIMUM] = _minimum;

		if (_current == 0) attributes[_attributeName].values[CURRENT] = getCurrent(_attributeName);
		else attributes[_attributeName].values[CURRENT] = _current;
		
		if (_maximum == 0) attributes[_attributeName].values[MAXIMUM] = getMaximum(_attributeName);
		else attributes[_attributeName].values[MAXIMUM] = _maximum;

		attributes[_attributeName].bindValues();
		
	};

	USI getMinimum(string _attributeName) { return attributes[_attributeName].values[MINIMUM]; };
	USI getCurrent(string _attributeName) { return attributes[_attributeName].values[CURRENT]; };
	USI getMaximum(string _attributeName) { return attributes[_attributeName].values[MAXIMUM]; };

private:
	
	map <string, BoundValue> attributes;

};

class Drone : Bee
{
public:
	Drone() 
	{
		updateAttribute(RANK, 1, 1, 3);
	};
	~Drone() {};

private:

};

class Worker : Bee
{
public:
	Worker() 
	{
		updateAttribute(RANK, 1, 2, 3);
	};
	~Worker() {};

private:
};

class Queen : Bee
{
public:
	Queen() 
	{
		updateAttribute(RANK, 1, 3, 3);
	};
	~Queen() {};

private:
};


#endif //BEES_H