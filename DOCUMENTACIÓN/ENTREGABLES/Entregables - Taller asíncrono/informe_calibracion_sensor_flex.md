# Taller asíncrono - Equipo 02

## Video
https://github.com/user-attachments/assets/627ce223-7813-42c3-8faf-78f3eb759bc6

## Capturas de pantalla

![Captura 1](https://github.com/user-attachments/assets/a9cb2a82-00df-48ea-9cff-3e316395341e)
![Captura 3](https://github.com/user-attachments/assets/04a14db0-bb59-4b2c-8627-307f2b13f2a4)
![Captura 2](https://github.com/user-attachments/assets/b6c7ec45-39e7-496c-b9c2-7dedc75c0797)

## Código `.ino` comentado

```cpp
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
```
## Informe explicando calibración y rango obtenido

## Descripción del sistema

El sistema desarrollado permite la lectura de un **sensor flex** conectado a un microcontrolador **ESP32**. Los datos son adquiridos a través del pin analógico **A0** y enviados mediante un **servidor web** alojado en el mismo ESP, accesible por navegador web. El sensor está conectado en conjunto con un **potenciómetro**, permitiendo el ajuste de la señal analógica para facilitar la calibración.

## Objetivo de la calibración

El objetivo de la calibración fue ajustar la lectura del ESP32 a un rango realista y útil de voltaje entregado por el sensor flex. Para esto se utilizó un **multímetro** como instrumento de referencia para comparar los valores de voltaje entregados físicamente con los valores digitales leídos desde el microcontrolador.

## Metodología de calibración

Se conectó el sensor flex al pin **A0** del ESP32 mediante un divisor de voltaje usando un potenciómetro. Luego:

1. Se midieron los valores de voltaje entregados por el sensor en su estado mínimo (sin flexión) y máximo (flexionado completamente), usando un **multímetro digital**.
2. Se compararon estos valores con las lecturas entregadas por `analogRead(A0)` en el ESP32.
3. Se aplicó una conversión con la función `map()` para transformar los valores del ADC (0–4095) a una escala de 0 a 3300 mV, ya que el ESP32 tiene una resolución ADC de 12 bits y un voltaje de referencia de 3.3V.

```cpp
a = analogRead(A0);
a = map(a, 0, 4095, 0, 3300); // Conversión a milivoltios
```

## Resultados de la calibración

- **Valor mínimo medido con multímetro:** ~2.8 V
- **Valor máximo medido con multímetro:** ~3.3 V

Esto indica que el sensor flex tiene un rango de salida estrecho, lo cual es común en este tipo de sensores resistivos.

- **Valor digital mínimo obtenido en el ESP32 (convertido):** ~2850 mV
- **Valor digital máximo obtenido en el ESP32 (convertido):** ~3290 mV

Estas diferencias mínimas entre la lectura física y digital pueden deberse a ruidos eléctricos o tolerancias internas del ADC.

## Conclusiones

- El sistema fue capaz de leer correctamente las variaciones del sensor flex.
- La conversión `analogRead` → milivoltios fue válida dentro del margen de error aceptable.
- El rango útil del sensor quedó comprendido entre **~2850 mV y ~3290 mV**, lo cual debe tenerse en cuenta al diseñar la lógica de interpretación de datos en App Inventor.
