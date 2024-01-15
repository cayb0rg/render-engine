#include "GenMath.h"
#include "defs.h"

float GenMath::interpolate(float a, float b, float t)
{
    // y value = initial y-value + (x value - initial x-value) * slope
    return (a + (b - a) * t);
}
float GenMath::toRadians(float deg)
{
    return (PI/180) * deg;
}
float GenMath::toDegrees(float rad)
{
    return (180/PI) * rad;
}