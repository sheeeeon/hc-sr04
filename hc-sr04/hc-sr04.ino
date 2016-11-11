#define DEFN_TRIGGER 3
#define DEFN_ECHO 4  

int vibPin1 = 6;
int ledPin = 13;
int delayTime = 300;
int distance = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(5, LOW);

  pinMode(vibPin1, OUTPUT);
  digitalWrite(vibPin1, HIGH); // off 
  Serial.begin(9600);  // initialize serial

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(DEFN_TRIGGER, LOW);      
 delayMicroseconds(2);
 digitalWrite(DEFN_TRIGGER, HIGH);
 delayMicroseconds(10);
 digitalWrite(DEFN_TRIGGER, LOW);
 
 long time_us = pulseIn(DEFN_ECHO, HIGH);  // Get DEFN_ECHO time in microsecs
 long dist_mm = time_us * 0.17;            // 0.34 / 2
 
 //Serial.print("Time(us) : ");        Serial.print(time_us);   
 Serial.print("Distance(mm) : ");  Serial.print(dist_mm); Serial.print(" mm");
 Serial.println("");

 if (dist_mm < distance) {
    digitalWrite(vibPin1, LOW);
 } else {
    digitalWrite(vibPin1, HIGH);
 }
 delay(delayTime);
 
}


