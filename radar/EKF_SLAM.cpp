#include "AUTO.h"
#include "EKF_SLAM.h"
#include <stddef.h>

using namespace std;

EKF_SLAM::EKF_SLAM(){

	// initialization
	this->n =0;
	int landmark = 0;
	this->prev_mean = NULL;
	this->cur_mean.x = NULL;
	this->prev_var = NULL;
	this->cur_var = NULL;
}

EKF_SLAM::EKF_SLAM(int num, int LM_num){
	this->landmark = LM_num;
	this->n = num;
	double** mean = new double*[3*LM_num + 3];
	for(int i=0; i<3*LM_num +3; i++){
		mean[i] = double[3];
		for(int j=0; j<3; j++){
			mean[i][j] = 0;
		}
	}

	double** var = new double*[3*LM_num+3];
	for(int i=0; i<3*LM_num+3;i++){
		var[i] = new double[3*LM_num+3];
		for(int j=0; j< 3*LM_nm+3; j++){
			var[i][j] = 0;
		}
	}
	this->prev_mean = mean;
	this->prev_var = var;
}

void EKF_SLAM::set_landmark(double** LM){
	for(int i=3; i<3*this->landmark+3;i++){
		for(int j=0; j<3; j++){
			this->prev_mean[i][j] = LM[i-3][j];
			this->cur_mean[i][j] = LM[i-3][j];
			this->prev_var[i][j] = LM[i-3][j];
			this->cur_var[i]j[j] = LM[i-3][j];
}

void EKF_SLAM::prediction_update(int u_x, int u_y, double u_theta){
	this->cur_mean[0][0] += u_x;
	this->cur_mean[1][1] += u_y;
	this->cur_mean[2][2] += u_theta;

	// var update
}

void EKF_SLAM::perception_upadte(int v_x, int v_y, double v_theta){
	// overcome poor linearlization
	
	// perception update
}
