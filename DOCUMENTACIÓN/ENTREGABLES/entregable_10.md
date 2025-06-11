
# ENTREGABLE 10

## 1. Hardware electrónico y software

### Diagrama o esquema electrónico

![Captura de pantalla 2025-06-04 175522](https://github.com/user-attachments/assets/623f20d1-ba62-4664-855d-977b31c38a09)


#### Observaciones respecto al esquema electrónico

- Especificaciones típicas del motor vibratorio tipo COIN HD-EM1003-LW15-R:
  - Voltaje nominal: 3 V DC
  - Corriente en carga típica: 85–100 mA
  - Corriente de arranque (inrush): hasta 150–200 mA durante los primeros milisegundos

- Los transistores usados del tipo 2N2222:
  - Corriente máxima (IC máx.): 800 mA
  - Segura hasta: ~500 mA continuos (con disipación mínima)

- El transistor del tipo TIP120:
  - Corriente máxima (IC máx.): 5 A
  - Aplicación: Perfecto para manejar hasta 1 A o más sin problemas

- Fuente de alimentación:
  - Usaremos 2 pilas recargables 18650 lithium ion con capacidad de 3000 mAh.
  - Duración aproximada: hasta 96 minutos (5 o 6 sesiones antes de recargar).

- Diodos añadidos en las zonas 1 y 2:
  - Zona 1: 3 motores de vibración y un diodo 1N5819 para protección del transistor conectados en paralelo a los motores
  - Zona 2: 2 motores de vibración y un diodo 1N5819 para protección del transistor conectados en paralelo a los motores

### Ejecución del código Arduino con componentes físicos implementados

![Captura de pantalla 2025-06-11 000413](https://github.com/user-attachments/assets/32eb50c5-3912-4950-9040-0dca9243c0b2)

![Captura de pantalla 2025-06-11 000445](https://github.com/user-attachments/assets/99133250-6f4c-4a2c-b9e7-335f2ab267c5)

![Captura de pantalla 2025-06-11 000502](https://github.com/user-attachments/assets/df1e92b2-4c59-4123-8ad9-9bdb59e2e53a)

![Captura de pantalla 2025-06-11 000520](https://github.com/user-attachments/assets/63eb05d3-24c3-46ca-adee-29dfb0e39e75)

![Captura de pantalla 2025-06-11 000533](https://github.com/user-attachments/assets/f3e0f772-2d7c-48dc-bc4d-86c5f30621b5)


### Avance de prototipado electrónico

![WhatsApp Image 2025-06-10 at 22 44 14](https://github.com/user-attachments/assets/f26b9128-06ca-4a88-bccf-a538cc6e0b4c)

![WhatsApp Image 2025-06-10 at 22 44 15](https://github.com/user-attachments/assets/d5a8da5f-22cf-4e82-94c1-8202cf52536c)

![WhatsApp Image 2025-06-10 at 22 44 15 (1)](https://github.com/user-attachments/assets/0f571917-e52a-4575-8e68-94952d6ada6b)


## 2. Fabricación digital

![image](https://github.com/user-attachments/assets/e986832e-82e7-460a-aa4d-cb8441da6ebd)

![image](https://github.com/user-attachments/assets/7b3b6e1a-59aa-4c73-bdc8-c4fbc6c4a47d)

### Archivos STL

![image](https://github.com/user-attachments/assets/e1d8b983-b53c-42a5-8afd-01f0e0f1811c)

- Tiempo inicial de impresión: 1 día, 1 hora y 52 minutos

![image](https://github.com/user-attachments/assets/0f347efe-8a4a-4b54-929a-50dd2f96512d)

- Tiempo optimizado ajustando la velocidad de impresión y el uso de material: 15 horas con 28 minutos

![image](https://github.com/user-attachments/assets/d09aaef4-e718-483e-9ab3-f98311aa364e)


## 3. Plan de usabilidad basado en evidencias

### Contexto de uso

- El dispositivo es una manta portátil con motores de vibración distribuidos en tres zonas (glúteos, lumbar e isquiotibiales).
- El cuidador enciende el sistema y usa un encoder rotativo KY-040 para seleccionar cada zona.
- Cada zona proporciona 12 minutos de estimulación vibrotáctil, tres veces al día.
- Diseñado para uso doméstico o espacios cómodos (cama o sillón), portátil y plegable.

#### Tipo de usuario

- **Paciente:** Persona con cuadriplejia que requiere estimulación para prevenir úlceras por presión.
- **Cuidador:** Persona encargada de operar el dispositivo. No requiere experiencia técnica.

#### Condiciones del entorno

- Entornos no clínicos (hogar).
- Adaptable a camas, sillones o sillas de ruedas.
- Formato plegable facilita transporte y almacenamiento.

#### Frecuencia de uso

- Tres veces al día.
- Cada sesión: 3 zonas de 12 minutos = 36 minutos.

### Perfil del usuario

#### Físicas

- Movilidad muy limitada.
- No puede manipular la manta por sí mismo.
- Riesgo de úlceras por presión.

#### Cognitivas

- Funciones cognitivas conservadas o levemente afectadas.

#### Emocionales

- Puede experimentar frustración o ansiedad.
- Se beneficia emocionalmente de la rutina de cuidado.

#### Caso seleccionado

- Mujer con cuadriplejia bajo cuidado permanente de un familiar.
- Sin limitaciones visuales o cognitivas.
- Permanece acostada o sentada por largos periodos.
- Cuidador adulto sin formación técnica usa el dispositivo.

### Análisis de tareas

#### Tareas

1. Colocar la manta correctamente.
2. Presionar botón de encendido.
3. Seleccionar zona con encoder.
4. Activar vibración en cada zona secuencialmente.
5. Apagar el sistema al finalizar.
6. Retirar la manta si es necesario.

#### Riesgos

- Colocación incorrecta: estimulación ineficaz, incomodidad.
- Encoder mal usado: omisión de zona.
- Sobreestimulación: irritación o incomodidad.
- Manta encendida sin supervisión: riesgo acumulativo.

#### Tabla de tareas críticas

| Tarea | ¿Es crítica? | Riesgo |
| --- | --- | --- |
| Colocar la manta | Sí | Estimulación incorrecta |
| Encender dispositivo | No | Sin riesgo directo |
| Seleccionar zona con encoder | Sí | Omisión de zona crítica |
| Activar zona | No | Puede interrumpir secuencia |
| No respetar los 12 minutos | Sí | Sobreestimulación |
| Apagar sistema | No | Consumo innecesario de energía |

### Criterios de éxito

- **Eficacia:** Completar rutina completa.
- **Eficiencia:** Total ~40 min por sesión (incluyendo colocación).
- **Satisfacción:** Fácil de usar, cómodo, útil.

#### Métricas

| Métrica | Objetivo |
| --- | --- |
| Tiempo de colocación | ≤ 2 min |
| Duración por zona | 12 min |
| Frecuencia vibración | 70 Hz |
| Ciclo vibración activa | 5 seg |
| Errores de selección | 0 |
| Zonas completadas | 3 |
| Satisfacción cuidador | ≥ 4 (escala 1-5) |
| Lesiones causadas | 0 |
| Desplazamiento de manta | 0 |
| Tiempo total de sesión | ≤ 40 min |
| Fallos técnicos semanales | ≤ 1 |

## Bibliografía

- Haba, D. et al. (2024). Effectiveness of vibration therapy for hard‑to‑heal wounds... [https://doi.org/10.2147/CWCMR.S423054](https://doi.org/10.2147/CWCMR.S423054)
- Seim, C. E. et al. (2022). Design of a wearable vibrotactile stimulation device... [https://doi.org/10.1109/TNSRE.2022.3174808](https://doi.org/10.1109/TNSRE.2022.3174808)
- Ebineshan K, et al. (2025). Global transcriptomic profile of biofilm producing... [https://pmc.ncbi.nlm.nih.gov/articles/PMC12053402/](https://pmc.ncbi.nlm.nih.gov/articles/PMC12053402/)
