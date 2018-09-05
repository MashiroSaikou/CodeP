#include "iostream"
#include "cstdio"
#include "vector"
#include "string.h"
using namespace std;
//bool cmp(vector<char>&v1,vector<char>&v2);
int main(int argc, char const *argv[])
{
	char v[22] = {'\0'}; 
	char f[22] = {'\0'};
	char rest = '0';
	char a;
	scanf("%s",v);
	int lenv = strlen(v);
	int j = 0;
	for(int i = lenv - 1; i >= 0; i--, j++){
		char b = ((v[i]-'0')*2+rest-'0')%10+'0';
		f[j] = b;
		rest = ((v[i]-'0')*2+rest-'0')/10+'0';
	}
	if(rest != '0'){
		f[j] = rest;
	}
	int lenf = strlen(f);
	char result = 0;
	for(int i = 0; i < lenf; i++){
		result = result^v[i];
		result = result^f[i];
	}
	if(result == 0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	for(int i = lenf - 1; i >= 0; i--){
		cout<<f[i];
	}
	return 0;
}
/*
bool cmp(vector<char>&v1,vector<char>&v2){
	for(int i = 0; i < v1.size(); i++){
		if(find(v2.begin(), v2.end(),v1[i]) == v2.end())
			return false;
		return true;
	}
}
*/
