
# Entregable 12

## 1. Boceto final

![image](https://github.com/user-attachments/assets/680385d8-31a8-4b76-9092-245792e13858)

## 2. Modelado final

### ● Ensamble completo caja:
[Ver modelo en Onshape](https://cad.onshape.com/documents/a2ab5cac928358b294b8e734/w/1b63dac98f2b4d9a44575ce3/e/246b7a50b909e9a633afc0a8)

![image](https://github.com/user-attachments/assets/f1e83eec-1497-4130-8e50-5305e8409b9a)

### ● Tornillo sin fin:
[Ver modelo en Onshape](https://cad.onshape.com/documents/a2ab5cac928358b294b8e734/w/1b63dac98f2b4d9a44575ce3/e/e1bfced4999270e78eeb9dfc)

![image](https://github.com/user-attachments/assets/0d610f5d-8d71-4c63-ba34-d5640d4e3d47)

## 3. Prototipo físico

**Materiales empleados en la confección de la manta:**

- Doble forro de nylon impermeable  
- Cierre de alta resistencia  
- Esponja de mayor grosor, específicamente seleccionada para brindar mayor acolchamiento y protección  

![image](https://github.com/user-attachments/assets/376b4912-df21-4ad4-9957-85d1bde04245)

![image](https://github.com/user-attachments/assets/8e23ac1c-4ac1-405b-bfe9-2272d386a01f)

# Código usado:

```cpp

#include <U8g2lib.h>
#include <Wire.h>

// OLED SSD1327 (128x128) en modo page buffer
U8G2_SSD1327_MIDAS_128X128_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Pines del motor en canal B
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10;

// Pines del encoder
const int CLK = 2;
const int DT  = 3;
const int SW  = 4;

int modo = 0;               // 0 = parado, 1 = sentido A, 2 = sentido B
bool pausado = false;
int ultimoCLK = HIGH;
bool ultimoSW = HIGH;

const int PWM_BAJO = 200;   //Velocidad del motor

void setup() {
  u8g2.begin();
  mostrarModo();

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(ENA, OUTPUT);
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  ultimoCLK = digitalRead(CLK);
}

void loop() {
  // Encoder - cambio de modo
  int estadoCLK = digitalRead(CLK);
  if (estadoCLK != ultimoCLK) {
    if (digitalRead(DT) != estadoCLK) {
      modo++; if (modo > 2) modo = 0;
    } else {
      modo--; if (modo < 0) modo = 2;
    }
    mostrarModo();
  }
  ultimoCLK = estadoCLK;

  // Encoder - botón para pausar
  int estadoSW = digitalRead(SW);
  if (estadoSW == LOW && ultimoSW == HIGH) {
    pausado = !pausado;
    mostrarModo();
    delay(200);  // antirrebote
  }
  ultimoSW = estadoSW;

  // Control del motor
  if (pausado || modo == 0) {
    analogWrite(ENA, 0);
  } else {
    analogWrite(ENA, PWM_BAJO);
    if (modo == 1) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    } else if (modo == 2) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
  }
}

void mostrarModo() {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    if (pausado) {
      u8g2.drawStr(0, 20, "Sistema pausado");
    } else {
      switch (modo) {
        case 0: u8g2.drawStr(0, 20, "Modo 0: Parado"); break;
        case 1: u8g2.drawStr(0, 20, "Modo 1: Gira -->"); break;
        case 2: u8g2.drawStr(0, 20, "Modo 2: Gira <--"); break;
      }
    }
  } while (u8g2.nextPage());
}


```

## Tabla de requisitos funcionales

| Requisito Funcional | Descripción | Prioridad | Criterio de Aceptación |
|----------------------|-------------|-----------|--------------------------|
| Masaje programable | El usuario puede seleccionar la duración del masaje entre 5 y 15 minutos | Alta | Satisfactorio |
| Interfaz de control sencilla | El sistema debe tener una pantalla y un botón rotativo para seleccionar ajustes | Alta | Satisfactorio |
| Compatibilidad con silla de ruedas | El cojín debe encajar en una silla de ruedas estándar sin interferencias | Alta | En proceso |
| Cambio de modo de masaje (Modo 1, 2, 3) | El sistema debe permitir cambiar entre tres modos de operación | Alta | En proceso |
| Encendido y apagado mediante switch | El sistema debe contar con un interruptor físico para encendido y apagado | Alta | Satisfactorio |
| Uso de espuma de soporte eficaz | El sistema debe estar integrado en un material de espuma que distribuya adecuadamente la presión | Media | En proceso |
| Protección contra líquidos | El sistema debe estar cubierto por un material impermeable para proteger la electrónica | Alta | Satisfactorio |
| Inclusión de zonas levantadas para ventilación | El cojín debe tener zonas elevadas o canales para permitir el flujo de oxígeno y evitar acumulación de humedad | Media | En proceso |
