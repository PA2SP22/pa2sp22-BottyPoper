#include "temperature.h"
#include "iostream"
#include <iomanip>
// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature()
{
    kelvin_ = 0;
}
Temperature::Temperature(double kelvin)
{
    kelvin_ = kelvin;
}
Temperature::Temperature(double temp, char unit)
{
    if (toupper(unit) == 'C')
    {
        SetTempFromCelsius(temp);
    }
    else if (toupper(unit) == 'F')
    {
        SetTempFromFahrenheit(temp);
    }
    else
    {
        SetTempFromKelvin(temp);
    }
}
void Temperature::SetTempFromKelvin(double kelvin)
{
    kelvin_ = kelvin;
}
void Temperature::SetTempFromCelsius(double celsius)
{
    kelvin_ = celsius + 273.15;
}
void Temperature::SetTempFromFahrenheit(double fahrenheit)
{
    kelvin_ = ((fahrenheit - 32) / 1.800) + 273.15;
}
double Temperature::GetTempAsKelvin() const
{
    return kelvin_;
}
double Temperature::GetTempAsCelsius() const
{
    return kelvin_ - 273.15;
}
double Temperature::GetTempAsFahrenheit() const
{
    return (kelvin_ - 273.15) * 1.8000 + 32.00;
}
string Temperature::ToString(char unit) const
{
    stringstream output;
    double after_unit;
    string unit_name;
    if (std::toupper(unit) == 'C')
    {
        after_unit = GetTempAsCelsius();
        unit_name = " Celsius";
    }
    else if (std::toupper(unit) == 'F')
    {
        after_unit = GetTempAsFahrenheit();
        unit_name = " Fahrenheit";
    }else if (std::toupper(unit) == 'K')
    {
        after_unit = GetTempAsKelvin();
        unit_name = " Kelvin";
    }else
    {
        return "Invalid Unit";
    }
    output << std::fixed << std::setprecision(2) << after_unit << unit_name;
    return output.str();
}