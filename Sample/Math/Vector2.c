#include "Vector2.h"
#include "Complex.h"

struct Complex Vector2_ToComplex(Vector2 v)
{
    struct Complex result;

    result.real = v.x;
    result.imag = v.y;

    return result;
}
