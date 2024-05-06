#ifndef POS_HPP
#define POS_HPP

class Pos {
public:
	Pos(int x, int y);
	int GetX() const;
	int GetY() const;
	
	bool operator==(const Pos &other) const;

private:

	int x;
	int y;
	
};

#endif // POS_HPP