#include<stdio.h>

int main()
{
	int N, teamScore[1001], teamID, stuID, score, maxScoreTeamID;
	for (int i = 1; i < 1001; ++i)teamScore[i] = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d-%d %d", &teamID, &stuID, &score);
		teamScore[teamID] += score;
	}
	maxScoreTeamID = 1;
	for (int i = 2; i < 1001; ++i)
	{
		if (teamScore[i]>teamScore[maxScoreTeamID])
			maxScoreTeamID = i;
	}
	printf("%d %d\n", maxScoreTeamID, teamScore[maxScoreTeamID]);
	return 0;
}