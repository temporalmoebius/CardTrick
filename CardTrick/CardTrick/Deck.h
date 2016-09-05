#pragma once

#include <vector>
#include <iostream>
#include <utility>

class Deck
{
public:
	Deck();
	void shuffle();
	void set_index(size_t&& n);
	std::pair<int, char>& get_card();
	~Deck();
	size_t index;
private:
	std::vector<std::pair<int, char>> cards;

};

