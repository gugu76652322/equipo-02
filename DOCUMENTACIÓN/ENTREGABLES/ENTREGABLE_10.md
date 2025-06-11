
# ENTREGABLE 10

## 1. Hardware electrónico y software

### Diagrama o esquema electrónico

**Observaciones sobre el esquema:**

- **Motor COIN HD-EM1003-LW15-R**  
  - Voltaje nominal: 3 V DC  
  - Corriente típica en carga: 85–100 mA  
  - Corriente de arranque: hasta 150–200 mA  

- **Transistores:**  
  - 2N2222: IC máx. 800 mA (uso seguro hasta ~500 mA)  
  - TIP120: IC máx. 5 A (recomendado hasta 1 A o más)  

- **Fuente de alimentación:**  
  - 2 baterías 18650 (3000 mAh), duración: ~96 min (~5-6 sesiones)  

- **Diodos 1N5819**  
  - Zona 1: 3 motores + 1 diodo  
  - Zona 2: 2 motores + 1 diodo  

### Código Arduino y prototipo electrónico

(Ejecutado con los componentes físicos implementados)

---

## 2. Fabricación digital

- **Archivos STL generados**
- **Tiempo inicial de impresión:** 1 día, 1 hora y 52 minutos
- **Optimización:** 15 horas y 28 minutos con nuevos parámetros

---

## 3. Plan de usabilidad basado en evidencias

### Contexto de uso

- **Dispositivo:** Manta portátil con vibración en tres zonas (glúteos, lumbar, isquiotibiales)
- **Activación:** Interruptor + encoder rotativo KY-040
- **Ciclo:** 3 veces al día, 3 zonas por sesión (12 min cada una)

**Usuarios:**
- Paciente cuadripléjico
- Cuidador sin experiencia técnica

**Entorno:**
- Uso en hogar, cama, sillón, silla de ruedas
- Manta plegable y portátil

---

### Perfil del usuario

- **Físico:** Movilidad muy limitada, riesgo de escaras
- **Cognitivo:** Conservado o levemente afectado
- **Emocional:** Posible frustración o ansiedad, beneficios emocionales de rutina confiable

**Paciente:**
- Mujer con cuadriplejia, movilidad completamente reducida
- Puede comunicarse verbalmente

**Cuidador:**
- Familiar sin formación técnica
- Realiza colocación y operación del sistema

---

### Análisis de tareas

**Pasos críticos:**
1. Colocar correctamente la manta
2. Encender dispositivo
3. Seleccionar zona con encoder
4. Activar zona
5. Respetar tiempo por zona
6. Apagar sistema
7. Retirar manta si es necesario

**Errores posibles y riesgos:**
- Mala colocación → estimulación incorrecta o incomodidad
- Zona incorrecta seleccionada
- Vibración excesiva (>12 min)
- Cables doblados → daño
- Dejar manta sin supervisión

---

### Criterios de éxito

#### Eficacia
- Vibración en 3 zonas en orden correcto
- Manta colocada correctamente
- Encendido/apagado correcto

#### Eficiencia
- Tiempo total ≤ 40 min (uso + configuración)
- Colocación inicial ≤ 2 min

#### Satisfacción
- Facilidad de uso, comodidad, claridad
- Valoración ≥ 4/5 en encuestas

---

### Métricas clave

| Métrica                         | Valor Objetivo | Descripción                                                  |
|-------------------------------|----------------|--------------------------------------------------------------|
| Tiempo de colocación          | ≤ 2 min        | Tiempo para alinear y fijar la manta                         |
| Duración por zona             | = 12 min       | Tiempo de vibración por zona                                 |
| Frecuencia de vibración       | = 70 Hz        | Estímulo constante                                           |
| Amplitud de vibración         | = 5 seg        | Tiempo de cada pulso vibratorio                              |
| Errores en selección de zona  | = 0            | Máxima precisión esperada                                    |
| Zonas completadas por sesión  | = 3            | Todas las zonas deben ser estimuladas en una sesión          |
| Satisfacción del cuidador     | ≥ 4            | Encuesta de satisfacción tipo Likert (1 a 5)                 |
| Lesiones causadas             | = 0            | Sin marcas ni heridas posteriores                            |
| Desplazamiento de la manta    | = 0            | Debe permanecer en su sitio                                  |
| Tiempo total de sesión        | ≤ 40 min       | Incluye vibración y transiciones                             |
| Fallos del sistema por semana | ≤ 1            | Tolerancia máxima a errores técnicos                         |

---

## Bibliografía

- Haba, D. et al. (2024). *Effectiveness of vibration therapy...*  
  https://doi.org/10.2147/CWCMR.S423054

- Seim, C. E. et al. (2022). *Design of a wearable vibrotactile stimulation device...*  
  https://doi.org/10.1109/TNSRE.2022.3174808

- Ebineshan K. et al. (2025). *Insights into global transcriptomic profile...*  
  https://pmc.ncbi.nlm.nih.gov/articles/PMC12053402/
