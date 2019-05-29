int pin = A2;
float value = 0.0;
float knownR = 0.0;
float R = 0;
float inputV = 1023.0;
float upper = 0.0;// upper bound
float lower = 0.0;// lower bound
float factor = 50.0; // TODO: how to determine the accuracy? 

void setup() {
Serial.begin(9600);
knownR = 91000.0; // known resister
upper = knownR * (factor/2);
lower = knownR / factor;
}

void loop() {
value = analogRead(pin);
Serial.print("Digital value of R: "); // the digital value from analogRead
Serial.println(value);

R = (knownR * value) / (inputV - value);// voltage divider
Serial.print("R value: ");
Serial.print(R);

if(R - knownR >= upper || R <= lower){// depend on the knownR, the range of measurement can be different
  Serial.println(" (measurement may be inaccurate)");
} else {
  Serial.println("");
}

delay(2000);

}
