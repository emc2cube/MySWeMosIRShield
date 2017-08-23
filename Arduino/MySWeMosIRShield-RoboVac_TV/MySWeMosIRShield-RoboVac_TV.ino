/**

   MySWeMosIRShield - IR blaster shield for WeMos D1 Mini with HTTP and MySensors support
   https://github.com/emc2cube/MySWeMosIRShield/

   Make sure to fill in your ssid and WiFi password below
   If you decide to enable ESP8266 OTA update it is recommended to set a password
   You will need to manually edit the IR codes in either/both the WebServer and MySensors section deep in the code

 *******************************

   The MySensors Arduino library handles the wireless radio link and protocol
   between your home built sensors/actuators and HA controller of choice.
   The sensors forms a self healing radio network with optional repeaters. Each
   repeater and gateway builds a routing tables in EEPROM which keeps track of the
   network topology allowing messages to be routed to nodes.

   Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
   Copyright (C) 2013-2015 Sensnology AB
   Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors

   Documentation: http://www.mysensors.org
   Support Forum: http://forum.mysensors.org

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   version 2 as published by the Free Software Foundation.

**/


// ** WiFi and network configuration **
// WiFi mode and configuration
// WIFI_STA       Connect to your WiFi network only
// WIFI_AP        Create and broadcast it's own WiFi network
// WIFI_AP_STA    Both
// WIFI_OFF       No WiFi
#define WIFI_MODE WIFI_STA

// WiFi credentials
const char *ssid = "YourSSIDHere";
const char *password = "YourPSKHere";

// Define password for OTA updates (recommended but optional)
//#define ESP8266_OTA_PASSWORD "MySuperSecretOTAPassword"


// ** MySensors Radio configuration **
// Enables and select radio type (if attached)
#define MY_RADIO_NRF24
//#define MY_RADIO_RFM69

// RF24 settings
// Use custom RF24 channel (default 76)
//#define MY_RF24_CHANNEL 42
// Enables RF24 encryption (all nodes and gateway must have this enabled, and all must be personalized with the same AES key)
//#define MY_RF24_ENABLE_ENCRYPTION

// RF69 settings
// RFM69 Frequency, default = 868MHz
//#define MY_RFM69_FREQUENCY RF69_868MHZ // RFM69 frequency to use (RF69_433MHZ for 433MHz, RF69_868MHZ for 868MHz or RF69_915MHZ for 915MHz)
// RFM69 Network ID. Use the same for all nodes that will talk to each other, default = 100
//#define MY_RFM69_NETWORKID     42
// Enables RFM69 encryption (all nodes and gateway must have this enabled, and all must be personalized with the same AES key)
//#define MY_RFM69_ENABLE_ENCRYPTION

// Enable this if you are running a RFM69HW module
//#define MY_IS_RFM69HW

// ** Mysensors additional functions **
// Use custom static node ID
// If disabled node ID will be automatically assigned
//#define MY_NODE_ID 42

// Use custom parent node ID. Use 0 to force direct connection to the gateway.
// If disabled parent ID will be automatically assigned
//#define MY_PARENT_NODE_ID 0

// Enable repeater feature for this node
//#define MY_REPEATER_FEATURE

// Enable software signing
//#define MY_SIGNING_SOFT

// Enable hardware signing
//#define MY_SIGNING_ATSHA204

// General signing settings
// Enable this if you want destination node to sign all messages sent to this gateway.
//#define MY_SIGNING_REQUEST_SIGNATURES
// Enable node whitelisting
//#define MY_SIGNING_NODE_WHITELISTING {{.nodeId = GATEWAY_ADDRESS,.serial = {0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01}}}

// Set how long to wait for radio transport to be ready. (in milliseconds)
#define MY_TRANSPORT_WAIT_READY_MS 10000

// Enable debug prints to serial monitor
//#define MY_DEBUG


// ** RAW IR codes **
uint16_t khz = 38; // 38kHz is the most common frequency
uint16_t eufyHOME[83] = {2950, 3000, 550, 450, 550, 1400, 550, 1450, 550, 450, 550, 1400, 550, 450, 550, 450, 550, 450, 550, 450, 500, 500, 450, 550, 500, 450, 550, 1450, 500, 1450, 550, 1450, 550, 1450, 500, 500, 500, 500, 550, 400, 550, 450, 550, 450, 500, 500, 500, 450, 550, 450, 450, 550, 500, 500, 500, 500, 550, 450, 500, 450, 550, 450, 500, 500, 550, 450, 500, 500, 550, 1400, 550, 1450, 500, 1450, 550, 450, 550, 1400, 500, 1500, 550, 1400, 550}; // UNKNOWN E8BEB62D
uint16_t eufyAUTO[83] = {2950, 3000, 550, 450, 550, 1450, 500, 1450, 550, 450, 550, 1400, 600, 400, 550, 450, 550, 450, 550, 1450, 500, 450, 550, 1450, 550, 450, 550, 450, 550, 450, 500, 450, 550, 450, 550, 450, 550, 450, 550, 450, 550, 450, 500, 450, 550, 450, 550, 450, 550, 400, 600, 400, 550, 450, 550, 450, 500, 500, 500, 500, 500, 450, 550, 450, 550, 450, 550, 450, 550, 450, 550, 450, 500, 450, 550, 1450, 550, 450, 550, 450, 550, 450, 500}; // UNKNOWN E474C5C6
uint16_t eufySTART[83] = {3000, 3050, 550, 500, 550, 1500, 550, 1500, 550, 500, 550, 1450, 600, 450, 600, 450, 600, 450, 600, 1450, 500, 1550, 550, 1500, 550, 1500, 550, 500, 550, 1500, 550, 500, 550, 1450, 600, 450, 600, 450, 600, 450, 550, 500, 500, 550, 500, 550, 550, 500, 550, 500, 550, 500, 550, 500, 550, 500, 550, 500, 550, 500, 550, 500, 550, 500, 550, 500, 550, 500, 550, 1500, 550, 450, 600, 1450, 600, 1450, 550, 1500, 550, 500, 550, 1500, 550}; // UNKNOWN C1C301C7
uint16_t eufyPAUSE[83] = {3050, 3000, 600, 450, 600, 1450, 600, 1450, 600, 500, 550, 1500, 600, 450, 550, 500, 600, 450, 600, 1450, 550, 1450, 600, 1450, 600, 1450, 600, 500, 550, 450, 600, 450, 600, 450, 600, 500, 550, 450, 600, 500, 550, 450, 600, 450, 600, 450, 550, 500, 550, 500, 550, 500, 550, 500, 600, 450, 550, 500, 600, 500, 550, 500, 550, 500, 550, 500, 550, 500, 600, 1500, 550, 450, 600, 1500, 550, 1500, 600, 450, 550, 500, 550, 450, 600}; // UNKNOWN 25638DD6
uint16_t eufySPOT[83] = {3000, 2950, 550, 500, 500, 1450, 550, 1450, 500, 500, 500, 1450, 550, 450, 550, 450, 550, 450, 500, 500, 500, 450, 450, 550, 550, 1400, 600, 450, 500, 500, 500, 1450, 550, 450, 500, 500, 500, 500, 500, 500, 500, 450, 550, 450, 500, 500, 550, 400, 600, 400, 550, 450, 550, 450, 500, 500, 500, 500, 450, 500, 550, 450, 500, 450, 550, 450, 550, 450, 550, 1450, 550, 1400, 550, 1450, 550, 1400, 600, 450, 500, 1450, 500, 500, 450}; // UNKNOWN ED40C288
uint16_t eufyROOM[83] = {2950, 3000, 550, 400, 600, 1400, 550, 1450, 550, 450, 550, 1400, 600, 400, 550, 450, 550, 400, 550, 450, 550, 450, 500, 1500, 500, 1450, 550, 450, 600, 1400, 550, 450, 550, 450, 550, 400, 550, 450, 600, 400, 550, 450, 550, 400, 600, 400, 550, 450, 550, 450, 550, 450, 500, 500, 450, 500, 550, 450, 550, 450, 550, 450, 550, 450, 550, 450, 550, 1400, 550, 450, 550, 450, 550, 1450, 550, 1400, 550, 1400, 600, 400, 500, 500, 550}; // UNKNOWN 1A8F2EB8
uint16_t eufyEDGE[83] = {2950, 3000, 550, 450, 500, 1450, 550, 1450, 550, 450, 550, 1400, 550, 450, 550, 450, 550, 450, 550, 400, 550, 450, 500, 1500, 550, 450, 500, 500, 500, 450, 550, 1450, 550, 1450, 550, 450, 500, 500, 500, 450, 550, 450, 550, 450, 550, 400, 600, 400, 550, 450, 550, 450, 500, 500, 450, 550, 500, 450, 550, 450, 550, 450, 550, 450, 550, 450, 550, 1450, 500, 450, 550, 450, 550, 450, 550, 1450, 500, 500, 500, 1450, 550, 1400, 550}; // UNKNOWN FFB2DFB1
uint16_t eufyMAX[83] = {3000, 2950, 600, 400, 550, 1450, 550, 1450, 500, 450, 550, 1450, 550, 400, 600, 400, 550, 450, 550, 450, 500, 500, 450, 500, 550, 1450, 550, 450, 550, 450, 550, 1400, 550, 1450, 550, 450, 550, 450, 550, 450, 550, 400, 550, 450, 550, 450, 550, 400, 550, 450, 550, 450, 550, 450, 450, 550, 500, 450, 550, 450, 600, 400, 550, 450, 550, 450, 550, 450, 550, 1400, 550, 1450, 550, 1400, 550, 1450, 550, 450, 550, 1400, 550, 1450, 550}; // UNKNOWN A2B091CB


// ******************************************//
// You probably don't need to edit this part //
// ******************************************//

#include <EEPROM.h>
#include <SPI.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
extern "C" {
#include "user_interface.h"
}
#include <IRremoteESP8266.h>  // From https://github.com/markszabo/IRremoteESP8266/
#include <IRsend.h>  // Needed if you want to send IR commands.
#include <IRrecv.h>  // Needed if you want to receive IR commands.
#include <IRutils.h>

// MySensors
#define SN "MySWeMosIRShield"   // Name of the sketch
#define SV "2.1.1"              // Version (2.x : compiled with MySensors 2.x)
boolean metric = true;          // Use SI by default
#define MESSAGEWAIT 500         // Wait a few ms between radio Tx
#define CHILD_ID_TxLED 0
#define CHILD_ID_RxLED 1

// Signing settings
#define MY_SIGNING_SOFT_RANDOMSEED_PIN A0
#define MY_SIGNING_ATSHA204_PIN D0  // GPIO 16

// Enable signing related debug prints to serial monitor if debug and signing are both enabled
#if ((defined MY_DEBUG) && ( defined MY_SIGNING_SOFT || defined MY_SIGNING_ATSHA204))
#define MY_DEBUG_VERBOSE_SIGNING
#endif

// Define RFM69 pins to match PCB traces
#if defined MY_RADIO_RFM69
#define MY_RF69_IRQ_PIN D2  // GPIO 4
#define MY_RF69_IRQ_NUM D2  // GPIO 4
#define MY_RF69_SPI_CS  D8  // GPIO 15
#endif

#define ARDUINO_ARCH_ESP8266

#include <MySensors.h>

// Define IR pins
uint16_t TX_PIN = D1; //an IR LED is connected to D1
uint16_t RX_PIN = D4; //an IR detector/demodulator is connected to D4
IRsend irsend(TX_PIN);
IRrecv irrecv(RX_PIN);

// IR decoding (from IRremoteESP8266: IRrecvDumpV2)
decode_results results; // Somewhere to store the results
irparams_t save;        // A place to copy the interrupt state while decoding.

// Setup AP IP Address
IPAddress ip(10, 0, 3, 1);
IPAddress gateway(10, 0, 3, 1);
IPAddress subnet(255, 255, 255, 0);

// WebServer configuration
ESP8266WebServer server(80);

// ******************************************//
// WebServer settings, you will need to edit //
// ******************************************//
void handleRoot() {
  server.send(200, "text/html", "\
<html>\
<head>\
  <title>MySWeMosIRShield: IR Remote</title>\
  <meta name=\"viewport\" content=\"initial-scale=1\">\
<style>\
  .bluebutton {\
  border: 1px solid #15aeec;\
  background-color: #49c0f0;\
  background-image: -webkit-linear-gradient(top, #49c0f0, #2cafe3);\
  background-image: linear-gradient(to bottom, #49c0f0, #2cafe3);\
  border-radius: 4px;\
  color: #fff;\
  line-height: 25px;\
  width: 75px;\
  transition: none;\
  text-shadow: 0 1px 1px rgba(0, 0, 0, .3);\
  text-align: center;\
}\
.bluebutton:hover {\
  border:1px solid #1090c3;\
  background-color: #1ab0ec;\
  background-image: -webkit-linear-gradient(top, #1ab0ec, #1a92c2);\
  background-image: linear-gradient(to bottom, #1ab0ec, #1a92c2);\
}\
.bluebutton:active {\
  background: #1a92c2;\
  box-shadow: inset 0 3px 5px rgba(0, 0, 0, .2);\
  color: #1679a1;\
  text-shadow: 0 1px 1px rgba(255, 255, 255, .5);\
}\
.redbutton {\
  border: 1px solid #eb1515;\
  background-color: #f04a4a;\
  background-image: -webkit-linear-gradient(top, #f04a4a, #e32d2d);\
  background-image: linear-gradient(to bottom, #f04a4a, #e32d2d);\
  border-radius: 4px;\
  color: #fff;\
  line-height: 25px;\
  width: 75px;\
  transition: none;\
  text-shadow: 0 1px 1px rgba(0, 0, 0, .3);\
  text-align: center;\
}\
.redbutton:hover {\
  border:1px solid #c21111;\
  background-color: #eb1d1d;\
  background-image: -webkit-linear-gradient(top, #eb1d1d, #c21b1b);\
  background-image: linear-gradient(to bottom, #eb1d1d, #c21b1b);\
}\
.redbutton:active {\
  background: #e32d2d;\
  box-shadow: inset 0 3px 5px rgba(0, 0, 0, .2);\
  color: #a11717;\
  text-shadow: 0 1px 1px rgba(255, 255, 255, .5);\
}\
table, th, td {\
    border-spacing: 5px 2px;\
    border: none;\
}\
</style> \
</head>\
<body>\
<h1>\
  Eufy RoboVac 11 \
</h1>\
<table>\
  <tr>\
    <td><a href=\"ir?eufy=home\"><button class=\"bluebutton\">Home</button></a></td>\
    <td></td>\
    <td><a href=\"ir?eufy=auto\"><button class=\"redbutton\">Auto</button></a></td>\
  </tr>\
  <tr>\
    <td><a href=\"ir?eufy=start\"><button class=\"bluebutton\">Start</button></a></td>\
    <td><a href=\"ir?eufy=pause\"><button class=\"bluebutton\">Pause</button></a></td>\
    <td><a href=\"ir?eufy=spot\"><button class=\"bluebutton\">Spot</button></a></td>\
  </tr>\
  <tr>\
    <td><a href=\"ir?eufy=room\"><button class=\"bluebutton\">Room</button></a></td>\
    <td><a href=\"ir?eufy=max\"><button class=\"bluebutton\">Max</button></a></td>\
    <td><a href=\"ir?eufy=edge\"><button class=\"bluebutton\">Edge</button></a></td>\
  </tr>\
</table>\
<h1>\
  TV \
</h1>\
<table>\
  <tr>\
    <td></td>\
    <td><a href=\"ir?tv=vup\"><button class=\"bluebutton\">Vol Up</button></a></td>\
    <td></td>\
  </tr>\
  <tr>\
    <td><a href=\"ir?tv=chdown\"><button class=\"bluebutton\">Ch Down</button></a></td>\
    <td><a href=\"ir?tv=power\"><button class=\"redbutton\">On / Off</button></a></td>\
    <td><a href=\"ir?tv=chup\"><button class=\"bluebutton\">Ch Up</button></a></td>\
  </tr>\
  <tr>\
    <td><a href=\"ir?tv=mute\"><button class=\"bluebutton\">Mute</button></a></td>\
    <td><a href=\"ir?tv=vdown\"><button class=\"bluebutton\">Vol Down</button></a></td>\
    <td></td>\
  </tr>\
</table>\
<h1>\
  Sound bar \
</h1>\
<table>\
  <tr>\
    <td></td>\
    <td><a href=\"ir?audio=vup\"><button class=\"bluebutton\">Vol Up</button></a></td>\
    <td></td>\
  </tr>\
  <tr>\
    <td></td>\
    <td><a href=\"ir?audio=power\"><button class=\"redbutton\">On / Off</button></a></td>\
    <td></td>\
  </tr>\
  <tr>\
    <td><a href=\"ir?audio=mute\"><button class=\"bluebutton\">Mute</button></a></td>\
    <td><a href=\"ir?audio=vdown\"><button class=\"bluebutton\">Vol Down</button></a></td>\
    <td></td>\
  </tr>\
</table>\
</body>\
</html>");
}

// ******************************************//
//  IR code settings, you will need to edit  //
// ******************************************//
void handleIr() {
  irrecv.disableIRIn();
  for (uint8_t i = 0; i < server.args(); i++) {
    if (server.argName(i) == "eufy")
    {
      if (server.arg(i) == "auto") { // Auto cleaning mode
        irsend.sendRaw(eufyAUTO, sizeof(eufyAUTO) / sizeof(eufyAUTO[0]), khz);
      }
      if (server.arg(i) == "home") { // Back to charging dock
        irsend.sendRaw(eufyHOME, sizeof(eufyHOME) / sizeof(eufyHOME[0]), khz);
      }
      if (server.arg(i) == "max") { // Max power
        irsend.sendRaw(eufyMAX, sizeof(eufyMAX) / sizeof(eufyMAX[0]), khz);
      }
      if (server.arg(i) == "spot") { // Spot cleaning mode
        irsend.sendRaw(eufySPOT, sizeof(eufySPOT) / sizeof(eufySPOT[0]), khz);
      }
      if (server.arg(i) == "edge") { // Edge cleaning mode
        irsend.sendRaw(eufyEDGE, sizeof(eufyEDGE) / sizeof(eufyEDGE[0]), khz);
      }
      if (server.arg(i) == "room") { // Single room cleaning mode
        irsend.sendRaw(eufyROOM, sizeof(eufyROOM) / sizeof(eufyROOM[0]), khz);
      }
      if (server.arg(i) == "start") { // Start
        irsend.sendRaw(eufySTART, sizeof(eufySTART) / sizeof(eufySTART[0]), khz);
      }
      if (server.arg(i) == "pause") { // Pause
        irsend.sendRaw(eufyPAUSE, sizeof(eufyPAUSE) / sizeof(eufyPAUSE[0]), khz);
      }
    }
    else if (server.argName(i) == "tv")
    {
      if (server.arg(i) == "power") { // switch On / Off
        irsend.sendNEC(0x20DF10EF, 32);
      }
      if (server.arg(i) == "chup") { // channel up
        irsend.sendNEC(0x20DF00FF, 32);
      }
      if (server.arg(i) == "chdown") { // channel down
        irsend.sendNEC(0x20DF807F, 32);
      }
      if (server.arg(i) == "vup") { // volume up
        irsend.sendNEC(0x20DF40BF, 32);
      }
      if (server.arg(i) == "vdown") { // volume down
        irsend.sendNEC(0x20DFC03F, 32);
      }
      if (server.arg(i) == "mute") { // mute
        irsend.sendNEC(0x20DF906F, 32);
      }
    }
    else if (server.argName(i) == "audio")
    {
      if (server.arg(i) == "power") { // switch On / Off
        irsend.sendRC6(0x150C, 20);
      }
      if (server.arg(i) == "vup") { // volume up
        irsend.sendRC6(0x1010, 20);
      }
      if (server.arg(i) == "vdown") { // volume down
        irsend.sendRC6(0x1011, 20);
      }
      if (server.arg(i) == "mute") { // mute
        irsend.sendRC6(0x100D, 20);
      }
    }
  }
  irrecv.enableIRIn();
  handleRoot();
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup() {

  // ** WiFi **
  // Hostname name hack
  String routername = SN;
  char* ourname = &routername[0];
  wifi_station_set_hostname(ourname);  //sdk, non-Arduino function

  // Set up AP mode
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(SN);

  // Switch to user selected WiFi mode
  if (WIFI_MODE == WIFI_OFF) {
    WiFi.disconnect();
  }
  WiFi.mode(WIFI_MODE);
  if (WIFI_MODE == WIFI_OFF) {
    WiFi.forceSleepBegin();
    delay(1);
  }

  // Arduino OTA
#if defined ESP8266_OTA_PASSWORD
  ArduinoOTA.setPassword(ESP8266_OTA_PASSWORD);
#endif
  ArduinoOTA.setHostname(SN);
  ArduinoOTA.onStart([]() {
    Serial.println("ArduinoOTA start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nArduinoOTA end");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("OTA Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();

  // Advertise http service on mDNS
  MDNS.addService("http", "tcp", 80);

  // Start WiFi
  WiFi.begin(ssid, password);

  // Wait up to 60s for connection
  if (WIFI_MODE != WIFI_OFF) {
    int wifi = 0;
    while (WiFi.status() != WL_CONNECTED) {
      if (wifi == 0) {
        Serial.println("Connecting to WiFi");
      } else if (wifi == 60) {
        Serial.println(".");
        Serial.println("Timeout");
        break;
      }
      delay(1000);
      Serial.print(".");
      wifi++;
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("");
#if defined MY_DEBUG
      Serial.println("");
      Serial.println("-- STA (client) informations --");
      Serial.print("Hostname: ");
      Serial.println(WiFi.hostname());
#endif
      Serial.print("Connected");
#if defined MY_DEBUG
      Serial.print(" to: ");
      Serial.print(WiFi.SSID());
      Serial.print(" (");
      Serial.print(WiFi.BSSIDstr());
      Serial.print("), ");
      Serial.print(WiFi.RSSI());
      Serial.println("dBm");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      Serial.print("Gateway address: ");
      Serial.println(WiFi.gatewayIP());
      Serial.print("Subnet mask: ");
      Serial.println(WiFi.subnetMask());
      Serial.print("MAC STA address: ");
      Serial.println(WiFi.macAddress());
      Serial.println("-- AP (server) informations --");
      Serial.print("Soft IP address: ");
      Serial.println(WiFi.softAPIP());
      Serial.print("MAC AP address: ");
      Serial.print(WiFi.softAPmacAddress());
      Serial.println("");
      Serial.println("----");
#endif
      Serial.println("");
    }
  } else {
    Serial.println("WiFi Disabled");
  }

  // WebServer
  server.on("/", handleRoot);
  server.on("/ir", handleIr);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");

  // ** Enable IR functions **
  irsend.begin();
  irrecv.enableIRIn();  // Start the receiver

  // ** MySensors **
  wait(MESSAGEWAIT);
  metric = getControllerConfig().isMetric;  // was getConfig().isMetric; before MySensors v2.1.1
  Serial.println(F("Node ready to receive messages"));
}


void presentation() {
  // Send the Sketch Version Information to the Gateway
  wait(MESSAGEWAIT);
  sendSketchInfo(SN, SV);

  // Register the Tx LED as a dimmer device with the gateway
  wait(MESSAGEWAIT);
  present(CHILD_ID_TxLED, S_DIMMER, "IR Blaster");

  // Register the Rx LED as a binary device with the gateway
  wait(MESSAGEWAIT);
  present(CHILD_ID_RxLED, S_BINARY, "IR Receiver");
}


// IR decoding code from IRremoteESP8266: IRrecvDumpV2 v0.2
//+=============================================================================
// Display encoding type
//
void encoding(decode_results *results) {
  switch (results->decode_type) {
    default:
    case UNKNOWN:      Serial.print("UNKNOWN");       break;
    case NEC:          Serial.print("NEC");           break;
    case SONY:         Serial.print("SONY");          break;
    case RC5:          Serial.print("RC5");           break;
    case RC6:          Serial.print("RC6");           break;
    case DISH:         Serial.print("DISH");          break;
    case SHARP:        Serial.print("SHARP");         break;
    case JVC:          Serial.print("JVC");           break;
    case SANYO:        Serial.print("SANYO");         break;
    case SANYO_LC7461: Serial.print("SANYO_LC7461");  break;
    case MITSUBISHI:   Serial.print("MITSUBISHI");    break;
    case SAMSUNG:      Serial.print("SAMSUNG");       break;
    case LG:           Serial.print("LG");            break;
    case WHYNTER:      Serial.print("WHYNTER");       break;
    case AIWA_RC_T501: Serial.print("AIWA_RC_T501");  break;
    case PANASONIC:    Serial.print("PANASONIC");     break;
    case DENON:        Serial.print("DENON");         break;
    case COOLIX:       Serial.print("COOLIX");        break;
  }
  if (results->repeat) Serial.print(" (Repeat)");
}

// Dump out the decode_results structure.
//
void dumpInfo(decode_results *results) {
  if (results->overflow)
    Serial.println("WARNING: IR code too long."
                   "Edit IRrecv.h and increase RAWBUF");

  // Show Encoding standard
  Serial.print("Encoding  : ");
  encoding(results);
  Serial.println("");

  // Show Code & length
  Serial.print("Code      : ");
  serialPrintUint64(results->value, 16);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
}

// Dump out the decode_results structure.
//
void dumpRaw(decode_results *results) {
  // Print Raw data
  Serial.print("Timing[");
  Serial.print(results->rawlen - 1, DEC);
  Serial.println("]: ");

  for (uint16_t i = 1;  i < results->rawlen;  i++) {
    if (i % 100 == 0)
      yield();  // Preemptive yield every 100th entry to feed the WDT.
    uint32_t x = results->rawbuf[i] * USECPERTICK;
    if (!(i & 1)) {  // even
      Serial.print("-");
      if (x < 1000) Serial.print(" ");
      if (x < 100) Serial.print(" ");
      Serial.print(x, DEC);
    } else {  // odd
      Serial.print("     ");
      Serial.print("+");
      if (x < 1000) Serial.print(" ");
      if (x < 100) Serial.print(" ");
      Serial.print(x, DEC);
      if (i < results->rawlen - 1)
        Serial.print(", ");  // ',' not needed for last one
    }
    if (!(i % 8)) Serial.println("");
  }
  Serial.println("");  // Newline
}

// Dump out the decode_results structure.
//
void dumpCode(decode_results *results) {
  // Start declaration
  Serial.print("uint16_t  ");              // variable type
  Serial.print("rawData[");                // array name
  Serial.print(results->rawlen - 1, DEC);  // array size
  Serial.print("] = {");                   // Start declaration

  // Dump data
  for (uint16_t i = 1; i < results->rawlen; i++) {
    Serial.print(results->rawbuf[i] * USECPERTICK, DEC);
    if (i < results->rawlen - 1)
      Serial.print(",");  // ',' not needed on last one
    if (!(i & 1)) Serial.print(" ");
  }

  // End declaration
  Serial.print("};");  //

  // Comment
  Serial.print("  // ");
  encoding(results);
  Serial.print(" ");
  serialPrintUint64(results->value, 16);

  // Newline
  Serial.println("");

  // Now dump "known" codes
  if (results->decode_type != UNKNOWN) {
    // Some protocols have an address &/or command.
    // NOTE: It will ignore the atypical case when a message has been decoded
    // but the address & the command are both 0.
    if (results->address > 0 || results->command > 0) {
      Serial.print("uint32_t  address = 0x");
      Serial.print(results->address, HEX);
      Serial.println(";");
      Serial.print("uint32_t  command = 0x");
      Serial.print(results->command, HEX);
      Serial.println(";");
    }

    // All protocols have data
    Serial.print("uint64_t  data = 0x");
    serialPrintUint64(results->value, 16);
    Serial.println(";");
  }
}
// End IR decoding code

void loop() {
  // WebServer
  server.handleClient();

  // Arduino ESP8266 OTA
  ArduinoOTA.handle();

  // IR decoding (from IRremoteESP8266: IRrecvDumpV2)
  // Check if the IR code has been received.
  if (irrecv.decode(&results, &save)) {
    dumpInfo(&results);           // Output the results
    dumpRaw(&results);            // Output the results in RAW format
    dumpCode(&results);           // Output the results as source code
    Serial.println("");           // Blank line between entries
  }
  // End IR decoding
}

void receive(const MyMessage &message) {

  if (message.isAck()) {
#if defined MY_DEBUG
    Serial.println("ACK received");
#endif
  }

  int ID = message.sensor;
  int mySwitch = 0 ;
#if defined MY_DEBUG
  Serial.print("Sensor: ");
  Serial.println(ID);
#endif
  switch (ID) {                                           // If different sensors for this node
    case CHILD_ID_TxLED:                                  // The number of the V_PERCENTAGE sensor to be controlled
      if (message.type == V_PERCENTAGE) {                 // Percentage indicates the pattern
        mySwitch = map(message.getInt(), 0, 100, 0, 15);  // Map dimmer values to Switch states 0..9  and wrap
        irrecv.disableIRIn();
        // ******************************************//
        //  IR code settings, you will need to edit  //
        // ******************************************//
        switch (mySwitch) {
          case 0:
            {
#if defined MY_DEBUG
              Serial.println(F("OFF"));
#endif
            } // whatever on switch action 0
            break ;
          case 1:
            {
#if defined MY_DEBUG
              Serial.println("Sending eufyAUTO");
#endif
              irsend.sendRaw(eufyAUTO, sizeof(eufyAUTO) / sizeof(eufyAUTO[0]), khz);
            } // whatever on switch action 1
            break ;
          case 2:
            {
#if defined MY_DEBUG
              Serial.println(F("Sending eufyHome"));
#endif
              irsend.sendRaw(eufyHOME, sizeof(eufyHOME) / sizeof(eufyHOME[0]), khz);
            } // whatever on switch action 2
            break ;
          case 3:
            {
#if defined MY_DEBUG
              Serial.println(F("Sending eufyMAX"));
#endif
              irsend.sendRaw(eufyMAX, sizeof(eufyMAX) / sizeof(eufyMAX[0]), khz);
            } // whatever on switch action 3
            break ;
          case 4:
            {
#if defined MY_DEBUG
              Serial.println(F("Sending eufyROOM"));
#endif
              irsend.sendRaw(eufyROOM, sizeof(eufyROOM) / sizeof(eufyROOM[0]), khz);
            } // whatever on switch action 4
            break ;
          case 5:
            {
#if defined MY_DEBUG
              Serial.println(F("Sending eufySPOT"));
#endif
              irsend.sendRaw(eufySPOT, sizeof(eufySPOT) / sizeof(eufySPOT[0]), khz);
            } // whatever on switch action 5
            break ;
          case 6:
            {
#if defined MY_DEBUG
              Serial.println(F("Sending eufyEDGE"));
#endif
              irsend.sendRaw(eufyEDGE, sizeof(eufyEDGE) / sizeof(eufyEDGE[0]), khz);
            } // whatever on switch action 6
            break ;
          case 7:
            {
#if defined MY_DEBUG
              Serial.println(F("Sending eufySTART"));
#endif
              irsend.sendRaw(eufySTART, sizeof(eufySTART) / sizeof(eufySTART[0]), khz);
            } // whatever on switch action 7
            break ;
          case 8:
            {
#if defined MY_DEBUG
              Serial.println(F("Sending eufyPAUSE"));
#endif
              irsend.sendRaw(eufyPAUSE, sizeof(eufyPAUSE) / sizeof(eufyPAUSE[0]), khz);
            } // whatever on switch action 8
            break ;
          case 9:
            {
              // whatever on switch action 9
            }
            break ;
          case 10:
            {
              // whatever on switch action 10
            }
            break ;
            // max switch actions in Domoticz = 10
        }
        irrecv.enableIRIn();
        break ;
      }
  }
}
