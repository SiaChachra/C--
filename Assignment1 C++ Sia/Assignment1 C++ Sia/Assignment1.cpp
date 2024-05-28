#include <iostream>
#include <cmath>

using namespace std;

double calculate_gibbs_free_energy(double R, double T, double lnK)
{
    // Modify the temperature from Celsius to Kelvin
    double T_kelvin = T + 273.15;
    // Calculate Gibbs free energy
    double delta_G = -R * T_kelvin * lnK;
    return delta_G;
}

int main()
{
    double R, T;
    const double lnK = -6.45; // Predefined value of lnK

    // Take user inputs for R and T
    cout << "Enter the value for R: ";
    cin >> R;

    cout << "Enter the value for T (in Celsius): ";
    cin >> T;

    // Calculate Gibbs free energy
    double delta_G = calculate_gibbs_free_energy(R, T, lnK);

    // Print the result
    cout << "The Gibbs free energy is: " << delta_G << endl;

    return 0;
}
