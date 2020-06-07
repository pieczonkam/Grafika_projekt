#ifndef _COLOUR_HPP_
#define _COLOUR_HPP_

#include "wx/wx.h"

namespace utility {

    /// accepts value 0-1 which will be mapped to red-blue color space
    wxColour mapToColour(double);

    double map(double, double, double, double, double);

}



#endif