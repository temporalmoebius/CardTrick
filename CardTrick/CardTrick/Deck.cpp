//#include <utility>
#include <random>
#include <algorithm>

#include "Deck.h"


Deck::Deck()
	:index(0)	//initialise index to 0; cards to empty
{
	std::string i_suits = "CSHD";
	for (auto suit : i_suits)
		for (auto rank = 1; rank < 14; rank++)
			cards.push_back(std::make_pair(rank, suit));
	Deck::shuffle();
}

void Deck::shuffle()
{
	std::random_device rng;
	std::mt19937 urng(rng());
	std::shuffle(cards.begin(), cards.end(), urng);
}

std::pair<int,char>& Deck::get_card()
{
	return cards.at(index);
}

Deck::~Deck()
{
}
