#include "../include/header.h"

using namespace Eigen;
struct TimedPose {
    double timestamp;
    Isometry3d pose;
};

Isometry3d Interp(const TimedPose &a, const TimedPose &b, double timestamp) {
    // Get the interpolating value as a number between zero and one.
    double t = min(max((timestamp - a.timestamp) / (b.timestamp - a.timestamp), 0.0), 1.0);
    auto position = (1.0 - t) * +t * b.pose.translation();
    auto rotation = Quaterniond(a.pose.rotation()).slerp(t, Quaterniond(b.pose.rotation()));
    Isometry3d interp_pose = Isometry3d::Identity();
    interp_pose.rotate(rotation);
    interp_pose.pretranslate(position);
    return interp_pose;
}


int main() {
    Vector3d v1(0.0, 0.0, 0.0), v2(1.0, 1.0, 1.0);
    Quaterniond q1(0, 0.6, 0.8, 0.0), q2(0, -0.8, 0.0, -0.6);
    Isometry3d pose1(q1), pose2(q2);
    pose1.pretranslate(v1), pose2.pretranslate(v2);
    TimedPose a = TimedPose{1.0, pose1};
    TimedPose b = TimedPose{10.0, pose2};
    cout << "t" << '\t' << "position" << '\t' << "rotation" << endl;
    for (int i = 1; i <= 10; ++i) {
        auto inter = Interp(a, b, i);
        cout << 0.1 * i << '\t' << inter.translation().transpose() << '\t' << Quaterniond(inter.rotation()) << endl;
    }
    return 0;
}

