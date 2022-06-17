#include "../include/header.h"

using namespace ceres;

struct CostFunc {
    template<typename T>
    bool operator()(const T *const x, T *residual) const {
        residual[0] = 10.0 - x[0];
        return true;
    }
};

int main() {
    // The variable to solve for with its initial value. It will be
    // mutated in place by the solver.
    double x = 0.5;
    const double initial_x = x;
    // Build the problem.
    Problem problem;
    // Set up the only cost function (also known as residual). This uses
    // auto-differentiation to obtain the derivative (jacobian).
    CostFunction *costFunction =
            new AutoDiffCostFunction<CostFunc, 1, 1>(new CostFunc);
    problem.AddResidualBlock(costFunction, nullptr, &x);

    // Run the solver!
    Solver::Options options;
    options.minimizer_progress_to_stdout = true;
    Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);
    cout << summary.FullReport() << endl;
    cout << "x : " << initial_x << " -> " << x << "\n";
    return 0;
}
