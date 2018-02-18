#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

#include "point_t.hpp"

using namespace std;

 class line_equ_t {
    private:
        double m_;
        double c_;
        
    public:
        line_equ_t (void):
        m_(0),
        c_(0) {}
        
        line_equ_t (double m, double c):
        m_(m),
        c_(c) {}   

        line_equ_t (const point_t& p1, const point_t& p2):
        m_(0),
        c_(0) 
	{            
            m_ = (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
            c_ = -p1.get_x() * m_ + p2.get_y();
        }

	~line_equ_t (void) {}  

	double get_m(void) const {return m_;}
	double get_c(void) const {return c_;}

	void set(double m, double c)
	{
		m_= m;
		c_= c; 
	}

        double distance(const point_t& p) const
        {
            const double d = fabs(m_* p.get_x() - p.get_y() + c_)/sqrt(m_ * m_ + 1);
            return d;
        }

	void write(ostream& os) const
	{
		os << "y = ";
		os << setw(6) << fixed << setprecision(2) << m_;
		os << "x + ";
		os << setw(6) << fixed << setprecision(2) << c_;
	}      
    };

