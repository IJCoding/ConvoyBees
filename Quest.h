#ifndef QUEST_H
#define QUEST_H
#include "Utilities.h"

class Quest
{
public:
	
	Quest(string _questName, map<string, USI> _requirements,
		bool _isActive = false, bool _isCompleted = false)
	{
		name = _questName;
		requirements = _requirements;
		isActive = _isActive;
		isCompleted = _isCompleted;
	};
	~Quest() {};

	bool isRequirement(string _type) const
	{
		return requirements.contains(_type);
	}

	USI getRequiredAmount(string _type) const
	{
		USI result = 0;
		if (isRequirement(_type))
		{
			result = requirements.at(_type);
		}

		return result;
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

	map<string, USI> const getRequirements() { return requirements; }
	bool getIsActive() const { return isActive; }
	bool getIsCompleted() const { return isCompleted; }
	string getName() const { return name; }
	void toggleQuestActive() { isActive = !getIsActive(); }
	void toggleQuestCompleted() { isCompleted = !getIsCompleted(); }

private:

	string name;
	map<string, USI> requirements;
	bool isActive = false;
	bool isCompleted = false;
};


#endif //QUEST_H