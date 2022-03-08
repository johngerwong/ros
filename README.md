# homework-ros
compile and build:(if rebuild needed, should do in workspace git@github.com:dongqingling/homework-workspace.git )
  1.compile ros:
    $cd ~/catkin_ws/
    $catkin_make

  2.compile rostest:
    $cd ~/catkin_ws/build
    $make run_tests



running sequence:
  1.run master node:
    $roscore

  2.run roslaunch: 
    $roslaunch beginner_tutorials turtlemimic.launch
    $rostopic pub /turtlesim1/turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'

  3.publisher and subscriber:
    $rosrun beginner_tutorials talker
    $rosrun beginner_tutorials listener

  4.service and client:
    $rosrun beginner_tutorials add_two_ints_server 
    $rosrun beginner_tutorials add_two_ints_client 1 3

  5.rostest:
    $rostest beginner_tutorials add_two_ints_service_client.launch






