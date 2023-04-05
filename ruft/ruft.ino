#define rain_sensor A1
int led_merah = 3;
int led_hijau = 2;

int delaytime = 3;
bool kering= true;
bool aktif= true;
int lamaputaran = 450;

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

int buzzer = 8;

int ldr = A0;
int ldr_state = 0;
\
// Bluetooth
char val;
void setup() {
  // put your se bup code here, to run once:
  Serial.begin(9600);
  pinMode(led_merah, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(13,OUTPUT);

  pinMode(ldr, INPUT);
  Serial.begin(9600);
}
void loop() {
  Serial.print("Analog output: ");
  Serial.println(readRainSensor());

  ldr_state = analogRead(ldr);
  Serial.print("Nilai LDR: ");
  Serial.println(ldr_state);
  // delay(500);


// bluetotth
if(Serial.available()){
 val = Serial.read();
 Serial.println(val);
  if(val=='0'){
    aktif=false;
 }
 if(val=='1'){
   aktif=true;
 }
}
if(aktif==false){
  digitalWrite(led_hijau, HIGH);
  digitalWrite(led_merah, LOW);
}
else if(aktif==true){
    if(ldr_state > 500){
     if (readRainSensor() > 100) {
    if(kering==false){
      digitalWrite(led_merah, HIGH);
      digitalWrite(led_hijau, LOW);
      for(int i = 0; i < lamaputaran; i++){
        maju();
        tone(buzzer, 1000,500);
      }  
      digitalWrite(led_hijau, HIGH);
      digitalWrite(led_merah, LOW);
      kering =true; 
    }
  }else {
    if(kering==true){
      digitalWrite(led_merah, HIGH);
      digitalWrite(led_hijau, LOW);
      for(int i = 0; i < lamaputaran; i++){
        mundur();
        tone(buzzer, 1000,500);
      }
        digitalWrite(led_hijau, HIGH);
        digitalWrite(led_merah, LOW);
      kering =false;
    }
  }
  }

 if(ldr_state < 300){
    if(kering == false){
      digitalWrite(led_merah, HIGH);
      digitalWrite(led_hijau, LOW);
      for(int i = 0; i < lamaputaran; i++){
        maju();
        tone(buzzer, 1000,500);
      }  
      digitalWrite(led_hijau, HIGH);
      digitalWrite(led_merah, LOW);
      kering =true; 
    }else{
      digitalWrite(led_hijau, HIGH);
      digitalWrite(led_merah, LOW);
  }
  }


}
  delay(500);
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

int readRainSensor() {
  int sensor_value = analogRead(rain_sensor);
  int output_value = map(sensor_value, 0, 1023, 255, 0);
  analogWrite(led_merah, output_value);
  return output_value;
}

