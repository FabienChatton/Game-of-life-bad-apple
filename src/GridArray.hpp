#ifndef GRID_ARRAY_HPP
#define GRID_ARRAY_HPP

#include "Grid.hpp"

#include <vector>

class GridArray: public Grid {
public:
	void Init(int row, int col);
	void RandomGrid(int row, int col) override;
	void NextGen() override;
	std::vector<Cell> GetAlivesCells() override;
	void Clear() override;
	void SetAt(int row, int col, char state) override;
	
private:
	int row;
	int col;
	std::vector<std::vector<char>> grid;
	
	int GetNeighbor(int i, int j);
};

#endif // GRID_ARRAY_HPP