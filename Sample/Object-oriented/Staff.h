#ifndef C_SAMPLE_STAFF_H
#define C_SAMPLE_STAFF_H

typedef struct Staff_
{
    // メンバ変数の隠蔽は言語レベルでできない
    char name_[32]; // アンダースコアで始まるオブジェクトは使用不可なものが多いので使用は避けたほうが無難
    int age_;

    void (* onEndSelfIntroduction_)(); // コールバック変数

    // publicメソッドだけ定義
    void (* SaySelfIntroduction)(const struct Staff_*);
} Staff;

// コンストラクタ
void Staff_Init(Staff* self,
                const char* name,
                int age,
                void (* onEndSelfIntroduction)());

// privateメソッドはstaticをつけて隠蔽
static const char* Staff_GetName(const Staff* self);

static int Staff_GetAge(const Staff* self);

static void Staff_SaySelfIntroduction(const Staff* self);

#endif //C_SAMPLE_STAFF_H
