// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>deklaracje dla VIRTUINO

bool sendValue(const char* tag, String value);
bool sendValue(const char* tag, String value);

//====== predefinicje funkcji z innych bloków programu

void pin6_rec(String value);
//void pin15_rec(String value);
void pin16_rec(String value) ;

//======= deklaracje wartości początkowych

int pin11_lastValue = 0;

// deklaracje pinów łączących ESP i APP
// ESP -------> app
const char* pin0 = "V0"; //led
const char* pin1 = "V1";  //przelacznik
const char* pin2 = "V2";
const char* pin3 = "V3";   //wys kod
const char* pin4 = "V4";   //temp
const char* pin5 = "V5";
// app ------> ESP
const char* pin6 = "V6";
//------------------------------zmienne programu
const char* pin10 = "V10";
const char* pin11 = "V11";  //obieg  esp>app
const char* pin12 = "V12";  //wskaznik działania pompy  esp>app
const char* pin13 = "V13";  //
const char* pin14 = "V14";
const char* pin15 = "V15";  // zał pompy esp<app
const char* pin16 = "V16";  // terminal om esp<app



//====================== sendPinStatus
// It is called every time a new client is connected.
// The void informs Virtuino app about the current pin states and variable values.

void sendPinsStatus() {
  sendValue(pin11, String(pin11_lastValue));    // send pin11 value

}

//======================== onValueReceived
// It is called every time a new value received  - add ---> esp

void onValueReceived(String tag, String value) {
  Serial.println("Received: tag=" + tag + "  value=" + value);

  if (tag == "V6") pin6_rec(value); // led in esp

//  if (tag == "V15") pin15_rec(value);  // zał pompy
  if (tag == "V16") pin16_rec(value);  // terminal on
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>deklaracje dla Arduino Cloud

void onR1Change();
void onR2Change();
void onR3Change();
void onR4Change();
int r1;
int r2;
bool r3;
String r4;

void initProperties() {

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(r1, READWRITE, 1 * SECONDS, onR1Change);
  ArduinoCloud.addProperty(r2, READWRITE, 1 * SECONDS, onR2Change);
  ArduinoCloud.addProperty(r3, READWRITE, ON_CHANGE, onR3Change);
  ArduinoCloud.addProperty(r4, READWRITE, 1 * SECONDS, onR4Change);

}
