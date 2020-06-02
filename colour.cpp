#include "colour.hpp"

wxColour mapToColour(double v) {
    return wxColour{static_cast<unsigned char>(255*(v)), 
                    static_cast<unsigned char>(0),
                    static_cast<unsigned char>(255*(1 - v))};
}
