/**
 * @file    MyRobot.h
 * @brief   A template for webots projects.
 *
 * @author  Guillermo Mendiguchia <100284346@alumnos.uc3m.es>
 * @date    08 / 11 / 2014
 */


#include <iostream>
#include <webots/DifferentialWheels.hpp>


using namespace webots;
using namespace std;

#define MAX_SPEED 	      100
#define DESIRED_DISTANCE      16
#define ENCODER_RESOLUTION    5

class MyRobot : public DifferentialWheels {
    private:

        double _left_encoder, _right_encoder;

        double _left_speed, _right_speed;

        double _right_distance;

        double _left_distance;

        int _status;

        int _time_step;
        /**
            * @brief This function will execute the main program
            * @param No parameters are passed to this function
            * @return This function doesn't return any type of value
            */
        void go_ahead();
        /**
            * @brief This function will stop the robot
            * @param No parameters are passed to this function
            * @return This function doesn't return any type of value
            */
        void reset_status();
        /**
            * @brief This function will turn left
            * @param No parameters are passed to this function
            * @return This function doesn't return any type of value
            */
        void turn_left();
        /**
            * @brief This function will turn right
            * @param No parameters are passed to this function
            * @return This function doesn't return any type of value
            */
        void turn_right();
        /**
            * @brief This function will advance in a straight line
            * @param No parameters are passed to this function
            * @return This function doesn't return any type of value
            */
        void direct();

    public:
     
        MyRobot();
        
      
        ~MyRobot();

      
        void run();
};
