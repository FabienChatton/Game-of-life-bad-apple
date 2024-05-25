#ifndef GRID_HPP
#define GRID_HPP

#include "Cell.hpp"
#include "Pos.hpp"

#include <vector>

class Grid {
public:
	Grid();
	virtual ~Grid() {};
	
	virtual void RandomGrid(int row, int col) = 0;
	virtual void NextGen() = 0;
	virtual std::vector<Cell> GetAlivesCells() = 0;
	virtual void Clear() = 0;
	virtual void SetAt(int row, int col, char state) = 0;
private:
	
};

#endif // GRID_HPP