#ifndef C_SAMPLE_MATHUTIL_H
#define C_SAMPLE_MATHUTIL_H

#include <math.h>

// 度数をラジアンに変換する関数
float DegreesToRadians(float degrees)
{
    return (float)(degrees * M_PI / 180.0);
}

#endif //C_SAMPLE_MATHUTIL_H
