# CardTrick
C++ parallel program to solve card problem

A magician shuffles a standard 52-card deck of playing cards.
He asks the player to pick a random number between 1 and 10.
Then, he deals and reveals, in order, that number of cards.

The last card dealt has a numeric value:
    1 if rank is Ace
    2-10 (Face value) if rank is 2-10
    5 if rank is Jack, Queen or King ("picture")

That value of the last card determines the next number of cards dealt.
The numeric value of the new card repeats this process,
  until the numeric value is larger than the number of cards left in the deck.

This final card is recorded.

The magician then collects all the dealt cards and places any unused cards at the bottom of the deck.
    This results in the SAME DECK used for the player.
THe magician then repeats the game, however he chooses to deal 1 card at the beginning instead.

What is the probability the magician will recieve the same card as the player?
