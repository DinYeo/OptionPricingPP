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

// Function Prototypes
void checkValues(double T, double sigma);
double normalCDF(double x);
double callOption(double S, double K, double r, double T, double sigma);
double putOption(double S, double K, double r, double T, double sigma);

int main() {
    // Declare variables for black-scholes parameters
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
    
    // Check if the time to expiration and volatility are valid
    checkValues(T, sigma);

    // Confirm the values entered by the user
    std::cout << "\nValues you've entered:" << std::endl;
    std::cout << "Current Stock Price (S): " << S << std::endl;
    std::cout << "Strike Price (K): " << K << std::endl;
    std::cout << "Risk-free interest rate (r): " << r << std::endl;
    std::cout << "Time to expiration (T): " << T << std::endl;
    std::cout << "Volatility (sigma): " << sigma << std::endl;

    // std::setprecisious is(2) sets the precision of the output to 2 decimal places
    std::cout << "\nPrice of the Call Option: " << std::fixed << std::setprecision(2) 
    << callOption(S, K, r, T, sigma) << std::endl;
    std::cout << "Price of the Put Option: " << std::fixed << std::setprecision(2) 
    << putOption(S, K, r, T, sigma) << std::endl;

    return 0;
}

void checkValues(double T, double sigma)
{
    // Check if the time to expiration and volatility are valid
    if (T <= 0) {
        std::cerr << "Error: Time to expiration must be greater than 0. Please re-enter a positive value for Time to expiration" 
        << std::endl;
        exit(EXIT_FAILURE);
    }
    if (sigma <= 0) {
        std::cerr << "Error: Volatility must be greater than 0. Please re-enter a positive value for volatility" 
        << std::endl;
        exit(EXIT_FAILURE);
    }
}


double normalCDF(double x)
{
    // Cumulative distribution function for the standard normal distribution
    return 0.5 * std::erf(-x / std::sqrt(2.0));
}

double callOption(double S, double K, double r, double T, double sigma)
{
    double C;

    // Calculate the price of the Call Option using the Black-Scholes formula
    double d1 = (std::log(S / K) + ((r + std::pow(sigma, 2) / 2) * T) / sigma * std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);
    C = S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);

    return C; // Set precision to 2 decimal places
}

double putOption(double S, double K, double r, double T, double sigma)
{
    double P;

    // Calculate the price of the Put Option using the Black-Scholes formula
    double d1 = (std::log(S / K) + ((r + std::pow(sigma, 2) / 2) * T)) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    P = -S * normalCDF(-d1) + K * std::exp(-r * T) * normalCDF(-d2);


    return P;
}