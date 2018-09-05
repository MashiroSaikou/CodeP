#include "iostream"
#include "string"
#include "vector"
#define INF 0x3f3f3f3f
#define n 6
using namespace std;
/*
	保证vertex从'a'开始
	最短路径储存
*/
typedef struct _path{
	string minPath;
}path;

//最小距离矩阵
//int minDisMatrix[n][n];
int minDisMatrix[n][n] =   {  0,  3,INF,  4,INF,  5,
							INF,  0,  1,INF,INF,  5,
							INF,INF,  0,  5,INF,INF,
							INF,INF,INF,  0,INF,INF,
							INF,INF,INF,  3,  0,  2,
							INF,INF,INF,INF,INF,  0,};
//路径矩阵
path minPathMatrix[n][n];

class Floyd
{
public:
	Floyd(){};
	//执行转换函数
	void startFloyd();
	//打印最小距离矩阵
	void printDis();
	//打印路径矩阵
	void printPath();
	//路径矩阵初始化
	void printPath(char, char);
	void initailPath();
	//距离矩阵初始化
//	void initailDis();
	~Floyd(){};
};

void Floyd::startFloyd(){
	initailPath();
	for (int k = 0; k < n; k++){
		//行
		for (int i = 0; i < n; i++){
			//列
			for (int j = 0; j < n; j++){
				if(minDisMatrix[i][j] > minDisMatrix[i][k] + minDisMatrix[k][j]){
					//最短路径数值更新
					minDisMatrix[i][j] = minDisMatrix[i][k] + minDisMatrix[k][j];
					//最短路径字符串更新
					minPathMatrix[i][j].minPath = minPathMatrix[i][k].minPath + minPathMatrix[k][j].minPath;
				}
			}
		}
	}
}

void Floyd::initailPath(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if(minDisMatrix[i][j] == INF||minDisMatrix[i][j] == 0){
				//两点间不存在路径
				minPathMatrix[i][j].minPath = "\0";
			}
			else{
				//初始化为起点
				minPathMatrix[i][j].minPath = ('a'+i);							
			}
		}
	}
}

void Floyd::printDis(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(minDisMatrix[i][j] == INF)
				cout<<'x'<<' ';
			else
				cout<<minDisMatrix[i][j]<<' ';
		}
		cout<<endl;
	}
}

void Floyd::printPath(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if(minPathMatrix[i][j].minPath != "\0"){
				cout<<(char)('a'+i)<<"->"<<(char)('a'+j)<<':';
				cout<<minPathMatrix[i][j].minPath+(char)('a'+j)<<"  ";
			}
		}
		cout<<endl;
	}
}

void Floyd::printPath(char start, char end){
	cout<<start<<"->"<<end<<':';
	cout<<minPathMatrix[start-'a'][end-'a'].minPath<<endl;
}

int main(int argc, char const *argv[])
{

	Floyd myFloyd;
	myFloyd.startFloyd();
	myFloyd.printDis();
	myFloyd.printPath();
	myFloyd.printPath('a','c');
	return 0;
}
