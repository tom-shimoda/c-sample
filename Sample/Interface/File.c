#include <stdio.h>
#include "File.h"

// Fileクラスのopen()メソッドのインターフェース実装本体です
static void file_open(IFile* const p_this, const char* filename)
{
    // 第一引数は必ずインターフェースを実装したインスタンスへの
    // ポインタが代入されるように呼び出し元でルール化します
    File* const p = (File* const)p_this;

    // メンバ変数へもアクセスできます
    p->private_filename = filename;
    printf("file open!: %s\n", p->private_filename);
}

// Fileクラスのclose()メソッドのインターフェース実装本体です
//
// これらのインターフェース実装本体は直接コールせず
// 関数ポインタを格納した関数テーブルを経由してコールします
// (そのため、スコープをファイル内に制限しています)
static void file_close(IFile* const p_this)
{
    File* const p = (File* const)p_this;
    printf("file close! :%s\n", p->private_filename);
}

// Fileクラスのインターフェース実装へアクセスするための関数テーブルです
// (実行中に書き換えないため、定数で定義します)
static const InterfaceFileMethods FILE_METHODS = {
        file_open,
        file_close
};

// コンストラクタ
void File_construct( File* const p_this)
{
    // インターフェースを表現している構造体が格納する
    // 関数テーブルのポインタを初期化します。
    //
    // これにより、インターフェース定義からインターフェースの実装本体への
    // アクセスが設定されます
    ((IFile*)p_this)->p_methods = &FILE_METHODS;

    // メンバ変数も初期化します
    p_this->private_filename = NULL;
}
