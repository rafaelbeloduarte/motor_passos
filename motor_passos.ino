int intervalo = 1;
int i = 0;
int aumenta, diminui;
int velocidade, n;

void setup() {
  Serial.begin(115200);
  /*  pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);*/
}

void loop() {
  while (Serial.available() == 0) {
    n = Serial.parseInt();
    if (n > 0) {
      velocidade = n*2.55;
    }
  }
  //  Serial.println(velocidade);
  //aceleração
  if (i == 0) {
    for (int j = 0; j != 100; j++) {
      analogWrite(6, 255);
      analogWrite(9, 0);
      delay(intervalo);

      analogWrite(6, 255);
      analogWrite(9, 255);
      delay(intervalo);

      analogWrite(6, 0);
      analogWrite(9, 255);
      delay(intervalo);

      analogWrite(9, 255);
      analogWrite(10, 0);
      delay(intervalo);

      analogWrite(9, 255);
      analogWrite(10, 255);
      delay(intervalo);

      analogWrite(9, 0);
      analogWrite(10, 255);
      delay(intervalo);

      analogWrite(10, 255);
      analogWrite(11, 0);
      delay(intervalo);

      analogWrite(10, 255);
      analogWrite(11, 255);
      delay(intervalo);

      analogWrite(10, 0);
      analogWrite(11, 255);
      delay(intervalo);

      analogWrite(11, 255);
      analogWrite(6, 0);
      delay(intervalo);

      analogWrite(11, 255);
      analogWrite(6, 255);
      delay(intervalo);

      analogWrite(11, 0);
      analogWrite(6, 255);
      delay(intervalo);
      Serial.println(j);
    }
  }
  i = 1;

  aumenta = 0;
  diminui = 255;
  analogWrite(6, 255);
  analogWrite(9, 0);
  while (aumenta < 255 or diminui > 0) {
    if ((aumenta) >= 255 or (aumenta + velocidade) >= 255) {
      aumenta = 255;
    }
    if ((diminui) <= 0 or (diminui - velocidade) <= 0) {
      diminui = 0;
    }
    
    Serial.print(diminui);
    Serial.print("  ");
    Serial.println(aumenta);
    analogWrite(6, diminui);
    analogWrite(9, aumenta);
    delay(intervalo);
    diminui = diminui - velocidade;
    aumenta = aumenta + velocidade;
  }

  aumenta = 0;
  diminui = 255;
  analogWrite(6, 0);
  analogWrite(9, 255);
  analogWrite(10, 0);
  while (aumenta < 255 or diminui > 0) {
    if ((aumenta) >= 255) {
      aumenta = 255;
    }
    if ((diminui) <= 0) {
      diminui = 0;
    }
    analogWrite(9, diminui);
    analogWrite(10, aumenta);
    delay(intervalo);
    diminui = diminui - velocidade;
    aumenta = aumenta + velocidade;
    //    Serial.println("teste");
  }

  aumenta = 0;
  diminui = 255;
  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 0);
  while (aumenta < 255 or diminui > 0) {
    if ((aumenta) >= 255) {
      aumenta = 255;
    }
    if ((diminui) <= 0) {
      diminui = 0;
    }
    analogWrite(10, diminui);
    analogWrite(11, aumenta);
    delay(intervalo);
    diminui = diminui - velocidade;
    aumenta = aumenta + velocidade;
  }

  aumenta = 0;
  diminui = 255;
  analogWrite(10, 0);
  analogWrite(11, 255);
  analogWrite(6, 0);
  while (aumenta < 255 or diminui > 0) {
    if ((aumenta) >= 255) {
      aumenta = 255;
    }
    if ((diminui) <= 0) {
      diminui = 0;
    }
    analogWrite(11, diminui);
    analogWrite(6, aumenta);
    delay(intervalo);
    diminui = diminui - velocidade;
    aumenta = aumenta + velocidade;
  }

}
