#include "init.h"
#include "position.h"

/**
* @file S_init
* @brief \‘¢‘Ì‚Ì‰Šú‰»
* @author ’·’Jì@—E‘¾
* @date 2019/06/10
* @param data :PDATA*
*/
void S_init(PDATA* pdata, DDATA* ddata) {

	for (int i = 0; i < CITY; i++) {
			pdata[i].x = xydate[i][0];
			pdata[i].y = xydate[i][1];
			pdata[i].rank = 0;
			pdata[i].check = false;
	}

	for (short i = 0; i < CHILDREN; i++) {
		ddata[i].distance = 0;
		ddata[i].rank = 0;
	}
}
