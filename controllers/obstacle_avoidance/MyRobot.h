/**
 * @file    MyRobot.h
 * @brief   A template for webots projects.
 *
 * @author  Guillermo Mendiguchia <100284346@alumnos.uc3m.es>
 * @date    08 / 11 / 2014
 */


#include <iostream>

#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define NUM_DISTANCE_SENSOR 16
#define DISTANCE_LIMIT      100
#define MAX_SPEED           40

class MyRobot : public DifferentialWheels {
    private:
        int _time_step;

        DistanceSensor * _distance_sensor[NUM_DISTANCE_SENSOR];
        double _left_speed, _right_speed;

        enum Mode {
            STOP,
            FORWARD,
            TURN_LEFT,
            TURN_RIGHT,
            OBSTACLE_AVOID,
            SHARP_TURN
        };

        Mode _mode;

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
         * @brief This function will execute the main program
         * @param No parameters are passed to this function
         * @return This function doesn't return any type of value
         */
        void run();
};
