#ifndef C_SAMPLE_COMPLEX_H
#define C_SAMPLE_COMPLEX_H

struct Vector2;

typedef struct Complex
{
    float real; // 実数部分
    float imag; // 虚数部分
} Complex;

Complex Complex_Init(float degrees);

struct Vector2 Complex_ToVector2(Complex c);

Complex Complex_Mul(Complex a, Complex b);

#endif //C_SAMPLE_COMPLEX_H
