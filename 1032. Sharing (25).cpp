#include "iostream"
#include "iomanip"
#include "cstdio" 
using namespace std;
int main(int argc, char const *argv[])
{
	int headA, headB, n, result;
	cin>>headA>>headB>>n;
	result = headA^headB;
	int flags = 0;
	for(int i = 0; i < n&&flags < 2; i++){
		int address,next;
		char letter;
		cin>>address>>letter>>next;
		result = result^address;
		if(next != -1){
			result = result^next;
		}
		else if(next == -1){
			flags ++;
		}
		
	}
	if(result == 0||flags > 1){
		cout<<-1;
	}
	else{
		printf("%.05d",result);
	}
	return 0;
}
/*
11111 22222 9
00006 i 00002
00010 a 12345
00003 g -1
12345 D 00006
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 00006
00001 o 00010
*/