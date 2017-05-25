//#include <Piches.h>
#include <C:/Users/garagebh/Downloads/genius-final/genius-final/Notes.h>
#include <C:/Users/garagebh/Downloads/genius-final/genius-final/Constantes.h>
#include <C:/Users/garagebh/Downloads/genius-final/genius-final/Variaveis.h>
#include <C:/Users/garagebh/Downloads/genius-final/genius-final/EasterEgg.h>

void setup() 
{                
  pinMode(LRED, OUTPUT);     
  pinMode(LBLUE, OUTPUT);     
  pinMode(LPINK, OUTPUT);     
  pinMode(LWHITE, OUTPUT);
  pinMode(KRED, INPUT); 
  pinMode(KWHITE, INPUT);      
  pinMode(KPINK, INPUT);    
  pinMode(KBLUE, INPUT);    
  pinMode(START, INPUT);      
  noSound = 0;
//  demo();
  playStart();
  delay(500);
  noSound = 50;
  Serial.begin(9600); 
  randomSeed(analogRead(0));
  generateSeq();
}

void startingDelay(){
    Serial.print("startingDelay");  

    delay(500);
    
    //Acende todas as luzes
    for (int thisLight = LWHITE; thisLight <= LRED; thisLight++) {
      digitalWrite(thisLight, HIGH);  
    }
    delay(500);
    //Apaga todas as luzes
    for (int thisLight = LWHITE; thisLight <= LRED; thisLight++) {
      digitalWrite(thisLight, LOW);  
    }
    delay(1000);
}

void loop() {
  
    running = 1;
    switch(state)
    {
      case WAITINGSTART:   
        interval = 500;
        if (DEBUGGING){
          //Serial.print("WAITINGSTART");  
          //Serial.println(WAITINGSTART);
        }
        
        if ( easterEggPos == 7 ){
          playEasterEgg();
          easterEggPos = 0;
        } else {
          
          if ( pushEasterEgg() == 1 ){
             easterEggPos++;
             Serial.println("acertou EASTEREGG!");
          }
          else {
             Serial.println("errou EASTEREGG!");
              easterEggPos = 0;
              key = pushSTART();
              if(key == 1){
                state = PLAYINGSEQ;
                startingDelay();
              }
          }
        }
        return;  
      case PLAYINGSEQ:
        if (DEBUGGING)
          Serial.println("PLAYINGSEQ");  
        playSeq();
        posType = 0;
        state = USERTYPING;
        return;
      case USERTYPING:
        if (DEBUGGING)
          Serial.println("USERTYPING");  
        key = 1;
        int ok = true;
        while(ok)
        {
            key = readKey(true);
            if (key == 0)
              break;
            play(key-4);
            ok = validateSeq(key);
            if (DEBUGGING)
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
                state = PLAYINGSEQ;
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
        mostraPontuacao();
        generateSeq();
        state = WAITINGSTART;
        return;
          
  }
}

int pushSTART(){
  startValue = digitalRead(START);

  if (startValue == 1){
    Serial.print("startValue=");
    Serial.println(startValue);
    return 1;
  }
  
  return 0;
}

void mostraPontuacao(){
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
     for (int i = KRED; i >= KWHITE; i--)
     {
       if (validateMilis)
         if ((millis() - ms) > 3000)
         {
           if (DEBUGGING)
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
  tone(BUZZER, pich);
  delay(duration);
  noTone(BUZZER);
}

void playStart() 
{
    int light = LWHITE;
    for (int thisNote = 1; thisNote < (life[0] * 2 + 1); thisNote = thisNote + 2) { // Run through the notes one at a time
      digitalWrite(light, HIGH);  
      tone(BUZZER, life[thisNote], (1000/life[thisNote + 1]));        // Play the single note
      delay((1000/life[thisNote + 1]) * 1.30);                        // Delay for the specified time
      noTone(BUZZER);                                                 // Silence the note that was playing

      digitalWrite(light, LOW);  
      if (light == LRED) {
        light = LWHITE;
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
    int light = LWHITE;
    for (int thisNote = 1; thisNote < (death[0] * 2 + 1); thisNote = thisNote + 2) { // Run through the notes one at a time
      if (death[thisNote] != NOTE_H) {
        digitalWrite(light, HIGH);
      }
      tone(BUZZER, death[thisNote], (1000/death[thisNote + 1]));// Play the single note
      delay((1000/death[thisNote + 1]) * 1.30);                        // Delay for the specified time
      noTone(BUZZER);                                                 // Silence the note that was playing

     digitalWrite(light, LOW);  
      if (light == LRED) {
        light = LWHITE;
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
    play(LRED);
    play(LBLUE);
    play(LPINK);
    play(LWHITE);
    interval = interval / 1.5;
  }
}

void blink(int led, int pich)
{
  digitalWrite(led, HIGH);
  tone(BUZZER,pich);
  delay(interval);
  digitalWrite(led, LOW);
  noTone(BUZZER);
  delay(noSound);
}

void play(int pich)
{
  switch(pich)
  {
    case 7:
      blink(LRED,NOTE_C4);
      break;
    case 6:
      blink(LBLUE,NOTE_E4);
      break;
    case 5:
      blink(LPINK,NOTE_G4);
      break;
    case 4:
      blink(LWHITE,NOTE_AS4);
      break;
  }  
}

void generateSeq()
{
  posSeq = 0;
  if (DEBUGGING)
    Serial.println("generateSeq");
  int note;
  for (int i = 0; i < 50; i++)
  {
    seq[i] = random(4) + 4;
    if (DEBUGGING)
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



