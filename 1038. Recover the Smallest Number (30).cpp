/* one wa not found*/

#include "iostream"
#include "string"
#include "vector"
#include "algorithm" 
using namespace std;
bool myCmp(const string &a,const string &b){
	//ei:"31" and "32"			//ei:"31""321"
	if(a.length() == b.length()||(a.find(b) == string::npos||a.find(b) != 0)){
		return a < b;
	}
	else{
		string tempAB = a+b;
		string tempBA = b+a;
		return (tempAB < tempBA)?true:false;
	}
}
int main(int argc, char const *argv[])
{
	//according to the first number of a string to store it
	std::vector<string> *firstNum = new std::vector<string>[10];
	//number of string
	int n; 
	scanf("%d",&n);
	//get string
	string _string;
	for(int i = 0; i < n; i++){
		cin>>_string;
		int j = _string.length()-1;
		while(j >= 0){
			if(_string[j] == '0') 
				j -- ;
			else break; 
		}
		if(j!=-1)
			firstNum[_string[0]-'0'].push_back(_string);
	}

	/*sort every vector*/
	for(int i = 0; i < 10; i++){
		//not empty
		if(!firstNum[i].empty()){
			sort(firstNum[i].begin(), firstNum[i].end(),myCmp);
		}
	}

	/*print the result;*/
	// erase the '0' at the begin of firstNum[0][0]
	if(!firstNum[0].empty()){
		for(int i = 0; firstNum[0][0][i] =='0';){
			firstNum[0][0].erase(0,1);
		}
	}
	//judge  whether all is empty 
	bool isAllZero = true;
	for(int i = 0; i < 10; i++){
		if(!firstNum[i].empty()) isAllZero = false;
	}
	
	if(isAllZero) cout<<'0';
	else{
		for(int i = 0; i < 10; i++){
			if(!firstNum[i].empty()){
				for(int j = 0; j < firstNum[i].size(); j++){
					cout<<firstNum[i][j];
				}
			}
		}
	} 
	return 0;
}
