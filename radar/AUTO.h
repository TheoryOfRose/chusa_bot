#ifndef AUTO_H
#define AUTO_H

#define location pair<int,int> 
#define PI 3.1415926535897

struct mean_value{
	int x;
	int y;
	double theta;
};

double get_radian(int angle){
	return angle*PI/180;
}

#endif

