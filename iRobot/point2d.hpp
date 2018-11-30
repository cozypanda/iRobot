#ifndef INCLUDED_PATCHBOT_POINT2D_HPP
#define INCLUDED_PATCHBOT_POINT2D_HPP


class point2d
{
private:
	int x;
	int y;
public:
	point2d(int x_coordinate, int y_coordinate);
	point2d() = delete;
	~point2d();
	int getX();
	int getY();
	void setX(int new_x_value);
	void setY(int new_y_value);
};
#endif // !INCLUDED_PATCHBOT_POINT2D_HPP
