// This code is only a reference for me to understand how to implement classes in C++

#include <iostream>
#include <cmath>

class BlackScholesPricer {
public:
    // Constructor - PUBLIC
    BlackScholesPricer(double S0, double K, double T, double r, double sigma)
        : S0_(S0), K_(K), T_(T), r_(r), sigma_(sigma) {}

    // Public method - this is how users interact with the class
    double callPrice() const {
        double d1 = (std::log(S0_ / K_) + (r_ + 0.5 * sigma_ * sigma_) * T_) / (sigma_ * std::sqrt(T_));
        double d2 = d1 - sigma_ * std::sqrt(T_);
        // IMPORTANT: callPrice() can call the private normal_cdf
        return S0_ * normal_cdf(d1) - K_ * std::exp(-r_ * T_) * normal_cdf(d2);
    }

private:
    // Private member variables (data)
    double S0_;
    double K_;
    double T_;
    double r_;
    double sigma_;

    // Private helper function - only usable BY OTHER MEMBER FUNCTIONS of BlackScholesPricer
    double normal_cdf(double x) const {
        return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
    }
};

int main() 
{
    // Here myPricer is an object and not a memeber function of a class
    BlackScholesPricer myPricer(100.0, 100.0, 1.0, 0.05, 0.20);

    // This is allowed: call a PUBLIC method
    double price = myPricer.callPrice();
    std::cout << "Option Price: " << price << std::endl;

    return 0;

}

/* 

You can think of BlackScholesPricer as a web browser application for example
and myPricer as a specific tab/instance of that broswer. So when you create the myPricer object, it's like opening
a new tab.

*/