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
  {

  WiFiClient client = server.available();
    if (!client){
      return;}  //se não tiver usuários não faz nada
    }
Serial.println("Usuário conectou-se");

  while (!client.available())
  {
delay(100);
  }

  String req = client.readStringUntil('\r');
  Serial.print("Requisição: ");
  Serial.println(req);

  //PAGINA HTML AQUI 




  //...

  client.print(html);
  client.flush();

  //verificar ações dos botoes em html
  if(req.indexOf("acao=liberar1))!=-1)
  {
      digitalWrite(0, HIGH);
  }
  else if(res.indexOf(acao=fechar1)!=-1){
    digitalWrite(0, LOW);
  }
   else if(res.indexOf(acao=liberar2)!=-1){
   digitalWrite(2, HIGH);
  }
   else if(res.indexOf(acao=fechar2)!=-1){
   digitalWrite(2, LOW);
  }

  client.stop();

  Serial.println("Desconectado");

}
