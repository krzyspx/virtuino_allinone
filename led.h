#define led_ziel 16      //program OK miganie led
#define sw   13
#define led_wew   2
#define led_czerw   0

// deklaracje dla mojej płytki testowej ESP 8266

void ledsetup() {
  pinMode(led_czerw, OUTPUT); //LED na module
  digitalWrite(led_czerw, HIGH);

  pinMode(led_wew, OUTPUT); //LED na module
  digitalWrite(led_wew, LOW);

  pinMode(led_ziel, OUTPUT); //LED na module
  digitalWrite(led_ziel, HIGH);

  pinMode(sw, INPUT_PULLUP);
}


void swOnOff();
int wsk_led = 0;
void led_app_timer()  // esp -----> app every 3000 ms
{
  wsk_led = !wsk_led;
  sendValue(pin0, String(wsk_led)); //esp ----> app
  get_time_ntp();     //test clock NTP
  swOnOff();         //test przełącznika na płytce prototypowej
  connetion_test(); // test czy jest połączenie z wifi
}
