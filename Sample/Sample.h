#ifndef C_SAMPLE_SAMPLE_H
#define C_SAMPLE_SAMPLE_H

typedef enum
{
    ObjectOriented,
    Thread,
    Math,
    Interface,
    Coroutine,
    List,
} SampleType;

void Sample_DoIt(SampleType type);

void Sample_DoEveryFrame(SampleType type);

#endif //C_SAMPLE_SAMPLE_H
