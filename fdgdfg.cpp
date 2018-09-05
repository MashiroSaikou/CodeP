#include "iostream"
#include "vector"
#include "cstdio"
#include "string.h"
#define INF 0x3f3f3f3f
using namespace std;
/* distance and cost between two cities*/
typedef struct _pathBet
{
	int distance,cost;
}pathBet;
//store the given info
pathBet **cityMap;
//used in dfs to judge if a point is visited;
bool *isVisited;
std::vector<int> final_path;
int final_long = INF, final_cost = 0;
void dfs(int point, int des, vector<int> &path, int n,int path_cost,int path_long){
	/*we arrive the destination, so we should to judge whether the path is most short
		if path_long is equal to final_long, we should judge buy cost
		*/
	if(point == des){
		//path.push_back(point);
		if(path_long < final_long){
			final_path = path;
			final_cost = path_cost;
			final_long = path_long;
		}
		else if(path_long == final_long&&path_cost < final_cost){
			final_path = path;
			final_cost = path_cost;
			final_long = path_long;
		}
//		for(int i = 0; i < final_path.size();i++){
//			cout<<final_path[i]<<' ';
//		}
//		cout<<path_cost<<' '<<path_long<<endl;
		return;
	}

	for(int i = 0; i < n; i++){
		pathBet temp = cityMap[point][i];
		if(isVisited[i] == false&&temp.distance!=INF){
			isVisited[i] = true;
			path.push_back(i);
			
//		for(int i = 0; i < path.size();i++){
//			cout<<path[i]<<' ';
//		}
//		cout<<endl;
			dfs(i,des,path,n,path_cost+temp.cost,path_long+temp.distance);
			path.pop_back();
			
//		for(int i = 0; i < path.size();i++){
//			cout<<path[i]<<' ';
//		}
//		cout<<endl;
			isVisited[i] = false;
//			path.pop_back();
		}
	}
}
int main(int argc, char const *argv[])
{
	int n, m, s, d;
	scanf("%d %d %d %d",&n,&m,&s,&d);
	cityMap = new pathBet*[n];
	isVisited = new bool[n];
	/*initial the arrays*/
	int city1, city2, dis, cost;
	for(int i = 0; i < n; i++){
		cityMap[i] = new pathBet[n];
		//cityMap[i][i] = 0;
		//memset(cityMap[i],(INF,INF),n);
		for(int j = 0; j < n; j++)
			cityMap[i][j].distance = INF;
		isVisited[i] = false;

	}
	for(int j = 0; j < m; j++){
		scanf("%d %d %d %d",&city1,&city2,&dis,&cost);
		cityMap[city1][city2].distance = cityMap[city2][city1].distance = dis;
		cityMap[city1][city2].cost = cityMap[city2][city1].cost = cost;
	}
	std::vector<int> path;
	path.push_back(s);
	isVisited[s] = true;
	dfs(s,d,path,n,0,0);
	
	for(int i = 0; i < final_path.size();i++){
		cout<<final_path[i]<<' ';
	}
	cout<<final_long<<' '<<final_cost;
	return 0;
}


