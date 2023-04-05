int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int delaytime = 3;
int lamaputaran = 200;
#define rain_sensor A1
int led1 = 2;
int led2 = 3;
const int buzzer = 8;

int ldr = A0;
int ldr_state = 0;

void setup() {
  // Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  ldr_state = analogRead(ldr);
  Serial.print("Nilai LDR: ");
  erial.println(ldr_state);
  Serial.print("Analog output: ");
  Serial.println(readSensor());
  delay(500);
}     
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  tone(buzzer, 1000,500);

  if(ldr_state > 300) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}

  for(int i = 0; i < lamaputaran; i++){
    maju();
  }
  delay(1000);
   for(int j = 0; j < lamaputaran; j++){
    mundur();
  }
  delay(1000);
}

void maju(){
  step1();delay(delaytime);
  step2();delay(delaytime);
  step3();delay(delaytime);
  step4();delay(delaytime);
}
void mundur(){
  step4();delay(delaytime); 
  step3();delay(delaytime); 
  step2();delay(delaytime); 
  step1();delay(delaytime); 
   
}

void step1(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);
}
void step2(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void step3(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void step4(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

int readSensor() {
  int sensor_value = analogRead(rain_sensor);
  int output_value = map(sensor_value, 0, 1023, 255, 0);
  analogWrite(led1, output_value);
  return output_value;
}
