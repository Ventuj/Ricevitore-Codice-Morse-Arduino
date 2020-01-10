int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  v();
  fine();
}

void spazio(){
  L();
  P();
  P();
  P();
  L();
  T();
}

void b(){
  L();
  P();
  P(); 
  P();
  T();
}

void d(){
  L();
  P();
  P();
  T();
}

void e(){
  P();
  T();
}

void f(){
  P();
  P();
  L();
  P();
  T();
}

void g(){
  L();
  L();
  P();
  T();
}

void h(){
  P();
  P();
  P();
  P();
  T();
}

void j(){
  P();
  L();
  L();
  L();
  T();
}

void k(){
  L();
  P();
  L();
  T();
}

void l(){
  P();
  L();
  P();
  P();
  T();
}

void m(){
  L();
  L();
  T();
}

void n(){
  L();
  P();
  T();
}

void p(){
  P();
  L();
  L();
  P();
  T();
}

void q(){
  L();
  L();
  P();
  L();
  T();
}

void r(){
  P();
  L();
  P();
  T();
}

void s(){
  P();
  P();
  P();
  T();
}

void t(){
  L();
  T();
}

void u(){
  P();
  P();
  L();
  T();
}

void v(){
  P();
  P();
  P();
  L();
  T();
}

void o(){
  L();
  L();
  L();
  T();
}

void a(){
  P();
  L();
  T();
}

void i(){
  P();
  P();
  T();
}

void c(){
  L();
  P();
  L();
  P();
  T();
}

void fine(){
  P();
  L();
  P();
  L();
  P();
  L();
  T();
}

void P(){
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(300);
}

void L(){
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(300);
}

void T(){
  digitalWrite(led, HIGH);
  delay(2010);
  digitalWrite(led, LOW);
  delay(8000);
}
