#pragma once

//#include <string>
#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include "frc/smartdashboard/SmartDashboard.h"
#include <AHRS.h>
#include <math.h>


using namespace frc;
using namespace rev;

class Robot : public TimedRobot {
  public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

    const enum {SPARKFRONTLEFT = 1, SPARKBACKLEFT, SPARKFRONTRIGHT, SPARKBACKRIGHT};

  private:
    rev::CANSparkMax *s_FrontLeft;
    rev::CANSparkMax *s_BackLeft;
    rev::CANSparkMax *s_FrontRight;
    rev::CANSparkMax *s_BackRight;
    rev::CANEncoder *e_FrontLeft;
    rev::CANEncoder *e_BackLeft;
    rev::CANEncoder *e_FrontRight;
    rev::CANEncoder *e_BackRight;
};
