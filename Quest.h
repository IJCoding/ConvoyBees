#ifndef QUEST_H
#define QUEST_H
#include "Utilities.h"

class Quest
{
public:

	Quest() {};
	~Quest() {};

	bool tryGiveRequirement(string _type, USI _amount)
	{
		if (requirements.contains(_type))
			if (!requirements.at(_type).isAtMax())
				updateRequirement(_type, _amount);
	}

	USI updateRequirement(string _type, USI _amount)
	{
		USI _localAmount = _amount;
		while (!requirements.at(_type).isAtMax() && (_localAmount != 0))
		{
			requirements.at(_type)++;
			_localAmount--;
		}
		requirements.at(_type).remainingToMax();
		_amount;


	};


private:

	map<string, BoundValue> requirements;
};


#endif //QUEST_H