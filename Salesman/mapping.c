#include "mapping.h"

/**
* @file    Mapping
* @brief   座標がどの分布に属しているか振り分ける
* @author  長谷川　勇太
* @date    2019/06/12
* @param   data     : PDATA*    : 座標データ 
* @param   anum     : short*    : 範囲座標数
* @return  なし     : void      
*/
short Mapping(PDATA* data,short* anum) {
	short half = MAX_POSITION / 2;

	// 振り分け
	for (short i = 0; i < CITY; i++) {
		if (data[i].x > 0 && data[i].x < half) {
			if (data[i].y > 0 && data[i].y < half) {
				data[i].rank = 0; 
				anum[0] += 1;
			}
		}

		if (data[i].x > half && data[i].x < MAX_POSITION) {
			if (data[i].y > 0 && data[i].y < half) {
				data[i].rank = 1;
				anum[1] += 1;
			}
		}

		if (data[i].x > half && data[i].x < MAX_POSITION) {
			if (data[i].y > half && data[i].y < MAX_POSITION) {
				data[i].rank = 2;
				anum[2] += 1;
			}
		}

		if (data[i].x > 0 && data[i].x < half) {
			if (data[i].y > half && data[i].y < MAX_POSITION) {
				data[i].rank = 3; 
				anum[3] += 1;
			}
		}

	}

	return PMax(&anum[0]);
 }

/**
* @file    Mapping
* @brief   座標がどの分布に属しているか振り分ける
* @author  長谷川　勇太
* @date    2019/06/12
* @param   pmax     :short*   : 範囲座標数
* @return           :short    : 一番座標数が多い範囲の番号
*/
short PMax(short* anum) {

	short temp = 0;
	short num[MAPNUM] = { 0,1,2,3 };

	// 範囲に
	for (short i = 0; i < MAPNUM; i++) {
		for (short j = MAPNUM - 1; j > i; j--) {
			if (anum[j] > anum[j -1]) {
				temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
			}
		}
	}

	return num[0];
}

