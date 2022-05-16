# Tesina_C (OBSOLETO)
Ahora en lenguaje C y usando el compilador 8XC de MATLAB X, implementamos por primera vez el rastreador de archivos GIT.
En el proceso de aprender estas herramientas creamos ramas confusas y *commit messages* inadecuados; opté por crear un nuevo repositorio en donde la progresión y los cambios de nuestro programa sean más consisos y se vean más limpios.
[ver repositorio actual](https://github.com/ewardq/Sistema_lider-seguidor)

PIC16F886

Se creó una librería (8XC) que permite usar:
- Sensor ultrasónico Hc-sr04 
- Servomotor, sin hacer uso del módulo PWM del uC
- Transmisor y receptor RF433 Mhz, haciendo uso de la transmisión EUSART del uC
- Tres puentes H, dos para las ruedas traseras (tracción) y uno para el direccionamiento de las delanteras
- Lectura de dos *quadrature encoders* (se duplicó su resolución en hardware a cambio de no poder saber en qué dirección giran las ruedas)

## Hardware
![Esquematico-1](https://user-images.githubusercontent.com/72580785/167339715-a51acf8f-584f-4c0b-9230-e884501456bf.jpg)
