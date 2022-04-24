class Solution {
    std::random_device seed_gen;
    std::default_random_engine engine;
    std::uniform_real_distribution<double> theta_dist;
    std::uniform_real_distribution<double> inner_dist;
    double radius_;
    double x_center_;
    double y_center_;
public:
    Solution(double radius, double x_center, double y_center) :
      engine(seed_gen()), theta_dist(0.0, 2*M_PI), inner_dist(0.0, 1.0)
    {
      radius_ = radius;
      x_center_ = x_center;
      y_center_ = y_center;
    }
    
    vector<double> randPoint() {
      double theta = theta_dist(engine);
      double inner = radius_ * sqrt(inner_dist(engine));
      return {x_center_ + inner * cos(theta), y_center_ + inner * sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */