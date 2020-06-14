#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include "wx/wx.h"

namespace utility {

    /// accepts value 0-1 which will be mapped to red-blue color space
    wxColour mapToColour(double);


    // Normalizacja wartosci z danego przedzialu do innego przedzialu
    double map(double, double, double, double, double);

}



#endif