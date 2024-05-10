#include "GridArray.hpp"

#include <time.h>
#include <stdlib.h>

void GridArray::RandomGrid(int row, int col)
{
	this->row = row;
	this->col = col;
	srand(time(0));
	grid = std::vector<std::vector<char>>(row);
	for (int i = 0; i < row; i++) {
		grid[i] = std::vector<char>(col);
		for (int j = 0; j < col; j++) {
			grid[i][j] = rand() % 2;
		}
	}
}

void GridArray::NextGen()
{
	std::vector tmp = std::vector<std::vector<char>>(row);

	for (int i = 0; i < row; i++) {
		tmp[i] = std::vector<char>(col);
		for (int j = 0; j < col; j++) {
			char datum = grid[i][j];
			int neighbor = GetNeighbor(i, j);

			if (datum == 1 && (neighbor == 2 || neighbor == 3)) {
				tmp[i][j] = 1;
			} else if (datum == 0 && neighbor == 3) {
				tmp[i][j] = 1;
			} else {
				tmp[i][j] = 0;
			}
		}
	}

	grid = tmp;
}

int GridArray::GetNeighbor(int i, int j)
{
	int neigbors = 0;
	for (int k = -1; k < 2; k++) {
		for (int h = -1; h < 2; h++) {
			if (k == 0 && h == 0) continue;

			int x = (k + i + row) % row;
			int y = (h + j + col) % col;

			neigbors += (int)grid[x][y];
		}
	}
	return neigbors;
}

std::vector<Cell> GridArray::GetAlivesCells()
{
	std::vector tmp = std::vector<Cell>();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 1) {
				Cell c(i, j);
				tmp.push_back(c);
			}
		}
	}

	return tmp;
}