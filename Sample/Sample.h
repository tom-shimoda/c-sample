#ifndef C_SAMPLE_SAMPLE_H
#define C_SAMPLE_SAMPLE_H

typedef enum
{
    ObjectOriented,
    Thread,
    Math,
} SampleType;

void Sample_DoIt(SampleType type);

#endif //C_SAMPLE_SAMPLE_H
