/**
 * @file    lines_detector.cpp
 * @brief   Detects a yellow line nearby
 *
 * @author  Guillermo Mendiguchia Martinez <100284346@alumnos.uc3m.es>
 * @date    2014-13
 */

#include "MyRobot.h"

/**
 * @brief Main program.
 */
int main(int argc, char **argv)
{
    MyRobot* my_robot = new MyRobot();

    my_robot->run();

    delete my_robot;

    return 0;
}
