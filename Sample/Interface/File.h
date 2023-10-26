#ifndef C_SAMPLE_FILE_H
#define C_SAMPLE_FILE_H

#include "IFile.h"

typedef struct file
{
    // インターフェースを実装(implements)するために
    // 継承と同様にインターフェース型の変数をクラスの先頭に定義します

    // 継承と同じ表現とすることでインターフェース型のポインタ変数に
    // 安全にキャストして代入することができます
    IFile interface;

    // このクラス独自のメンバ変数は
    // インターフェースの下に定義します
    const char* private_filename;
} File;

// 通常のクラスと同様に公開関数を定義します
// (インターフェースで定義される関数は除きます)
void File_construct(File* const p_this);

#endif //C_SAMPLE_FILE_H

