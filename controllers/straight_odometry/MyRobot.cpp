
#include "MyRobot.h"


MyRobot::MyRobot() : DifferentialWheels()
{
    _time_step = 64;

    enableEncoders(_time_step);

    _left_speed = 100;
    _right_speed = 100;
    _status = 1;
    _distance = 0;
}

//////////////////////////////////////////////

MyRobot::~MyRobot()
{
    disableEncoders();
}

//////////////////////////////////////////////

void MyRobot::run()
{

    while (step(_time_step) != -1)
    {

        _left_encoder = getLeftEncoder();
        _right_encoder = getRightEncoder();


        if (_distance < DESIRED_DISTANCE)
        {
            go_ahead();
            setSpeed(_left_speed, _right_speed);
        }
        else{
            reset_status();
            setSpeed(_left_speed, _right_speed);
            break;


        }
    }
  }

    //////////////////////////////////////////////

    void  MyRobot::go_ahead()
    {
        _left_speed = MAX_SPEED;
        _right_speed = MAX_SPEED;

        _distance = (_left_encoder/ENCODER_RESOLUTION)*0.0825;
        _distance = (_right_encoder/ENCODER_RESOLUTION)*0.0825;

        cout<< _left_encoder << " - " << _right_encoder << " - " << _distance << " - " <<_status << endl;

        if(_left_encoder > _right_encoder)
        {
            _left_speed = 90;
            _right_speed = 100;
        }
        else
        {
            _left_speed = 100;
            _right_speed = 90;
        }





    }

    void MyRobot::reset_status()
    {
        _left_speed = 0;
        _right_speed = 0;
        _distance = 0;
        setEncoders(0,0);



    }
