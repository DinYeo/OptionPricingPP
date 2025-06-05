#include <iostream>
#include <cmath>

using namespace std;

enum class PayOffType
{
    Call = 1,
    Put = -1
};

class BlackScholesModel
{
    double putPrice();
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}