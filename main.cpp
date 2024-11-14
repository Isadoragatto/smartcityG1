#include <WiFi.h>
#include <PubSubClient.h>

// Configurações de WiFi
const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";

// Configurações do servidor MQTT
const char* mqtt_server = "broker.exemplo.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "seu/topico";

// Instâncias do WiFi e MQTT Client
WiFiClient espClient;
PubSubClient client(espClient);



// Definição dos pinos dos LEDs
const int led1Verde1 = 5;
const int led1Verde2 = 25;
const int ledAmarelo1 = 4;
const int ledAmarelo2 = 27;
const int led1Vermelho1 = 15;
const int led1Vermelho2 = 12;

void setup() {
  // Configura os pinos como saída
  pinMode(led1Verde1, OUTPUT);
  pinMode(led1Verde2, OUTPUT);
  pinMode(ledAmarelo1, OUTPUT);
  pinMode(ledAmarelo2, OUTPUT);
  pinMode(led1Vermelho1, OUTPUT);
  pinMode(led1Vermelho2, OUTPUT);
}

void dia() {
  //Semáforo 1
  digitalWrite(led1Verde1, HIGH);
  digitalWrite(led1Vermelho1, LOW);
  digitalWrite(ledAmarelo1, LOW);
  // Semáforo 2
  digitalWrite(led1Verde2, LOW);
  digitalWrite(led1Vermelho2, HIGH);
  digitalWrite(ledAmarelo2, LOW);
  delay(6000);

  //Semáforo 1
  digitalWrite(led1Verde1, LOW);
  digitalWrite(led1Vermelho1, HIGH);
  digitalWrite(ledAmarelo1, LOW);
  // Semáforo 2
  digitalWrite(led1Verde2, LOW);
  digitalWrite(led1Vermelho2, LOW);
  digitalWrite(ledAmarelo2, HIGH);
  delay(2000);

  //Semáforo 1
  digitalWrite(led1Verde1, LOW);
  digitalWrite(led1Vermelho1, HIGH);
  digitalWrite(ledAmarelo1, LOW);
  // Semáforo 2
  digitalWrite(led1Verde2, LOW);
  digitalWrite(led1Vermelho2, HIGH);
  digitalWrite(ledAmarelo2, LOW);
  delay(4000);

  //Semáforo 1
  digitalWrite(led1Verde1, HIGH);
  digitalWrite(led1Vermelho1, LOW);
  digitalWrite(ledAmarelo1, LOW);
  // Semáforo 2
  digitalWrite(led1Verde2, LOW);
  digitalWrite(led1Vermelho2, HIGH);
  digitalWrite(ledAmarelo2, LOW);
  delay(4000);


}

void noite() {
  // Desliga todos os LEDs exceto os amarelos
  digitalWrite(led1Verde1, LOW);
  digitalWrite(led1Verde2, LOW);
  digitalWrite(led1Vermelho1, LOW);
  digitalWrite(led1Vermelho2, LOW);

  // Pisca os LEDs amarelos nos dois semáforos
  digitalWrite(ledAmarelo1, HIGH);
  digitalWrite(ledAmarelo2, HIGH);
  delay(500);  // Liga os amarelos por 500 ms (ajuste conforme necessário)

  digitalWrite(ledAmarelo1, LOW);
  digitalWrite(ledAmarelo2, LOW);
  delay(500);  // Desliga os amarelos por 500 ms (ajuste conforme necessário)
}



// // Callback para quando uma mensagem é recebida
// void callback(char* topic, byte* message, unsigned int length) {
//     Serial.print("Mensagem recebida no tópico: ");
//     Serial.println(topic);

//     // Converte a mensagem para String
//     String messageTemp;
//     for (int i = 0; i < length; i++) {
//         messageTemp += (char)message[i];
//     }
//     Serial.println("Mensagem: " + messageTemp);

//     // Verifica se a mensagem é o comando esperado
//     if (messageTemp == "chamarFuncao") {
//         minhaFuncaoEspecifica(); // Chama a função específica
//     }
// }

// // Função para conectar ao servidor MQTT
// void reconnect() {
//     while (!client.connected()) {
//         Serial.print("Tentando conectar ao MQTT...");
//         if (client.connect("ESP32Client")) {
//             Serial.println("Conectado ao MQTT");
//             client.subscribe(mqtt_topic); // Inscreve-se no tópico
//         } else {
//             Serial.print("Falha, rc=");
//             Serial.print(client.state());
//             Serial.println(" Tentando novamente em 5 segundos");
//             delay(5000);
//         }
//     }
// }

// void setup() {
//     Serial.begin(115200);

//     // Conecta ao WiFi
//     WiFi.begin(ssid, password);
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(1000);
//         Serial.println("Conectando ao WiFi...");
//     }
//     Serial.println("Conectado ao WiFi");

//     // Configura o cliente MQTT
//     client.setServer(mqtt_server, mqtt_port);
//     client.setCallback(callback); // Define o callback para mensagens recebidas
// }

void loop() {
    // // Verifica a conexão com o servidor MQTT
    // if (!client.connected()) {
    //     reconnect();
    // }
    // client.loop(); // Mantém a conexão MQTT

      dia();
     noite();  
}