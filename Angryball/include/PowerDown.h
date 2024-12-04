#ifndef POWERDOWN_H
#define POWERDOWN_H

#include <string>

class PowerDown
{
public:
    enum class Type
    {
        ExtremeSpeeds,
        ShorterPowerBar
    };

    PowerDown(Type type);
    void applyPowerDown(double &speed, int& barLength);
    std::string getPowerDown() const;

private:
    Type type;
    std::string lastEffect; // Store the last applied effect
};

#endif // POWERDOWN_H