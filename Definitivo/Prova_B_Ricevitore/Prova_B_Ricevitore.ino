int res = A5;
int led = 13;
int count = 0;

String ponte;
String frase;

void setup() {
  pinMode(res, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(analogRead(res) > 800 && analogRead(res) < 1100){
    count++;
  }
  if(count > 0){
    if(count >= 1000 && count < 4000){
      ponte += ".";
    }
    if(count >= 4000 && count < 5000){
      ponte += "-";
    }
    if(count > 5000){
      frase += converter(ponte);
      Serial.print(converter(ponte));
      if(ponte == ".-.-.-"){
        termine();
        //Serial.println(frase);
        Serial.println();
        frase = "";
      }
      ponte = "";
    }
    count = 0;
  }
  delay(20);
}

void termine(){
  for(int i = 0; i < 3; i++){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
}

String Lettere[26][2] = {
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
  { "Y", "-.--" }, { "Z", "--.." }
};

String Caratteri[15][2] = {
  { "0", "-----" }, { "1", ".----" },
  { "2", "..---" }, { "3", "...--" },
  { "4", "....-" }, { "5", "....." },
  { "6", "-...." }, { "7", "--..." },
  { "8", "---.." }, { "9", "----." },
  { ".", ".-.-.-" }, { ",", "--..--" },
  { ":", "---..." }, { "?", "..--.." },
  { " ", "-...-"}
};

String converter(String var){
  bool check = false;
  String ret;
  for(int i = 0; i < 26; i++){
    if(var == Lettere[i][1]){
      ret = Lettere[i][0];
      check = true;
    }
  }
  if(!check){
    for(int i = 0; i < 15; i++){
      if(var == Caratteri[i][1]){
        ret = Caratteri[i][0];
      }
    }
  }
  return ret;
}
