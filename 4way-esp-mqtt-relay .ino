#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// wifi and MQTT broker vars

const char* ssid = "**********";              // your network ssid
const char* password = "*******";             // password
const char* mqtt_server = "192.168.1.121";    // your mqtt server
boolean pin1 = false;
boolean pin2 = false;
boolean pin3 = false;                          //not shure here but i commented temp pin
boolean pin4 = false;
boolean pin5 = false;
//boolean pin6 = false;
const int   misc_sens_pin = 12;                // temp was after thought 12 was free,. change to pin you like
const int   mqtt_interval = 60000;

WiFiClient espClient;
PubSubClient client(espClient);
OneWire oneWire(misc_sens_pin);
DallasTemperature DS18B20(&oneWire);

long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  if( (char)topic[0] == 'A') {
    if ((char)payload[0] == '1') {
        digitalWrite(16, LOW);  // you will need to change pin # if done elswere, it is 16 now thats the onboard led for testing
    }
    if ((char)payload[0] == '0') {
        digitalWrite(16, HIGH);          // and here same as above and for any pin changes
    }
  }

  if( (char)topic[0] == 'B') {
    if ((char)payload[0] == '1') {
        digitalWrite(4, LOW);   // Turn the LED on (Note that LOW is the voltage level
    }
    if ((char)payload[0] == '0') {
        digitalWrite(4, HIGH);   // Turn the LED on (Note that LOW is the voltage level
    }
  }

  if( (char)topic[0] == 'C') {
    if ((char)payload[0] == '1') {
        digitalWrite(0, LOW);   // Turn the LED on (Note that LOW is the voltage level
    }
    if ((char)payload[0] == '0') {
        digitalWrite(0, HIGH);   // Turn the LED on (Note that LOW is the voltage level
    }
  }
 
  if( (char)topic[0] == 'D') {
    if ((char)payload[0] == '1') {
        digitalWrite(2, LOW);   // Turn the LED on (Note that LOW is the voltage level
    }
    if ((char)payload[0] == '0') {
        digitalWrite(2, HIGH);   // Turn the LED on (Note that LOW is the voltage level
    }
  }
}
  
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client5")) {
      Serial.println("connected");
      
      
      // ... and resubscribe
      client.subscribe("A");
      client.subscribe("B");
      client.subscribe("C");
      client.subscribe("D");

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {
  pinMode(16, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);                     // if you changed temp pin then it needs to be input..
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);                    //xtra
  pinMode(12, INPUT);                     //temp pin 
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  float temp;
  char tempStr[5];
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
   long now = millis();
  if (now - lastMsg > mqtt_interval) {
    lastMsg = now;
    ++value;
    DS18B20.requestTemperatures();
    temp = DS18B20.getTempCByIndex(0); 
     
    String(temp).toCharArray(tempStr, 2);
    
    String(temp).toCharArray(tempStr, 5);
    client.publish("outTopictemp", tempStr);
    client.publish("outTopic", "Relay Board OK");
    
  }
}
