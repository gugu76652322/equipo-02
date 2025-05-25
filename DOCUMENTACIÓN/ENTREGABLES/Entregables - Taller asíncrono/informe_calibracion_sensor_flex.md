# Informe de Calibración y Rango Obtenido

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