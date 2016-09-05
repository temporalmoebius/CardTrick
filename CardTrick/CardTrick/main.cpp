#include <vector>
#include <numeric>
#include <iostream>
#include "Deck.h"
#include <random>

std::pair<int,char> game(Deck& deck, const int n);
int get_num(const std::pair<int,char> card);
int randnum();

int main()
{

	Deck cards;
	int runs;
	std::cout << "Enter number of runs: ";
	std::cin >> runs;
	int tally{ 0 };
	for (auto i = 0; i < runs; i++) {
		std::pair<int, char> player_last_card = game(cards, randnum());
		std::pair<int, char> magic_last_card = game(cards, 1);
		if (player_last_card == magic_last_card)
			tally++;
		cards.shuffle();
	}
	int fails = runs - tally;
	std::cout << tally << " successes out of " << runs << std::endl;
	double success = static_cast<double>(tally) / static_cast<double>(runs);
	std::cout << "P(success) = " << success << " , P(failure) = " << 1 - success << std::endl;
	system("pause");
	return 0;
}

std::pair<int, char> game(Deck& deck, const int n)
{
	deck.index = n - 1;
	std::pair<int, char> new_card;
	do {
		new_card = deck.get_card();
		deck.index += get_num(new_card);
		//std::cout << new_card.first << " , " << deck.index << std::endl;
	} while (deck.index <= 51);
	return new_card;
		
}
int get_num(const std::pair<int, char> card)
{
	auto value = card.first;
	if (value > 10)
		return 5;
	else
		return value;
}
int randnum()
{
	std::random_device rng;
	std::mt19937 urng(rng());
	std::uniform_int_distribution<> dis(1, 10);
	return dis(urng);
}