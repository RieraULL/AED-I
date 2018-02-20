#pragma once

#include <cassert>
#include <iostream>

#include "point.hpp"

using namespace std;

namespace AEDA {

	enum       Direction          {  N,   S,   E,   W };

	const char Direction_char[] = {'^', 'v', '<', '>' };

	class ant {
        
	private:
        point          position_;
		unsigned short direction_;

	public:
		ant(void):
        position_(),
		direction_(N) {}

		ant(const point& p, unsigned short d):
        position_(p),
		direction_(d)
		{
			assert(direction_ <= W);
		}

		~ant(void) {}

		unsigned short get_direction(void) const {return direction_;}
        
        const point& get_position(void) const {return position_;}

		void set_direction(unsigned short d){
			
			assert(direction_ <= W);
			direction_ = d;
		}
        
        void set_position(const point& p) {
                        
            position_ = p;
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
