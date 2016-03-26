/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  //int sensrValue = random(100,300);
  
  
  int sensorValue = analogRead(A0);
  if(sensorValue > 200)
  {
    Serial.begin(9600);
    delay(2000);
    Serial.print("AT+CMGF=1\r\n"); // set the SMS mode to text
    delay(3000);
    Serial.print("AT+CMGS=\"+919654063008\"\r\n"); // send the SMS the number
    delay(9000); 
    Serial.print("HELP !!\r\n");
    delay(3000);
    Serial.write(0x1A);
    delay(150000);
    Serial.end();
  }
  // print out the value you read:
  Serial.println(sensorValue);
  delay(500);        // delay in between reads for stability
}

