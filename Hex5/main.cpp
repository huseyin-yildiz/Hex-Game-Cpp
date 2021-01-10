#include <iostream>
#include "HexVector.h"


int main()
{
	HexVector* game = new HexVector(7, "user1", "user2");
	game->print();
	Location location(0, 0);
	game->play(location);
	game->writeToFile("savedGame");

	for (int i = 0; i < 6; i++)
	{
		location.setByAdding(0, 1);
		game->play(location);
	}
	
	game->print();
	if (game->isEnd())
		cout << "oyun bitti"; ;
	game->readFromFile("savedGame");
	game->print();

}