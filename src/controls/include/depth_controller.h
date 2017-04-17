#ifndef DEPTH_CONTROLLER_H
#define DEPTH_CONTROLLER_H

#include <ros/ros.h>
#include "std_msgs/Float64.h"


class DepthController {
    public:
    DepthController(ros::NodeHandle n);
    ~DepthController();

	void update();
	
    protected:
    
    ros::Time m_prev_time; 

    ros::Subscriber m_sensor_sub;
    void sensorCallback(const std_msgs::Float64::ConstPtr& msg);
    double m_current_depth;

	ros::Publisher m_command_pub;
    void commandhCallback(const std_msgs::Float64::ConstPtr& msg);
    std_msgs::Float64  m_depth_command;

	double m_desired_depth = 5;

    
    //P,I, and D terms, as it where. 
    double m_error;
    double m_error_integral;
    double m_error_derivative; 

	double m_prev_error;

    //gains
    double m_kp = 1;
    double m_ki = 0;
    double m_kd = 0; 
	
};
#endif //PID_CONTROLLER_H
