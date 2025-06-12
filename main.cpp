/* 

This program calculates the price of a European option using the Black-Scholes
Model.

CDF of the standard normal disitrbution determins the fair prie of the option.
It calculates the probability that a r.v. will fall below a certain value, 
likelihood that the option will expire in-the-money or out-of-the-money.
Eqn: N(x) = 0.5 * (1 + erf(x / sqrt(2)))

*/

#include <iostream> // For input and output operations (std::cout, std::cin)
#include <cmath> // For mathematical functions (std::sqrt, std::exp, std::log))
#include <iomanip> // For setting output precision (std::setprecision)

class BlackScholesCal
{
    public:
        BlackScholesCal(double S, double K, double r, double T, double sigma)
            : S_(S), K_(K), r_(r), T_(T), sigma_(sigma)
        {
            // Private member function to check the validity of the input values
            checkValues();
        }

        // Public methods to calculate the price of Call and Put options
        double callOption() const;
        double putOption() const;

    private:
        double S_; // Current stock price
        double K_; // Strike price
        double r_; // Risk-free interest rate
        double T_; // Time to expiration in years
        double sigma_; // Volatility

        double normalCDF(double x) const
        {
            // Cumulative distribution function for the standard normal distribution
            return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
        }
        
        void checkValues() const
        {
            // Check if the time to expiration and volatility are valid
            if (T_ <= 0) {
                std::cerr << "Error: Time to expiration must be greater than 0. Please re-enter a positive value for Time to expiration" 
                << std::endl;
                exit(EXIT_FAILURE);
            }
            if (sigma_ <= 0) {
                std::cerr << "Error: Volatility must be greater than 0. Please re-enter a positive value for volatility" 
                << std::endl;
                exit(EXIT_FAILURE);
            }
        }

};

int main() {
    // Declare variables for the parameters
    double S, K, r, T, sigma;

    // Get user input for the parameters
    std::cout << "Enter the Current Stock Price: ";
    std::cin >> S;

    std::cout << "Enter the Strike Price: ";
    std::cin >> K;

    std::cout << "Enter the risk-free interest rate: ";
    std::cin >> r;

    std::cout << "Enter the time to expiration in years: ";
    std::cin >> T;

    std::cout << "Enter the Volatility: ";
    std::cin >> sigma;

    // Confirm the values entered by the user
    std::cout << "\nValues you've entered:" << std::endl;
    std::cout << "Current Stock Price (S): " << S << std::endl;
    std::cout << "Strike Price (K): " << K << std::endl;
    std::cout << "Risk-free interest rate (r): " << r << std::endl;
    std::cout << "Time to expiration (T): " << T << std::endl;
    std::cout << "Volatility (sigma): " << sigma << std::endl;

    // Creates an instance of the BlackScholesCal class
    BlackScholesCal OptionPricer(S, K, r, T, sigma);

    // std::setprecisious is(2) sets the precision of the output to 2 decimal places
    std::cout << "\nPrice of the Call Option: " << std::fixed << std::setprecision(2) 
    << OptionPricer.callOption() << std::endl;
    std::cout << "Price of the Put Option: " << std::fixed << std::setprecision(2) 
    << OptionPricer.putOption() << std::endl;

    return 0;
}

// Function is defined outside the class
double BlackScholesCal::callOption() const
{
    double C;

    // Calculate the price of the Call Option using the Black-Scholes formula
    double d1 = (std::log(S_ / K_) + ((r_ + (std::pow(sigma_, 2) / 2)) * T_) / (sigma_ * std::sqrt(T_)));
    double d2 = d1 - sigma_*std::sqrt(T_);
    C = S_ * normalCDF(d1) - K_ * std::exp(-r_ * T_) * normalCDF(d2);

    return C; // Set precision to 2 decimal places
}

double BlackScholesCal::putOption() const
{
    double P;

    // Calculate the price of the Put Option using the Black-Scholes formula
    double d1 = (std::log(S_ / K_) + ((r_ + (std::pow(sigma_, 2) / 2)) * T_) / (sigma_ * std::sqrt(T_)));
    double d2 = d1 - sigma_ * std::sqrt(T_);
    P = -S_ * normalCDF(-d1) + K_ * std::exp(-r_ * T_) * normalCDF(-d2);

    return P;
}