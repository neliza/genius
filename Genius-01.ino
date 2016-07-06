#include <Piches.h>

#define buzzer 6

#define waitingStart   0 
#define playingSeq     1
#define userTyping     3
#define validatingSeq  4
// botões
#define kred    5 // verde
#define kyellow 4 //branco
#define kgreen   3 //amarelo
#define kwhite   2 //vermelho
// led
#define lred    11 //verde
#define lyellow 10 // branco
#define lgreen  9 // amarelo
#define lwhite  8 // vermelho

#define debugging 1

int interval = 500;
int noSound = 200;
int seq[50];
int posSeq = 0;
int posType = 0;
int state = waitingStart; 
int key = 0; 

void setup() 
{                
  pinMode(lred, OUTPUT);     
  pinMode(lyellow, OUTPUT);     
  pinMode(lgreen, OUTPUT);     
  pinMode(lwhite, OUTPUT);   
  pinMode(kred, INPUT);  
  pinMode(kyellow, INPUT);  
  pinMode(kgreen, INPUT);  
  pinMode(kwhite, INPUT);  
  noSound = 0;
//  demo();
  playWrong();
  noSound = 50;
  Serial.begin(9600); 
  randomSeed(analogRead(0));
  generateSeq();
}

void loop() {
  switch(state)
  {
    case waitingStart:   
      interval = 500;
      if (debugging)
        Serial.println("waitingStart");  
      key = readKey(false);
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
        Serial.println("Putz, continue a nadar ...!");
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

void playWrong()
{
    int ritym = 50;
//    for(int i = 0; i < 2; i++)
//    {
      digitalWrite(lred, HIGH);
      digitalWrite(lyellow, HIGH);
      digitalWrite(lgreen, HIGH);
      digitalWrite(lwhite, HIGH);
      playPich(NOTE_A3, ritym);
      playPich(NOTE_A3, ritym);
      playPich(NOTE_A3, ritym);
      playPich(NOTE_F3, ritym * 3 / 4);
      playPich(NOTE_C4, ritym * 1 / 4);
      playPich(NOTE_A3, ritym);
      playPich(NOTE_F3, ritym * 3 / 4);
      playPich(NOTE_C4, ritym * 1 / 4);
      playPich(NOTE_A3, ritym * 2);
      playPich(NOTE_E4, ritym);
      playPich(NOTE_E4, ritym);
      playPich(NOTE_E4, ritym);
      playPich(NOTE_F4, ritym * 3 / 4);
      playPich(NOTE_C4, ritym * 1 / 4);
      playPich(NOTE_GS3, ritym);
      playPich(NOTE_F3, ritym * 3 / 4);
      playPich(NOTE_C4, ritym * 1 / 4);
      playPich(NOTE_A3, ritym * 2);
      digitalWrite(lred, LOW);
      digitalWrite(lyellow, LOW);
      digitalWrite(lgreen, LOW);
      digitalWrite(lwhite, LOW);
      noTone(buzzer);
      delay(500);
//    }  
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
