#ifndef CHARACTER_H
#define CHARACTER_H
#include "Utilities.h"
#include "Quest.h"

class Character
{
public:

	//Checks if a character has a quest (searched for by name)
	bool hasQuest(string _questName) const { return allQuests.contains(_questName); }

	//Retun a non const reference to a given quest that the character has
	Quest& getQuest(const string& questName) { return allQuests.at(questName); }

	//Return a const reference to a given quest that the character has
	const Quest& getQuest(const string& questName) const {return allQuests.at(questName); }

	//Checks if the character has an active quest given by name
	bool hasActiveQuest(string _questName, bool _isActive) 
	{
		compareActiveStateOfQuest(_questName, true);
	}

	//Checks if the character has a quest given by name but is inactive
	bool hasInactiveQuest(string _questName, bool _isActive)
	{
		compareActiveStateOfQuest(_questName, false);
	}

	//Checks that a quest has been completed
	bool hasCompletedQuest(string _questName)
	{
		compareQuestCompletion(_questName, true);
	}

	//Checks that a quest has not been completed
	bool hasNotCompletedQuest(string _questName)
	{
		compareQuestCompletion(_questName, false);
	}

	//If we do not currently have the given quest, add the quest
	void makeQuest(Quest _quest)
	{
		if (!hasQuest(_quest.getName()))
		{
			allQuests.emplace(_quest.getName(), _quest);
		}
	}

	//Marks a given quest as complete
	void markQuestComplete(const string& _questName)
	{
		markActiveStatusOfQuest(_questName, true);
	}

	//Marks a given quest as incomplete
	void markQuestInComplete(const string& _questName)
	{
		markActiveStatusOfQuest(_questName, false);
	}

	//Marks a given quest as active
	void markQuestActive(const string& _questName)
	{
		markActiveStatusOfQuest(_questName, true);
	}
	
	//Marks a given quest as inactive
	void markQuestInactive(const string& _questName)
	{
		markActiveStatusOfQuest(_questName, false);
	}

	//Checks if the character is active
	bool getIsActive() const { return isActive; }

	//Returns the name of the character
	string getName() const { return name; }

	//Toggles if this character is active
	void toggleCharacterActive() { isActive = !getIsActive(); }

private:

	//Sets the active-state of a given quest(found by name) to the given active-state
	void markActiveStatusOfQuest(const string& _questName, bool shouldBeActive)
	{
		if (!hasQuest(_questName))
			return;

		Quest& quest = getQuest(_questName);

		if (!shouldBeActive)
			quest.toggleQuestActive();

	}

	//Sets the completed-state of a given quest(found by name) to the given active-state
	void markCompletedStatusOfQuest(const string& _questName, bool shouldBeCompleted)
	{
		if (!hasQuest(_questName))
			return;

		auto& quest = getQuest(_questName);

		if (!shouldBeCompleted)
			quest.toggleQuestCompleted();
	}

	//Checks the completed-state of a given quest(found by name) to a given bool
	bool compareQuestCompletion(string _questName, bool _isCompleted)
	{
		bool result = false;
		if (_isCompleted)
			if (hasQuest(_questName)) result = getQuest(_questName).getIsCompleted();
		else 
			if (hasQuest(_questName)) result = !getQuest(_questName).getIsCompleted();
		return result;
	}

	//Checks the act of a given quest(found by name) to a given bool
	bool compareActiveStateOfQuest(string _questName, bool _isActive)
	{
		bool result = false;
		if (_isActive)
			if (hasQuest(_questName)) result = getQuest(_questName).getIsActive();
		else
			if (hasQuest(_questName)) result = !getQuest(_questName).getIsActive();
		return result;
	}

	//Name of the character
	string name;

	//Whether the character is active
	bool isActive = false;

	//A map of all quests the character is related to
	map<string, Quest> allQuests;

};

#endif //CHARACTER_H