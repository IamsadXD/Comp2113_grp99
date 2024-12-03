#ifndef POWERDOWN_H
#define POWERDOWN_H

#include <string>

class PowerDown
{
public:
    enum class Type
    {
        ExtremeSpeeds,
        ShorterPowerBar,
        DecreaseBallSize,
        ReduceLives
    };

    PowerDown(Type type);
    void applyEffect();
    std::string getName() const;

private:
    Type type;
};

#endif // POWERDOWN_H
