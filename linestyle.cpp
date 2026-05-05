#include "linestyle.h"

LineStyle::LineStyle(const LineType& t, const int th) : type(t), thickness(th) 
{
    if (thickness <= 0) 
    {
        thickness = 1;
    }
}
