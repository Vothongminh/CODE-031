//youtube.com/thongminhvo
//.....................................................................................
int piezoPin = 8;
int button = 2;
int lengths = 185;
char jbnotes[] = "CCCCbeag CCCCbeag DDDDFEbCE DEg ageeDD CCCCbaegab CCCCbaegab DDDDFEbCDE DEgageeaa CDEDEDEGEDCDCD DEFEFEFFGAE abCbCbCECbabab DEgageeCa CDEDEDEGEDCDCD DEFEFEFFGAE abCbCbCECbabab DEgggaega";
int jbbeats[] = {2, 2, 1, 4, 2, 2, 2, 4,2, 2, 2, 1, 4, 2, 2, 2, 4,2, 2, 2, 1, 4, 2, 2, 2, 4, 4,2, 2, 2, 4,1, 2, 2, 2, 2, 4, 4,2, 2, 2, 1, 4, 2, 2, 2, 4, 2, 4,2, 2, 2, 1, 4, 2, 2, 2, 4, 2, 4,2, 2, 2, 1, 4, 2, 2, 2, 4, 2, 4,2, 2, 2, 4, 2, 2, 2, 2, 4, 4,2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4,1, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4,1, 2, 2, 4, 2, 2, 2, 2, 4, 4,1, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4,1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4,1, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4,1, 2, 2, 4, 2, 2, 2, 2, 4, 4};
int length = 50;
int tempo = 170;
//.....................................................................................
void playTone(int tone, int duration)
{
  for (long i = 0; i < duration * 1000L; i += tone * 2)
  {
    digitalWrite(piezoPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(piezoPin, LOW);
    delayMicroseconds(tone);
  }
}
//.....................................................................................
void playNote(char note, int duration)
{
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' , 'D', 'E', 'F', 'G', 'A', 'B'};       //c  d  e  f  g  a  b
  int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 880, 784, 698, 659, 587, 523};   //do re mi fa so la si
  for (int i = 0; i < 15; i++)
  {
    if (names[i] == note)
    {
      playTone(tones[i], duration);
    }
  }
}
//.....................................................................................
void setup()
{
  pinMode(piezoPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}
//.....................................................................................
void loop()
{
  for (int i = 0; i < lengths; i++)
  {
    if (jbnotes[i] == ' ')
    {
      delay(jbbeats[i] * tempo);
    }
    else
      playNote(jbnotes[i], jbbeats[i] * tempo);
    delay(tempo / 2);
  }
  while (1);
}
