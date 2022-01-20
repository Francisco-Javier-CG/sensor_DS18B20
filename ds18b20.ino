//20-Enero-2022

// las constantes no cambiarán: Se utiliza aquí para establecer un número pin:
const int ledPin =  LED_BUILTIN;			// el número del pin LED

// Las variables cambiarán:
int ledState = LOW;             			// ledState utilizado para configurar el LED

// En general, debe usar "unsigned long" para las variables que mantienen el tiempo
// El valor rápidamente se volverá demasiado grande para que un int lo almacene
unsigned long previousMillis = 0;     // almacenará la última vez que se actualizó el LED

// las constantes no cambiarán:
const long interval = 1000;           // intervalo en el cual parpadea (milisegundos)

void setup() {
  // establece el pin digital como salida:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // aquí es donde colocaría el código que debe ejecutarse todo el tiempo.

	// verifique si es hora de hacer parpadear el LED; es decir, si la diferencia
  // entre la hora actual y la última vez que parpadeó, el LED es más grande que
  // el intervalo en el que desea que parpadee el LED.
	
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // guarda la última vez que parpadeó el LED
    previousMillis = currentMillis;

    // si el led esta apagado encenderlo y viceversa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // configure el LED con el ledState de la variable:
    digitalWrite(ledPin, ledState);
  }
	
// determinar presencia 
int presencia(byte pin){
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	delayMicroseconds(480); 		// Esperar 480us
	pinMode(pin, INPUT);
	delayMicroseconds(70); 		// Esperar 70us
	int valor = 0;
	valor = digitalRead(pin);	//leer el pin
	delayMicroseconds(410); 		// esperar 410us
	return valor;
}
void sec_Inicializacion(byte pin){
	if(presencia(pin) == 1){
		Serial.print(" Sin dispositivo! ");
	}
	else{
		Serial.print(" Dispositivo funcionando! "
	}
	//Serial.println(contador);
}

void escribir_Bit(int pin, int bit){
	int slot_i,slot_f;
	if(bit == 1){
		slot_i = 6;
		slot_f = 64;
	}else{
		slot_i = 80;
		slot_f = 10;
	}
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	delayMicroseconds(slot_i); 		// Esperar
	pinMode(pin, INPUT);
	delayMicroseconds(slot_f); 		// Esperar
}
// para un solo dispositivo
void omitir_ROM(){
	
}
