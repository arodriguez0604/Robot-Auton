#include "Test.h"

void Robot::RobotInit() {   
    s_FrontLeft     = new CANSparkMax(SPARKFRONTLEFT, CANSparkMax::MotorType::kBrushless);
    s_BackLeft      = new CANSparkMax(SPARKBACKLEFT, CANSparkMax::MotorType::kBrushless);
    s_FrontRight    = new CANSparkMax(SPARKFRONTRIGHT, CANSparkMax::MotorType::kBrushless);
    s_BackRight     = new CANSparkMax(SPARKBACKRIGHT, CANSparkMax::MotorType::kBrushless);
    e_FrontLeft     = new CANEncoder(*s_FrontLeft);
    e_BackLeft      = new CANEncoder(*s_BackLeft);
    e_FrontRight    = new CANEncoder(*s_FrontRight);
    e_BackRight     = new CANEncoder(*s_BackRight);
}

void Robot::RobotPeriodic()  {
    TeleopPeriodic();
}

void Robot::AutonomousInit() {
    TeleopInit();
}

void Robot::AutonomousPeriodic() {
    frc::DifferentialDrive::DifferentialDrive(SpeedControllerGroup & 	s_FrontLeft,  s_BackLeft,
                                              SpeedControllerGroup & 	s_FrontRight, s_BackRight);

    frc::SmartDashboard::GetNumber("Start", start);
    frc::SmartDashboard::GetNumber("Exit", exit);
    frc::SmartDashboard::GetNumber("Delay", delay);
    Sleep (delay);
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
    
}

void Robot::TestPeriodic() {
    TeleopPeriodic();
}

void Robot::Sleep(int time) {
    std::this_thread::sleep_for (std::chrono::seconds(time));
}

void AutonTurn(double robotFromPlayerWall, double robotFromSideWall) {
    double turn = atan (robotFromPlayerWall / robotFromSideWall);
}

#ifndef RUNNING_FRC_TESTS
int main()  { 
  return frc::StartRobot<Robot>();
}
#endif