int greenLight =0;
int yellowLight =1;
int redLight =2;
int piezoBuzzer =3;
int maximumMoistureLevel;
int currentMoistureLevel;
void moistureDetection()
{
  if(currentMoistureLevel/maximumMoistureLevel <=0.1)
  {
    digitalWrite (greenLight,LOW);
    digitalWrite (yellowLight,LOW);
    digitalWrite (redLight,HIGH);
    tone (piezoBuzzer,5000,500);
    delay (2000);
  }
  else if (currentMoistureLevel/maximumMoistureLevel <=0.3 && currentMoistureLevel/maximumMoistureLevel >0.1)
  {
    digitalWrite (greenLight,LOW);
    digitalWrite (yellowLight,LOW);
    digitalWrite (redLight,HIGH);
  }
  else if(currentMoistureLevel/maximumMoistureLevel <=0.6 && currentMoistureLevel/maximumMoistureLevel >0.3)
  {
    digitalWrite (greenLight,LOW);
    digitalWrite (yellowLight,HIGH);
    digitalWrite (redLight,LOW);
  }
  else
  {
    digitalWrite (greenLight,HIGH);
    digitalWrite (yellowLight,LOW);
    digitalWrite (redLight,LOW);
  }
}
void setup ()
{
  for (int i=0; i<4; i++)
  {
    pinMode (i,OUTPUT);
  }
  pinMode (A0,INPUT);
  maximumMoistureLevel =analogRead (A0);
  tone(piezoBuzzer,5000,500);
  delay (200);
  tone(piezoBuzzer,6000,500);
  delay (600);
  }
  void loop ()
  {
    currentMoistureLevel= analogRead (A0);
    moistureDetection();
    delay (100);
    Serial.println(currentMoistureLevel);
}
