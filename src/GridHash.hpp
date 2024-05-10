#ifndef GRID_HASH_HPP
#define GRID_HASH_HPP

#include "Grid.hpp"

#include <vector>
#include <optional>
#include <unordered_map>

class GridHash: public Grid {
public:
	void RandomGrid(int row, int col) override;
	void NextGen() override;
	std::vector<Cell> GetAlivesCells() override;

private:
	std::unordered_map<long int, Cell, PosHash> cells;
	std::optional<Cell> GetCellAt(int x, int y);
	std::unordered_map<long int, Pos> GetPosToCheck();
};

#endif // GRID_HASH_HPP