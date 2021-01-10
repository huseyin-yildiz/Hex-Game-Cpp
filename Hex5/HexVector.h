#pragma once
#ifndef HEXVECTOR_H_
#define HEXVECTOR_H_


#include<iostream>
#include"AbstractHex.h"
#include<vector>
#include<string>
#include <random>

using namespace std;


class HexVector : public AbstractHex
{
public:
    HexVector(int boardSize, string user1, string user2);
    void setSize(int size) final;  // throws string
    void reset() final;
    void  play(Location location) final;
    void play() final;

    //bool isEnd() final;
    CellState& operator()(int i,int j) final;



private:
    vector< vector<CellState> > matrix;


};


#endif

