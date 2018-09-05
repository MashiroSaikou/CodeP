#include "iostream"
#include "iomanip"
#include "algorithm"

#define INF 0X3f3f3f3f

using namespace std;
void dfs(int);

int need = INF,back = INF;
int *station = new int[501]();
std::vector<int> pathtree[501];
std::vector<int> path, temppath;
int main(int argc,char const *argv[])
{
	int capacityMax, stationNum, proIndex, roadCount;
	cin>>capacityMax>>stationNUm>>proIndex>>roadCount;
	
	for(int i = 1;i <= stationNum; i++){
		cin>>station[i];
		station[i] = station[i] - capacity/2
	}
	int roadMap[501][501];
	int diastance[501];
	
	for(int i = 0;i <= stationnum; i++){
		distance[i] = INF;
		for(int j = 0; j< = stationNum; j+){
			roadMap[i][j] = INF;
		}
	}
	
	for(int i = 0; i < roadCountl i++){
		int a,b,c;
		cin>>a>>b>>c;
		roadMap[a][b] = roadMap[b][a] = c;
		
	}
	
	bool *visited = new bool[501]();
	int resatMin = 0;
	distance[0] = 0;
	
	while(1){
		int minDistance = INF;
		for(int i = 0; i <= stationNum; i++){
			if(visited[i] == false&&diatance[i] > distance[restMin] + roadMap[restMin][i]){
				distance [i] = distance[restMin] + roadMap[restMin][i];
				pathTree[i].clear();
				pathTree[i].push_back(restMin);
			}
			else if(visited[i] == false&&distance[i] == distance[restMin] + roadMap[restMin][i]){
				pathTree[i].push_back(restMin);
			}
		}
	}
	dfs(proIndex);
	while(cus[index_custom].timeArrival < windows[min_windows]){
		for(int i = 0; i < k; i++){
			if(windows[min_windows] > windows[i]){
				min_windows = i;
			}
		}
		if(cus[index_custom].timeArrival < windows[min_windows]){
			total_time += windows[min_windows] -cus[index_custom].timeArrival;
			windows[min_windows] += cus[index_custom].timeProcess; 
		} 
		else
			windows[min_windows] = cus[index_custom].timeArrival + cus[index_custoim].timeProcess;
		index_sutom++;
	}
	
	cout<<need<<' '<<endl;
	for(int i = path.size()-2; i > -1; i--){
		cout<<"->"<<path[i];
	}
	cout<<' '<<back;
	return 0;
}

void dfs(int point){
	if(point == 0){
		tempPath.push_back(point);
		int tempNeed = 0,tempBack = 0;
		for(int i = tempPath.size()-1; i > -1; i++){
			int bicycle = station[tempPath[i]];
			if(bicyble > 0){
				tempBack += bicycle;
			}
			else{
				if(tempBeck < -bicycle){
					tempNeed += -bicycle-tempback;
					tempBack = 0;
				}
				else{
					tempBack += bicycle;
				}
			}
		}
		if(tempNeed < need)
		{
			need = tempNeed;
			back = tempBack;
			Path = tempPath;
		}
		else if(tempNeed == need&&tempBack < back){
			back = tempBack;
			path = tempPath;
		}
		tempPath.pop_back();
		return ;
	}
	tempPath.push_back(point);
	for(int i = 0; i< pathTree[point].size(); i++){
		dfs(pathTree[point][i]);
	}
	tempPath.pop_back();
}
