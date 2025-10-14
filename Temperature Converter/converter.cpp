#include <iostream>
#include <iomanip>
using namespace std;

double celsiusToFahrenheit(double c) {
	return c * 9.0 / 5.0 + 32.0;
}

double fahrenheitToCelsius(double f) {
	return (f - 32.0) * 5.0 / 9.0;
}

double celsiusToKelvin(double c) {
	return c + 273.15;
}

double kelvinToCelsius(double k) {
	return k - 273.15;
}

int main() {
	cout << "Temperature Converter\n";
	cout << "Choose conversion type:\n";
	cout << "1. Celsius to Fahrenheit\n";
	cout << "2. Fahrenheit to Celsius\n";
	cout << "3. Celsius to Kelvin\n";
	cout << "4. Kelvin to Celsius\n";
	cout << "Enter option (1-4): ";
	int option;
	cin >> option;

	double inputTemp, resultTemp;
	cout << "Enter temperature: ";
	cin >> inputTemp;

	cout << fixed << setprecision(2);
	switch (option) {
		case 1:
			resultTemp = celsiusToFahrenheit(inputTemp);
			cout << inputTemp << " Celsius = " << resultTemp << " Fahrenheit\n";
			break;
		case 2:
			resultTemp = fahrenheitToCelsius(inputTemp);
			cout << inputTemp << " Fahrenheit = " << resultTemp << " Celsius\n";
			break;
		case 3:
			resultTemp = celsiusToKelvin(inputTemp);
			cout << inputTemp << " Celsius = " << resultTemp << " Kelvin\n";
			break;
		case 4:
			resultTemp = kelvinToCelsius(inputTemp);
			cout << inputTemp << " Kelvin = " << resultTemp << " Celsius\n";
			break;
		default:
			cout << "Invalid option.\n";
	}
	return 0;
}
