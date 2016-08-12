/*
题目描述

狐进行了一次黑客马拉松大赛，全公司一共分为了N个组，每组一个房间排成一排开始比赛，比赛结束后没有公布成绩，但是每个组能够看到自己相邻的两个组里比自己成绩低的组的成绩，比赛结束之后要发奖金，以1w为单位，每个组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组发的奖金，就会不满意，作为比赛的组织方，根据成绩计算出至少需要发多少奖金才能让所有的组满意。


输入描述:
每组数据先输入N，然后N行输入N个正整数，每个数表示每个组的比赛成绩。


输出描述:
输出至少需要多少w的奖金

输入例子:
10
20
32
12
32
45
11
21
31
41
33

输出例子:
20
*/
/*
先按成绩把各组升序排序，然后从低成绩到高成绩依次发奖金
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct JudgeBy
{
	int i;//index
	int score;
};

bool compareScore(const JudgeBy &a,const JudgeBy &b){
	return a.score < b.score;
}
int main()
{
	int N;

	while (cin >> N)
	{
		vector<JudgeBy> scores(N);
		vector<int> money(N,0);
		for (int i = 0; i < N; ++i)
		{
			scores[i].i = i;
			cin >> scores[i].score;
		}
		sort(scores.begin(), scores.end(), compareScore);
		for (int i = 0; i < N; ++i) {
			int j = scores[i].i;
			if (0 == j) {
				money[0] = money[1] + 1;
			}
			else if (N - 1 == j) {
				money[N - 1] = money[N - 2] + 1;
			}else{
				money[j] = max(money[j - 1], money[j + 1]) + 1;
			}
		}
		int sum = 0;
		for (int i = 0; i < N; ++i)
			sum += money[i];
		cout << sum << endl;
	}
	return 0;
}