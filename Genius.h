#include <C:/Users/garagebh/Documents/WomenBH/28_12_2017/Genius/Notes.h>
#include <C:/Users/garagebh/Documents/WomenBH/28_12_2017/Genius/Constants.h>

int interval = 500;
int noSound = 200;
int seq[50];
int posSeq = 0;
int posType = 0;
int state = WAITING_EASTER_EGG; 
int key = 0; 
int running = 0;
int startValue = 0;
int easterEggPos = 0;

void setup() 
{                
  pinMode(L_RED, OUTPUT);     
  pinMode(L_WHITE, OUTPUT);     
  pinMode(L_BLUE, OUTPUT);     
  pinMode(L_PINK, OUTPUT);
  pinMode(BTN_WHITE, INPUT); 
  pinMode(BTN_PINK, INPUT);      
  pinMode(BTN_BLUE, INPUT);    
  pinMode(BTN_RED, INPUT);    
  pinMode(BTN_START, INPUT);      
  noSound = 0;

  playStart();
  noSound = 50;
  Serial.begin(9600); 
  randomSeed(analogRead(0));
  generateSeq();
}

void startingDelay(){
    Serial.print("startingDelay");  

    delay(500);
    
    //Acende todas as luzes
    for (int thisLight = L_PINK; thisLight <= L_WHITE; thisLight++) {
      digitalWrite(thisLight, HIGH);  
    }
    delay(500);
    //Apaga todas as luzes
    for (int thisLight = L_PINK; thisLight <= L_WHITE; thisLight++) {
      digitalWrite(thisLight, LOW);  
    }
    delay(1000);
}
int botao = -1;

void loop() {
    
    running = 1;
    switch(state)
    {
      case WAITING_EASTER_EGG:
        if (DEBUGGING){
          Serial.print("WAITING_EASTER_EGG ");  
          Serial.println(WAITING_EASTER_EGG);
        }

        botao = verificaBotao(true);
        
        if (botao!=0){
          Serial.print("botao apertado: ");
          Serial.println(botao);
          if (botao==BTN_START){
             state=PLAYING_SEQ;
             startingDelay();
             return;
          }
          else{
            if (validaEasterEgg (botao)){
              Serial.print("easterEggPos ");
              Serial.println(easterEggPos);
              delay(500);
              easterEggPos++;
            }
            else{
              easterEggPos=0;
            }
            if(easterEggPos==8){
              easterEggPos=0;
              playEasterEgg();
            }
          }
          botao = 0;
        }
        
      return;
      
      case WAITING_START:   
        interval = 500;
        if (DEBUGGING){
          Serial.print("WAITING_START");  
          Serial.println(WAITING_START);
        }
        key = pushStart();
        
        if(key == 1){
          state = PLAYING_SEQ;
          startingDelay();
        }
        return;  
      case PLAYING_SEQ:
        if (DEBUGGING)
          Serial.println("PLAYING_SEQ");  
        playSeq();
        posType = 0;
        state = USER_TYPING;
        return;
      case USER_TYPING:
        if (DEBUGGING)
          Serial.println("USER_TYPING");  
        key = 1;
        Serial.println("key = 1");
        int ok = true;
        Serial.print("ok = ");
        Serial.println(ok);
        while(ok)
        {
            key = readKey(true);
            Serial.print("botao pressionado");  
            Serial.println(key); 
            if (key == 0)
              break;
            play(retornaPortaLed(key));
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
                Serial.print("Antes do delay");
                delay(1000);
                posSeq++;
                state = PLAYING_SEQ;
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
        state = WAITING_EASTER_EGG;
        return;
          
  }
}

int pushStart(){
  startValue = digitalRead(BTN_START);

  if (startValue == 1){
    Serial.print("StartValue=");
    Serial.println(startValue);
    return 1;
  }
  
  return 0;
}
int retornaPortaLed(int botao){
  if(botao == BTN_WHITE){
    return L_WHITE;
  }
  else if(botao == BTN_RED){
    return L_RED;
  }
  else if(botao == BTN_PINK){
    return L_PINK;
  }
  else if(botao == BTN_BLUE){
    return L_BLUE;
  }
  return 0;
}

int validateSeq(int key)
{
   if (DEBUGGING){
    Serial.print("Seq[posType]: "); 
    Serial.println(seq[posType]); 
    Serial.print("Posição: "); 
    Serial.println(posType); 
    Serial.print("retornaPortaLed: "); 
    Serial.println(retornaPortaLed(key)); 
    Serial.print("key: "); 
    Serial.println(key); 
   }
  return retornaPortaLed(key) == seq[posType];
}

int readKey(int validateMilis)
{
  if (DEBUGGING)
     Serial.println("ReadKey"); 
   unsigned long ms = millis();
   int value = LOW;
   while(value == LOW)
   {
     for (int i = BTN_PINK; i >= BTN_WHITE; i--)
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


int verificaBotao(int validateMilis)
{
   unsigned long ms = millis();
   int value = LOW;
   while(value == LOW)
   {
     for (int i = 5; i >= 0; i--)
     {
       if (validateMilis)
         if ((millis() - ms) > 3000)
         {
           if (DEBUGGING)
             Serial.println("Timeout"); 
           return 0;
         }
        value = digitalRead(BOTOES_SEQ[i]);
       
       if (value == HIGH)
       {
         return BOTOES_SEQ[i];
       }
     }
  }
  return 0;
}

void playPich(int pich, int duration)
{
  tone(BUZZER, pich);
  delay(duration);
  noTone(BUZZER);
}

void playStart() 
{
    int light = L_PINK;
    for (int thisNote = 1; thisNote < (LIFE[0] * 2 + 1); thisNote = thisNote + 2) { // Run through the notes one at a time
      digitalWrite(light, HIGH);  
      tone(BUZZER, LIFE[thisNote], (1000/LIFE[thisNote + 1]));        // Play the single note
      delay((1000/LIFE[thisNote + 1]) * 1.30);                        // Delay for the specified time
      noTone(BUZZER);                                                 // Silence the note that was playing

      digitalWrite(light, LOW);  
      if (light == L_WHITE) {
        light = L_PINK;
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
    int light = L_PINK;
    for (int thisNote = 1; thisNote < (DEATH[0] * 2 + 1); thisNote = thisNote + 2) { // Run through the notes one at a time
      if (DEATH[thisNote] != NOTE_H) {
        digitalWrite(light, HIGH);
      }
      tone(BUZZER, DEATH[thisNote], (1000/DEATH[thisNote + 1]));// Play the single note
      delay((1000/DEATH[thisNote + 1]) * 1.30);                        // Delay for the specified time
      noTone(BUZZER);                                                 // Silence the note that was playing

     digitalWrite(light, LOW);  
      if (light == L_WHITE) {
        light = L_PINK;
      } else if (DEATH[thisNote] != NOTE_H) {
        light++;
      }
    }
      delay(500);
}

void playEasterEgg() 
{
    int light = L_PINK;
    int x = 0;
    while (NOTES_MISS_IMP[x]!=-1){
       if (NOTES_MISS_IMP[x] != NOTE_H) {
        digitalWrite(light, HIGH);
       }
       tone(BUZZER, NOTES_MISS_IMP[x], (TIME_NOTES_MISS_IMP[x]));
       delay(TIME_NOTES_MISS_IMP[x]);
       noTone(BUZZER);
       digitalWrite(light, LOW);  
       if (light == L_WHITE) {
          light = L_PINK;
       } else {
          light++;
       }
       x++;
    }
    delay(500);
}

void demo()
{
  interval = 500;
  while(interval > 5)
  {
    play(L_RED);
    play(L_WHITE);
    play(L_BLUE);
    play(L_PINK);
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
    case L_RED:
      blink(L_RED,NOTE_C4);
      break;
    case L_WHITE:
      blink(L_WHITE,NOTE_E4);
      break;
    case L_BLUE:
      blink(L_BLUE,NOTE_G4);
      break;
    case L_PINK:
      blink(L_PINK,NOTE_AS4);
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
    if (DEBUGGING) {
      Serial.print(seq[i]);
      Serial.print(", ");
    }
  }
  if (DEBUGGING)
      Serial.println("");
}

void playSeq()
{
  for (int i = 0; i <= posSeq; i++)
  {
    play(seq[i]);
  }
}
int validaEasterEgg(int proxKeyEasterEgg){
   if (proxKeyEasterEgg == EASTER_EGG_SEQ[easterEggPos]){  
    Serial.print("proxKeyEasterEgg=");
    Serial.println(proxKeyEasterEgg);
    return 1;
  }
  return 0;
}
