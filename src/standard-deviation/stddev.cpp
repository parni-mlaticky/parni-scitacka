/* Název projektu: Parni Scitacka
 * Soubor: stddev.cpp
 * Datum: 24.04.2022
 * Posledni zmena: 24.04.2022
 * Autor: Marek Havel ivs(at)havy.eu
 *
 * Popis: Program vypocita standardni odchylku ze zadanych cisel
 */

//todo add to Makefile:
// successfully built, pwd in this folder, using g++ stddev.cpp ../steammath/steammath.cpp -o stddev
// for testing I used ./stddev < test.txt which includes many kinds of pain, but not all

/**
 * Simple CLI app, which performs standard deviation calculation on number from stdin.
 * @author Marek Havel
 * @date 2022-04-24
 * @version 1.0
 * @file stddev.cpp
 * @return standard deviation on stdout.
 * @return 0 if everything was successful.
 */

#include <iostream>
#include "../steammath/steammath.h"

using namespace std;
using namespace sm;

/**
 * @brief Method to calculate standard deviation of a sample
 *
 * @param *data Pointer to input data
 * @param n Number of elements in input data
 * @return double Standard deviation of input data
 * @bug does not work for numbers with a decimal dash instead of a point todo fix
 * @bug does not work for too precise numbers todo fix
 */
double stddev_sample(double *data, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++) //add all numbers in *data
    {
        sum = SteamMath::sum(sum, data[i]); // sum += data[i];
    }

    double mean = SteamMath::div(sum, n); // compute mean average, mean = sum / n;

    double variance = 0.0;
    for (int i = 0; i < n; i++) // calculate, how much do numbers in data variate
    {
        variance = SteamMath::sum(variance, SteamMath::mul(SteamMath::sub(data[i], mean), SteamMath::sub(data[i], mean))); //variance += (data[i] - mean) * (data[i] - mean);
    }

    variance = SteamMath::div(variance, SteamMath::sub(n, 1)); // Correction using sample amount, variance /= (n - 1);
    double std_dev = SteamMath::root(variance,2); // calculate standard deviation from variance, sqrt(variance)

    return std_dev;
}

/**
 * @brief Fetch user input, execute calculation of standard deviation, and print result
 * @return 0 if everything was successful
*/
int main()
{
    string input;
    int n = 0;
    double *data;

    while(cin >> input)
    {
        n++;
        double *temp = data;
        data = new double[n];
        for (int i = 0; i < n-1; i++)
        {
            data[i] = temp[i];
        }
        data[n-1] = stod(input);
        cout << data[n-1] << endl;
    }

    if(n > 0) // different behaviour if no data was provided
    {
        cout << stddev_sample(data, n) << endl;
        delete[] data;
    }
    else
    {
        cout << "No data" << endl;
    }

    return 0;
}
