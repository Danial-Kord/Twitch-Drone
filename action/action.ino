
String command="";
#define in1 4
#define in2 5

#define in3 6
#define in4 7

void setup() {  

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200); 

 } 


void moveMotor(int a,int b){
if(a>=0){
    digitalWrite(in1, LOW);
    analogWrite(in2,a);
}
else{
  digitalWrite(in2, LOW);
  analogWrite(in1,-a);
}

if(b>=0){
    digitalWrite(in3, LOW);
    analogWrite(in4,b);
}
else{
  digitalWrite(in4, LOW);
  analogWrite(in3,-b);
}


}
bool state = false;
void loop(){
    
  if(Serial.available()){
   while(Serial.available()>0){
   command+=Serial.read();
 }
    state = !state;
    digitalWrite(LED_BUILTIN, state );

  }
//  int c;
//
//  String com1 = command.substring(command.indexOf('(')+1,command.indexOf(')')); 
//  int a = com1.toInt();
//  command = command.substring(command.lastIndexOf('(')+1,command.lastIndexOf(')'));
//  c = command.toInt();


//  moveMotor(a,c);

}
