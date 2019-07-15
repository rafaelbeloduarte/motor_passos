int intervalo = 1, passo = 127;
int i = 0;
float aumenta, diminui, n_voltas, j;
int pino1 = 3, pino2 = 9, pino3 = 10, pino4 = 11;

void setup() {
  Serial.begin(9600);
}
//512?
void loop() {
  while (Serial.available() == 0) {
    Serial.println("Passo,n_voltas?");
    passo = Serial.parseInt();
    n_voltas = Serial.parseInt();
    Serial.println(passo);
    Serial.println(n_voltas);
  }
  //  aceleração
  if (i == 0) {
    for (int m = 1; m <= 512; m++) {
      analogWrite(pino1, 255);
      analogWrite(pino2, 0);
      delay(1);

      analogWrite(pino1, 255);
      analogWrite(pino2, 255);
      delay(1);

      analogWrite(pino1, 0);
      analogWrite(pino2, 255);
      delay(1);

      analogWrite(pino2, 255);
      analogWrite(pino3, 0);
      delay(1);

      analogWrite(pino2, 255);
      analogWrite(pino3, 255);
      delay(1);

      analogWrite(pino2, 0);
      analogWrite(pino3, 255);
      delay(1);

      analogWrite(pino3, 255);
      analogWrite(pino4, 0);
      delay(1);

      analogWrite(pino3, 255);
      analogWrite(pino4, 255);
      delay(1);

      analogWrite(pino3, 0);
      analogWrite(pino4, 255);
      delay(1);

      analogWrite(pino4, 255);
      analogWrite(pino1, 0);
      delay(1);

      analogWrite(pino4, 255);
      analogWrite(pino1, 255);
      delay(1);

      analogWrite(pino4, 0);
      analogWrite(pino1, 255);
      delay(1);
    }
  }
  i = 1;
  j = (n_voltas) * 550;
  Serial.println(j);
  for (int k; k < j; k++) {
    //    Serial.println(k);
    //------3cte-9aumenta---------------------
    analogWrite(pino1, 255);
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      Serial.println(aumenta);
      analogWrite(pino2, aumenta);
      delay(intervalo);
    }
    analogWrite(pino2, 255);
    //----------------------------------------

    //------3diminui-9cte---------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      Serial.println(diminui);
      analogWrite(pino1, diminui);
      delay(intervalo);
    }
    analogWrite(pino1, 0);
    //----------------------------------------

    //------9cte-10aumenta--------------------
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      analogWrite(pino3, aumenta);
      delay(intervalo);
    }
    analogWrite(pino3, 255);
    //----------------------------------------

    //------10cte-9diminui--------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      analogWrite(pino2, diminui);
      delay(intervalo);
    }
    analogWrite(pino2, 0);
    //----------------------------------------

    //------10cte-11aumenta-------------------
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      analogWrite(pino4, aumenta);
      delay(intervalo);
    }
    analogWrite(pino4, 255);
    //----------------------------------------

    //------11cte-10diminui-------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      analogWrite(pino3, diminui);
      delay(intervalo);
    }
    analogWrite(pino3, 0);
    //----------------------------------------

    //------11cte-3aumenta--------------------
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      analogWrite(pino1, aumenta);
      delay(intervalo);
    }
    analogWrite(pino1, 255);
    //----------------------------------------


    //-----3cte-11diminui---------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      analogWrite(pino4, diminui);
      delay(intervalo);
    }
    analogWrite(pino4, 0);
    //----------------------------------------
  }
}
