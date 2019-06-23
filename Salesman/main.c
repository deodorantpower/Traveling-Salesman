#include "main.h"

/**
* @file main
* @brief �z�Z�[���X�}�����̉���
* @author ���J��@�E��
* @date 2019/06/10
*/
int main(void) {

	PDATA pxy  [CITY];                     //�@���W�f�[�^ 
	DDATA cdata[CHILDREN];			       // �q�\����
	short anum [MAPNUM] = { 0,0,0,0 };	   // �͈͓��ɂ�����W�̌�
	short pmax = 0;                        // �͈͂ň�ԍ��W���������ꏊ

	// �\���̏�����	
	S_init(&pxy[0],&cdata[0]);

	// �|�����킹��
	srand((unsigned int)time(NULL));

	/**
	* STEP�P���W�̕��z�𕪂��e���z�ŏ��񏇔Ԃ����߂�
	**/
		// �S�̍��W�𕪊������z�����߂�
	    pmax = Mapping(&pxy[0], &anum[0]);
		
		// �͈͕ʂŃ\�[�g
		AreaSort(&pxy[0]);

		/**
		* STEP�Q���񂷂�
		* ����������
		**/
		for (int f = 0; f < LOOP; f++) {

			// �q�𐶐�����	
			for (short child = 0; child < CHILDREN; child++) {

				// 4�͈͏���
				for (short i = 0; i < MAPNUM; i++) {
					Seales(&pxy[0], &anum[0], i);
				}

				// �͈͍��W�̐ڑ�����
				for (short i = 0; i < CITY - 1; i++) {
					if (pxy[i].check != true) {
						pxy[i].check = true;
						Distance(sqrt(pow((pxy[i + 1].x - pxy[i].x), 2.0) + pow((pxy[i + 1].y - pxy[i].y), 2.0)), 1);
					}
				}

				// �q����
				cdata[child].distance = Distance(0, 2);

				// �������킹
				Change(&pxy[0], &anum[0], pmax);
				
				// �ˑR�ψ�
				if (rand() % 100 == 1) {
					pmax = CNum(0,MAPNUM);
				}

				// �������̃��Z�b�g
				Distance(0, 0);
			}

			// rank�\�[�g
			RankSort(&cdata[0]);
		}

		// �ēx�\�[�g����
		RankSort(&cdata[0]);

		printf("�ŒZ��%d��%0.5lf\n",cdata[0].rank, cdata[0].distance);
	

	system("pause");
	return 0;
}

