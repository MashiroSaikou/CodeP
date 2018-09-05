#include "iostream"
#include "iomanip"
#include "algorithm"
//#include "climits"

#define INF 0x3f3f3f3f
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M, C1, C2;
	cin>>N>>M>>C1>>C2;
	int number_of_rescueteam[501];
	for (int i = 0; i < N; ++i)
	{
		cin>>number_of_rescueteam[i];
	}

	int city_weight[501][501];
	int distance[501];
	for (int i = 0; i < N; ++i)
	{
		distance[i] = INF;
		for (int j = 0; j < N; ++j)
		{
			city_weight[i][j] = INF;
		}
	}
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin>>a>>b>>c;
		city_weight[a][b] = c;
		city_weight[b][a] = c;
	}

	bool *visited = new bool[501]();
	int *path_count = new int[501]();
	int *every_amount = new int[501]();
	int min_of_rest = C1;
	every_amount[C1] = number_of_rescueteam[C1];
	path_count[C1] = 1;
	distance[C1] = 0;

	while(1)
	{
		int min_distance = INF;
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] != true&&distance[i] < min_distance)
			{
				min_of_rest = i;
				min_distance = distance[i];
			}
		}

		if (min_distance == INF||min_of_rest == C2)
		{
			break;
		}

		visited[min_of_rest] = true;

		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == false&&distance[i] > distance[min_of_rest] + city_weight[min_of_rest][i])
			{
				distance[i] = distance[min_of_rest] + city_weight[min_of_rest][i];
				path_count[i] = path_count[min_of_rest];
				every_amount[i] = every_amount[min_of_rest]+number_of_rescueteam[i];
			}
			else if (visited[i] == false&&distance[i] == distance[min_of_rest] + city_weight[min_of_rest][i])
			{
				path_count[i] += path_count[min_of_rest];
				if (every_amount[i] < every_amount[min_of_rest] + number_of_rescueteam[i])
				{
					every_amount[i] = every_amount[min_of_rest] + number_of_rescueteam[i];
				}
			}
		}
	}

	cout<<path_count[C2]<<' '<<every_amount[C2];



	return 0;
}
