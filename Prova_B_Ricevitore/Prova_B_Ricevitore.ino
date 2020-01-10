#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7);

int res = A0;
int led = 13;

int pos = 0;

typedef struct nodo{
  String dato;
  struct nodo* next;
}Lista;

Lista* lista = NULL;

// prototipi
Lista* nuovoNodo(String d);
Lista* inserisciDopo(Lista* l, String d);
// fine prototipi


int start = 0;
int count = 0;

String ponte;
String frase;

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

String Caratteri[14][2] = {
  { "0", "-----" }, { "1", ".----" },
  { "2", "..---" }, { "3", "...--" },
  { "4", "....-" }, { "5", "....." },
  { "6", "-...." }, { "7", "--..." },
  { "8", "---.." }, { "9", "----." },
  { ".", ".-.-.-" }, { ",", "--..--" },
  { ":", "---..." }, { "?", "..--.." }
};

void setup() {
  lcd.begin (20,4);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  
  pinMode(res, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  lista = inserisciDopo(lista, "");
}

void loop() {
  while(analogRead(res) > 0 && analogRead(res) < 200){
    //Serial.println(String(analogRead(res)));
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
      lcd.clear();
      printlcd(0,0,ponte);
      //Serial.println(ponte);
      //lista = inserisciDopo(lista, ponte);
      frase += converter(ponte);
      if(ponte == ".-.-.-"){
        lcd.clear();
        printlcd(0,0,frase);
        termine();
        frase = "";
      }
      ponte = "";
    }
    printlcd(0,1, "             ");
    printlcd(0,1, String(count));
    count = 0;
  }
  delay(20);
}

void printlcd(int c1, int c2, String text){
  lcd.setCursor(c1,c2);
  lcd.print(text);
}

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
    for(int i = 0; i < 14; i++){
      if(var == Caratteri[i][1]){
        ret = Caratteri[i][0];
      }
    }
  }
  return ret;
}

void termine(){
  for(int i = 0; i < 3; i++){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
}



Lista* inserisciDopo(Lista* l, String d) // Metodo che inserisce il coda alla lista
{
  if (l == NULL) // Se sono a NULL ovvero in ultima posizione
  {
    l = nuovoNodo(d); // Creo il nuovo nodo
  }
  else
  {
    l -> next = inserisciDopo(l -> next, d); // Richiama se stesso e lo mette sul next
  }
  return l;
}

Lista* nuovoNodo(String d) // Metodo che crea un nuovo nodo
{
  Lista* n = (Lista *)malloc(sizeof(Lista)); // Creo il nodo
  n -> dato = d; // Attribuisco un valore a 'dato'
  n -> next = NULL; // Atribuisco un nodo a 'next' (da parametri può essere il resto della lista oppure NULL)
  return n; // ritorno il nodo
}
