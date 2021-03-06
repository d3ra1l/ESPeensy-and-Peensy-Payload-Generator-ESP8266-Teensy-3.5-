#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid     = "TnSy";
const char* password  = "Peensy3.5!";

IPAddress ip(192, 168, 0, 1);       // IP of the AP
IPAddress netmask(255, 255, 255, 0);  // Netmask

WiFiServer server(80);

void setup() {
  delay(500);
  Serial.begin(115200);
  WiFi.softAPConfig(ip, ip, netmask);   // configure ip address for softAP 
  WiFi.softAP(ssid, password);        // configure ssid and password for softAP
  server.begin();                   // start TCP server  
}

void loop() {

  // ## Connect Client
  WiFiClient client = server.available(); 
  if (!client){return;}
  //Serial.println("Client connected");

  // ## Warte auf Daten
  unsigned long ultimeout = millis()+2500;
  while(!client.available() && (millis()<ultimeout)){delay(1);}
  if(millis()>ultimeout){Serial.println("client connection time-out!");return;}
  //Serial.println("Client received");

  // ## Hole Datenheader
  String sRequest = client.readStringUntil('\r'); client.flush();
  delay (50); if(sRequest==""){client.stop();return;}
  //Serial.println(sRequest);
    
  // ## Hole Daten aus Header
  // 1) GET / HTTP/1.1
  // 2) GET /Index.html HTTP/1.1
  // 3) GET /Index.html?DCL=STRING-ENTER%20Hallo HTTP/1.1
  String sPath="", sResponse="";
  int iGET = sRequest.indexOf("GET");       //Serial.println(iGET);  // 0
  int iSPE = sRequest.indexOf(" ",iGET+4);  //Serial.println(iSPE);  // 41
    
  sPath  = sRequest.substring(iGET+4,iSPE);   // 0-41   (2)=> /Index.html
  if (sPath == "/favicon.ico"){
    client.flush();
    client.stop();
    } else {
  Serial.println(sPath);
  
  String Content = "";
  Content += "<HTML><HEAD></HEAD><BODY><style>* {Margin-Top:5px; Margin-bottom:0px;}</style><a href='/DCL?PAR=NUM'> <button style='width:50px;height:20px;background-color:lightgreen;'>NUM</Button></a>";
  Content += "<a href='/DCL?PAR=CAPS'><button style='width:50px;height:20px;background-color:lightgrey;'>CAPS</Button></a><a href='/DCL?PAR=SCRL'><button style='width:50px;height:20px;background-color:lightgrey;'>SCRL</Button></a>";
  Content += "<form method='GET' action='/DCL'><select style='width:81%' name='PAR' size='1'><option>1.txt</option><option>2.txt</option><option>3.txt</option><option>4.txt</option>";
  Content += "<option>5.txt</option><option>6.txt</option><option>7.txt</option><option>8.txt</option><option>9.txt</option><option>10.txt</option><option>11.txt</option><option>12.txt</option>";
  Content += "<option>13.txt</option><option>14.txt</option><option>15.txt</option><option>16.txt</option></Select><button style='width:15%' type='submit'>Senden</button>";
  Content += "</form><form method='GET' action='/DCL'><select style='width:40%' name='PAR' size='1'><option>STRING</option><option>STRING-ENTER</option>";
  Content += "</Select><input  style='width:40%' name='STR' type='text' value='cmd'/><button style='width:15%' type='submit'>Senden</button>";
  Content += "</form><form method='GET' action='/DCF'><select style='width:40%' name='PAR' size='1'><option>ALT</option><option>GUI</option>";
  Content += "<option>CTRL</option><option>SHIFT</option><option>COMMAND</option><option>WINDOWS</option><option disabled>## Multiple Keys ##</option>";
  Content += "<option>CTRL-ALT</option><option>CTRL-SHIFT</option><option>ALT-SHIFT</option><option>CTRL-ESC</option></Select><input  style='width:40%' name='STR' type='text' value='A'/>";
  Content += "<button style='width:15%' type='submit'>Senden</button></form><Table style='width:100%' Border='0'><TR><TD><a href='/DCL?PAR=ENTER'><button style='width:100%;Height:35px;' type='button'>ENTER</button></a></TD>";
  Content += "<TD><a href='/DCL?PAR=REPEAT'><button style='width:100%;Height:35px;' type='button'>REPEAT</button></a></TD><TD><a href='/DCL?PAR=MENU'><button style='width:100%;Height:35px;' type='button'>MENU</button></a></TD>";
  Content += "</TR><TR><TD><a href='/DCL?PAR=CTRL'><button style='width:100%;Height:35px;' type='button'>CTRL</button></a></TD><TD><a href='/DCL?PAR=GUI'><button style='width:100%;Height:35px;' type='button'>GUI</button></a></TD>";
  Content += "<TD><a href='/DCL?PAR=ALT'><button style='width:100%;Height:35px;' type='button'>ALT</button></a></TD></TR><TR><TD></TD><TD><a href='/DCL?PAR=UPARROW'><button style='width:100%;Height:35px;;background-color:lightblue;' type='button'>UP</button></a></TD><TD></TD>";
  Content += "</TR><TR><TD><a href='/DCL?PAR=LEFTARROW'><button style='width:100%;Height:35px;;background-color:lightblue;' type='button'>LEFT</button></a></TD>";
  Content += "<TD><a href='/DCL?PAR=DOWNARROW'><button style='width:100%;Height:35px;;background-color:lightblue;' type='button'>DOWN</button></a></TD>";
  Content += "<TD><a href='/DCL?PAR=RIGHTARROW'><button style='width:100%;Height:35px;;background-color:lightblue;' type='button'>RIGHT</button></a></TD>";
  Content += "</TR></Table><Table align='center' style='width:97%;Position:absolute;Bottom:0px' Border='0'><TR><TD><a href='/DCL?PAR=FAKEAP'><button style='width:100%;Height:35px;'>ESPFakeAP</Button></a></TD>";
  Content += "<TD><a href='/DCL?PAR=DEAUTH'><button style='width:100%;Height:35px;'>ESPDeauth</Button></a></TD></TR></TABLE></BODY></HTML>";

  sResponse = Content;

  String sHeader  = "HTTP/1.1 200 OK\r\n";
  sHeader += "Content-Length: ";
  sHeader += sResponse.length();
  sHeader += "\r\n";
  sHeader += "Content-Type: text/html\r\n";
  sHeader += "Connection: close\r\n";
  sHeader += "\r\n";

  client.print(sHeader);          // Send the response-Header to the client
  client.print(sResponse);        // Send the response to the client
  delay(100);client.stop();
  }
  
}



