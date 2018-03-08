#pragma once

#define NCOLORS 2

namespace AEDA {
    
    typedef unsigned short color_t;
      
    enum Background                { WHITE , BLACK, RED, GREEN};
    const char Background_char[] = {   ' ',    'B', 'R',   'G'};      
}