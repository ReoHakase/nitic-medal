#define STRLEN 256 // 国名の文字型配列の長さ
#define ARRLEN 64 // 国別のデータを表す構造体が含まれる配列の長さ
#define CSVNAME "count.csv" // 入出力で扱うcsvファイルの名前
#define FILEHANDLEERROR -1 // ファイル入出力でエラーが出たときに返す(int)整数値

// 国のデータを示す構造体
struct _country {
  char name[STRLEN]; // 国名
  int gold; // 金メダルの数
  int silver;
  int bronze;
};

// 固定長(ARRLEN)の配列の中に、与えられる個数が変わり得る要素を入れる必要がある
// そこで、
// 1. 配列を宣言するときにその長さを十分に大きくする
// 2. 国のデータが入らない箇所は、それ特有の値をもつ構造体で埋める
// struct _country emptyCountry = {
//  {0}, 0, 0, 0
// };
// 0埋めかどうかを調べるための関数がこれ
int isEmptyCountry(const struct _country *country);

// 与えられたポインタが示す配列を空の国で埋める
void fillEmpty(struct _country *arrayPointer);

// 2つの_country構造体の入れ替え
void swapCountries(struct _country *a, struct _country *b);

// 与えられたポインタが示す配列へ、CSVファイルから読み込み
int readCsv(struct _country *arrayPointer);
// 与えられたポインタが示す配列から、CSVファイルへ書き込み
int writeCsv(struct _country *arrayPointer);

// 対象となる_country構造体の配列を、ポインタで指定された関数を基準に(Bubble Sortで)並び替え
void sort(struct _country *arrayPointer, const int (*funcPointer)(const struct _country *, const struct _country *));

// 並び替えの基準になる比較関数たち

// 総メダル獲得数で比較したいときの基準となる関数
// 配列内での番号(index)が小さい方の要素をleft,大きい方の要素をrightとしてうけとる。
// ２つの値を入れ替えたいときにfalseを返し、そのままにしておきたいときはtrueを返す。
int compareTotal(const struct _country *left, const struct _country *right);

// メダル順位で比較したいときの基準となる関数
// 配列内での番号(index)が小さい方の要素をleft,大きい方の要素をrightとしてうけとる。
// ２つの値を入れ替えたいときにfalseを返し、そのままにしておきたいときはtrueを返す。
int compareMedalRank(const struct _country *left, const struct _country *right);

// 国名のアルファベット順で比較したいときの基準となる関数
// 配列内での番号(index)が小さい方の要素をleft,大きい方の要素をrightとしてうけとる。
// ２つの値を入れ替えたいときにfalseを返し、そのままにしておきたいときはtrueを返す。
int compareNameAlphabetically(const struct _country *left, const struct _country *right);

// 与えられたポインタが示す配列の中身を、国別メダル獲得数の表として出力
void printTable(const struct _country *arrayPointer);