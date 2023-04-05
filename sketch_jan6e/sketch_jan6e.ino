int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int delaytime = 3;
int lamaputaran = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
