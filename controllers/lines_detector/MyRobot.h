#ifndef MY_ROBOT_H_
#define MY_ROBOT_H_

/**
 * @file    MyRobot.h
 * @brief   Detects a yellow line nearby
 *
 * @author  Guillermo Mendiguchia Martinez <100284346@alumnos.uc3m.es>
 * @date    2014-13
 */


#include <iostream>
#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define NUM_DISTANCE_SENSOR 2
#define DISTANCE_LIMIT      100
#define MAX_SPEED           100

class MyRobot : public DifferentialWheels {
    public:
       

        /**
         * @brief Empty constructor of the class.
         */
        MyRobot();

        /**
         * @brief Destructor of the class.
         */
        ~MyRobot();

        /**
         * @brief Function with the logic of the controller.
         * @param
         * @return
         */
        void run();
        
    private:
        int _time_step;
        
        // velocities
        double _left_speed, _right_speed;

        // sensors
        Camera *_forward_camera;
        Camera *_spherical_camera;
};

#endif

