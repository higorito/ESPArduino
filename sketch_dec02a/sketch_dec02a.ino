#include<ESP8266WiFi.h>

//inicar server porta 80(padrão)
WiFiServer server(80);

void setup() {
 serial begin(115200);
 //saidas p/ controle
 pinMode(0, OUTPUT);
 pinMode(2, OUTPUT;

 digitalWrite(0, LOW);
 digitalWrite(2, LOW);

 Serial.print("Conectando a rede...");

 WiFi.begin("Assure 02", "12345");   //ssid , senha ---- conectar o ESP a rede


 while(WiFi.status()!=WL_CONNECTED)
 {
  delay(100);
  Serial.print("...");
 }
  
  Serial.println("Conectado ao WiFi!");

  //configurar o IP fixo(pode ser mudado)

  IPAddress ip(000, 000, 0, 0);
  IPAddress gateway(000, 000, 0, 0);
  IPAddress subnet(000, 000, 000, 0);

  Serial.print("Definindo IP fixo:");
  Serial.print(ip);

  WiFi.config(ip, gateway, subnet);
  
  //iniciando na porta definida

  Server.begin();
  Serial.print("Servidor iniciado!");
  //IP do ESP P/ verificação

  Serial.println("Servidor Web conectado...");
  Serial.print("Endereço de IP web server: ", WiFi.localIP());
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
