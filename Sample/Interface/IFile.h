#ifndef C_SAMPLE_IFILE_H
#define C_SAMPLE_IFILE_H

// インターフェースが提供する関数のテーブルを保持する型を定義します
// (前方宣言です)
struct interfacefilemethods;

// インターフェース本体です
//
// このインターフェースが提供する関数を定義した
// 関数テーブルを保持する型のポインタのみを格納します。
typedef struct interfacefile
{
    const struct interfacefilemethods* p_methods;
} IFile;


// インターフェースが提供する関数(メソッド)のテーブルの定義です。
//
// それぞれの関数の第一引数はインターフェース本体のポインタ型に統一します
// このポインタには使用者側で具象クラスのインスタンスのポインタを代入するようにルール化します
typedef struct interfacefilemethods
{
    // 関数独自の引数は第二引数以降に定義します
    void (* open)(IFile* const, const char*);

    void (* close)(IFile* const);
} InterfaceFileMethods;

#endif //C_SAMPLE_IFILE_H

