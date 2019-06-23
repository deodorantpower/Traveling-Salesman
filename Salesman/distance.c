#include "distance.h"

/**
* @file     Distance
* @brief    総距離管理する
*			第二引数により返す値を変化させる
*           (第一引数,0) = 総距離をリセットする 
*           (第一引数,1) = 第一引数を総距離に加算する
*           (第一引数,2) = 現在までの総距離をそのまま返す
* @author   長谷川　勇太
* @date     2019/06/12
* @param    distance     :double
* @param    flg          :short
* @return   総距離を返す :double
* 
*/
double Distance(double distance,short flg) {

	static double all_distance = 0;

	switch (flg)
	{
	case 0:    
		return all_distance = 0;
	case 1:
		return all_distance += distance;
	case 2:
		return all_distance;
	default:
		return -1;
	}
}