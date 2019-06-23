#include <stdbool.h>
#include <time.h>

#define LOOP          10000
#define MAX_POSITION    100
#define CITY             64
#define CHILDREN         10
#define MAPNUM            4


#ifndef DATA
#define DATA

// 座標データ構造体
typedef struct {
	double x;
	double y;
	short rank;  // 範囲のどこか
	bool check;
}PDATA;

// 総距離データ
typedef struct {
	short rank;
	double distance;
}DDATA;

#endif
