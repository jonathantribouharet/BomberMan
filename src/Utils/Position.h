#ifndef _POSITION_H_
#define _POSITION_H_

#include <cmath>
#include <map>

template<class Coord>
class Point2D{
	
	public:
		enum Direction {UP, DOWN, LEFT, RIGHT};
		
		Point2D(const Coord &_x = 0, const Coord &_y = 0)
		:x(_x),
		y(_y){
		}

		Point2D(const Point2D &point)
		:x(point.x),
		y(point.y){
		}
			
		Coord getX() const{
			return x;
		}
		
		Coord getY() const{
			return y;
		}
		
		void setX(const Coord &_x){
			x = _x;
		}
		
		void setY(const Coord &_y){
			y = _y;
		}
		
		void set(const Coord &_x, const Coord &_y){
			x = _x;
			y =_y;
		}
				
		bool operator ==(const Point2D &position) const{
			if(position.x == x && position.y == y){
				return true;
			}

			return false;
		}
		
		bool operator !=(const Point2D &position) const{
			return !operator==(position);
		}
										
		void move(const Direction &direction, const Coord &value = 1){
			switch(direction){
				case UP:
					y -= value;
					break;
				case DOWN:
					y += value;
					break;
				case RIGHT:
					x += value;
					break;
				case LEFT:
					x -= value;
					break;
			}
		}
		
	private:
		Coord x;
		Coord y;
};

typedef Point2D<float> Position;

#endif
