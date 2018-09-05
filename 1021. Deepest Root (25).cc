#include "iostream"
#include "vector"
#include "cstdio"
#include "algorithm"
#include "set"
using namespace std;
std::vector<vector<int> > v;
std::vector<int> temp;
set<int> s;
int countComponent = 0;
int maxHeight = 0;
bool *isVisited = new bool[10000];
void doDFS(int node, int height); 
int main(int argc, char const *argv[])
{
	int n;	cin>>n;
	int a,b;
	v.resize(n+1);
	for(int i = 0; i < n-1; i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}//读取两点关系

//	for(int i = 1; i <= n; i++){
//		fill(isVisited,isVisited + 10000,false);
//	//	if(isVisited[i] == false){
//			//isVisited[i] = true;
//			doDFS(i,1);
			//countComponent ++;
//	//	}
//	}
	fill(isVisited,isVisited + 10000,false);
	for(int i = 1; i <= n; i++){
		if(isVisited[i] == false){
			doDFS(i,1);
            if(i == 1) {
                for(int j = 0; j < temp.size(); j++) 
                    s.insert(temp[j]);
                }
			countComponent ++;
		}
	}
	if(countComponent > 1){
		printf("Error: %d components",countComponent);
	}
	else if(countComponent == 1){
		//sort(temp.begin(), temp.end());
		fill(isVisited,isVisited + 10000,false);
		maxHeight = 0;
		int firstNode = temp[0];
		//s.insert(firstNode);
		temp.clear();
		doDFS(firstNode,1);
		for(int i = 0; i < temp.size(); i++){
			s.insert(temp[i]);
		}
		for (set<int>::iterator i = s.begin(); i != s.end(); ++i){
			cout<<*i<<endl;
		}
	}
	return 0;
}

void doDFS(int node, int height){
	if(height > maxHeight){
		temp.clear();
		temp.push_back(node);
		maxHeight = height;
	}
	else if(height == maxHeight){
		temp.push_back(node);
		//cout<<"get"<<node<<endl;
	}
	isVisited[node] = true;
	for(int i = 0; i < v[node].size(); i++){
		if(isVisited[v[node][i]] == false){
			doDFS(v[node][i],height+1);
		}
	}
}
