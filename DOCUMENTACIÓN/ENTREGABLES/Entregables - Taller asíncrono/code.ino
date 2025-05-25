#include <WiFiManager.h> // Librería para gestionar la conexión WiFi de forma sencilla

//#include <WiFiClient.h> // Comentado, no se está usando en este código

#include <WebServer.h> // Librería para crear un servidor web en el ESP

#include "index.h" // Archivo que contiene el contenido HTML de la página principal (MAIN_page)

WebServer server(80); // Se crea un servidor web en el puerto 80


// Función que maneja la raíz del servidor ("/")
void handleRoot() {
  String s = MAIN_page; // Se obtiene el contenido HTML desde la variable MAIN_page
  server.send(200, "text/html", s); // Se envía la página al cliente con estado 200 (OK) y tipo de contenido HTML
}


// Función que maneja la lectura del valor analógico desde el pin A0
void handleADC() {
  int a = 0;
  a = analogRead(A0); // Se lee el valor analógico del pin A0 (por ejemplo, de un potenciómetro)
  a = map(a, 0, 4095, 0, 3300); // Se convierte el valor leído (0-4095) a milivoltios (0-3300 mV)
  String adcValue = String(a); // Se convierte el valor a String
  server.send(200, "text/plane", adcValue); // Se envía el valor como texto plano al cliente
}


void setup() {
  // Inicializa el monitor serial a 115200 baudios
  Serial.begin(115200);
  
  // Inicializa una instancia de WiFiManager
  WiFiManager wm;

  // Conexión automática al WiFi, si falla crea un punto de acceso llamado "ConnectAP" con contraseña "1234567890"
  bool res;
  res = wm.autoConnect("ConnectAP", "1234567890"); // Punto de acceso protegido por contraseña

  if (!res) {
    Serial.println("Failed to connect"); // Si falla la conexión, lo muestra en el monitor serial
    // ESP.restart(); // Se puede reiniciar el ESP si falla, pero está comentado
  } else {
    Serial.println("connected...yeey :)"); // Mensaje de éxito en la conexión
  }

  // Muestra la IP local asignada al ESP
  Serial.println("");
  Serial.print("Connected to ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Asocia las rutas del servidor web con sus funciones manejadoras
  server.on("/", handleRoot);       // Ruta raíz "/"
  server.on("/readADC", handleADC); // Ruta para lectura de ADC

  server.begin(); // Inicia el servidor HTTP
  Serial.println("HTTP server started");
}


void loop(void) {
  server.handleClient(); // Atiende las peticiones de los clientes al servidor web
}
