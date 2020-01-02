/** Copyright 2020 Lucas Walter
 *
 */

#include <ros/ros.h>
#include <std_msgs/Float32.h>

class TimerTest
{
public:
  TimerTest()
  {
    update_time_pub_ = nh_.advertise<std_msgs::Float32>("update_time", 10);
    update_dt_pub_ = nh_.advertise<std_msgs::Float32>("update_dt", 10);
    double period = 0.01;
    ros::param::get("~period", period);
    timer_ = nh_.createTimer(ros::Duration(period), &TimerTest::timerCallback, this);
  }
private:
  void timerCallback(const ros::TimerEvent& te)
  {
    std_msgs::Float32 msg;
    msg.data = te.current_real.toSec();
    update_time_pub_.publish(msg);

    if (te.last_real.toSec() > 0.0) {
      msg.data = (te.current_real - te.last_real).toSec();
      update_dt_pub_.publish(msg);
    }
  }

  ros::NodeHandle nh_;
  ros::Timer timer_;
  ros::Publisher update_time_pub_;
  ros::Publisher update_dt_pub_;
};

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "timer_test_cpp");
  TimerTest timer_test;
  ros::spin();
  return 0;
}
