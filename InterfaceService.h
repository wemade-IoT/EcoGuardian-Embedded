#ifndef INTERFACESERVICE_H
#define INTERFACESERVICE_H
#include <WebServer.h>
#include "MonitorinPlantDevice.h"
#include <HTTPClient.h>

class InterfaceService {
  private:
    WebServer* server;
    MonitorinPlantDevice* device;
    unsigned long lastSendTime = 0;
    unsigned long sendInterval = 20000;
    void sendSensorData();
    void sendMetric(float value, int metricTypesId, int deviceId);
  public:
    InterfaceService(WebServer* server, MonitorinPlantDevice* device);
    void begin();
    void handleClient();
    void setSendInterval(unsigned long intervalMs);
};

#endif // INTERFACESERVICE_H