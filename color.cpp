#include "Color.h"
#include <stdexcept>

Color::Color(int r, int g, int b) 
{
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) 
    {
        throw std::out_of_range("The color value must be between 0 and 255");
    }
    red = static_cast<uint8_t>(r);
    green = static_cast<uint8_t>(g);
    blue = static_cast<uint8_t>(b);
}

std::ostream& operator<<(std::ostream& os, const Color& c) 
{
    os << "RGB(" << (int)c.red << ", " << (int)c.green << ", " << (int)c.blue << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Color& c) 
{
    int r, g, b;
    if (is >> r >> g >> b) 
    {
        c = Color(r, g, b);
    }
    return is;
}
