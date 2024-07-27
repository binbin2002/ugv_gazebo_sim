#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "scout_demo");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 创建一个Publisher，发布到/cmd_vel话题，消息类型为Twist
    ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // 设置循环频率
    ros::Rate rate(10);

    // 创建一个Twist消息实例
    geometry_msgs::Twist move_cmd;
    move_cmd.linear.x = 0.5; 
    move_cmd.linear.y = 0.5;  // 线速度
    move_cmd.angular.z = 0.0;  // 角速度

    // 发布速度命令
    while (ros::ok()) {
        cmd_vel_pub.publish(move_cmd);
        rate.sleep();
    }

    return 0;
}

