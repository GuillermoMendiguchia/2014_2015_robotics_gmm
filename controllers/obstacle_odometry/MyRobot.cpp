/**
 * @file    MyRobot.h
 * @brief   A template for webots projects.
 *
 * @author  Guillermo Mendiguchia <100284346@alumnos.uc3m.es>
 * @date    08 / 11 / 2014
 */



#include "MyRobot.h"
#include "math.h"


MyRobot::MyRobot() : DifferentialWheels()
{
    _time_step = 64;

    enableEncoders(_time_step);

    _left_speed = 100;
    _right_speed = 100;

    _left_distance = 0;
    _right_distance = 0;

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


        go_ahead();



    }    //cierro while
  }      //cierro run

    //////////////////////////////////////////////

    void  MyRobot::go_ahead()
    {   _left_encoder = getLeftEncoder();
        _right_encoder = getRightEncoder();
        _left_distance = (_left_encoder/ENCODER_RESOLUTION)*0.0825;
        _right_distance = (_right_encoder/ENCODER_RESOLUTION)*0.0825;

             direct();

        cout<< _left_encoder << " - " <<_left_distance<<"   -   "<< _right_encoder << " - " << _right_distance <<"  -  "<<_status << endl;



        if(_right_distance>4.6 && _right_distance<=5.4)
        {
          turn_left();
        }


        if (_right_distance>5.3)
        {
            direct();

        }

        if (_left_distance>7.93 && _left_distance<=8)
        {
          turn_right();
        }
        if (_left_distance>8)
           {
            direct();
            }
        if(_left_distance>16 && _left_distance<=16.5)
            {
           turn_right();
            }
        if (_left_distance>16.5)
        {
            direct();
        }



        setSpeed(_left_speed,_right_speed);

    }


    void MyRobot::reset_status()
    {
        _left_speed = 0;
        _right_speed = 0;
        _left_distance = 0;
        _right_distance = 0;
        setEncoders(0,0);
    }
    void MyRobot::turn_left()
    {
        _left_speed=0;
        _right_speed=MAX_SPEED/3;
        setSpeed(_left_speed,_right_speed);

    }

    void MyRobot::turn_right()
    {
        _left_speed=MAX_SPEED/3;
        _right_speed=0;
        setSpeed(_left_speed,_right_speed);
    }

    void MyRobot::direct()
    {     cout<<"Advancing"<<endl;

        _left_encoder = getLeftEncoder();
        _right_encoder = getRightEncoder();
        _left_speed = 80;
        _right_speed = 80;


        if(_left_encoder > _right_encoder)
        {
            _left_speed = 80;
            _right_speed = 90;
        }
        else
        {
            _left_speed = 90;
            _right_speed = 80;
        }
          setSpeed(_left_speed,_right_speed);
    }
