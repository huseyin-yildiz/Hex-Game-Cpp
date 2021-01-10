#pragma once

#ifndef HEXARRAY1D_H_
#define HEXARRAY1D_H_

#include "AbstractHex.h"

class HexArray1D : public AbstractHex
{
public:
	void setSize(int size) final;
	void reset() final;
private:
	CellState* matrix;
};

#endif