int intervalo = 1, passo = 127;
int i = 0;
float aumenta, diminui, n_voltas, j;
int para = 0;

void setup() {
  Serial.begin(9600);
}
//512?
void loop() {
  //  while (para == 0) {
  //    para = Serial.parseInt();
  //  }
  //  para = 0;
  while (Serial.available() == 0) {
    Serial.println("Passo,n_voltas?");
    passo = Serial.parseInt();
    n_voltas = Serial.parseInt();
    Serial.println(passo);
    Serial.println(n_voltas);
  }
  //aceleração
  if (i == 0) {
    for (int m = 1; m <= 512; m++) {
      analogWrite(6, 255);
      analogWrite(9, 0);
      delay(1);

      analogWrite(6, 255);
      analogWrite(9, 255);
      delay(1);

      analogWrite(6, 0);
      analogWrite(9, 255);
      delay(1);

      analogWrite(9, 255);
      analogWrite(10, 0);
      delay(1);

      analogWrite(9, 255);
      analogWrite(10, 255);
      delay(1);

      analogWrite(9, 0);
      analogWrite(10, 255);
      delay(1);

      analogWrite(10, 255);
      analogWrite(11, 0);
      delay(1);

      analogWrite(10, 255);
      analogWrite(11, 255);
      delay(1);

      analogWrite(10, 0);
      analogWrite(11, 255);
      delay(1);

      analogWrite(11, 255);
      analogWrite(6, 0);
      delay(1);

      analogWrite(11, 255);
      analogWrite(6, 255);
      delay(1);

      analogWrite(11, 0);
      analogWrite(6, 255);
      delay(1);
    }
  }
  i = 1;
  j = (n_voltas - 1) * 512;
  Serial.println(j);
  for (int k; k <= j; k++) {
    //    Serial.println(k);
    //------6cte-9aumenta---------------------
    analogWrite(6, 255);
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      //      Serial.println(aumenta);
      analogWrite(9, aumenta);
      delay(intervalo);
    }
    analogWrite(9, 255);
    //----------------------------------------

    //------6diminui-9cte---------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      Serial.println(diminui);
      analogWrite(6, diminui);
      delay(intervalo);
    }
    analogWrite(6, 0);
    //----------------------------------------

    //------9cte-10aumenta--------------------
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      analogWrite(10, aumenta);
      delay(intervalo);
    }
    analogWrite(10, 255);
    //----------------------------------------

    //------10cte-9diminui--------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      analogWrite(9, diminui);
      delay(intervalo);
    }
    analogWrite(9, 0);
    //----------------------------------------

    //------10cte-11aumenta-------------------
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      analogWrite(11, aumenta);
      delay(intervalo);
    }
    analogWrite(11, 255);
    //----------------------------------------

    //------11cte-10diminui-------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      analogWrite(10, diminui);
      delay(intervalo);
    }
    analogWrite(10, 0);
    //----------------------------------------

    //------11cte-6aumenta--------------------
    for (aumenta = 0; aumenta <= 255; aumenta = aumenta + passo) {
      analogWrite(6, aumenta);
      delay(intervalo);
    }
    analogWrite(6, 255);
    //----------------------------------------


    //-----6cte-11diminui---------------------
    for (diminui = 255; diminui >= 0; diminui = diminui - passo) {
      analogWrite(11, diminui);
      delay(intervalo);
    }
    analogWrite(11, 0);
    //----------------------------------------
  }
}
