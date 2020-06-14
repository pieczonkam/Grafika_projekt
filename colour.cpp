#include "colour.hpp"

wxColour utility::mapToColour(double v) {
   
    return wxColour{ static_cast<unsigned char>(255 * (v)),
                    static_cast<unsigned char>(0),
                    static_cast<unsigned char>(255 * (1 - v)) };
}

double utility::map(double v, double e1, double e2, double m1, double m2) {
    double ret;

    if ((e2 - e1) == 0)
        ret = 0;
    else {
        ret = (m2 - m1) * (v - e1) / (e2 - e1) + m1;
    }
    
    return ret;
}