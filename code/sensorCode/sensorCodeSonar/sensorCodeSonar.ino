//Timeout for the sonar. 
int timeOut = 20;

//Pin number allocation.
const int pwPinFront = 2;
const int triggPinFront = 3;

const int pwPinRight = 4;
const int triggPinRight = 5;

const int pwPinBack = 6;
const int triggPinBack = 7;

const int pwPinLeft = 8;
const int triggPinLeft = 9;

const int firstPinAPM = 10;
const int secondPinAPM = 11;

//Variables needed to store values
long pulseFront, pulseBack, pulseLeft, pulseRight, cmFront, cmBack, cmLeft, cmRight;

//Dangerzone radius.
const int limit = 50;

//Variables needed to send information to APM.
int sonarcombination, firststate, secondstate;
int sonarDataToApm[] = {40, 110, 180, 250};
int tooClose[] = {0,0,0,0};


void setup() {
 //Initialize pins.
 pinMode(pwPinFront, INPUT);
 pinMode(triggPinFront, OUTPUT);
 
 pinMode(pwPinRight, INPUT);
 pinMode(triggPinRight, OUTPUT);
 
 pinMode(pwPinBack, INPUT);
 pinMode(triggPinBack, OUTPUT);
 
 pinMode(pwPinLeft, INPUT);
 pinMode(triggPinLeft, OUTPUT);
 
 pinMode(firstPinAPM, OUTPUT);
 pinMode(secondPinAPM, OUTPUT);

}

void loop()
 
 //Front
 pinMode(triggPinFront, HIGH);
 delayMicroseconds(25);
 pinMode(triggPinFront, LOW);
 pulseFront = pulseIn(pwPinFront, HIGH);
 delayMicroseconds(timeOut);
 
 //Back
 pinMode(triggPinBack, HIGH);
 delayMicroseconds(25);
 pinMode(triggPinBack, LOW);
 pulseBack = pulseIn(pwPinBack, HIGH);
 delayMicroseconds(timeOut);
 
 //Right
 pinMode(triggPinRight, HIGH);
 delayMicroseconds(25);
 pinMode(triggPinRight, LOW);
 pulseRight = pulseIn(pwPinRight, HIGH);
 delayMicroseconds(timeOut);

 //Left
 pinMode(triggPinLeft, HIGH);
 delayMicroseconds(25);
 pinMode(triggPinLeft, LOW);
 pulseLeft = pulseIn(pwPinLeft, HIGH);
 delayMicroseconds(timeOut);
 
 //Conversion
 cmFront=pulseFront/58;
 cmRight=pulseRight/58;
 cmBack=pulseBack/58;
 cmLeft=pulseLeft/58;
 
 //Check if distance to detected object is too small. 
 tooClose[0] = (cmFront < limit);
 tooClose[1] = (cmBack < limit);
 tooClose[2] = (cmRight < limit);
 tooClose[3] = (cmLeft < limit);  
 
 //Create an interger that represents all combinations of detection. 
 sonarcombination = 0;
 
 for(int i = 3; i >= 0; i = i-1){
   sonarcombination = sonarcombination | (tooClose[3-i] << i);
 }

 //Prepare for analogWrite.
 firststate = sonarcombination / 4;
 secondstate = sonarcombination % 4;
 
 //Send PWM to APM.
 analogWrite(firstPinAPM, sonarDataToApm[firststate]);
 analogWrite(secondPinAPM, sonarDataToApm[secondstate]);

}