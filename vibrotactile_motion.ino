
String timeData;
int motorPin1 = 3;
int motorPin2 = 5;

String combinations[42] = {"150 100", "250 300", "250 0", "250 150", "150 200", "150 50", "250 250", "150 300", "150 0", "250 100", "150 150", "250 50", "150 250", "250 200",
                           "250 150", "150 200", "250 250", "250 100", "250 50", "150 100", "150 250", "250 200", "250 300", "150 150", "150 300", "150 50", "250 0", "150 0",
                           "150 50", "250 300", "150 300", "250 0", "250 200", "150 100", "250 50", "250 150", "150 200", "150 0", "250 100", "150 150", "150 250", "250 250"};
//String combinations[1] = {"250 0"};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void runCode(int durationToRun, int soa){
 if(soa == 0){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    delay(durationToRun);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
 }
  else{
  if(soa >= durationToRun){
    digitalWrite(motorPin1, HIGH); //vibrate
    delay(durationToRun);  // delay one second
    digitalWrite(motorPin1, LOW);
    
    delay(soa - durationToRun);

    digitalWrite(motorPin2, HIGH); //vibrate
    delay(durationToRun);  // delay one second
    digitalWrite(motorPin2, LOW);

  }

  else{
    digitalWrite(motorPin1, HIGH); //vibrate
    delay(soa);  // delay one second
    digitalWrite(motorPin2, HIGH);
    delay(durationToRun - soa);
    digitalWrite(motorPin1, LOW);
    delay(soa);
    digitalWrite(motorPin2, LOW);
  }
  }
  
}

void loop() {
  Serial.println("Get ready... ");
  int input;
  for (int i = 0; i < 42; i++) {
    Serial.println("Press 1 for next input: ");
    while(Serial.parseInt() != 1){
    }
    int durationToRun;
    int soa;
   int k;     
for(int j=0; j < combinations[i].length(); j++){
  Serial.println(combinations[i][j]);
  if(combinations[i][j] == ' '){
     durationToRun = combinations[i].substring(0, j).toInt();
     k = j + 1;
     break;
  }
}
  soa = combinations[i].substring(k, combinations[i].length()).toInt();

   Serial.println("Duration to run:");
   Serial.println(durationToRun);
   Serial.println("SOA: ");
   Serial.println(soa);
   runCode(durationToRun, soa);
}
Serial.println("User survey completed... ");

}
