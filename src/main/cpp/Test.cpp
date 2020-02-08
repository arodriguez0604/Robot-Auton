#include "Test.h"

void Robot::RobotInit() {   
    s_FrontLeft     = new CANSparkMax(SPARKFRONTLEFT, CANSparkMax::MotorType::kBrushless);
    s_BackLeft      = new CANSparkMax(SPARKBACKLEFT, CANSparkMax::MotorType::kBrushless);
    s_FrontRight    = new CANSparkMax(SPARKFRONTRIGHT, CANSparkMax::MotorType::kBrushless);
    s_BackRight     = new CANSparkMax(SPARKBACKRIGHT, CANSparkMax::MotorType::kBrushless);
    e_FrontLeft     = new CANEncoder(*SPARKFRONTLEFT);
    e_BackLeft      = new CANEncoder(*SPARKBACKLEFT);
    e_FrontRight    = new CANEncoder(*SPARKFRONTRIGHT);
    e_BackRight     = new CANEncoder(*SPARKBACKRIGHT);
}

void Robot::RobotPeriodic()  {
    TeleopPeriodic();
}

void Robot::AutonomousInit() {
    TeleopInit();
}

void Robot::AutonomousPeriodic() {
    
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
    
}

void Robot::TestPeriodic() {
    TeleopPeriodic();
}

#ifndef RUNNING_FRC_TESTS
int main()  { 
  return frc::StartRobot<Robot>();
}
#endif