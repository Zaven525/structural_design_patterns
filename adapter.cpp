// #include <iostream>

// class TemperatureSensor {
// public:
//     virtual double getTemperatureCelsius() = 0;
// };

// class LegacySensor {
// private:
//     double Fahrenheit;
// public:
//     LegacySensor(double F): Fahrenheit{F} {}
//     double OldFahrenheitSensor() { return Fahrenheit; }
// };

// class Adapter : public TemperatureSensor{
// public:
//     double getTemperatureCelsius() override { return (ls.OldFahrenheitSensor() - 32) * (5/9); }
// private:
//     LegacySensor ls;
// };

// class ModernSensor : public TemperatureSensor{
// public:
//     double getTemperatureCelsius() override { return Celsius; }
// private:
//     double Celsius;
// };



// int main() {


//     return 0;
// }

#include <iostream>
#include <vector>

class TemperatureSensor {
public:
    virtual double getTemperatureCelsius() = 0;
    virtual ~TemperatureSensor() = default;
};

class LegacySensor {
private:
    double Fahrenheit;
public:
    LegacySensor(double F): Fahrenheit{F} {}
    double OldFahrenheitSensor() { return Fahrenheit; }
};

class Adapter : public TemperatureSensor {
private:
    LegacySensor ls;
public:
    Adapter(double F) : ls(F) {}

    double getTemperatureCelsius() override {
        return (ls.OldFahrenheitSensor() - 32) * 5.0 / 9.0;
    }
};

class ModernSensor : public TemperatureSensor {
private:
    double Celsius;
public:
    ModernSensor(double C) : Celsius(C) {}

    double getTemperatureCelsius() override {
        return Celsius;
    }
};

int main() {
    // Create legacy sensor and wrap it in adapter
    TemperatureSensor* legacyAdapter = new Adapter(98.6); // Fahrenheit

    // Create modern sensor
    TemperatureSensor* modernSensor = new ModernSensor(37.0); // Celsius

    // Store in vector
    std::vector<TemperatureSensor*> sensors = {legacyAdapter, modernSensor};

    // Print temperatures
    for (TemperatureSensor* sensor : sensors) {
        std::cout << "Temperature: " << sensor->getTemperatureCelsius() << " °C" << std::endl;
    }

    // Clean up
    for (TemperatureSensor* sensor : sensors) {
        delete sensor;
    }

    return 0;
}
