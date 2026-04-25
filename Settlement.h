#ifndef SETTLEMENT_H
#define SETTLEMENT_H
#include "Character.h"

class Settlement
{
public:
	Settlement() {};
	~Settlement() {};
	
	//Checks if a given character exists (by giving the name of the character)
	bool hasCharacter(string _characterName) const { return allCharacters.contains(_characterName); }

	//Returns a given character (by searching for it's name)
	Character& getCharacter(const string& _characterName) { return allCharacters.at(_characterName); }

	//Get a const version of a given character (by searching for it's name)
	const Character& getCharacter(const string& _characterName) const { return allCharacters.at(_characterName); }

	//Checks if a given character exists and is active (by searching for it's name)
	bool hasActiveCharacter(string _characterName, bool _isActive)
	{
		bool result = false;
		if (hasCharacter(_characterName)) result = getCharacter(_characterName).getIsActive();
		return result;
	}

	//Creates a character if it does not currently exist within all characters in a given settlement
	void makeCharacter(Character _character)
	{
		if (!hasCharacter(_character.getName()))
		{
			allCharacters.emplace(_character.getName(), _character);
		}
	}

	//When given a characters' name, mark it as active (if it is currently inactive)
	void markCharacterActive(const string& _characterName)
	{
		markCharacterStatus(_characterName, true);
	}	

	//When given a characters' name, mark it as inactive (if it is currently inactive)
	void markCharacterInactive(const string& _characterName)
	{
		markCharacterStatus(_characterName, false);
	}

	//Returns all attributes for the settlement
	const map<string, BoundValue>& getAttributes() const { return attributes; }

private:

	//Sets the active-state of a given character(found by name) to the given active-state
	void markCharacterStatus(const string& _characterName, bool shouldBeActive)
	{
		if (!hasCharacter(_characterName))
			return;

		Character& character = getCharacter(_characterName);

		if (!shouldBeActive)
			character.toggleCharacterActive();
	}

	map<string, BoundValue> attributes;
	map<string, Character> allCharacters;

};

#endif //SETTLEMENT_H