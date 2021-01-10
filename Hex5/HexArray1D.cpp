#include "HexArray1D.h"

void HexArray1D::setSize(int size)
{
	free(matrix);
	matrix = (CellState*) calloc(size * size, sizeof(CellState) );							// allocates some places for board
	boardSize = size;
	reset();
}

void HexArray1D::reset()
{
	for (int i = 0; i < (boardSize * boardSize); i++)													// filling the matrix with cellstate dot
		matrix[i] = CellState::dot;
}
