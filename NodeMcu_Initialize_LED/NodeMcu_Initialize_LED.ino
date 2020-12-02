void setup() {
  pinMode(13, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(15, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(13, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);                      // Wait for two seconds (to demonstrate the active low LED)

// New program for second LED with other PIN 
 digitalWrite(15, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
//  delay(1000);                      // Wait for a second
  digitalWrite(15, HIGH);  // Turn the LED off by making the voltage HIGH
//  delay(1000);                      // Wait for two seconds (to demonstrate the active low LED)
}
