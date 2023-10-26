#ifdef WINDOWS
#include <stdio.h>
#elif MAC
#include <printf.h>
#endif

#include "Object-oriented.h"
#include "Staff.h"

static void OnEndSelfIntroduction()
{
    printf("Self-Introduction finished.\n");
}

void ObjectOrientedSample()
{
    Staff staff;
    Staff_Init(&staff, "Tom", 20, OnEndSelfIntroduction);

    staff.SaySelfIntroduction(&staff);
}