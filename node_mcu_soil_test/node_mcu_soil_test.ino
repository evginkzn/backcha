void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("ADC Value: ");Serial.println(analogRead(A0));
  delay(300);
}
