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

	//A checker to make sure that the given item is part of the requirement
	bool isRequirement(string _type) const
	{
		return requirements.contains(_type);
	}

	//Returns how many of the type are required
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

	//It changes the requirement to be lower than it currently is to a minimum of 0
	void lowerRequirement(pair<string, USI> _givenAttribute, USI _amount)
	{
		if (isRequirement(_givenAttribute.first))
		{
			while ((_amount >= 0) && (requirements.at(_givenAttribute.first) > 0))
				requirements.at(_givenAttribute.first)--;
		}
	}

	//Returns all the current requirements and their values
	map<string, USI> const getRequirements() { return requirements; }

	//Checker to make sure that the requirement is needed
	bool getIsActive() const { return isActive; }
	
	//Checker to make sure that the quest is not yet completed
	bool getIsCompleted() const { return isCompleted; }

	//The name of the quest
	string getName() const { return name; }

	//Alternates whether the quest is active
	void toggleQuestActive() { isActive = !getIsActive(); }

	//Alternates whether the quest is completed
	void toggleQuestCompleted() { isCompleted = !getIsCompleted(); }

private:

	//The name of the quest
	string name;

	//The map of quest requirements
	map<string, USI> requirements;

	//Whether the quest is active
	bool isActive = false;

	//Whether the quest is completed
	bool isCompleted = false;
};


#endif //QUEST_H