#include <Stepper.h>

// Define the number of steps per revolution for your stepper motor
const int stepsPerRevolution = 200; // Adjust this value according to your motor

// Initialize the Stepper library on pins 8, 9, 10, and 11
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Set the speed at 60 rpm
  myStepper.setSpeed(60);
  
  // Start the serial communication
  Serial.begin(9600);
  Serial.println("Stepper Motor Control:");
  Serial.println("Send commands in the format: <steps> <direction>");
  Serial.println("Example: 100 1 (100 steps clockwise)");
  Serial.println("         -200 0 (-200 steps counterclockwise)");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming string
    String command = Serial.readStringUntil('\n');
    
    // Parse the command to get steps and direction
    int spaceIndex = command.indexOf(' ');
    int steps = command.substring(0, spaceIndex).toInt();
    int direction = command.substring(spaceIndex + 1).toInt();
    
    // Set direction based on the input (1 for clockwise, 0 for counterclockwise)
    if (direction == 1) {
      // Rotate the motor clockwise
      myStepper.step(steps);
    } else if (direction == 0) {
      // Rotate the motor counterclockwise
      myStepper.step(-steps);
    } else {
      Serial.println("Invalid direction. Use 1 for clockwise, 0 for counterclockwise.");
    }
  }
}
