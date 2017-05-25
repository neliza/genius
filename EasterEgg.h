int pushEasterEgg(){

  int proxKeyEASTEREGG = digitalRead(EASTEREGGSEQ[easterEggPos]);

  if (proxKeyEASTEREGG == 1){
    Serial.print("proxKeyEASTEREGG=");
    Serial.println(proxKeyEASTEREGG);
    return 1;
  }
  return 0;
  Serial.println("Implementar as teclas do EASTEREGG!");
}

void playEasterEgg() 
{
    int light = LWHITE;
    int x = 0;
    while (missImp2[x]!=-1){
       if (missImp2[x] != NOTE_H) {
        digitalWrite(light, HIGH);
       }
       tone(BUZZER, missImp2[x], (missImp2Dur[x]));
       delay(missImp2Dur[x]);
       noTone(BUZZER);
       digitalWrite(light, LOW);  
       if (light == LRED) {
          light = LWHITE;
       } else {
          light++;
       }
       x++;
    }
    delay(500);
}