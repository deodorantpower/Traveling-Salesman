#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "data.h"

#ifndef CHANGE
#define CHANGE
extern void Change(PDATA*,short*, short);       
extern int CNum(int min, int max);              // �w��͈̗͂����𐶐�
void Swap(PDATA* pdata, int* cnum);             //  ���W����ւ�
#endif  