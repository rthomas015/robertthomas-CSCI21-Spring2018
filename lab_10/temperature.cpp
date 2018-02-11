/*Temperature.cpp
  By: Robert Thomas
  Date: 2/09/2018
*/

#include "temperature.h"

  /*
   * Constructor #1.
   * Sets kelvin_ to 0
   */
  Temperature::Temperature() {
      kelvin_ = 0;
  }

  /*
   * Constructor #2.
   * Sets kelvin_ to the supplied value
   * @param double kelvin - The value to set the internal kelvin to
   */
  Temperature::Temperature(double kelvin) {
      kelvin_ = kelvin;
  }

  /*
   * Constructor #3.
   * Converts the supplied temperature to kelvin and internally stores it.
   * The temperature's unit will be provided in the second argument.
   * If the second argument is not value (i.e. not 'F' or 'C') assume the
   * temperature is in kelvin
   * @param double temp - The value to set the internal kelvin to once
   *                    - converted.
   * @param char unit - The type of unit temp is. Will be either 'F' or 'C',
   *                    case-insensitive
   */
  Temperature::Temperature(double temp, char unit) {
      if (unit == 'F' || unit == 'f') {
          kelvin_ = (5.0 * (temp - 32.0) / 9.0) + 273.15;
      }
      else if (unit == 'C' || unit == 'c') {
          kelvin_ = temp + 273.15;
      }
      else {
          kelvin_ = temp;
      }
  }

  /*
   * The temperature will come in as kelvin and this function will set the
   * internal temp to this value
   * @param double kelvin - The value to set the internal kelvin to.
   */
  void Temperature::SetTempFromKelvin(double kelvin)  {
      kelvin_ = kelvin;
  }

  /*
   * The temperature will come in as Celsius and this function will set the
   * internal temp to this value, once converted to kelvin
   * Formula: k = c + 273.15
   * @param double celsius - The value (in celsius) to set the internal kelvin
   *                       - to.
   */
  void Temperature::SetTempFromCelsius(double celsius) {
      kelvin_ = celsius + 273.15;
  }

  /*
   * The temperature will come in as Fahrenheit and this function will set the
   * internal temp to this value, once converted to kelvin
   * Formula: k = (5.0 * (f - 32) / 9) + 273.15
   * @param double fahrenheit - The value (in fahrenheit) to set the internal
   *                          - kelvin to.
   */
  void Temperature::SetTempFromFahrenheit(double fahrenheit) {
      kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
  }

  /*
   * Gets the internal temperature in Kelvin.
   * @return double - The temperature in Kelvin
   */
  double Temperature::GetTempAsKelvin() const {
      return kelvin_;
  }

  /*
   * Returns the internal temp converted to Celsius
   * Formula: k - 273.15
   * @return double - The temperature in Celsius
   */
  double Temperature::GetTempAsCelsius() const {
      return (kelvin_ - 273.15);
  }

  /*
   * Returns the internal temp converted to Fahrenheit
   * Formula: ((c * 9.0) / 5) + 32;
   * @return double - The temperature in Fahrenheit
   */
  double Temperature::GetTempAsFahrenheit() const {
      return ((((kelvin_ - 273.15) * 9.0) / 5) + 32);
  }

  /*
   * Get a string representation of the temperature.
   * The string will be formatted as:
   * "TEMP UNIT"
   * where TEMP is the temperature to 2 decimal places and UNIT is either
   * "Kelvin", "Celsius", or "Fahrenheit".
   * The conversion to perform is denoted by the parameter.
   * If the unit given through the argument is invalid, set the string to:
   * "Invalid Unit"
   * @uses stringstream
   * @param char unit - The conversion to perform, either 'K', 'C' or 'F',
   *                    defaults to 'K' and is case-insensitive
   * @return string - A string representation of the temperature or invalid if
   *                  the provided unit is not recognized
   */
  string Temperature::ToString(char unit = 'K') const {
      stringstream full_string;
      double temp_value = 0.00;
      
      if (unit == 'F' || unit == 'f') {
          temp_value = ((((kelvin_ - 273.15) * 9.0) / 5) + 32);
          full_string << fixed << setprecision(2) << temp_value << " Fahrenheit";
      }
      else if (unit == 'C' || unit == 'c') {
          temp_value = kelvin_ - 273.15;
          full_string << fixed << setprecision(2) << temp_value << " Celsius";
      }
      else if (unit == 'K' || unit == 'k') {
          temp_value = kelvin_;
          full_string << fixed << setprecision(2) << temp_value << " Kelvin";
      }
      else {
          full_string << "Invalid Unit";
      }
      
      return full_string.str();
  }