#include "distance.h"

/**
* @file     Distance
* @brief    �������Ǘ�����
*			�������ɂ��Ԃ��l��ω�������
*           (������,0) = �����������Z�b�g���� 
*           (������,1) = �������𑍋����ɉ��Z����
*           (������,2) = ���݂܂ł̑����������̂܂ܕԂ�
* @author   ���J��@�E��
* @date     2019/06/12
* @param    distance     :double
* @param    flg          :short
* @return   ��������Ԃ� :double
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