#include "../include/header.h"

struct SE3Pose {
    Eigen::Vector3d &position;
    Eigen::Quaternion<double> &rotation;
};
struct TimedPose {
    double timestamp;
    SE3Pose pose;
};

SE3Pose Interp(const TimedPose &a, const TimedPose &b, double timestamp) {
    // Get the interpolating value as a number between zero and one.
    double t = (timestamp - a.timestamp) / (b.timestamp - a.timestamp);
    Eigen::Vector3d position = (1.0 - t) * a.pose.position + t * b.pose.position;
    Eigen::Quaternion<double> rotation = a.pose.rotation.slerp(t, b.pose.rotation);
    SE3Pose interp_pose = SE3Pose{position, rotation,};
    return interp_pose;
}


int main() {
    Eigen::Vector3d v1(0.0, 0.0, 0.0), v2(1.0, 1.0, 1.0);
    Eigen::Quaternion<double> q1(0, 0.6, 0.8, 0.0), q2(0, -0.8, 0.0, -0.6);
    SE3Pose pose1 = SE3Pose{v1, q1};
    SE3Pose pose2 = SE3Pose{v2, q2};
    TimedPose a = TimedPose{1.0, pose1};
    TimedPose b = TimedPose{2.0, pose2};
    cout << "t" << '\t' << "position" << '\t' << "rotation" << endl;
    for (int i = 0; i <= 10; ++i) {
        cout << 0.1 * i << '\t' << Interp(a, b, 0.1 * i).position.transpose() << '\t' << Interp(a, b, 0.1 * i).rotation << endl;
    }
    return 0;
}

