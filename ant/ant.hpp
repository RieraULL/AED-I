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

namespace AEDA
{



enum  Direction                {           N,           E,          S,           W };

const char Direction_char[] =  {         '^',         '>',         'v',        '<' };
const point move_direction[] = {point(-1, 0), point(0, 1), point(1, 0), point(0,-1)};

enum Turn                      {L, R, B};


class ant: public point
{
private:
    typedef void (ant::*turn_func_t)(void);

private:
    unsigned short direction_;

    const turn_func_t turn_function[3] = {&ant::turn_LEFT, &ant::turn_RIGHT, &ant::turn_BACK};

public:
    ant(void):
        point(),
        direction_(N)
    {
    }

    ant(const point& p, unsigned short d):
        point(p),
        direction_(d)
    {
        assert(direction_ <= W);
    }

    virtual ~ant(void) {}

    virtual void write(ostream& os) const
    {
        os << Direction_char[direction_];
    }

    virtual void move(grid& G) {
        
        change_direction(G.get_color(*this));
        go();
        
    }

protected:

    void turn_LEFT(void)
    {
        direction_ = (direction_ + MINUS_NINETY_DEG) % NCARD;
    }

    void turn_RIGHT(void)
    {
        direction_ = (direction_ + PLUS_NINETY_DEG) % NCARD;
    }

    void turn_BACK(void)
    {
        direction_ = (direction_ + BACK) % NCARD;
    }

    void change_direction(int d)
    {
        (this->*turn_function[d])();
    }

    void go(void)
    {
        point::add(move_direction[direction_]);
    }

};




class ant_DDII: public ant
{
private:

    const int Direction[4] = {R, R, L, L};
    
public:
    ant_DDII(const point& p, unsigned short d):
        ant(p, d) {}

    virtual ~ant_DDII(void) {}

};

}
