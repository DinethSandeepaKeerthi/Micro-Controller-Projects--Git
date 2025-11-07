// Define the connections to the TB6600
const int dirPin = 8;   // Direction pin
const int stepPin = 9;  // Step pin
const int enablePin = 7; // Enable pin

// Motor movement parameters
int stepsPerRevolution = 200; // Adjust this to match your stepper motor
int steps = 0;
int direction = 1;
int speedDelay = 500; // Delay between steps (in microseconds), controls speed

void setup() {
  // Set pins as output
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  // Enable the motor
  digitalWrite(enablePin, LOW);
  
  // Start serial communication
  Serial.begin(9600);
  Serial.println("TB6600 Stepper Motor Control:");
  Serial.println("Send commands in the format: <steps> <direction> <speed>");
  Serial.println("Example: 1000 1 500 (1000 steps clockwise at 500us delay)");
  Serial.println("         -500 0 1000 (-500 steps counterclockwise at 1000us delay)");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming string
    String command = Serial.readStringUntil('\n');
    
    // Parse the command to get steps, direction, and speed
    int firstSpaceIndex = command.indexOf(' ');
    int secondSpaceIndex = command.indexOf(' ', firstSpaceIndex + 1);
    
    steps = command.substring(0, firstSpaceIndex).toInt();
    direction = command.substring(firstSpaceIndex + 1, secondSpaceIndex).toInt();
    speedDelay = command.substring(secondSpaceIndex + 1).toInt();
    
    // Set the direction (1 for clockwise, 0 for counterclockwise)
    if (direction == 1) {
      digitalWrite(dirPin, HIGH);
    } else if (direction == 0) {
      digitalWrite(dirPin, LOW);
    } else {
      Serial.println("Invalid direction. Use 1 for clockwise, 0 for counterclockwise.");
      return;
    }
    
    // Move the motor by the specified number of steps
    for (int i = 0; i < abs(steps); i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speedDelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speedDelay);
    }
  }
}
