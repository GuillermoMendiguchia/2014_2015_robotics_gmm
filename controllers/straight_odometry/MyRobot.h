
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

        double _distance;

        int _status;

        int _time_step;

        void go_ahead();
        void reset_status();

    public:
     
        MyRobot();
        
      
        ~MyRobot();

      
        void run();
};
