/*-----------------------------
	Mashiro
	1018. Public Bike Management (30)
--------------------------------*/

#include "iostream"
#include "iomanip"
#include "algorithm"
#include "vector"

#define INF 0x3f3f3f3f
using namespace std;
void dfs(int);

int need = INF,back = INF;
int *station = new int[501]();
std::vector<int> pathTree[501];
std::vector<int> path, tempPath;
int main(int argc, char const *argv[])
{
	int capacityMax, stationNum, proIndex, roadCount;//最大容量，站点数，问题站点，道路数
	cin>>capacityMax>>stationNum>>proIndex>>roadCount;

	for (int i = 1;i <= stationNum; ++i){
		cin>>station[i];
		station[i] = station[i] - capacityMax/2;
	}
	int roadMap[501][501];
	int distance[501];
	//初始化距离数组和地图
	for(int i = 0;i <= stationNum; ++i){
		distance[i] = INF;
		for (int j = 0; j <= stationNum; ++j){
			roadMap[i][j] = INF;
		}
	}
	//读取地图
	for(int i = 0; i < roadCount; ++i){
		int a, b, c;
		cin>>a>>b>>c;
		roadMap[a][b] = roadMap[b][a] = c;
	}

	bool *visited = new bool[501]();//默认false
	int restMin = 0;
	distance[0] = 0;

	while(1){
		int minDistance = INF;//单次中最小距离
		for(int i = 0; i <= stationNum; ++i){
			if(visited[i] == false&&distance[i] < minDistance){
				restMin = i;
				minDistance = distance[i];
			}
		}//找到未被访问中的最小值

		if(minDistance == INF||restMin == proIndex)
			break;
		//结束条件
		visited[restMin] = true;
		for (int i = 0; i <= stationNum; ++i){
			if (visited[i] == false&&distance[i] > distance[restMin] + roadMap[restMin][i]){
				distance[i] = distance[restMin] + roadMap[restMin][i];
				pathTree[i].clear();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
				pathTree[i].push_back(restMin);
			}
			else if(visited[i] == false&&distance[i] == distance[restMin] + roadMap[restMin][i]){
				pathTree[i].push_back(restMin);
			}
		}


	}
	dfs(proIndex);
	cout<<need<<' '<<0;
	for (int i = path.size()-2; i > -1; --i){
		cout<<"->"<<path[i];
	}
	cout<<' '<<back;
	return 0;
}

void dfs(int point){
	if(point == 0){
		tempPath.push_back(point);
		int tempNeed = 0, tempBack = 0;
		for (int i = tempPath.size()-1; i > -1; i--){
			int bicycle = station[tempPath[i]];
			if(bicycle > 0){
				tempBack += bicycle;
			}
			else{
				if(tempBack < -bicycle){
					tempNeed += -bicycle-tempBack;
					tempBack = 0;
				}
				else{
					tempBack += bicycle;
				}
			}
		}
		if(tempNeed < need){
			need = tempNeed;
			back = tempBack;
			path = tempPath;
		}
		else if(tempNeed == need&&tempBack < back){
			back = tempBack;
			path = tempPath;			
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(point);
	//need += capacityMax/2 - station[point];
	for (int i = 0; i < pathTree[point].size(); ++i){
		dfs(pathTree[point][i]);
	}
	tempPath.pop_back();
}

