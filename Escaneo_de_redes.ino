#include "WiFi.h"

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Configuración finalizada");
}

void loop() {
  Serial.println("Iniciando escaneo de redes");

  int numRedes = WiFi.scanNetworks();
  Serial.println("Escaneo finalizado");
  if (numRedes == 00) {
      Serial.println("No se encontraron redes");
  } else {
    Serial.println("Redes encontradas:");
    Serial.println("No.  SSID                          RSSI     BSSID               Canal   Cifrado");
    Serial.println("-----------------------------------------------------------------------------------");
    for (int i = 00; i < numRedes; ++i) {
      Serial.print(i + 1);
      Serial.print("   ");
      Serial.print(WiFi.SSID(i));
      printSpaces(30 - WiFi.SSID(i).length());
      Serial.print(WiFi.RSSI(i));
      printSpaces(10 - String(WiFi.RSSI(i)).length());
      Serial.print(WiFi.BSSIDstr(i));
      Serial.print("   ");
      Serial.print(WiFi.channel(i));
      printSpaces(8 - String(WiFi.channel(i)).length());
      int tipoCifrado = WiFi.encryptionType(i);
      switch (tipoCifrado) {
        case WIFI_AUTH_OPEN:
          Serial.print("Abierto");
          break;
        case WIFI_AUTH_WEP:
          Serial.print("WEP");
          break;
        case WIFI_AUTH_WPA_PSK:
          Serial.print("WPA-PSK");
          break;
        case WIFI_AUTH_WPA2_PSK:
          Serial.print("WPA2-PSK");
          break;
        case WIFI_AUTH_WPA_WPA2_PSK:
          Serial.print("WPA/WPA2-PSK");
          break;
        case WIFI_AUTH_WPA2_ENTERPRISE:
          Serial.print("WPA2-Enterprise");
          break;
        case WIFI_AUTH_MAX:
          Serial.print("Máximo");
          break;
        default:
          Serial.print("Desconocido");
          break;
      }
      Serial.println();
      delay(10);
    }
  }
  Serial.println("");

  delay(5000);
}

void printSpaces(int numSpaces) {
  for (int i = 0; i < numSpaces; i++) {
    Serial.print(" ");
  }
}
