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


private:
	
	map <string, BoundValue> attributes;

};


class Drone : Bee
{
public:
	Drone() {};
	~Drone() {};

private:

};

class Worker : Bee
{
public:
	Worker() {};
	~Worker() {};

private:
};

class Queen : Bee
{
public:
	Queen() {};
	~Queen() {};

private:
};


#endif //BEES_H