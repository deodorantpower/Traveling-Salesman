#include "main.h"

/**
* @file main
* @brief 循環セールスマン問題の解決
* @author 長谷川　勇太
* @date 2019/06/10
*/
int main(void) {

	PDATA pxy  [CITY];                     //　座標データ 
	DDATA cdata[CHILDREN];			       // 子構造体
	short anum [MAPNUM] = { 0,0,0,0 };	   // 範囲内にある座標の個数
	short pmax = 0;                        // 範囲で一番座標個数が多い場所

	// 構造体初期化	
	S_init(&pxy[0],&cdata[0]);

	// 掛け合わせの
	srand((unsigned int)time(NULL));

	/**
	* STEP１座標の分布を分け各分布で巡回順番を決める
	**/
		// 全体座標を分割し分布を求める
	    pmax = Mapping(&pxy[0], &anum[0]);
		
		// 範囲別でソート
		AreaSort(&pxy[0]);

		/**
		* STEP２巡回する
		* 成長させる
		**/
		for (int f = 0; f < LOOP; f++) {

			// 子を生成する	
			for (short child = 0; child < CHILDREN; child++) {

				// 4つ範囲巡回
				for (short i = 0; i < MAPNUM; i++) {
					Seales(&pxy[0], &anum[0], i);
				}

				// 範囲座標の接続部分
				for (short i = 0; i < CITY - 1; i++) {
					if (pxy[i].check != true) {
						pxy[i].check = true;
						Distance(sqrt(pow((pxy[i + 1].x - pxy[i].x), 2.0) + pow((pxy[i + 1].y - pxy[i].y), 2.0)), 1);
					}
				}

				// 子生成
				cdata[child].distance = Distance(0, 2);

				// かけあわせ
				Change(&pxy[0], &anum[0], pmax);
				
				// 突然変異
				if (rand() % 100 == 1) {
					pmax = CNum(0,MAPNUM);
				}

				// 総距離のリセット
				Distance(0, 0);
			}

			// rankソート
			RankSort(&cdata[0]);
		}

		// 再度ソートする
		RankSort(&cdata[0]);

		printf("最短は%d位%0.5lf\n",cdata[0].rank, cdata[0].distance);
	

	system("pause");
	return 0;
}

