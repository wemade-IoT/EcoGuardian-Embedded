#include "MonitorinPlantDevice.h"
#include "InterfaceService.h"
#include <WiFi.h>
#include <WebServer.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define WIFI_CHANNEL 6
#define DEVICE_ID 1

MonitorinPlantDevice device(DEVICE_ID);
WebServer server(80);
InterfaceService interfaceService(&server, &device);

void setup() {
  device.init();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  interfaceService.begin();
}

void loop() {
  interfaceService.handleClient();
}
