int led_hijau = 2;
#define rain_sensor A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_hijau, OUTPUT);
  digitalWrite(led_hijau, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Analog output: ");
  Serial.println(readSensor());
  delay(500);
}

int readSensor() {
  int sensor_value = analogRead(rain_sensor);
  int output_value = map(sensor_value, 0, 1023, 255, 0);
  analogWrite(led_hijau, output_value);
  return output_value;
}
