// Basic project to control LED from Browser with NodeMCU 

#include <ESP8266WiFi.h>

#define LED D2

const char* ssid = "<WiFi SSID>";
const char* password = "<WiFi Password>";

unsigned char status_led=0;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
   }
  Serial.println("");
  Serial.println("WiFi Connected");

  server.begin();
  Serial.println("Server Started");
  Serial.println(WiFi.localIP()); //WiFi.localIP() prints ip allocated to NodeMcu
 
}

void loop() 
{
  WiFiClient client = server.available();

  if(!client){
    return;
  }

  Serial.println("New Client");
  while(!client.available())
  {
    delay(1);
  }
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  if(req.indexOf("/ledoff") != -1) // Check for client data 
  {
    status_led=0;
    digitalWrite(LED,LOW);
    Serial.println("LED OFF");
  }

  else if(req.indexOf("/ledon") != -1)
  {
    status_led=1;
    digitalWrite(LED,HIGH);
    Serial.println("LED ON");
  }

  String web = "HTTP/1.1 200 OK\r\nContent=Type: text/html\r\n\r\n";
  // Setting up http request from browser
  web += "<html>\r\n";
  web += "<body>\r\n";
  web += "<h1> LED Status </h1>\r\n";
  
  web += "<p>\r\n";
  if(status_led==1) // code stored in string and return in HTTP response
    web += "LED ON\r\n";
  else 
    web += "LED Off\r\n";
  web +="</p>\r\n";

  web +="<p>\r\n";
  web += "<a href=\"/ledon\">\r\n"; // Create hyperlink
  web += "<button> LED ON </button>\r\n";
  web += "</a>\r\n";
  web += "</p>\r\n";

  web += "<a href=\"/ledoff\">\r\n"; // Create hyperlink
  web += "<button> LED OFF </button>\r\n";
  web += "</a>\r\n";

  web += "</body>\r\n";
  web += "</html>\r\n";
  client.print(web);
 
}
