#include <iostream>
#include <stdio.h>
#include <vector>
#include "AUTO.h"
#include "robot.h"
#include <math.h>

using namespace std;

Robot(){
	loc.first = 0;
	loc.second = 0;
	num = 0;
	map = NULL;
}

Robot(location l, int angle){
	loc.first = l.first;
	loc.second = l.second;
	num = 1;
	sensing_angle = angle;
}

location Searching(location loc, int angle){
	int x = loc.first;
	int y = loc.second;
	int n;
	double rad = get_radian(angle);

	while(true){
		if( Map[x + n*cos(rad), y + n*sin(rad)]){
			return location(x + n*cos(rad), y+n*sin(rad));
		}
		n++;
	}
}

location* Sensing(){
	location* points = new location[360/sensing_angle +1];
	int index=0;
	for(int i=sensing_angle; i<360; i= i+sensing_angle){
	       points[index++] = (Searching(loc, i));
	}

	return points;
}

void Move(location l){
	if(l.first <= map.width && l.second <= map.height){
		loc.first = l.first;
		loc.second = l.second;
		num++;
	}
	else{
		printf("Out of Range!\n");
	}
}
