#define STRLEN 256 // 国名の文字型配列の長さ
#define ARRLEN 64 // 国別のデータを表す構造体が含まれる配列の長さ
#define CSVNAME "count.csv" // 入出力で扱うcsvファイルの名前
#define FILEHANDLEERROR -1

struct _country {
  char name[STRLEN]; // 国名
  int gold; // 金メダルの数
  int silver;
  int bronze;
};

// 渡されたポインタが指す国の構造体が、0埋めで初期化されたままのときtrueを返す
// 利用例 --- 固定長配列の中に、与えられる数が変わり得る国の構造体を入れる必要がある
// そこで、
// 1. 配列を宣言するときにその長さを十分に大きくする
// 2. 国のデータが入らない箇所は、すべて0で埋める
// 3. 並び替えや表示の際は0埋めの国はないものとして扱う
// 0埋めかどうかを調べるための関数がこれ
int isEmptyCountry(const struct _country *country);

// CSVファイルから読み込み
int importCsv(struct _country *arrayPointer);
// CSVファイルへ書き込み
int exportCsv(struct _country *arrayPointer);

// 2つの_country構造体の入れ替え
void swapCountries(struct _country *a, struct _country *b);

// 対象となる_country構造体の配列を、ポインタで指定された関数を基準に並び替え
void sort(struct _country *arrayPointer, const int (*funcPointer)(const struct _country *, const struct _country *));

// 並び替えの基準になる比較関数たち
// 配列内での番号(index)が小さい方の要素をleft,大きい方の要素をrightとしてうけとる。
// ２つの値を入れ替えたいときにfalseを返し、そのままにしておきたいときはtrueを返す。
// 総メダル獲得数で比較
int compareTotal(const struct _country *left, const struct _country *right);
// メダル順位で比較
int compareMedalRank(const struct _country *left, const struct _country *right);
// 国名のアルファベット順で比較
int compareNameAlphabetically(const struct _country *left, const struct _country *right);


void printCountries(const struct _country *arrayPointer);