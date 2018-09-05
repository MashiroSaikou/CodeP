#include "iostream"
#include "vector"
#include "string"
#include "cstdio"

using namespace std;
int charge[24];

typedef struct call_data
{
	string name;
	int mouth;
	int day;
	int hour;
	int minute;
	int total_time;
	//int total_cost;
	string state;
};
bool cmp(call_data a,call_data b)
{
	if (a.name<b.name)
	{
		return 1;
	}
	else if (a.name == b.name && a.total_time<b.total_time)
	{
		return 1;
	}
	else
		return 0;
}
std::vector<call_data> data_origin;
std::vector<call_data> data_need;
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 24; ++i)
	{
		cin>>charge[i];
	}
	int n_line;
	cin>>n_line;
	for (int i = 0; i < n_line; ++i)
	{
		call_data temp;
		cin>>temp.name;
		//getchar();
		scanf(" %d:%d:%d:%d ",&temp.mouth,&temp.day,&temp.hour,&temp.minute);
		cin>>tmep.state;
		temp.total_time = (day-1)*24*60+hour*60+minute;
		data_origin.push_back(temp);
	}
	sort(data_origin.begin(), data_origin.end(),cmp);
	bool isOnLine = false;
	call_data lastData;
	for (int i = 0; i < n_line; ++i)
	{
		if (isOnLine == false && data_origin[i].state == "on-line")
		{
			data_need.push_back(data_origin[i]);
			isOnLine = true;
			lastData = data_origin[i];
		}
		else if (isOnLine == true && data_origin[i].state == "on-line")
		{
			data_need.pop_back();
			data_need.push_back(data_origin[i]);
			isOnLine = true;
			lastData = data_origin[i];
		}
		else if (isOnLine == true && data_origin[i].state == "off-line" && data_origin[i].name == lastData.name)
		{
			data_need.push_back(data_origin[i]);
			isOnLine = false;
		}
	}
	if (*(data_need.end()-1).state == "on-line")
	{
		data_need.pop_back();
	}

	double total_cost;
	for (int i = 0; i < data_need.size(); i+=2)
	{
		
	}
	return 0;
}