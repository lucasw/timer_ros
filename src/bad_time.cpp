/** Copyright (c) 2021 Lucas Walter */
#include <iostream>
#include <ros/ros.h>

int main()
{
  const auto cur = ros::Time(-1);
/**
 * this will be the result of the above
terminate called after throwing an instance of 'std::runtime_error'
  what():  Time is out of dual 32-bit range
Aborted (core dumped)
*/
  std::cout << cur << std::endl;
  const double sec = cur.toSec();
  std::cout << sec << std::endl;
}
