#!/usr/bin/env python
# Copyright 2020 Lucas Walter

import rospy

from std_msgs.msg import Float32


class TimerTest:
    def __init__(self):
        self.update_time_pub = rospy.Publisher("update_time", Float32, queue_size=10)
        self.update_dt_pub = rospy.Publisher("update_dt", Float32, queue_size=10)
        self.period = rospy.get_param("~period", 0.01)
        self.cycles = rospy.get_param("~cycles", 1)
        self.count = 0
        self.last_real = None
        self.timer = rospy.Timer(rospy.Duration(self.period / self.cycles), self.timer_callback)

    def timer_callback(self, te):
        self.count += 1
        if self.count % self.cycles != 0:
            return

        self.update_time_pub.publish(Float32(te.current_real.to_sec()))
        if self.last_real is not None:
            msg = Float32()
            msg.data = (te.current_real - self.last_real).to_sec()
            self.update_dt_pub.publish(msg)
        self.last_real = te.current_real

if __name__ == '__main__':
    rospy.init_node("timer_test_py")
    timer_test = TimerTest()
    rospy.spin()
