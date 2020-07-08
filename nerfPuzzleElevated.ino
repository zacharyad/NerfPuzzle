int peizoPin1 = A0;
int peizoPin2 = A1;
int peizoPin3 = A2;

int greenLEDPin1 = 2;
int greenLEDPin2 = 3;
int greenLEDPin3 = 4;
int redLEDPin = 5;

int buzzer = 6;
float sinVal;
int toneVal;


int calibrationReading1 = 0;
int calibrationReading2 = 0;
int calibrationReading3 = 0;

int highest1 = 0;
int highest2 = 0;
int highest3 = 0;

int sensor1Threshold = 200;
int sensor2Threshold = 300;
int sensor3Threshold = 350;

int hit1 = 0;
int hit2 = 0;
int hit3 = 0;

int arrSize = 3;
int arrCounter = 0;
int ledCounter = 1;

int hitAnswer[] = {1, 2, 3};
int hitGuesses[] = {0,0,0};

int relayPin = 11;

int state = 0;



//funcs

int isWinner(){
  Serial.println("WINNER CHECK");
  Serial.println(hitGuesses[0]);
  Serial.println(hitGuesses[1]);
  Serial.println(hitGuesses[2]);
  
  for(int i = 0; i < arrSize - 1; i++){
    if(hitGuesses[i] != hitAnswer[i]){
      return 0;
    }
  }
  return 1;
}

void wrongOrderSound(){
  tone(buzzer, 200, 200);
  delay(100);
  tone(buzzer, 100, 500);
  delay(100);
}

void successBuzzerHit(){
 tone(buzzer,200,200);
 delay(200);
 tone(buzzer,300,200);
 delay(200);
 tone(buzzer,500,200);
}

void successBuzzerWin(){
// Notes
#define NOTE_C4  262 
#define NOTE_D4  294 
#define NOTE_E4  330 
#define NOTE_G4  392
#define REST      0

int tempo = 208;
int melody[] = {
  NOTE_E4,2, NOTE_G4,4,
  NOTE_D4,2, NOTE_C4,8, NOTE_D4,8, 
  NOTE_E4,2
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    tone(buzzer, melody[thisNote], noteDuration*0.9);
    delay(noteDuration);
    noTone(buzzer);
  }

}

void hit(){
  switch(ledCounter){
    case 0:
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      miss();
      ledCounter = 1;
    break;
    case 1:
    successBuzzerHit();
    Serial.println("case ONE");
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, LOW);
      digitalWrite(greenLEDPin1, LOW);
      delay(100);
      ledCounter = 2;
    break;
    
    case 2:
    successBuzzerHit();
    Serial.println("case TWO");
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      ledCounter = 3;
    break;

    case 3:
      Serial.println("case THREE, Check for winner...");
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
      delay(100);
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      delay(100);
      digitalWrite(greenLEDPin1, HIGH);
      digitalWrite(greenLEDPin2, HIGH);
      digitalWrite(greenLEDPin3, HIGH);
    break;
    default:
      Serial.println("SHOULD NOT BE HERE!");
    break;
  }
  
}

void miss(){
      wrongOrderSound();
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      delay(100);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      delay(100);
      wrongOrderSound();
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      delay(100);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      delay(100);
      wrongOrderSound();
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      delay(100);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      delay(100);
      wrongOrderSound();
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      delay(100);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      delay(100);
      wrongOrderSound();
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      delay(100);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(redLEDPin, LOW);
      delay(100);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(greenLEDPin1, OUTPUT);
  pinMode(greenLEDPin2, OUTPUT);
  pinMode(greenLEDPin3, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLEDPin1, LOW);
  digitalWrite(greenLEDPin2, LOW);
  digitalWrite(greenLEDPin3, LOW);
  digitalWrite(redLEDPin, LOW);
  
  pinMode(peizoPin1, INPUT);
  pinMode(peizoPin2, INPUT);
  pinMode(peizoPin3, INPUT);
  delay(1000);

  

  calibrationReading1 = analogRead(peizoPin1);
  calibrationReading2 = analogRead(peizoPin2);
  calibrationReading3 = analogRead(peizoPin3);

  //popLOCK on restart
  digitalWrite(relayPin, HIGH);
  delay(30);
  digitalWrite(relayPin, LOW);
  
  tone(buzzer,500,200);
  tone(buzzer,500,200);
  tone(buzzer,500,200);
  Serial.println("Puzzle Armed");

}

void loop() {
  SM();
}

void SM(){
  switch(state){
    case 0:
    //reset stuff
      digitalWrite(greenLEDPin1, LOW);
      digitalWrite(greenLEDPin2, LOW);
      digitalWrite(greenLEDPin3, LOW);
      arrCounter = 0;
      ledCounter = 1;
      hit1 = 0;
      hit2 = 0;
      hit3 = 0;
      highest1 = 0;
      highest2 = 0;
      highest3 = 0;
      delay(100);
      state = 1;
    break;
    
    case 1:
      int reading1 = analogRead(peizoPin1);
      int reading2 = analogRead(peizoPin2);
      int reading3 = analogRead(peizoPin3);

      if(highest1 < reading1){highest1 = reading1;}
      if(highest2 < reading2){highest2 = reading2;}
      if(highest3 < reading3){highest3 = reading3;}

      if(highest1 > sensor1Threshold && !hit1 && arrCounter < 3){
        hit1 = 1;
        hitGuesses[arrCounter] = 1;
        arrCounter++;
        delay(60);
        hit();
      }
      
      if(highest2 > sensor2Threshold && !hit2 && arrCounter < 3){
        hit2 = 1;
        hitGuesses[arrCounter] = 2;
        arrCounter++;
        delay(60);
        hit();
      }
      
      if(highest3 > sensor3Threshold && !hit3 && arrCounter < 3){
        hit3 = 1;
        hitGuesses[arrCounter] = 3;
        arrCounter++;
        delay(60);
        hit();
      }

      if(arrCounter == 3){
        if(isWinner() == 1){
          //winner
          Serial.println("YOU WON");
          successBuzzerWin();
          hit();
          //unlock DOOR
          digitalWrite(relayPin, HIGH);
          delay(30);
          digitalWrite(relayPin, LOW);
          delay(3000);
          hit();
          ledCounter = 1;
          state = 0;
        } else {
          //loser
          Serial.println("YOU LOST");
          state = 0;
          ledCounter = 0;
          hit();
        }
      }
    break;
    
    default:
    break;
  }
}
