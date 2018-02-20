#pragma once

#include <cassert>
#include <iostream>

#include "point.hpp"

using namespace std;

namespace AEDA {

	enum       Direction          {  N,   S,   E,   W };

	const char Direction_char[] = {'^', 'v', '<', '>' };

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
