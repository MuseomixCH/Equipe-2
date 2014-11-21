#define trigPin 13
#define echoPin 12
#define led1     9   
//#define led2     6

float color1=0;
//float color2=0;
boolean growAlpha=true;
int freq;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
 // pinMode(led2, OUTPUT);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 10 and distance <= 175){
    growAlpha=true;
    freq=1;
    Serial.print(distance);
    Serial.println(" right");
  }
  else {
    growAlpha=false;
    freq=3;
    Serial.print(distance);
    Serial.println(" cm");
  }
  Serial.print(color1);
  Serial.println(" color1");
  //Serial.print(color2);
  //Serial.println(" color2");
  color1=changeAlpha(color1, freq, 255, 0, growAlpha);
 // color2=changeAlpha(color2, 1, 15, 0, growAlpha);
  analogWrite(led1, color1);
  //analogWrite(led2, color2);
  delay(40);
}


float changeAlpha(float value, int frequence,int limitUp, int limitDown, boolean grow){
   if(value < limitUp and grow){
     value+= frequence;
   }
   else if(value>limitDown and !grow){
     value-= frequence;
   }
   if(value>limitUp)
      value=limitUp;
    if(value<limitDown)
      value=limitDown;
   return value;
}
