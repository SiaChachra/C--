#include <iostream>
#include <cmath>

using namespace std;

double calculate_gibbs_free_energy(double R, double T, double lnK)
{

    double T_kelvin = T + 273.15;

    double delta_G = -R * T_kelvin * lnK;
    return delta_G;
}

int main()
{
    double R, T;
    const double lnK = -6.45;

    cout << "Enter the value for R: ";
    cin >> R;

    cout << "Enter the value for T (in Celsius): ";
    cin >> T;

    double delta_G = calculate_gibbs_free_energy(R, T, lnK);

    cout << "The Gibbs free energy is: " << delta_G << endl;

    return 0;
}
