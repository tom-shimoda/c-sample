#include <printf.h>
#include "Rotate2D.h"

#include "Vector2.h"
#include "Complex.h"

void Rotate2DSample()
{
    Vector2 v = {1, 3};
    float degrees = 90;
    Complex rotate_complex = Complex_Init(degrees); // 回転複素数 (３次元でいうクォータニオン的な)
    printf("(%f, %f) rotate %f degrees.\n", v.x, v.y, degrees);

    Complex mul = Complex_Mul(Vector2_ToComplex(v), rotate_complex);
    Vector2 res = Complex_ToVector2(mul);

    printf("(%f, %f)\n", res.x, res.y);
}
