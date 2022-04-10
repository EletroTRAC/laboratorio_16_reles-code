/* ---------------------------------------------------------
  ETEC Profa. Dra. Doroti Quiomi Kanashiro Toyohara

  Projeto: Automação das bancadas do laboratório 16
  Professor organizador e instrutor: Saulo Benatti
  Alunos: Gustavo Damasceno, Igor Santos e Rangel Barbosa

  Contato/código fonte:
  https://www.instagram.com/eletro_por_amor/
  https://github.com/EletroTRAC/laboratorio_16_reles-code.git
--------------------------------------------------------- */

/* Inicio */
/* -------------------------------------------------------- */

/* Bibliotecas */
#include <WiFi.h>
#include <ESPmDNS.h>
#include <DNSServer.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "credentials.h"

/* Variaveis de conexão */
const char* ssid = apSSID;
const char* password = apPASS;
const char* myHostname = mDNSHostName;
const byte DNS_PORT = 53;

/* Variaveis de GPIO */
const int BC [12] = {2, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26};
bool BC1_status = LOW, BC2_status = LOW, BC3_status = LOW, BC4_status = LOW, BC5_status = LOW, BC6_status = LOW, BC7_status = LOW, BC8_status = LOW, BC9_status = LOW, BC10_status = LOW, BC11_status = LOW, BC12_status = LOW;

/* Objetos WEB e de métodos */
WebServer server(80);
DNSServer dnsServer;
IPAddress apIP(192,168,1,1);

/* Função de execução unica e inicial */
void setup(void)
{
    Serial.begin(115200);
    for(int i = 0; i < 12; i++) {
      pinMode(BC[i], OUTPUT);
    }

    WiFi.mode(WIFI_AP);
    WiFi.softAP("ESP32-DNSServer");
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));

    if (!MDNS.begin(myHostname)) {
        Serial.println("Error setting up MDNS responder!");
        while(1) {
            delay(1000);
        }
    }

    dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
    dnsServer.start(DNS_PORT, "*", apIP);
    Serial.println("mDNS responder started");

    server.on("/", handleRoot);
    server.on("/bc1", handleRele1);
    server.on("/bc2", handleRele2);
    server.on("/bc3", handleRele3);
    server.on("/bc4", handleRele4);
    server.on("/bc5", handleRele5);
    server.on("/bc6", handleRele6);
    server.on("/bc7", handleRele7);
    server.on("/bc8", handleRele8);
    server.on("/bc9", handleRele9);
    server.on("/bc10", handleRele10);
    server.on("/bc11", handleRele11);
    server.on("/bc12", handleRele12);
    
    server.onNotFound(handleNotFound);
    server.begin();
    Serial.println("TCP server started");

    MDNS.addService("http", "tcp", 80);
}

/* Função de execução ccontinua e infinita */
void loop(void)
{
  dnsServer.processNextRequest();
  server.handleClient();
}

/* -------------------------------------------------------- */
/* Fim */

/*creditos/referências:
    https://github.com/esp8266/Arduino/tree/master/libraries/DNSServer/examples/CaptivePortalAdvanced
    https://www.arduino.cc/reference/en/
    https://github.com/espressif/arduino-esp32/tree/master/libraries/DNSServer/examples/CaptivePortal
*/