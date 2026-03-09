#ifndef CHARACTER_H
#define CHARACTER_H
#include "Utilities.h"
#include "Quest.h"

class Character
{
public:

	bool hasQuest(string _questName) const { return allQuests.contains(_questName); }

	Quest& getQuest(const string& questName) { return allQuests.at(questName); }

	const Quest& getQuest(const string& questName) const {return allQuests.at(questName); }

	bool hasActiveQuest(string _questName, bool _isActive) 
	{
		bool result = false;
		if (hasQuest(_questName)) result = getQuest(_questName).getIsActive() ; 
		return result;
	}

	bool hasCompletedQuest(string _questName, bool _hasCompleted)
	{
		bool result = false;
		if (hasQuest(_questName)) result = getQuest(_questName).getIsCompleted();
		return result;
	}

	void makeQuest(Quest _quest)
	{
		if (hasQuest(_quest.getName()))
		{
			allQuests.emplace(_quest.getName(), _quest);
		}
	}

	void markQuestComplete(const string& _questName)
	{
		if (!hasQuest(_questName))
			return;

		auto& quest = getQuest(_questName);

		if (!quest.getIsCompleted())
			quest.toggleQuestCompleted();
	}

	void markQuestActive(const string& _questName)
	{
		if (!hasQuest(_questName))
			return;

		auto& quest = getQuest(_questName);

		if (!quest.getIsActive())
			quest.toggleQuestActive();
	}
	
	void markQuestInactive(const string& _questName)
	{
		if (!hasQuest(_questName))
			return;

		auto& quest = getQuest(_questName);

		if (quest.getIsActive())
			quest.toggleQuestActive();
	}
	bool getIsActive() const { return isActive; }
	string getName() const { return name; }
	void toggleCharacterActive() { isActive = !getIsActive(); }

private:
	string name;
	bool isActive = false;
	map<string, Quest> allQuests;

};

#endif //CHARACTER_H