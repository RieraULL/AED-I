#include <iostream>

#include "config.hpp"
#include "machine.hpp"
#include "point.hpp"

using namespace std;


int main(void)
{
    AEDA::config conf;
    
    conf.initial_position_  = AEDA::point(50,50);
    conf.initial_direction_ = AEDA::N;
    conf.rows_              = 100;
    conf.cols_              = 100;
    conf.max_iterations_    = 99999;
    
	AEDA::machine M(conf);    
}
