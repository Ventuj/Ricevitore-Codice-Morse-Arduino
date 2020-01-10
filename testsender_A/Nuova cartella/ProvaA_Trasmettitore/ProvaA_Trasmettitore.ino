int pinLed = 13;
String a = "";
int lunghezza = 0;

String codici[51][2] = {
  { "A", ".-" }, { "B", "-..." },
  { "C", "-.-." }, { "D", "-.." },
  { "E", "." }, { "F", "..-." },
  { "G", "--." }, { "H", "...." },
  { "I", ".." }, { "J", ".---" },
  { "K", "-.-" }, { "L", ".-.." },
  { "M", "--" }, { "N", "-." },
  { "O", "---" }, { "P", ".--." },
  { "Q", "--.-" }, { "R", ".-." },
  { "S", "..." }, { "T", "-" },
  { "U", "..-" }, { "V", "...-" },
  { "W", ".--" }, { "X", "-..-" },
  { "Y", "-.--" }, { "Z", "--.." },
  { "0", "-----" }, { "1", ".----" },
  { "2", "..---" }, { "3", "...--" },
  { "4", "....-" }, { "5", "....." },
  { "6", "-...." }, { "7", "--..." },
  { "8", "---.." }, { "9", "----." },
  { ".", ".-.-.-" }, { ",", "--..--" },
  { ":", "---..." }, { "?", "..--.." },
  { " ", "-...-" }
};

void converti(String messaggio[], String convertito[])
{
  for (int i = 0; i < lunghezza; i++)
  {
    for (int j = 0; j < sizeof(codici); j++)
    {
      if (messaggio[i] == codici[j][0])
      {
        convertito[i] = codici[j][1];
        j = sizeof(codici);
      }
    }
  }
}

void accendiSpegni(String vettore[], String messaggio[])
{
  for (int i = 0; i < lunghezza; i++)
  {
    for (int j = 0; j < vettore[i].length(); j++)
    {
      if (vettore[i].substring(j, j + 1) == ".")
      {
        digitalWrite(pinLed, HIGH);
        delay(500);
        digitalWrite(pinLed, LOW);
      }
      else
      {
        digitalWrite(pinLed, HIGH);
        delay(1000);
        digitalWrite(pinLed, LOW);
      }
      delay(300);
      if (j == vettore[i].length() - 1)
      {
        digitalWrite(pinLed, HIGH);
        delay(2000);
        digitalWrite(pinLed, LOW);
        delay(300);
      }
    }
  }
}

void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (!Serial.available());
  a = Serial.readString();
  a.toUpperCase();
  lunghezza = a.length() - 1;
  String messaggio[lunghezza];
  for (int i = 0; i < lunghezza; i++)
  {
    messaggio[i] = a.substring(i, i + 1);
  }
  String convertito[lunghezza];
  converti(messaggio, convertito);
  accendiSpegni(convertito, messaggio);
}
