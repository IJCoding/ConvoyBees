#ifndef QUEST_H
#define QUEST_H
#include "Utilities.h"

using std::pair;

class Quest
{
public:

	Quest() {};
	~Quest() {};

	bool isRequirement(string _type) const
	{
		return requirements.contains(_type);
	}

	//Returns true only if present and meets or exceeds requirement
	bool isMeetingRequirement(pair<string, USI> _givenAttribute) const
	{
		bool result = false;
		if (isRequirement(_givenAttribute.first))
		{
			result = _givenAttribute.second >= requirements.at(_givenAttribute.first);
		}

		return result;
	}

	void lowerRequirement(pair<string, USI> _givenAttribute, USI _amount)
	{
		if (isRequirement(_givenAttribute.first))
		{
			while ((_amount >= 0) && (requirements.at(_givenAttribute.first) > 0))
				requirements.at(_givenAttribute.first)--;
		}
	}

private:

	map<string, USI> requirements;
};


#endif //QUEST_H