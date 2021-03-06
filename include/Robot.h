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
     * Move robot forward
     * 
     * @param period - Period to run the motor in seconds
     */ 
    void forward(const int period) {
      driveTrain.setWheelSpeeds(1, 1, 190, 190);
      digitalWrite(LED_BUILTIN, HIGH); // Turn LED on to indicate message received
      delay(period*1000); // delay is specified in micro seconds
      stop();
    }

    /**
     * Move robot backward
     * 
     * @param period - Period to run the motor in seconds
     */ 
    void backward(const int period) {
      driveTrain.setWheelSpeeds(-1, -1, 190, 190);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(period*1000);
      stop();
    }

    /**
     * Spin the robot to the left
     * 
     * @param period - Period to run the motor in seconds
     */ 
    void left(const int period) {
      driveTrain.setWheelSpeeds(-1, 1, 190, 190);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(period*1000);
      stop();
    }

    /**
     * Spin the robot to the right
     * 
     * @param period - Period to run the motor in seconds
     */ 
    void right(const int period) {
      driveTrain.setWheelSpeeds(1, -1, 190, 190);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(period*1000);
      stop();
    }

    /**
     * Stop the robot
     */ 
    void stop() {
      driveTrain.setWheelSpeeds(0, 0, 0, 0);
      digitalWrite(LED_BUILTIN, LOW);
    }
};

#endif _ROBOT_H_