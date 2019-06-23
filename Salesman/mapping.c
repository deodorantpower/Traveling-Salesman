#include "mapping.h"

/**
* @file    Mapping
* @brief   À•W‚ª‚Ç‚Ì•ª•z‚É‘®‚µ‚Ä‚¢‚é‚©U‚è•ª‚¯‚é
* @author  ’·’Jì@—E‘¾
* @date    2019/06/12
* @param   distance :double
* @param   anum     :short*
* @return  ‚È‚µ     :void
*/
short Mapping(PDATA* data,short* anum) {
	short half = MAX_POSITION / 2;

	// U‚è•ª‚¯
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

short PMax(short* pmax) {

	short temp = 0;
	short num[MAPNUM] = { 0,1,2,3 };

	// ”ÍˆÍ‚É
	for (short i = 0; i < MAPNUM; i++) {
		for (short j = MAPNUM - 1; j > i; j--) {
			if (pmax[j] > pmax[j -1]) {
				temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
			}
		}
	}

	return num[0];
}

