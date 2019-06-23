#include "change.h"


void Change(PDATA* pdata,short* anum ,short range) {
	
	int cnum[2] = { 0,0 };

	for (int i = 0; i < 2; i++) {

		// À•W‚ªˆê”Ô‘½‚¢”ÍˆÍ‚ð¬’·‚³‚¹‚é
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
	// ”ÍˆÍ–ˆ‚É“ü‚ê‘Ö‚¦‚é
	Swap(&pdata[0], &cnum[0]);
}

/*
* 
*
*/
int CNum(int min, int max) {
	int cnum = 0;
	
	// —”‚ð—p‚¢‚Ä„‰ñ‡‚ð•Ï‚¦‚é
	do {
		cnum = rand() % (min + max);

	} while (cnum < min || cnum > max);

	return cnum;
}

void Swap(PDATA* pdata, int* cnum) {

	//! ˆêŽžŠi”[
	PDATA* temp  = &pdata[0];

	*temp = *(pdata + cnum[0]);
	*(pdata + cnum[0]) =  *(pdata + cnum[1]);
	*(pdata + cnum[1]) = *temp;


}