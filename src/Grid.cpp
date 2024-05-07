#include "Grid.hpp"

#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <stdexcept>

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
				cells.insert(std::make_pair(c.GetPos().ToLong(), c));
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
	std::unordered_map<long int, Cell> tmp = std::unordered_map<long int, Cell>();
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
			long int nLong = nCell.GetPos().ToLong();
			tmp.insert(std::make_pair(nLong, nCell));
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
	std::vector v = std::vector<Cell>();
	v.reserve(cells.size());
	for (auto k : cells) {
		v.push_back(k.second);
	}
	return v;
}

std::optional<Cell> Grid::GetCellAt(int x, int y)
{
	try {
		Cell c = cells.at(Pos::ToLong(x, y));
		return c;
	} catch (std::out_of_range &e) {
		return std::nullopt;
	}
}
