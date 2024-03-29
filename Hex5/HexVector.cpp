#include "HexVector.h"

HexVector::HexVector(int boardSize, string user1, string user2) : AbstractHex(user1, user2)
{
	setSize(boardSize);
}

void HexVector::setSize(int size)
{
	matrix.clear();

	if (size > 5 && size < 32)
	{
		for (int i = 0; i < size; i++)
		{
			vector<CellState> row;
			for (int j = 0; j < size; j++)
				row.push_back(CellState::dot);
			matrix.push_back(row);
		}
		boardSize = size;
	}
	else
		throw string("Size cant be"+ to_string(size)  +"size should be larger than 5 and smaller than 32") ;
}

void HexVector::reset()
{
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			matrix[i][j] = CellState::dot;
}

void HexVector::play(Location location)
{
	if (playerTurn == 1)																// if user turn is 1 
		matrix[location.get_x()][location.get_y()] = (CellState::user1);

	else if (playerTurn == 2)
		matrix[location.get_x()][location.get_y()] = (CellState::user2); 				// if turn is 2	

	lastLocation = location;	
	numberOfSteps++;
}

void HexVector::play()
{
	vector<Location> freeCells;
	for (int i = 0; i<boardSize; i++)
		for (int j = 0; j <boardSize; j++)								// finds free cells
			if (matrix[i][j] == CellState::dot)
				freeCells.push_back(Location(i,j));


	default_random_engine defEngine;
	uniform_int_distribution<int> intDistro(0, freeCells.size());					// selects one of them
	int randomIndex = intDistro(defEngine);						

	play( freeCells.at(randomIndex) );
}




CellState& HexVector::operator()(int i, int j)
{
	return matrix[i][j];
}



