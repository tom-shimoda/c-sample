#ifndef C_SAMPLE_SAMPLE_H
#define C_SAMPLE_SAMPLE_H

typedef enum
{
    SampleType_ObjectOriented,
    SampleType_Thread,
    SampleType_Math,
    SampleType_Interface,
    SampleType_Coroutine,
    SampleType_List,
} SampleType;

void Sample_DoIt(SampleType type);
void Sample_Init(SampleType type);
void Sample_Update(SampleType type);
void Sample_Exit(SampleType type);

#endif //C_SAMPLE_SAMPLE_H
