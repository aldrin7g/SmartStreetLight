// Define the analog pin where the LDR is connected
const int ldrPin = A0;
// Define the LED pin
const int ledPin = 4; // D2 pin 9 supports PWM

int HighLimit = 650;
int LowLimit = 75;

void setup() {
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(115200);
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog value from the LDR
  int ldrValue = analogRead(ldrPin);

  // Invert the LDR value and map it to the LED brightness (0-650 to 255-0)
  int brightness = map(ldrValue, LowLimit, HighLimit, 0, 255);

  // Ensure the brightness is within bounds
  brightness = constrain(brightness, 0, 255);

  // // If LDR value is below 75, set LED to full brightness
  if (ldrValue < LowLimit) {
    brightness = 0;
  }
  
  // // If LDR value is above 1000, turn off the LED
  if (ldrValue > HighLimit) {
    brightness = 255;
  }

  // Set the LED brightness using PWM
  analogWrite(ledPin, brightness);

  // Print the LDR value and LED brightness to the serial monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  Serial.print("LED Brightness: ");
  Serial.println(brightness);

  // Add a delay for stability (you can adjust the delay as needed)
  delay(100);
}
