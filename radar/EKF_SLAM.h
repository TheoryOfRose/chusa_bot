#ifndef EKF_SLAM_H
#define EKF_SLAM_H

class EKF_SLAM{
	public:
		// constructor
		EKF_SLAM();
		EKF_SLAM(int n, int LM_num);
		
		// variable
		int n;
		int landmark;
		double** prev_mean;
		double** cur_mean;
		double** prev_var;
		double** cur_var;
		
		// member function
		void prediction_update();
		void perception_update();
		void set_landmark(double** LM);
}

#endif
