#include <strings.h>
#include <printf.h>
#include "Staff.h"

static char* Secret = "*****"; // クラスstatic変数

void Staff_Init(Staff* self,
                const char* name,
                int age,
                void (* onEndSelfIntroduction)())
{
    strcpy(self->name_, name);
    self->age_ = age;
    self->onEndSelfIntroduction_ = onEndSelfIntroduction;

    self->SaySelfIntroduction = Staff_SaySelfIntroduction; // メンバーポインタ関数に実装をセット
}

const char* Staff_GetName(const Staff* self)
{
    return self->age_ > 18 ? self->name_ : Secret;
}

int Staff_GetAge(const Staff* self)
{
    return self->age_;
}

void Staff_SaySelfIntroduction(const Staff* self)
{
    printf("%s's age_ is %d.\n", Staff_GetName(self), Staff_GetAge(self));

    self->onEndSelfIntroduction_();
}
