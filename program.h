// miejsce na główny kod programu


void programsetup() {
}
void programakcja(){
}
void program_timer() {
}

//>>>>>>>>>>>>>>>>>>>>>>przykład dla komunikacji z VIRTUINO


void pin6_rec(String value) //do testu komunikacji APP --> ESP   - LED in ESP
{
  int v = value.toInt();
  if (v == 1) digitalWrite(led_wew, HIGH); else digitalWrite(led_wew, LOW);
}


int flaga_led = 0;
void led_timer() // test pracy programu w ESP
{
  flaga_led = !flaga_led;
  digitalWrite(led_czerw, flaga_led);
}

int  stanswOnOff = 1; // test przełącznika
void swOnOff() {
  stanswOnOff = digitalRead(sw);
  sendValue(pin1, String(stanswOnOff)); // sw esp ----> app

}

  
//>>>>>>>>>>>>>>>>>>>>>>>przykład dla Clock NTP

int hour = 10;
int minute = 10;
void time_compare() {
  if (hour == timeClient.getHours() && minute == timeClient.getMinutes()) {
//    digitalWrite(led, 0);
  }
}

//>>>>>>>>>>>>> przykłady dla Arduino Cloud


void onR1Change()  { // test komunikacji z Arduino Cloud  odbiór danych z suwaka i wysłanie ich na value widget
  Serial.print("r1 =  ");
  Serial.println(r1);
  r4 = String("r4 =  ") + String(r1);
}


void onR2Change()  {
}

void onR3Change()  { // sterowanie led przełącznikiem w AC
  digitalWrite(2, r3);
}
void onR4Change()  {
}
