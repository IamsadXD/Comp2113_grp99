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
    void applyEffect(int &speed, int& barLength);
    std::string getName() const;

private:
    Type type;
};

#endif // POWERDOWN_H