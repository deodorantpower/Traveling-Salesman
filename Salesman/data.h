#include <stdbool.h>
#include <time.h>

#define LOOP          10000
#define MAX_POSITION    100
#define CITY             64
#define CHILDREN         10
#define MAPNUM            4


#ifndef DATA
#define DATA

// ���W�f�[�^�\����
typedef struct {
	double x;
	double y;
	short rank;  // �͈͂̂ǂ���
	bool check;
}PDATA;

// �������f�[�^
typedef struct {
	short rank;
	double distance;
}DDATA;

#endif
