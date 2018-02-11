/*
 * Name        : temperature.h
 * Author      : FILL IN
 * Description : Class Header File
 */

// ADD HEADER GUARD HERE
#ifndef temperature_h
#define temperature_h

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

using std::string;
using std::stringstream;

/*
 * Class Temperature.
 * A class that converts temperatures. It will always internally store the value
 * in kelvin.
 */
class Temperature {
 public:
  Temperature();

  Temperature(double kelvin);

  Temperature(double temp, char unit);

  void SetTempFromKelvin(double kelvin);

  void SetTempFromCelsius(double celsius);

  void SetTempFromFahrenheit(double fahrenheit);

  double GetTempAsKelvin() const;

  double GetTempAsCelsius() const;

  double GetTempAsFahrenheit() const;

  string ToString(char unit) const;

 private:
  double kelvin_;
};

// REST OF HEADER GUARD GOES HERE
#endif