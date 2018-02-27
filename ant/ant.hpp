#pragma once

#include <cassert>
#include <iostream>

#include "point.hpp"
#include "grid.hpp"

using namespace std;

#define NCARD 4
#define PLUS_NINETY_DEG     (NCARD/4)
#define MINUS_NINETY_DEG    (2*NCARD/3)
 
#define PLUS_FORTYFIVE_DEG  (NCARD/8)    // NCARD  8
#define MINUS_FORTYFIVE_DEG (NCARD - 1)  // NCARD  8

#define BACK                (NCARD/2)

namespace AEDA {

	enum  Direction                {           N,           E,          S,           W };

	const char Direction_char[] =  {         '^',         '>',         'v',        '<' };
	const point move_direction[] = {point(-1, 0), point(0, 1), point(1, 0), point(0,-1)};
	
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

		virtual ~ant(void) {}
        
        	void turn_LEFT(void)  {direction_ = (direction_ + MINUS_NINETY_DEG) % NCARD;}
        	void turn_RIGHT(void) {direction_ = (direction_ + PLUS_NINETY_DEG) % NCARD;}
		void turn_back(void)  {direction_ = (direction_ + BACK) % NCARD;}
            
            void go_back(void) {turn_back(); go();}
		void go(void) {point::add(move_direction[direction_]);}
            
		void write(ostream& os) const {
			os << Direction_char[direction_];
		}	

            virtual void move(grid& G)
            {
             /*     if (G.is_in_bound(p))
                        go_back();
                  else
                        go();*/
            }
	};

      class ant_A: public ant
      {
      public:
            ant_A(const point& p, unsigned short d):
            ant(p, d) {}
            
            virtual ~ant_A(void) {}
            
            virtual void move(grid& G)
            {
             /*     if (G.is_in_bound(p))
                        go_back();
                  else
                        go();*/
            }
            
      };

}
