#include "InputOutput.hpp"

#include <iostream>
#include <fstream>


void InputOutput::SaveAlivesCells(std::vector<Cell> cells)
{
	std::ofstream out("assets/output.txt");
	
	for (unsigned int i = 0; i < cells.size(); i++) {
		Cell c = cells[i];
		Pos p = c.GetPos();
		
		out << std::to_string(p.GetX());
		out << " ";
		out << std::to_string(p.GetY());
		out << " ";
	}
}

std::vector<Cell> InputOutput::ReadCells()
{
	int a, b;
	std::vector<Cell> tmp = std::vector<Cell>();
	std::ifstream infile("assets/input.txt");
	
	while (infile >> a >> b)
	{
		Cell c(a, b);
		tmp.push_back(c);
	}
	return tmp;
}

std::vector<Cell> InputOutput::ReadCells(unsigned int i)
{
	int a, b;
	std::vector<Cell> tmp = std::vector<Cell>();
	std::string badAppleFileName = "assets/input" + std::to_string(i);
	badAppleFileName += ".txt"; 
	std::ifstream infile(badAppleFileName);
	
	while (infile >> a >> b)
	{
		Cell c(a, b);
		tmp.push_back(c);
	}
	return tmp;
}