#include "sort.h"

/**
* @file     AreaSort
* @brief    �͈͂̏��Ԃ��\�[�g����
* @author   ���J��@�E��
* @date     2019/06/11
* @param    distance :double
* @param    anum    :short*
* @return   �Ȃ�     :void
*/
void AreaSort(PDATA* data) {

	//! �ꎞ�i�[
	PDATA temp;
	// �\�[�g
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
* @brief   rank�̃\�[�g
* @author  ���J��@�E��
* @date    2019/06/20
* @param   ddata    :DDATA*
* @return  �Ȃ�     :void
*/
void RankSort(DDATA* ddata) {
	//! �ꎞ�i�[
	DDATA temp;
	// �\�[�g
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

