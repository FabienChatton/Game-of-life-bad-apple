#include "Grid.hpp"

#include <time.h>
#include <stdlib.h>
#include <algorithm>

Grid::Grid()
{
	
}

void Grid::RandomGrid(int row, int col)
{
	srand(time(0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (rand() % 2 == 0) {
				Cell c(i, j);
				cells.push_back(c);
			}
		}
	}
	
	/*
	Cell c(10, 10); cells.push_back(c);
	Cell c1(11, 10); cells.push_back(c1);
	Cell c2(12, 10); cells.push_back(c2);
	*/
}

void Grid::ClearGrid()
{
	cells.clear();
}

void Grid::NextGen()
{
	std::vector<Cell> tmp = std::vector<Cell>();
	std::vector<Pos> toCheck = GetPosToCheck();
	
	for (unsigned int i = 0; i < toCheck.size(); i++) {
		Pos pos = toCheck[i];
		int x = pos.GetX();
		int y = pos.GetY();
		unsigned int count = 0;
		for (int j = -1; j <= 1; j++) {
			for (int k = -1; k <= 1; k++) {
				if (j == 0 && k == 0) continue;
				int nX = x + j;
				int nY = y + k;
				std::optional opt = GetCellAt(nX, nY);
				
				count += opt.has_value();
			}
		}
		
		bool alive = GetCellAt(x, y).has_value();
		bool ok = false;
		if (alive && (count == 2 || count == 3)) {
			ok = true;
		} else if (!alive && count == 3) {
			ok = true;
		} 
		
		if (ok) {
			Cell nCell(x, y);
			// if not found
			if (std::find(tmp.begin(), tmp.end(), nCell) == tmp.end()) {
				tmp.push_back(nCell);
			}
		}
	}
	
	cells = tmp;
}

std::vector<Pos> Grid::GetPosToCheck()
{
	std::vector<Pos> tmp;
	std::vector<Cell> alivesCell = GetAlivesCells();
	
	for (unsigned int i = 0; i < alivesCell.size(); i++) {
		Pos pos = alivesCell[i].GetPos();
		tmp.push_back(pos);
		for (int j = -1; j <= 1; j++) {
			for (int k = -1; k <= 1; k++) {
				// if (j == 0 && k == 0) continue;
				int nX = pos.GetX() + j;
				int nY = pos.GetY() + k;
				std::optional opt = GetCellAt(nY, nX);
				
				if (opt.has_value()) continue;
				
				Pos nPos(nX, nY);
				
				// if not found
				if (std::find(tmp.begin(), tmp.end(), nPos) == tmp.end()) {
					tmp.push_back(nPos);
				}
			}
		}
	}
	
	return tmp;
}

std::vector<Cell> Grid::GetAlivesCells()
{
	return cells;
}

std::optional<Cell> Grid::GetCellAt(int x, int y)
{
	for (unsigned int i = 0; i < cells.size(); i++) {
		Cell c = cells[i];
		Pos pos = c.GetPos();
		int ox = pos.GetX();
		int oy = pos.GetY();
		if (ox == x && oy == y) {
			return c;
		}
	}
	
	return std::nullopt;
}