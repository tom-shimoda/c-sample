#ifndef C_SAMPLE_VECTOR2_H
#define C_SAMPLE_VECTOR2_H

struct Complex;

typedef struct Vector2
{
    float x;
    float y;
} Vector2;


struct Complex Vector2_ToComplex(Vector2 v);

#endif //C_SAMPLE_VECTOR2_H
