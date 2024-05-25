#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include <vector>

#include "Cell.hpp"

class InputOutput {
public:
	static void SaveAlivesCells(std::vector<Cell> cells);
	static std::vector<Cell> ReadCells();
	static std::vector<Cell> ReadCells(unsigned int i);
};

#endif // INPUT_OUTPUT_HPP