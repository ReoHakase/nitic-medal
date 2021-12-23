#define STRLEN 256 // 国名の文字型配列の長さ
#define ARRLEN 64 // 国別のデータを表す構造体が含まれる配列の長さ
#define CSVNAME "count.csv" // 入出力で扱うcsvファイルの名前
#define FILEHANDLEERROR -1 // ファイル入出力でエラーが出たときに返す(int)整数値

// 国のデータを示す構造体

// struct _country ABC = {
//   "japan", 3, 2, 1
// }
// ABC.name // == "japan";

struct _country {
  char name[STRLEN]; // 国名
  int gold; // 金メダルの数
  int silver;
  int bronze;
};

// 可変長配列を実装するのはむずかしそうだから、固定長配列を使うしかない
// このとき、固定長(ARRLEN)の配列の中に、与えられる個数が変わり得る要素を入れる必要がある
// そこで、
// 1. 配列を宣言するときにその長さを十分に大きくする
// 2. 国のデータが入らない箇所は、それ特有の値をもつ構造体で埋める
// struct _country emptyCountry = {
//  {0}, 0, 0, 0
// };
// 0埋めかどうかを調べるための関数がこれ はしもとくん
int isEmptyCountry(const struct _country *country);

// 与えられたポインタが示す配列を空の国で埋める はしもとくん
void fillEmpty(struct _country *arrayPointer);

// 与えられたポインタが示す配列が含む空ではない国の数を数えて返す  たーくん
int countCountries(struct _country *arrayPointer);

// 2つの_country構造体の入れ替え ひゅうがじさん
void swapCountries(struct _country *a, struct _country *b);

// 与えられたポインタが示す配列に国を追加 追加に成功したらtrue, 失敗したらfalseを返す
int addCountry(struct _country *arrayPointer, const struct _country *country);

// -----

// 与えられたポインタが示す配列へ、CSVファイルから読み込み 白田
int readCsv(struct _country *arrayPointer);
// 与えられたポインタが示す配列から、CSVファイルへ書き込み
int writeCsv(struct _country *arrayPointer);

// -----

// 対象となる_country構造体の配列を、ポインタで指定された関数を基準に(Bubble Sortで)並び替え
void sort(struct _country *arrayPointer, const int (*funcPointer)(const struct _country *, const struct _country *));

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
int compareName(const struct _country *left, const struct _country *right);

// ---

// queryで指定された文字列を含む国だけを、target配列からresult配列にコピーする
void search(const struct _country *target, struct _country *result, char *query);

// 与えられたポインタが示す配列の中身を、国別メダル獲得数の表として出力
void printTable(const struct _country *arrayPointer);