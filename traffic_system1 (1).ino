// Pin definitions for vehicle lights
const int redVehicle = 6;
const int yellowVehicle = 5;
const int greenVehicle = 4;
// Pin definitions for pedestrian lights
const int redPedestrian = 12;
const int greenPedestrian = 10 ;

// Button for pedestrian crossing
const int buttonPin = 8;

// State variable for the system
enum State {VEHICLE_GREEN, VEHICLE_YELLOW, VEHICLE_RED};
State currentState = VEHICLE_GREEN;

// Time tracking
unsigned long previousMillis = 0;
const long interval = 5000;  // Time interval for changing light (5 seconds)

// Button state tracking
bool buttonPressed = false;

void setup() {
  // Initialize the traffic light pins as outputs
  pinMode(redVehicle, OUTPUT);
  pinMode(yellowVehicle, OUTPUT);
  pinMode(greenVehicle, OUTPUT);

  // Initialize the pedestrian light pins as outputs
  pinMode(redPedestrian, OUTPUT);
  pinMode(greenPedestrian, OUTPUT);

  // Initialize the button pin as input
  pinMode(buttonPin, INPUT_PULLUP);  // Button connected to ground

  // Initial states of the traffic and pedestrian lights
  digitalWrite(redVehicle, LOW);
  digitalWrite(yellowVehicle, LOW);
  digitalWrite(greenVehicle, HIGH);  // Vehicle green light on
  digitalWrite(redPedestrian, HIGH);  // Pedestrian red light on
  digitalWrite(greenPedestrian, LOW); // Pedestrian green light off

  Serial.begin(9600); // For debugging
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = true;
  }

  unsigned long currentMillis = millis();

  switch (currentState) {
    case VEHICLE_GREEN:
      // Vehicle green light is on, pedestrian red light is on
      digitalWrite(greenVehicle, HIGH);
      digitalWrite(yellowVehicle, LOW);
      digitalWrite(redVehicle, LOW);
      digitalWrite(redPedestrian, HIGH);
      digitalWrite(greenPedestrian, LOW);

      if (buttonPressed) {
        if (currentMillis - previousMillis >= interval) {
          previousMillis = currentMillis;
          currentState = VEHICLE_YELLOW;
        }
      }
      break;

    case VEHICLE_YELLOW:
      // Vehicle yellow light is on
      digitalWrite(greenVehicle, LOW);
      digitalWrite(yellowVehicle, HIGH);
      digitalWrite(redVehicle, LOW);

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        currentState = VEHICLE_RED;
      }
      break;

    case VEHICLE_RED:
      // Vehicle red light is on, pedestrian green light is on
      digitalWrite(greenVehicle, LOW);
      digitalWrite(yellowVehicle, LOW);
      digitalWrite(redVehicle, HIGH);
      digitalWrite(redPedestrian, LOW);
      digitalWrite(greenPedestrian, HIGH);

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        buttonPressed = false;  // Reset the button press
        currentState = VEHICLE_GREEN;
      }
      break;
  }
}