#include "InterfaceService.h"
#include <Arduino.h>
#include <HTTPClient.h>

#define EDGE_URL "http://host.wokwi.internal:5000/api/v1/analytics/metrics"
#define API_KEY "b1e2c3d4-5f6a-7b8c-9d0e-1f2a3b4c5d6e"

InterfaceService::InterfaceService(WebServer* server, MonitorinPlantDevice* device)
    : server(server), device(device) {}

void InterfaceService::begin() {
    server->begin();
}

void InterfaceService::handleClient() {
    server->handleClient();
    unsigned long now = millis();
    if (now - lastSendTime >= sendInterval) {
        sendSensorData();
        lastSendTime = now;
    }
}

void InterfaceService::setSendInterval(unsigned long intervalMs) {
    sendInterval = intervalMs;
}

void InterfaceService::sendSensorData() {
    // Humedad
    device->triggerHumiditySensorEvent();
    float humidity = device->getHumiditySensor().getValue(device->getSensors());
    sendMetric(humidity, 1, device->getHumiditySensor().getId()); // metricTypesId=1

    // Luz
    device->triggerLightSensorEvent();
    float light = device->getLightSensor().getValue();
    sendMetric(light, 2, device->getLightSensor().getId()); // metricTypesId=2

    // Agua
    device->triggerWaterSensorEvent();
    float water = device->getWaterSensor().getValue();
    sendMetric(water, 3, device->getWaterSensor().getId()); // metricTypesId=3
}

void InterfaceService::sendMetric(float value, int metricTypesId, int deviceId) {
    HTTPClient http;
    http.begin(EDGE_URL);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Api-Key", API_KEY); 
    http.addHeader("Device-Id", String(deviceId)); 
    String payload = "{";
    payload += "\"metricValue\":" + String(value, 2) + ",";
    payload += "\"metricTypesId\":" + String(metricTypesId) + ",";
    payload += "\"deviceId\":" + String(deviceId);
    payload += "}";
    int httpResponseCode = http.POST(payload);
    Serial.print(payload);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    if (httpResponseCode != 201 && httpResponseCode != 200) {
        String response = http.getString();
        Serial.print("Error response: ");
        Serial.println(response);
    }
    http.end();
}