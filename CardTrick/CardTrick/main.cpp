#include <vector>
#include <iostream>
#include <random>
#include <omp.h>

#include "Deck.h"

std::pair<int,char> game(Deck& deck, const int n);	//instance of card game
int get_num(const std::pair<int,char>& card);		//return numeric value of card
int randnum();										//MT random int between 1 and 10

//Number of concurrent threads running instances
#define NUM_THREADS 8

int main()
{
	std::cout << "Enter number of runs: ";
	int runs{0};
	std::cin >> runs;

	double start = omp_get_wtime();
	int main_tally{ 0 };					//total number of successes go here

	omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
{
	int tally{ 0 };
	Deck cards;
	
	int thread_runs = runs / omp_get_num_threads();	//split load between threads
	if (omp_get_thread_num() == 0)
		thread_runs += runs % omp_get_num_threads();	//master thread runs remainder

	for (auto i = 0; i < thread_runs; i++) {
		std::pair<int, char> player_last_card = { game(cards, randnum()) };
		std::pair<int, char> magic_last_card = { game(cards, 1) };
		if (player_last_card == magic_last_card)
			tally++;
		cards.shuffle();
	}

#pragma omp atomic
	main_tally += tally;

}

	double end = omp_get_wtime();
	std::cout << "Program finished in " << end - start << " seconds" << std::endl;

	int fails = runs - main_tally;
	std::cout << main_tally << " successes out of " << runs << std::endl;

	double success = static_cast<double>(main_tally) / static_cast<double>(runs);
	std::cout << "P(success) = " << success << " , P(failure) = " << 1 - success << std::endl;

	system("pause");
	return 0;
}

std::pair<int, char> game(Deck& deck, const int n)
{
	deck.index = n - 1;	//0-indexed; deal n cards initially
	std::pair<int, char> new_card;	//most recently dealt card goes here
	do {
		new_card = deck.get_card();	//deal card at index
		deck.index += get_num(new_card);	//advance index by value of card
	} while (deck.index <= 51);		//if next card beyond end of deck, end loop

	return new_card;
		
}
int get_num(const std::pair<int, char>& card)
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