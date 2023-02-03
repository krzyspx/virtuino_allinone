
#include <Timers.h>
Timers<7> akcja;
#include <EEPROM.h>

#include "wifi_clock.h"  // procedury obsługi wifi i clock NTP
#include "ota.h"
#include "websocket.h"    // procedury bsługi websocket czyli virtuino
#include "cloud.h"      // connect to Arduino cloud

#include "piny.h"         //deklaracje pinów i programów obsługi pinów
#include "led.h"          // obsługa ledów
#include "NO433.h"        //procedury transmisji 433 MHz
#include "eeprom.h"
#include "dallas.h"       // obsługa DS18b20
#include "program.h"      // my program

//=============================================== setup

void setup() {
  ledsetup();
  if (procesor == D1MINI) Serial.begin(115200);

  delay(100);
  Serial.println();  Serial.println(F(__FILE__));

  akcja.attach(0, 3001, led_app_timer); // miganie led w aplikacji
  akcja.attach(2, 2003, led_timer);     // miganie led w ESP
  akcja.attach(3, 1000, program_timer);   // timer dla programu - czas pompy
  akcja.attach(4, 10000, sensorT_timer); //

  connectToWiFiNetwork();
  otasetup();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  cloudsetup();
  ntpsetup();    //setup for NTP clock
  no433setup();  //setup 433 MHz
  dallasset(); //setup for ds18b20
  programsetup();   //setup for my program
}

//===================================================== loop

void loop() {
  akcja.process();  // timer
  ArduinoOTA.handle();
  webSocket.loop();
  cloudloop();
  no433akcja();     //433 Mhz
  programakcja();     //my program

}
