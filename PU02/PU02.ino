void setup() {
  // put your setup code here, to run once:
  unsigned int result = 0;
  int t = 0;
  //************INCREMENTO Y DECREMENTO DE BIT***********
  int count = 0;
  Serial.begin(9600);
  Serial.println(count);
  count++;
  Serial.println(count);
  count++;
  Serial.println(count);
  count++;
  Serial.println(count);
  DDRD = 255; //se declara todo el puerto como salida
  Serial.begin(9600) ; // Inicializa el Puerto serie con 9600 bits/s.
  DDRD = DDRD | B11111100;   // selecciona la dirección de los bit 2 a 7, deja 0 y 1 sin tocar (xx | 00 == xx)
  // igual que pinMode(pin, OUTPUT) para los pines 2 a 7
}

void loop() {
  // put your main code here, to run repeatedly:
  //*************CONTADOR BINARIO**************
  for (int i = 0; i < 32 ; i++)
  { int valor = digitalPinToInterrupt(i) ;
    PORTD = valor; //el puerto D tomara el numero que contenga "1" y encenderá los LEDs con el
    //numero correspondiente
    delay(1000); // espera 1s entre cada numero
  }
  //*************CORRIMIENTO DE BIT DE IZQUIERDA A DERECHA***************
  int a = 40;     // Binario: 0000000000101000, o 40 en decimal
  int b = a >> 3; // Binario: 0000000000000101, o de nuevo a 5 como empezamos
  int c = -16;         // Binario: 1111111111110000
  int y = 3;
  int result = c >> y; // Binario: 1111111111111110
  int z = -16;                       // Binario: 1111111111110000
  int t = 3;
  result = z >> t; // Binario: 0001111111111110
  int x = 1000;
  t = 1 >> 3; // División entera de 1000 por 8, haciendo que y = 125., haciendo que y = 125.
  //************CORRIMIENTO PAR-IMPAR*************************
  int i = 23 ; // Esto es una variable definida como entero que tiene como valor 23
  if ( i % 2 == 0) { // La condición que hemos impuesto
    Serial.println("Es par") ; // Si se cumple la condición se ejecuta el mensaje.
    delay(1000); // Espera 1 segundo a volver a ejecutar.
  }
  else {
    Serial.println("Es impar"); // Si no se cumple la condición se ejecuta el mensaje.
    delay(1000); // Espera 1 segundo a volver a ejecutar.
  }
  //************************BASCULACION DE BIT****************
  for (i = 0; i < 64; i++) {

    PORTD = PORTD & B00000011;    // borra los bits 2 - 7, ldeja los pines 0 y 1 sin tocar (xx & 11 == xx)
    int   j = (i << 2);     // desplaza los pines 2 - 7 de la variable - para eludir los pines 0 y 1
    PORTD = PORTD | j;    // combina la información de los puertos con la nueva información para los pines LED
    Serial.println(PORTD, BIN); // debug to show masking
    delay(100);
  }

}
