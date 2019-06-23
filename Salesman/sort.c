#include "sort.h"

/**
* @file     AreaSort
* @brief    範囲の順番をソートする
* @author   長谷川　勇太
* @date     2019/06/11
* @param    distance :double
* @param    anum    :short*
* @return   なし     :void
*/
void AreaSort(PDATA* data) {

	//! 一時格納
	PDATA temp;
	// ソート
	for (short i = 0; i < CITY; i++) {
		for (short j = CITY - 1; j > i; j--) {
			if (data[j].rank < data[j - 1].rank) {
				memcpy(&temp, &data[j], sizeof(PDATA));
				memcpy(&data[j], &data[j - 1], sizeof(PDATA));
				memcpy(&data[j - 1], &temp, sizeof(PDATA));
			}
		}
	}
}

/**
* @file    RankSort
* @brief   rankのソート
* @author  長谷川　勇太
* @date    2019/06/20
* @param   ddata    :DDATA*
* @return  なし     :void
*/
void RankSort(DDATA* ddata) {
	//! 一時格納
	DDATA temp;
	// ソート
	for (short i = 0; i < MAPNUM; i++) {
		for (short j = MAPNUM - 1; j > i; j--) {
			if (ddata[j].distance < ddata[j - 1].distance) {
				memcpy(&temp, &ddata[j], sizeof(PDATA));
				memcpy(&ddata[j], &ddata[j - 1], sizeof(PDATA));
				memcpy(&ddata[j - 1], &temp, sizeof(PDATA));
			}
		}
	}
	for (short i = 0; i < MAPNUM; i++) {
		ddata[i].rank = i+1;
	}
}

