int intervalo = 1;
int i = 0;
int aumenta, diminui;
int passo = 127;

void setup() {
  Serial.begin(115200);
  /*  pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);*/
}

void loop() {
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
    if ((aumenta + passo) > 255) {
      aumenta = 255;
    }
    if ((diminui - passo) < 0) {
      diminui = 0;
    }
    Serial.print(diminui);
    Serial.print("  ");
    Serial.println(aumenta);
    analogWrite(6, diminui);
    analogWrite(9, aumenta);
    delay(intervalo);
    diminui = diminui - passo;
    aumenta = aumenta + passo;
  }

  aumenta = 0;
  diminui = 255;
  analogWrite(6, 0);
  analogWrite(9, 255);
  analogWrite(10, 0);
  while (aumenta < 255 or diminui > 0) {
    if ((aumenta + passo) > 255) {
      aumenta = 255;
    }
    if ((diminui - passo) < 0) {
      diminui = 0;
    }
    analogWrite(9, diminui);
    analogWrite(10, aumenta);
    delay(intervalo);
    diminui = diminui - passo;
    aumenta = aumenta + passo;
    Serial.println("teste");
  }

  aumenta = 0;
  diminui = 255;
  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 0);
  while (aumenta < 255 or diminui > 0) {
    if ((aumenta + passo) > 255) {
      aumenta = 255;
    }
    if ((diminui - passo) < 0) {
      diminui = 0;
    }
    analogWrite(10, diminui);
    analogWrite(11, aumenta);
    delay(intervalo);
    diminui = diminui - passo;
    aumenta = aumenta + passo;
  }

  aumenta = 0;
  diminui = 255;
  analogWrite(10, 0);
  analogWrite(11, 255);
  analogWrite(8, 0);
  while (aumenta < 255 or diminui > 0) {
    if ((aumenta + passo) > 255) {
      aumenta = 255;
    }
    if ((diminui - passo) < 0) {
      diminui = 0;
    }
    analogWrite(11, diminui);
    analogWrite(8, aumenta);
    delay(intervalo);
    diminui = diminui - passo;
    aumenta = aumenta + passo;
  }

}
