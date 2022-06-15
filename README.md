# SLAM-Basics
SLAM Basic Code C++

- 1.distance of two points. Need to support  2d, 3d or finite high-dimensional points.
- 2.function a 6d pose TimedPose.  std::vector<TimedPose> struct TimedPose { int64 time_stamp, pose }
- 3.TimedPose support std::list<TimedPose> std::map<double, TimedPose>
- 4.let function 2 can support self def getTime and getPose
- 5.```for_each(begin, end, [](int i){cout<<i;}); ``` 
- 6.self def edge/factor/residual function
- 7.read topic messages from rosbag and run callback
- 8.convert and write the message from 7 to another rosbag
- 9.ros header.timestamp convert to timestamp
- 10.3d point operator < 
- 11.hash 3d grid, and write a hash container that can store grid.
- 12.synchronous ros message handler function to asynchronous.
- 13.base on 10, support any message types and asynchronous callback.
- 14.fits plane of 3D points using the least squares
- 15.base on 14, support high-dimensional vector.
- 16.computes the mean and variance of an array.
- 17.base on 16, support field of any structure as input.






