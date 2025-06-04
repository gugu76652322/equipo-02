# Entregable 9

## Diseño o esquema electrónico del concepto de solución

![Captura de pantalla 2025-06-03 232539](https://github.com/user-attachments/assets/31612d1e-2255-4341-97b8-e84215b2067c)

---

## Plan de usabilidad basado en evidencias

### Paper 1

**Título:** Vibration Accelerates Healing of Stage I Pressure Ulcers in Older Adult Patients  
**Producto:** Dispositivo médico - Vibrador (modelo RelaWave, Matsuda Micronics Corp, Japón)  
**Usuarios:** Adultos mayores (>65 años) en cuidados a largo plazo con úlceras por presión estadio I  

**Métodos:**
- Ensayo clínico controlado, no aleatorizado y con evaluación ciega
- Vibración localizada: 47 Hz, 15 min, 3 veces/día, máx. 7 días
- Grupo experimental: 16 pacientes (20 úlceras)
- Grupo control: 15 pacientes (21 úlceras)

**Criterios de éxito:**
- Curación total (desaparición del eritema)
- Reducción del área de herida y enrojecimiento

**Evidencia:**
- Curación: experimental 40%, control 9.5% (p = 0.033)
- Reducción del área (p = 0.007)
- Disminución del enrojecimiento (p = 0.023)

**Lecciones:**
- Vibración acelera curación
- 47 Hz / 15 min x3/día efectivo y cómodo
- Puede integrarse con cuidados estándar
- Diseño adaptable según ubicación de la úlcera

---

### Paper 2

**Título:** Estimulación eléctrica en el tratamiento de la úlcera por presión  
**Producto:** Dispositivo de estimulación eléctrica cutánea  
**Usuarios:** Personas con movilidad reducida (ej. cuadriplejia)

**Métodos:**
- Estudio de caso clínico (úlcera occipital)
- Evaluación progresiva del tejido

**Criterios de éxito:**
- Mejora visible
- Reducción de tamaño/profundidad
- Regeneración del tejido

**Lecciones:**
- Aplicable a glúteos/isquiones
- Compatible con mantas/cojines con estímulo programado
- Intervalos programados (10-15 min) mejoran oxigenación
- Económico, portátil, práctico

---

### Paper 3

**Título:** Optimizing the Design of a Lateral Oscillating Device for Pressure Ulcer Prevention  
**Producto:** Cojín/colchón oscilante para redistribución de presión  
**Usuarios:** Pacientes inmovilizados

**Métodos:**
- Estudio cuasi-experimental (25 voluntarios sanos)
- Medición de presión en sacro y trocánteres
- Variables: edad, sexo, IMC → 60% variabilidad

**Criterios de éxito:**
- Identificación de picos de presión
- Oscilación adaptada por edad/peso/género
- Sin efectos adversos

**Lecciones:**
- Personalización por usuario
- Vibración localizada efectiva
- Estímulos por intervalos no invasivos

---

## Modelado en 3D de componentes electrónicos

- Pantalla OLED I2C de 1.54''

  ![image](https://github.com/user-attachments/assets/be7293a3-cff2-4998-b399-3829987a416c)

- Arduino UNO R3

  ![image](https://github.com/user-attachments/assets/72b9a054-135a-45e0-9739-c1d3bbf8dca2)

- Motor Vibrador tipo COIN HD-EM1003-LW15-R

  ![image](https://github.com/user-attachments/assets/0b33c46a-a38c-4c17-b248-f37d7d0b2b78)

- Soporte de baterías

  ![image](https://github.com/user-attachments/assets/58088e6d-8d9b-4579-8c72-09021036bbd0)

- Encoder rotativo KY-040

  ![image](https://github.com/user-attachments/assets/af83c6d3-a745-4eaa-b193-c3735f0a78a9)

- Switch ON/OFF

  ![image](https://github.com/user-attachments/assets/3d6d7465-36ab-497c-b2fe-7ce0e1b802c6)

- Diodo Schottky

  ![image](https://github.com/user-attachments/assets/08a92049-daa7-4594-9ae8-ae3d9d9d2c67)

- Resistor 1K Ohm

  ![image](https://github.com/user-attachments/assets/73b4049a-63e1-4b45-a4cc-9c389de2694e)

- Transistor TIP120

  ![image](https://github.com/user-attachments/assets/32f03cc0-192a-437d-950a-12cf1f809c1c)

- Transistor 2N2222

  ![image](https://github.com/user-attachments/assets/d83747b7-e9fd-4f3f-8745-c80cd6cc441f)


🔗 [Ver piezas en OnShape](https://cad.onshape.com/documents/a2ab5cac928358b294b8e734/w/1b63dac98f2b4d9a44575ce3/e/93f64a861063b6d3c5daa7a0?renderMode=0&uiState=683fcbf0890e3e5bb443480a)

---

## Fuentes bibliográficas

[1] Arashi M et al. "Vibration therapy accelerates healing of Stage I pressure ulcers..."  
https://pubmed.ncbi.nlm.nih.gov/20562541/

[2] Rizo-García, A. et al. "Estimulación eléctrica en el tratamiento de la úlcera por presión"  
http://scielo.sld.cu/scielo.php?script=sci_arttext&pid=S1682-00372020000300011

[3] "Optimizing the Design of a Lateral Oscillating Device for Pressure Ulcer Prevention"  
https://pubmed.ncbi.nlm.nih.gov/39800635/
