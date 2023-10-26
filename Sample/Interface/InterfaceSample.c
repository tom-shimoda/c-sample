#include "InterfaceSample.h"

#include "File.h"

int InterfaceSample(void)
{
    // インターフェースを実装したFileクラスのインスタンスです
    File f;

    const char filename[] = "sample.txt";

    // コンストラクタは手動で呼ぶ必要があるためコールします
    //
    // この中でFileクラス向けに定義した関数テーブルが
    // インスタンスfにセットされることになります
    File_construct(&f);

    // FileクラスはInterfaceFileインターフェースを実装しているため
    // 安全にInterfaceFile型のポインタにキャストできます
    file_processing((IFile*)&f, filename);

    return 0;
}


// インターフェースにより、具象クラスを意識することなく
// 関数の処理を実装することができます
static void file_processing(IFile* const p_file, const char* filename)
{
    // 各メソッドの第一引数には必ずインターフェース自身のポインタを代入します
    //
    // これにより、各メソッドの実装側で第一引数を経由して
    // インスタンス自身へアクセスすることができます
    p_file->p_methods->open(p_file, filename);

    // 何らかの処理・・・

    p_file->p_methods->close(p_file);
}
