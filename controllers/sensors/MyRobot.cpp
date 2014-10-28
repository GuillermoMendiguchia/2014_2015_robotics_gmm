

#include "MyRobot.h"

//////////////////////////////////////////////

MyRobot::MyRobot() : DifferentialWheels()
{
    _time_step = 64;

    _left_speed = 0;
    _right_speed = 0;

    // Get and enable the compass device
    _my_compass = getCompass("compass");
    _my_compass->enable(_time_step);

    _distance_sensor[0] = getDistanceSensor("ds0");
    _distance_sensor[0]->enable(_time_step);
    _distance_sensor[1] = getDistanceSensor("ds1");
    _distance_sensor[1]->enable(_time_step);
    _distance_sensor[2] = getDistanceSensor("ds2");
    _distance_sensor[2]->enable(_time_step);
    _distance_sensor[3] = getDistanceSensor("ds3");
    _distance_sensor[3]->enable(_time_step);
    _distance_sensor[4] = getDistanceSensor("ds12");
    _distance_sensor[4]->enable(_time_step);
    _distance_sensor[5] = getDistanceSensor("ds13");
    _distance_sensor[5]->enable(_time_step);
    _distance_sensor[6] = getDistanceSensor("ds14");
    _distance_sensor[6]->enable(_time_step);
    _distance_sensor[7] = getDistanceSensor("ds15");
    _distance_sensor[7]->enable(_time_step);
}


//////////////////////////////////////////////

MyRobot::~MyRobot()
{
    _my_compass->disable();
    for (int i=0; i<NUM_DISTANCE_SENSOR; i++) {
            _distance_sensor[i]->disable();
        }
}

//////////////////////////////////////////////

void MyRobot::run()
{
    double compass_angle;
    int num_step=0;
    double dis15_val = 0.0, dis14_val = 0.0, dis13_val = 0.0, dis12_val = 0.0, dis0_val = 0.0, dis1_val = 0.0, dis2_val = 0.0, dis3_val = 0.0;

    while (step(_time_step) != -1) {
        // Read the sensors
        if (num_step==360)
        {
          setSpeed(0, 0);
        }
        else
        {
        // Read the sensors
        dis0_val = _distance_sensor[0]->getValue();
        dis1_val = _distance_sensor[1]->getValue();
        dis2_val = _distance_sensor[2]->getValue();
        dis3_val = _distance_sensor[3]->getValue();
        dis12_val = _distance_sensor[4]->getValue();
        dis13_val = _distance_sensor[5]->getValue();
        dis14_val = _distance_sensor[6]->getValue();
        dis15_val = _distance_sensor[7]->getValue();

        num_step = num_step + 1;
        const double *compass_val = _my_compass->getValues();

        // Convert compass bearing vector to angle, in degrees
        compass_angle = convert_bearing_to_degrees(compass_val);

        // Print sensor values to console
        cout << "Compass angle (degrees): " << compass_angle << endl;
        cout << "Number of cycles: " << num_step << endl;
        cout << "Frontal left sensors: dist0: " << dis0_val <<endl<< " dist1:" <<dis1_val <<endl<< " dist2:" << dis2_val<<endl<< " dist3:"  << dis3_val << endl << "Frontal right sensors: dist12:" << dis12_val<<endl<< " dist13:" << dis13_val<<endl<< " dist14:" << dis14_val<<endl<< " dist15:" << dis15_val<< endl<< endl;

        // Simple bang-bang control
        if (compass_angle < (DESIRED_ANGLE - 2)) {
            // Turn right
            _left_speed = MAX_SPEED;
            _right_speed = MAX_SPEED - 15;
        }
        else {
            if (compass_angle > (DESIRED_ANGLE + 2)) {
                // Turn left
                _left_speed = MAX_SPEED - 15;
                _right_speed = MAX_SPEED;
            }
            else {
                // Move straight forward
                _left_speed = MAX_SPEED;
                _right_speed = MAX_SPEED;
            }
        }

        // Set the motor speeds
        setSpeed(_left_speed, _right_speed);
        }
    }
}

//////////////////////////////////////////////

double MyRobot::convert_bearing_to_degrees(const double* in_vector)
{
    double rad = atan2(in_vector[0], in_vector[2]);
    double deg = rad * (180.0 / M_PI);

    return deg;
}

//////////////////////////////////////////////
