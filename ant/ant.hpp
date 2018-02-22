#pragma once

#include <cassert>
#include <iostream>

#include "point.hpp"

using namespace std;

#define NCARD 4

namespace AEDA {

	enum  Direction               {  N,   E,   S,   W };

	const char Direction_char[] = {'^', '>', 'v', '<' };
	const point_t move_direction[] = {point_t(-1, 0), point_t(0, 1), point_t(1, 0), point_t(0,-1)};
	
	class ant: public point {
        
	private:
		unsigned short direction_;

	public:
		ant(void):
        	point(),
		direction_(N) {}

		ant(const point& p, unsigned short d):
        	point(p),
		direction_(d)
		{
			assert(direction_ <= W);
		}

		~ant(void) {}

		unsigned short get_direction(void) const {return direction_;}
        
		void set_direction(unsigned short d){
			
			assert(direction_ <= W);
			direction_ = d;
		}
        
        	void turn_LEFT(void)  {direction_ = (direction_ + 3) % NCARD;}
        
        	void turn_RIGHT(void) {direction_ = (direction_ + 1) % NCARD;}
        
		void go_back(void) {direction_ = (direction_ + 2) % NCARD;}
		void go(void) {point_t::add(move_direction[direction_]);}
		void write(ostream& os) const {
		
			os << Direction_char[direction_];
		}		
	};
}

ostream& operator<<(ostream& os, const AEDA::ant& a)
{
	a.write(os);
	return os;
}
