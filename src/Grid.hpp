#ifndef GRID_HPP
#define GRID_HPP

#include "Cell.hpp"
#include "Pos.hpp"

#include <vector>
#include <unordered_map>
#include <optional>

class Grid {
public:
	Grid();
	
	void RandomGrid(int row, int col);
	void ClearGrid();
	void NextGen();
	
	std::vector<Cell> GetAlivesCells();
	
private:
	std::optional<Cell> GetCellAt(int x, int y);
	std::unordered_map<long int, Pos> GetPosToCheck();

	std::unordered_map<long int, Cell, PosHash> cells;
};

#endif // GRID_HPP