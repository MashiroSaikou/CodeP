/*--------------------------
	Mashiro
	1017. Queueing at Bank (25)
----------------------------*/

#include "iostream"
#include "vector"
#include "algorithm"
#include "cstdio"
#include "iomanip"

using namespace std;
class custom
{
public:
	int timeArrival;
	int timeProcess;
	custom(int _timeArrival, int _timeProcess):timeArrival(_timeArrival),timeProcess(_timeProcess){};
	bool operator<(custom &a) const{return timeArrival < a.timeArrival;};
};
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;
	std::vector<custom> cus;
	std::vector<int> windows(k);
	for (int i = 0;i < n; ++i){
		int hh,mm,ss,tt;
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&tt);
		cus.push_back(custom(hh*3600+mm*60+ss,tt*60));
	}
	for (int i = 0;i < k; ++i){
		windows[i] = 8*3600;
	}
	sort(cus.begin(), cus.end());
	int min_windows = 0;
	int index_custom = 0;
	double total_time = 0;
	//结束条件，要么有17点以后的，要么人数达到上限
	while(cus[index_custom].timeArrival < 17*3600&&index_custom < n){
		for (int i = 0; i < k; ++i){
			if(windows[min_windows] > windows[i]){
				min_windows = i;
			}
		}//最早结束的窗口
		if (cus[index_custom].timeArrival < windows[min_windows]){
			total_time += windows[min_windows]-cus[index_custom].timeArrival;
			windows[min_windows] += cus[index_custom].timeProcess;
		}
		else
			windows[min_windows] = cus[index_custom].timeArrival + cus[index_custom].timeProcess;
		index_custom ++;
	}
	cout<<fixed<<setprecision(1)<<total_time/60/index_custom;
	return 0;
}
