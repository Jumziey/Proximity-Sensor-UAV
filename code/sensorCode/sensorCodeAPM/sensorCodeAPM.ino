//Pin number allocation.
int pwPinDown = 4;
int FirstStatePin = 5; //From pin 10 on the Arduino pro mini.
int SecondStatePin = 6; //From pin 11 on the Arduino pro mini. 

//Variables for storing values.
long valueDown, valueFirst, valueSecond;
long firstState, secondState;

//Integers used to convert the pulses to corresponding numbers.
int nullOffset = 640;
int bitStep = 1110;

void setup() {
 
 Serial.begin(9600);
 
 //Set pinmodes.
 pinMode(pwPinDown, INPUT);
 pinMode(FirstStatePin, INPUT);
 pinMode(SecondStatePin, INPUT);
 
}

void loop() {
 
 //Read pulsewidth from pins.
 valueDown = pulseIn(pwPinDown,HIGH);
 valueFirst = pulseIn(FirstStatePin,HIGH);
 valueSecond = pulseIn(SecondStatePin,HIGH);
 
 //Convert to corresponding numbers.
 firstState = ( valueFirst - nullOffset + bitStep/2 ) / bitStep;
 secondState = ( valueSecond - nullOffset + bitStep/2 ) / bitStep;
 
 Serial.print("Down: ");
 Serial.print(valueDown/58);
 Serial.print(" First t : ");
 Serial.print(valueFirst);
 Serial.print(" Second t : ");
 Serial.print(valueSecond);
 Serial.print(" stateOne : ");
 Serial.print(firstState);
 Serial.print(" stateTwo : ");
 Serial.println(secondState);
 delay(500);

}