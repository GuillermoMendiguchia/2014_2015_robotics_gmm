/**
 * @file    MyRobot.h
 * @brief   A template for webots projects.
 *
 * @author  Guillermo Mendiguchia <100284346@alumnos.uc3m.es>
 * @date    08 / 11 / 2014
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
