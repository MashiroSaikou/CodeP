#include "iostream"
#include "cstdio"
#include "math.h"
using namespace std;
#define INF 0x3f3f3f3f
//info of gas station
typedef struct _gas_station{
	int distance;
	double price;
}gas_station;
//car's info
typedef struct _car{
	int dis;	//distance it runs
	int cur_station;	//where it is now
	double cost;	//gas cost
	double cur_tank;	//left tank
}Car;

int main(int argc, char const *argv[])
{
	int Cmax, D, N;
	double Davg;
	scanf("%d %d %lf %d",&Cmax,&D,&Davg,&N);
	gas_station *st = new gas_station[N+1];	//the end of st is destination, so n+1
	Car car; 
	bool *isVisited = new bool[N+1];
	//get info from cin
	for(int i = 0; i < N; i++){
		int distance;
		double price;
		scanf("%lf %d",&price,&distance);
		isVisited[i] = false;
		if(distance == 0) {
			car.dis = car.cur_tank = car.cost = 0;
			car.cur_station = i;
			isVisited[i] = true;
		}
		st[i].price = price;
		st[i].distance = distance;
	}
	isVisited[N] = false;
	st[N].price = 0; 
	st[N].distance = D;
	// initial for car

	bool isCanArrive;	//whether it can arrive at destination

	while(car.dis < D){
		//find the least gas price that the station'dis <= Cmax*Davg
		//if they are equal, find the dis of which station is least
		int max_dis_can_arrive = Cmax*Davg;
		gas_station temp_min_station;
		temp_min_station.price = INF;
		int station_index = car.cur_station;
		isCanArrive = false;
		bool min = false;
		
		for(int i = 0; i <= N; i++){
			if(isVisited[i] == false&&st[i].distance-car.dis<=max_dis_can_arrive&&st[i].distance-car.dis>0){
				isCanArrive = true;
				if((temp_min_station.price > st[i].price&&i!=N)||((i == N)&&temp_min_station.price>st[car.cur_station].price)){
					temp_min_station = st[i];
					station_index = i;
				}
				else if(temp_min_station.price == st[i].price){
					if(temp_min_station.distance > st[i].distance){
						temp_min_station = st[i];
						station_index = i;
					}
				}
				
			}
		}
		//fresh
		isVisited[station_index] = true;
		if(isCanArrive == true){
			double add;
			if( temp_min_station.price<= st[car.cur_station].price){
				add = (temp_min_station.distance-st[car.cur_station].distance)/Davg-car.cur_tank;
				if(add>0) car.cur_tank = 0;
				else car.cur_tank = -add;
			}
			else{
				add = Cmax-car.cur_tank;
				car.cur_tank = Cmax - (temp_min_station.distance-st[car.cur_station].distance)/Davg;
			}
			if(add>0)
				car.cost += st[car.cur_station].price*add;
			car.dis = temp_min_station.distance;
			car.cur_station = station_index;	
		}
		else{
			car.dis += max_dis_can_arrive;
			break;
		}
	}
	if(isCanArrive == true)
		printf("%.2lf",car.cost);
	else
		printf("The maximum travel distance = %.2lf",car.dis);
	return 0;
}
