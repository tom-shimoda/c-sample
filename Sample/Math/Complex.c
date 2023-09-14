#include "Complex.h"
#include "Vector2.h"
#include "MathUtil.h"

Complex Complex_Init(float degrees)
{
    Complex result;
    float rad = DegreesToRadians(degrees);

    result.real = cosf(rad);
    result.imag = sinf(rad);

    return result;
}

struct Vector2 Complex_ToVector2(Complex c)
{
    struct Vector2 result;

    result.x = c.real;
    result.y = c.imag;

    return result;
}

Complex Complex_Mul(Complex a, Complex b)
{
    Complex ans;

    ans.real = a.real * b.real - a.imag * b.imag;
    ans.imag = a.real * b.imag + a.imag * b.real;

    return (ans);
}
