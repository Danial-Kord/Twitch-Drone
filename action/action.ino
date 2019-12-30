
String command="";
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(115200); 

  } 
void backward(){
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);  
}
void forward(){
     // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void moveMotor(int xAxis,int yAxis,intl dir){

    if(dir)
      forward();
     else
     backward();
    motorSpeedA = yAxis;
    motorSpeedB = yAxis;
    motorSpeedA = motorSpeedA - xAxis;
    motorSpeedB = motorSpeedB + xAxis;
    if (motorSpeedA > 255) {
      motorSpeedA = 255;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  
  // Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}
void loop(){
    
if (Serial.available() > 0) {
  command = Serial.readString();
  int in[3];
  int index=0;
  String temp="";
  for(int i=command.indexOf('!');i<command.length();i++){
    char nnow = command.charAt(i);
    if(now == ' '){
      in[index] = temp.toInt();
      temp = "";
      index++; 
      if(index == 3)
       break;
    }
    else if(now != '#'){
      temp+= now;
    }
    else{
      break;
    }
  }
   moveMotor(in[0],in[1],in[3]) 
}
}
