# Prototipado electrónico:

![WhatsApp Image 2025-06-17 at 21 33 22](https://github.com/user-attachments/assets/bc4cbbb9-0810-4acf-a4f6-7741bde87090)

# Video en funcionamiento:

https://github.com/user-attachments/assets/616cca93-1117-4f44-90d2-93936758373e

# Código usado:

```cpp

#include <U8g2lib.h>
#include <Wire.h>

// OLED SSD1327 (128x128) en modo page buffer
U8G2_SSD1327_MIDAS_128X128_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Pines del motor en canal B
const int IN3 = 6;
const int IN4 = 7;
const int ENB = 11;

// Pines del encoder
const int CLK = 2;
const int DT  = 3;
const int SW  = 4;

int modo = 0;               // 0 = parado, 1 = sentido A, 2 = sentido B
bool pausado = false;
int ultimoCLK = HIGH;
bool ultimoSW = HIGH;

const int PWM_BAJO = 100;   //Velocidad del motor

void setup() {
  u8g2.begin();
  mostrarModo();

  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);
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
    analogWrite(ENB, 0);
  } else {
    analogWrite(ENB, PWM_BAJO);
    if (modo == 1) {
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    } else if (modo == 2) {
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
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
# Avance de Fabricación Digital:

### Prototipo

![image](https://github.com/user-attachments/assets/5860326c-cec9-4a21-9f1b-a7fde2e586f5)

### Piezas que se imprimirán

![image](https://github.com/user-attachments/assets/1de39bf4-a52f-4109-97d4-b8093d4e478f)

![image](https://github.com/user-attachments/assets/7a7227fd-026b-4ec7-920f-03d5cb15f0b4)

![image](https://github.com/user-attachments/assets/4ed435fd-b6ef-41fd-908e-b65ef3efa913)

![image](https://github.com/user-attachments/assets/bfdee1a0-578b-4de1-90c9-4d4cc81dad93)

# Boceto:

![WhatsApp Image 2025-06-18 at 15 01 35](https://github.com/user-attachments/assets/f73d1ecd-29b1-45b7-b90f-999eff23e298)

# Justificación de nuevo proyecto

## Proyecto de Dispositivo Masajeador Automatizado para Prevención de Lesiones por Presión (LPP)

### 1. Introducción y Justificación

Este proyecto tiene como objetivo diseñar un sistema de masaje automático, compacto y portátil, destinado a la prevención indirecta de lesiones por presión (LPP) en pacientes con lesión medular. A diferencia de los sistemas tradicionales recreativos, esta propuesta se basa en evidencia científica reciente sobre los beneficios del masaje de tipo effleurage/petrissage para mejorar la circulación y retrasar la aparición de úlceras por presión en zonas críticas como los glúteos e isquiones.

En personas con movilidad reducida —como es el caso de una lesión medular cervical alta—, el riesgo de desarrollar úlceras por presión es constante debido a la falta de movilidad activa y de sensibilidad. Aunque existen tecnologías de redistribución de presión como colchones inflables o cojines inteligentes, pocas soluciones se enfocan en aplicar masaje mecánico localizado y programado en zonas como los glúteos. El diseño aquí propuesto busca cubrir justamente ese vacío.

Sabemos que existen estudios clínicos que avalan el uso de masajes suaves para mejorar la perfusión tisular. Por ejemplo, Akyol y Yigit (2025) demostraron en pacientes críticos que los masajes periódicos con técnicas simples como el effleurage retardaron de manera significativa la aparición de lesiones por presión en comparación con el grupo control [1]. Otro estudio, realizado por Wiguna et al. (2025), aplicó masaje con aceite de canola en pacientes post-ACV y encontró una reducción estadísticamente significativa en el riesgo de úlceras (medido por la escala de Braden) [2].

Además, existe al menos un prototipo automatizado que se asemeja parcialmente a nuestra propuesta: el dispositivo VEPMAS, desarrollado en India, logró mejorar los puntajes de riesgo de úlceras en pacientes encamados, demostrando que un sistema mecánico puede tener resultados clínicos positivos [3]. Sin embargo, este dispositivo es voluminoso, no portátil y no está diseñado para zonas específicas como las que abordamos.

### 2. Diferenciación frente a Sillones Comerciales

| Característica         | Sillón de Masaje Comercial      | Dispositivo Propuesto                        |
|------------------------|----------------------------------|----------------------------------------------|
| Objetivo               | Relajación, bienestar           | Prevención de LPP en pacientes               |
| Zona tratada           | Espalda, cuello, piernas        | Glúteos e isquiones, lumbar, espalda baja    |
| Público objetivo       | Personas sanas                  | Pacientes con lesión medular                 |
| Portabilidad y tamaño  | Grande, fijo                    | Compacto, embebido en cojín                  |
| Justificación clínica  | Recreativo                      | Clínico-preventivo con evidencia             |

Aunque existen sillones de masaje en el mercado, estos están orientados al confort del usuario sano y aplican técnicas generales como percusión, rodamiento o compresión neumática. No se enfocan en prevenir lesiones, ni mucho menos en usuarios con movilidad reducida. Nuestro proyecto, trabaja con un enfoque clínico, de bajo costo, aplicable en contextos hospitalarios o domiciliarios.

### 3. Diseño Mecánico Funcional

**Descripción del mecanismo:**
- Un motor DC con reductor (GM3 R48) acciona eje de rotación a un cilindro con una espiral diseñada para simular la estimulación de un masaje
- El cilindro con diseño de espiral, simulará la estimulación de masaje tipo effleurage.
- El conjunto se aloja dentro de un cojín/tapete con una cobertura de doble tela para evitar el exceso de fricción.

**Ventajas:**
- Movimiento ondulado similar al masaje tipo effleurage.
- Adaptable a camas, sillas de ruedas o superficies clínicas.
- Fácil mantenimiento y bajo costo.

### 4. Diseño Electrónico del Sistema

**Componentes incluidos:**
- Arduino UNO R3
- Motor GM3 R48
- Encoder rotativo KY-040
- Pantalla OLED I2C 1.54"
- Módulo puente en H
- Diodo Schottky (protección)
- Switch ON/OFF

**Funcionamiento:**
- El usuario enciende el sistema.
- Selecciona un modo de masaje con el encoder.
- La pantalla OLED muestra el modo seleccionado.
- Arduino controla el encendido y velocidad del motor.
- El motor acciona el eje masajeador durante intervalos definidos.

### 5. Sustentación Técnica del Proyecto

Aunque nuestro dispositivo no existe como una patente idéntica, su funcionamiento se basa en principios fisiológicos ampliamente estudiados. La evidencia clínica demuestra que el masaje mejora la circulación, previene el estancamiento venoso y mejora la oxigenación local, factores claves en la prevención de LPP.

Además, existen tecnologías cercanas en función, como los cojines inflables dinámicos o colchones con redistribución de presión (ej. patente US20120078144A1), pero ninguna aplica una acción de masaje mecánico localizado con nodos rotatorios pequeños embebidos en un cojín como el nuestro. Esto evidencia la originalidad del diseño, pero también su base común con tecnologías ya probadas [4].

### 6. Factor Innovador

- Sistema embebido en cojín, adaptado a zonas críticas para LPP.
- Control digital programable por el usuario.
- Bajo costo, alta disponibilidad y aplicabilidad en contextos domiciliarios o rurales.

### 7. Conclusión

El dispositivo propuesto constituye una solución clínica válida, técnicamente factible y diferenciada de productos recreativos. Si bien no reemplaza al terapeuta humano, puede complementar cuidados en pacientes con movilidad severamente reducida, reduciendo el riesgo de lesiones por presión a través de estimulación mecánica suave, rítmica y localizada.

### 8. Consideraciones extra:

#### - Tipos de Masajes

Al existir 5 diferentes tipos de masajes básicos, nos basaremos unicamente en lo siguientes:

1. **Effleurage:** se define como golpes largos y deslizantes y presión suave. En la mayoria de casos, los terapeutas de masaje realizan dicha técnica con las palmas o pulgares abiertos mientras aplica un lubricante que prepara al cliente/paciente para alternar con otra técnica usada posteriormente donde se aplica mas presión. Entre sus beneficios encontramos que alivia la ansiedad, estrés, depresión, mejora la circulación, además en muchas ocasiones se ha implementado para tratar lesiones o dolor postoperatorio.[6]

2. **Petrisagge:** A diferencia del anterior, el terapeuta usará sus palmas, yemas de los dedos, nudillos y/o antebrazos para crear movimientos lentos y rítmicos asociados con amasar para rodar, retorcer, levantar y apretar, para trabajar los músculos y la fascia. Se destacan diferentes beneficios, entre ellos se sabe que puede ayudar a aumentar el flujo sanguíneo y linfático, acelera el proceso de curación de la rigidez muscular, descomprimir la espalda y/ó cuello para así liberar areas apretadas. [6]

#### - Presion aplicada

En effleurage, se utiliza presión de baja a moderada para promover la relajación, favoreciendo la circulación sanguínea sin causar incomodidad al paciente. Se enfatiza el deslizamiento sobre la piel sin ejercer presión significativa sobre los músculos subyacentes.[7]

En petrisagge, se utiliza presión de moderada a intensa, ya que se enfoca en manipular los músculos más profundos para liberar tensiones y mejorar la circulación. Se puede aplicar presión moderada en áreas más sensibles y presión fuerte en zonas musculares más gruesas.[7]

#### - Velocidad de rotación:

La velocidad de rotación de masaje debe de ser lenta y moderada al rededor de 20 y 30 revoluciones con un desplazamiento vertical estimado de 10-15mm. Estos valores impulsan el movimiento rítmico de técnicas el effleurage y son consistentes con estudios de masaje terapéutico  [5]

#### - Tiempo de duración de los masajes y número de sesiones recomendadas al día:

En el estudio de Chinnappan [3], el dispositivo VEPMAS fue aplicado durante 5–10 minutos, dos veces al día, y se observaron efectos positivos clínicamente significativos en la prevención de úlceras. Sin embargo, el estudio no evalúa la frecuencia como variable independiente. Es decir, no concluye que “dos veces al día” sea la frecuencia ideal o universal, solo que funcionó dentro de ese protocolo.

#### - Dimensiones del cojín:

Podemos partir con unas dimensiones para el cojín de: 40 × 40 cm con un grosor no mayor a 6–8 cm, estas por ser compatibles con sillas de ruedas estándar. Además estas dimensiones permiten cubrir la región glútea sin comprometer estabilidad ni movilidad del usuario.

#### - Material de recubrimiento:

**Papel que respalda el uso de espuma y/o piel de oveja:**

1. Las alternativas de espuma a los colchones hospitalarios estándar reducen la incidencia de úlceras por presión en personas en riesgo (RR 0,40; IC del 95 %: 0,21 a 0,74).  
2. Un metanálisis de tres ensayos sugiere que las cubiertas de piel de oveja médicas estándar australianas previenen las úlceras por presión (RR: 0,56; IC del 95 %: 0,32 a 0,97).  
3. Las personas con alto riesgo de desarrollar úlceras por presión deberían usar colchones de espuma de mayor especificación.  
4. Las pieles de oveja de grado médico se asocian con una disminución del desarrollo de úlceras por presión.  

*Seleccionamos espuma de mayor especificación por ser más económica y operativamente viable.*

https://pmc.ncbi.nlm.nih.gov/articles/PMC7075275/

**Material clínico para el forro externo:**
- Nylon recubierto de poliuretano médico stretch 4-way (tipo Dartex™, tipo Trelleborg Soft Skin).
- Sistema incluye un forro stretch, transpirable y permeable al vapor.

https://iqmedical.co.uk/wp-content/uploads/2020/starii/BJON_2017IQ%20medical%20JSH.pdf?utm_source=chatgpt.com

### Referencias (formato IEEE)

[1] P. D. Akyol and A. A. Yigit, "Evaluation of the Effect of Massage on Pressure Injury Prevention among Intensive Care Patients: A Randomized Controlled Study," *Journal of Tissue Viability*, vol. 34, 2025, pp. 75–81.  
https://doi.org/10.1016/j.jtv.2024.12.008

[2] R. N. Wiguna, I. H. Prasetya, and D. Sudiana, "The Effect of Effleurage Massage Using Canola Oil on the Risk of Pressure Ulcer in Stroke Patients," *Indonesian Journal of Global Health Research*, vol. 4, no. 2, Apr. 2025.  
https://www.researchgate.net/publication/392088822

[3] P. R. Chinnappan et al., "Effect of VEPMAS Device on Prevention of Pressure Ulcer Among Immobilized Patients," *Pondicherry Journal of Nursing*, vol. 14, no. 4, 2021.  
https://www.academia.edu/78955450

[4] US Patent US20120078144A1, "Air-powered cushion system for pressure ulcer prevention", 2012.  
https://patents.google.com/patent/US20120078144A1/en

[5] J. B. D. Trower and A. M. Hill, "Effect of massage on blood flow and skin temperature in elderly patients," *Physiotherapy*, vol. 101, no. 1, pp. 56–62, 2015.  
https://pubmed.ncbi.nlm.nih.gov/15114265/

[6] American Massage Therapy Association, "Basics of Massage Therapy," *Massage Therapy Journal*.  
https://www.amtamassage.org/publications/massage-therapy-journal/basics-of-massage-therapy/

[7] J. E. Kelley et al., “Massage therapy has short‑term benefits for people with common musculoskeletal conditions,” *Complementary Therapies in Clinical Practice*, vol. 21, pp. 7–14, 2015.  
https://www.sciencedirect.com/science/article/pii/S1836955315000582

