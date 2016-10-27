//#include <Piches.h>
//#include <Notes.h>

#define buzzer 15

#define waitingStart   0 
#define playingSeq     1
#define userTyping     3
#define validatingSeq  4

#define kred    11
#define kyellow  10
#define kgreen   9
#define kwhite   8
#define start    3

#define lred    7
#define lyellow 6
#define lgreen  5
#define lwhite  4

#define debugging 1

// início de código temporário pra sempre

#define NOTE_H   0
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Piche
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// fim de código temporário pra sempre. by karina

// Array for Game over song
const int theme[] = {11,                                                  // Array for Theme song
  NOTE_E4, 8, NOTE_E4, 8, NOTE_H, 8, NOTE_E4, 8, NOTE_H, 8, NOTE_C4, 8, NOTE_E4, 8, NOTE_H, 8, NOTE_G4, 8, NOTE_H, 3, NOTE_G3, 8};
const int life[] = {6,                                                    // Array for 1-up sound effect
  NOTE_E5, 10, NOTE_G5, 10, NOTE_E6, 10, NOTE_C6, 10, NOTE_D6, 10, NOTE_G6, 10};
const int flagpole[] = {27,                                               // Array for Flag pole sound effect & song
  NOTE_G2, 10, NOTE_C3, 10, NOTE_E3, 10, NOTE_G3, 10, NOTE_C4, 10, NOTE_E4, 10, NOTE_G4, 3, NOTE_E4, 3, NOTE_GS2, 10, NOTE_C3, 10, 
  NOTE_DS3, 10, NOTE_GS3, 10, NOTE_C4, 10, NOTE_DS4, 10, NOTE_GS4, 3, NOTE_DS4, 3, NOTE_AS2, 10, NOTE_D3, 10, NOTE_F3, 10, 
  NOTE_AS3, 10, NOTE_D4, 10, NOTE_F4, 10, NOTE_AS4, 3, NOTE_B4, 10, NOTE_B4, 10, NOTE_B4, 10, NOTE_C5, 2};

// Array for Death sound effect & song
const int death[] = {17,
  NOTE_C4, 32, NOTE_CS4, 32, NOTE_D4, 16, NOTE_H, 4,
  NOTE_H, 4, NOTE_B3, 8, NOTE_F4, 8, NOTE_H, 8, NOTE_F4, 8, NOTE_F4, 6, 
  NOTE_E4, 6, NOTE_D4, 6, NOTE_C4, 8, NOTE_E3, 8, NOTE_H, 8, NOTE_E3, 8, NOTE_C3, 8};
const int gameover[] = {15,                                               // Array for Game over song
  NOTE_C4, 8, NOTE_H, 8, NOTE_H, 8, NOTE_G3, 8, NOTE_H, 4, NOTE_E3, 4, NOTE_A3, 6, NOTE_B3, 6, NOTE_A3, 6, NOTE_GS3, 6, NOTE_AS3, 6, 
  NOTE_GS3, 6, NOTE_G3, 8, NOTE_F3, 8, NOTE_G3, 4};

int interval = 500;
int noSound = 200;
int seq[50];
int posSeq = 0;
int posType = 0;
int state = waitingStart; 
int key = 0; 
int running = 0;
int startValue = 0;

void setup() 
{                
  pinMode(lred, OUTPUT);     
  pinMode(lyellow, OUTPUT);     
  pinMode(lgreen, OUTPUT);     
  pinMode(lwhite, OUTPUT);
  pinMode(kred, INPUT); 
  pinMode(kwhite, INPUT);      
  pinMode(kgreen, INPUT);    
  pinMode(kyellow, INPUT);    
  pinMode(start, INPUT);      
  noSound = 0;
//  demo();
  playStart();
  noSound = 50;
  Serial.begin(9600); 
  randomSeed(analogRead(0));
  generateSeq();
}

void loop() {
  
    running = 1;
    switch(state)
    {
      case waitingStart:   
        interval = 500;
        if (debugging){
          Serial.print("waitingStart");  
          Serial.println(waitingStart);
        }
        key = pushStart();
        if(key == 1)
          state = playingSeq;
        return;  
      case playingSeq:
        if (debugging)
          Serial.println("playingSeq");  
        playSeq();
        posType = 0;
        state = userTyping;
        return;
      case userTyping:
        if (debugging)
          Serial.println("userTyping");  
        key = 1;
        int ok = true;
        while(ok)
        {
            key = readKey(true);
            if (key == 0)
              break;
            play(key-4);
            ok = validateSeq(key);
            if (debugging)
            {
              Serial.print("ok=");
              Serial.println(ok);
            }
            if (ok)
            {
              if (posType == posSeq)
              {
                delay(1000);
                posSeq++;
                state = playingSeq;
                interval = interval * 0.95;
                return;
              }  
              else
              {
                posType++;
              }            
            }
        } 
        playWrong();
        Serial.print("Voce fez ");
        Serial.println(posSeq);
        if (posSeq == 0)
          Serial.println("Putz, como vc e burro!");
        else
           if (posSeq <= 5)
              Serial.println("Alzheimer");
           else
              if (posSeq < 10)
                 Serial.println("Uai... ate que nao tao pessimo");
              else
                 if (posSeq < 15)
                   Serial.println("Uia!");
                 else
                   Serial.println("Cool!");
        generateSeq();
        state = waitingStart;
        return;
          
  }
}

int pushStart(){
  startValue = digitalRead(start);

  if (startValue == 1){
    Serial.print("StartValue=");
    Serial.println(startValue);
    return 1;
  }
  
  return 0;
}

int validateSeq(int key)
{
  return (key-4) == seq[posType]; // (key -4) = key to LED
}


int readKey(int validateMilis)
{
   unsigned long ms = millis();
   int value = LOW;
   while(value == LOW)
   {
     for (int i = kred; i >= kwhite; i--)
     {
       if (validateMilis)
         if ((millis() - ms) > 3000)
         {
           if (debugging)
             Serial.println("Timeout"); 
           return 0;
         }
       value = digitalRead(i);
       if (value == HIGH)
       {
         return i;
       }
     }
  }
}

void playPich(int pich, int duration)
{
  tone(buzzer, pich);
  delay(duration);
  noTone(buzzer);
}

void playStart() 
{
    int light = lwhite;
    for (int thisNote = 1; thisNote < (life[0] * 2 + 1); thisNote = thisNote + 2) { // Run through the notes one at a time
      digitalWrite(light, HIGH);  
      tone(buzzer, life[thisNote], (1000/life[thisNote + 1]));        // Play the single note
      delay((1000/life[thisNote + 1]) * 1.30);                        // Delay for the specified time
      noTone(buzzer);                                                 // Silence the note that was playing

      digitalWrite(light, LOW);  
      if (light == lred) {
        light = lwhite;
      } else {
        light++;
      }
    }
    delay(500);
}

void playWrong()
{
    Serial.println("playWrong");
    running = 0;
    int light = lwhite;
    for (int thisNote = 1; thisNote < (death[0] * 2 + 1); thisNote = thisNote + 2) { // Run through the notes one at a time
      if (death[thisNote] != NOTE_H) {
        digitalWrite(light, HIGH);
      }
      tone(buzzer, death[thisNote], (1000/death[thisNote + 1]));// Play the single note
      delay((1000/death[thisNote + 1]) * 1.30);                        // Delay for the specified time
      noTone(buzzer);                                                 // Silence the note that was playing

     digitalWrite(light, LOW);  
      if (light == lred) {
        light = lwhite;
      } else if (death[thisNote] != NOTE_H) {
        light++;
      }
    }
      delay(500);
}

void demo()
{
  interval = 500;
  while(interval > 5)
  {
    play(lred);
    play(lyellow);
    play(lgreen);
    play(lwhite);
    interval = interval / 1.5;
  }
}

void blink(int led, int pich)
{
  digitalWrite(led, HIGH);
  tone(buzzer,pich);
  delay(interval);
  digitalWrite(led, LOW);
  noTone(buzzer);
  delay(noSound);
}

void play(int pich)
{
  switch(pich)
  {
    case 7:
      blink(lred,NOTE_C4);
      break;
    case 6:
      blink(lyellow,NOTE_E4);
      break;
    case 5:
      blink(lgreen,NOTE_G4);
      break;
    case 4:
      blink(lwhite,NOTE_AS4);
      break;
  }  
}

void generateSeq()
{
  posSeq = 0;
  if (debugging)
    Serial.println("generateSeq");
  int note;
  for (int i = 0; i < 50; i++)
  {
    seq[i] = random(4) + 4;
    if (debugging)
      Serial.println(seq[i]);
  }
}

void playSeq()
{
  for (int i = 0; i <= posSeq; i++)
  {
    play(seq[i]);
  }
}