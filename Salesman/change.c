#include "change.h"


/**
* @file    Change
* @brief   指定範囲の中の座標を入れ替える指示
* @author  長谷川　勇太
* @date    2019/06/22
* @param   pdata  　　: PDATA*    : 座標データ
* @param   anum       : short*    : 範囲座標数
* @param   range      : short     : 成長範囲場所
* @return  　　       : void
*/
void Change(PDATA* pdata,short* anum ,short range) {
	
	int cnum[2] = { 0,0 };

	for (int i = 0; i < 2; i++) {

		// 座標が一番多い範囲を成長させる
		switch (range)
		{
		case 0:
			cnum[i] = CNum(0, anum[0] - 1);
			break;
		case 1:
			cnum[i] = CNum(anum[0], anum[0] + anum[1] - 1);
			break;
		case 2:
			cnum[i] = CNum(anum[0] + anum[1], anum[0] + anum[1] + anum[2] - 1);
			break;
		case 3:
			cnum[i] = CNum(anum[0] + anum[1] + anum[2], anum[0] + anum[1] + anum[2] + anum[3] - 1);
			break;
		default:
			break;
		}
	}
	// 範囲入れ替え
	Swap(&pdata[0], &cnum[0]);
}

/**
* @file    CNum
* @brief   指定範囲の中の乱数を返す
* @author  長谷川　勇太
* @date    2019/06/22
* @param   min  　  　: int    : 範囲最小
* @param   max        : int    : 範囲最大
* @return  cnum　　   : int    : 乱数を返す
*/
int CNum(int min, int max) {
	int cnum = 0;
	
	// 乱数を用いて巡回順を変える
	do {
		cnum = rand() % (min + max);

	} while (cnum < min || cnum > max);

	return cnum;
}


/**
* @file    Swap
* @brief   座標データの入れ替え
* @author  長谷川　勇太
* @date    2019/06/22
* @param   pdata    : PDATA*    : 座標データ
* @param   cnum     : int*      : 入れ替えデータ
* @return           : void      
*/
void Swap(PDATA* pdata, int* cnum) {

	//! 一時格納
	PDATA* temp  = &pdata[0];

	*temp = *(pdata + cnum[0]);
	*(pdata + cnum[0]) =  *(pdata + cnum[1]);
	*(pdata + cnum[1]) = *temp;
}