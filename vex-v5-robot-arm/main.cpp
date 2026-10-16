#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor Shoulder = motor(PORT1, ratio18_1, false);

motor Elbow = motor(PORT2, ratio18_1, false);

controller Controller1 = controller(primary);


// generating and setting random seed
void initializeRandomSeed(){
  int systemTime = Brain.Timer.systemHighResolution();
  double batteryCurrent = Brain.Battery.current();
  double batteryVoltage = Brain.Battery.voltage(voltageUnits::mV);

  // Combine these values into a single integer
  int seed = int(batteryVoltage + batteryCurrent * 100) + systemTime;

  // Set the seed
  srand(seed);
}



void vexcodeInit() {

  //Initializing random seed.
  initializeRandomSeed(); 
}


// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int main() {
  vexcodeInit(); // Khởi động hệ thống

  while (true) { // Vòng lặp: Robot sẽ liên tục kiểm tra lệnh từ bạn
    
    // Điều khiển khớp vai bằng nút L1 và L2
    if (Controller1.ButtonL1.pressing()) {
      Shoulder.spin(forward); // Nhấn L1 thì quay tới
    } else if (Controller1.ButtonL2.pressing()) {
      Shoulder.spin(reverse); // Nhấn L2 thì quay lùi
    } else {
      Shoulder.stop(hold);    // Buông tay thì đứng yên tại chỗ
    }

    // Điều khiển khớp khuỷu bằng nút R1 và R2
    if (Controller1.ButtonR1.pressing()) {
      Elbow.spin(forward);    // Nhấn R1 thì quay tới
    } else if (Controller1.ButtonR2.pressing()) {
      Elbow.spin(reverse);    // Nhấn R2 thì quay lùi
    } else {
      Elbow.stop(hold);       // Buông tay thì đứng yên tại chỗ
    }

    wait(20, msec); // Nghỉ 0.02 giây để não không bị nóng
  }
}
  