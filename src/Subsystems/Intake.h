#ifndef FRC2018_INTAKE_H
#define FRC2018_INTAKE_H

#include "wpilib.h"
#include "RobotMap.h"

class Intake {
public:
    DoubleSolenoid * piston;
    Intake();
    bool SetState(bool closed);
};


#endif //FRC2018_INTAKE_H
