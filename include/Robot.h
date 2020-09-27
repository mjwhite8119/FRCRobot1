#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "DriveTrain.h"

class Robot
{
  public:

    // --- Constructor ---
    Robot() {}
    
    // --- Member classes (Robot configuration) ---

    // Drive train of robot
    DriveTrain driveTrain;

    /**
     * Handles tasks to be performed while the command is running.
     * This is called from the main loop.
     */ 
    void handleRunningCommand() {
      // If the driveTrain is inactive then the command is finished
      if (driveTrain.inActive()) {
        commandRunning = false;
      }
    }

    /**
     * Handles tasks to be performed after a command has completed.
     * This is called from the main loop.
     */ 
    void handleEndCommand() {

      // Do nothing if the command is running
      if (commandRunning) { return; }

       // Turn off the LED
      digitalWrite(LED_BUILTIN, LOW);

      // Get the number of pulses from each encoder
      int leftMotorPulses = robot.driveTrain.leftWheel.motor.getPulsesPerSecond();
      int rightMotorPulses = robot.driveTrain.rightWheel.motor.getPulsesPerSecond();
      
      // Display pulses per second for this command to the OLED
      drawText(2, 0, "L");
      drawText(2, 10, String(leftMotorPulses));
      drawText(2, 50, "R");
      drawText(2, 60, String(rightMotorPulses));
    }

    /**
     * Move robot forward
     * 
     * @param period - Period to run the motor in seconds
     * @param leftPWM - Left wheel PWM signal
     * @param rightPWM - Right wheel PWM signal
     */ 
    void forward(const int period, const int leftPWM, const int rightPWM) {

      // Convert seconds to micro seconds since that's what the timer interrupt wants
      int timeOut = period*1000;     
      driveTrain.setWheelSpeeds(1, 1, leftPWM, rightPWM, timeOut);
    }

    /**
     * Move robot backward
     * 
     * @param period - Period to run the motor in seconds
     * @param leftPWM - Left wheel PWM signal
     * @param rightPWM - Right wheel PWM signal
     */ 
    void backward(const int period, const int leftPWM, const int rightPWM) {

      // Convert seconds to micro seconds since that's what the timer interrupt wants
      int timeOut = period*1000;
      driveTrain.setWheelSpeeds(-1, -1, leftPWM, rightPWM, timeOut);
    }

    /**
     * Spin the robot to the left
     * 
     * @param period - Period to run the motor in seconds
     * @param speed - A wheel speed between 1 and -1
     */ 
    // void left(const int period, const float speed) {
    //   driveTrain.setWheelSpeeds(speed, speed);
    //   digitalWrite(LED_BUILTIN, HIGH);
    //   delay(period*1000);
    //   stop();
    // }

    /**
     * Spin the robot to the right
     * 
     * @param period - Period to run the motor in seconds
     * @param speed - A wheel speed between 1 and -1
     */ 
    // void right(const int period, const float speed) {
    //   driveTrain.setWheelSpeeds(speed, speed);
    //   digitalWrite(LED_BUILTIN, HIGH);
    //   delay(period*1000);
    //   stop();
    // }

    /**
     * Stop the robot
     */ 
    // void stop() {
    //   driveTrain.setWheelSpeeds(0, 0, 0);
    //   digitalWrite(LED_BUILTIN, LOW);
    // }
};

#endif _ROBOT_H_