#ifndef SETTLEMENT_H
#define SETTLEMENT_H
#include "Character.h"

class Settlement
{
public:
	Settlement() {};
	~Settlement() {};

	bool hasCharacter(string _characterName) const { return allCharacters.contains(_characterName); }

	Character& getCharacter(const string& _characterName) { return allCharacters.at(_characterName); }

	const Character& getCharacter(const string& _characterName) const { return allCharacters.at(_characterName); }

	bool hasActiveCharacter(string _characterName, bool _isActive)
	{
		bool result = false;
		if (hasCharacter(_characterName)) result = getCharacter(_characterName).getIsActive();
		return result;
	}

	void makeCharacter(Character _character)
	{
		if (hasCharacter(_character.getName()))
		{
			allCharacters.emplace(_character.getName(), _character);
		}
	}

	void markCharacterActive(const string& _characterName)
	{
		if (!hasCharacter(_characterName))
			return;

		auto& character = getCharacter(_characterName);

		if (!character.getIsActive())
			character.toggleCharacterActive();
	}	
	void markCharacterInactive(const string& _characterName)
	{
		if (!hasCharacter(_characterName))
			return;

		auto& character = getCharacter(_characterName);

		if (character.getIsActive())
			character.toggleCharacterActive();
	}

	const map<string, BoundValue>& getAttributes() const { return attributes; }

private:
	map<string, BoundValue> attributes;
	map<string, Character> allCharacters;

};

#endif //SETTLEMENT_H