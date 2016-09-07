#pragma once

#include <vector>
#include <iostream>
#include <utility>

class Deck
{
public:
	Deck();
	void shuffle();	//Randomly re-arranges Deck.cards
	std::pair<int, char>& get_card();	//Returns Deck.cards.at(Deck.index)
	~Deck();
	size_t index;
private:
	std::vector<std::pair<int, char>> cards;

};

