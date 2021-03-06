#include "OI.h"
#include "Robot.h"
#include "WPILib.h"


OI::OI() {
    for(bool &canPressi : canPress) {
        canPressi = true;
    }
    joy1 = new Joystick(0);
}

void OI::pollButtons() {
    //Block button
    //REMOVE BEFORE COMP
    //trolololol @Lucas
    /*if(joy1->GetRawButton(1)) {
        while(true) {}
    }*/
    if(joy1->GetRawButton(2)) {
        Robot::drivetrain->ReturnWheelsToZero();
    }
    if(joy1->GetRawButton(3)) {
        if(canPress[2]) {
            Robot::arm->Toggle();
        }
        canPress[2] = false;
    } else { canPress[2] = true; }
    if(joy1->GetRawButton(6)) {
        if(canPress[5]) {
            Robot::gyro->ResetHeading();
            Robot::drivetrain->desiredHeading = 180.0;
        }
        canPress[5] = false;
    } else { canPress[5] = true; }
}

double OI::GetX() {
    return this->applyDeadzone(joy1->GetRawAxis(0), 0.15, 1);
}

double OI::GetY() {
    return this->applyDeadzone(-joy1->GetRawAxis(1), 0.15, 1);
}

double OI::GetTwist() {
    return this->applyDeadzone(joy1->GetRawAxis(2), 0.70, 1) / 2;
}

double OI::GetSlider() {
    return joy1->GetRawAxis(3);
}

double OI::applyDeadzone(double val, double deadzone, double maxval) {
    if (fabs(val) <= deadzone) {
        return 0;
    }
    double sign = val / fabs(val);
    val = sign * maxval * (fabs(val) - deadzone) / (maxval - deadzone);
    return val;
}
