#define delay50 100

int myled[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int num_of_leds;

void setup() {
  num_of_leds = sizeof(myled) / sizeof(int);
  for (int i = 0; i < num_of_leds; i++) {
    pinMode(myled[i], OUTPUT);
  }
}

void loop() {
  delay(1000);
  ledonn();
  delay(1000);
  ledoff();
  delay(1000);
  for (int i = 0; i < 2; i++){pattern1();}
  for (int i = 0; i < 2; i++){pattern2();}
  for (int i = 0; i < 2; i++){pattern3();}
  for (int i = 0; i < 2; i++){pattern4();}
  for (int i = 0; i < 2; i++){pattern5();}
  for (int i = 0; i < 2; i++){pattern6();}
  for (int i = 0; i < 2; i++){pattern7();}
  for (int i = 0; i < 20; i++){pattern8();}
  for (int i = 0; i < 2; i++) {pattern9();}
  for (int i = 0; i < 3; i++){pattern10();}
  for (int i = 0; i < 3; i++){pattern11();}
  for (int i = 0; i < 2; i++){pattern12();}
  for (int i = 0; i < 2; i++){pattern13();}
  for (int i = 0; i < 20; i++){pattern14();}
  for (int i = 0; i < 40; i++){pattern15();}
  for (int i = 0; i < 7; i++){pattern16();}
  ledoff();
  delay(5000);
}

//PRENDER TODOS LOS LEDs
void ledonn() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
  }
}

//APAGAR TODOS LOS LEDs
void ledoff() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
  }
}

//IZQUIERDA A DERECHA
void pattern1() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
  }
}

//DERECHA A IZQUIERDA
void pattern2() {
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
    digitalWrite(myled[i - 1], LOW);
  }
}

//IZQUIERDA A DERECHA LLENO
void pattern3() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], LOW);
    delay(delay50);
  }
}

//DERECHA A IZQUIERDA LLENO
void pattern4() {
  ledonn();
  delay(delay50);
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
    delay(delay50);
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
  }
  ledoff();
}

//DE A UNO
void pattern5() {
  ledoff();
  for(int i = num_of_leds; i > 0; i--) {
    for (int j = 0; j < num_of_leds; j++) {
      if(j<(i)) {
        digitalWrite(myled[j], HIGH);
        delay(delay50);
        digitalWrite(myled[j], LOW);
      }
    }
    digitalWrite(myled[i-1], HIGH);
  }
  ledoff();
  delay(500);
}

//TRIANGULO VUELVE
void pattern6() {
  for (int i = 0; i < (num_of_leds/2); i++) {
      digitalWrite(myled[(num_of_leds/2)+i], HIGH);
      digitalWrite(myled[(num_of_leds/2)-1-i], HIGH);
      delay(delay50);
    }
    for (int i = 0; i < (num_of_leds/2); i++) {
      digitalWrite(myled[num_of_leds-1-i], LOW);
      digitalWrite(myled[i], LOW);
      delay(delay50);
    }
}

//TRIANGULO
void pattern7() {
    for (int i = 0; i < (num_of_leds/2); i++) {
      digitalWrite(myled[(num_of_leds/2)+i], HIGH);
      digitalWrite(myled[(num_of_leds/2)-1-i], HIGH);
      delay(delay50);
    }
    for (int i = 0; i < (num_of_leds/2); i++) {
      digitalWrite(myled[(num_of_leds/2)+i], LOW);
      digitalWrite(myled[(num_of_leds/2)-1-i], LOW);
      delay(delay50);
    }
}

//LEDs ALTERNADOS
void pattern8() {
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i + 1], LOW);
  }
  delay(delay50);
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[i + 1], HIGH);
  }
  delay(delay50);
}

//LEDs OSCILANDO
void pattern9() {   //osc
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
  }
  delay(delay50);
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
    digitalWrite(myled[i - 1], LOW);
  }
}

//ADENTRO
void pattern10() {
  for (int i = 0; i < num_of_leds / 2; i++) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
  }
}

//AFUERA
void pattern11() 
{
  for (int i = (num_of_leds / 2) - 1; i >= 0 ; i--)
  {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
  }
}

//IZQUIERDA A DERECHA 3 LEDs
void pattern12() {
  for (int i = 0; i < num_of_leds + 3; i++) {
    if (i < num_of_leds) {
      digitalWrite(myled[i], HIGH);
    }
    if (i > 2) {
      digitalWrite(myled[i - 3], LOW);
    }
    delay(delay50);
  }
}

//3 LEDs OSCILANDO
void pattern13() {
  for (int i = 2; i < num_of_leds; i++) {
    if (i == 2) {
      digitalWrite(myled[0], HIGH);
      digitalWrite(myled[1], HIGH);
    }
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i - 3], LOW);
    delay(delay50);
  }
  for (int i = num_of_leds - 4; i > -1; i--) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i + 3], LOW);
    delay(delay50);
  }
  ledoff();
}

//EFECTO RANDOM 1
void pattern14() {
  int randomnum = random(0, num_of_leds + 1);
  digitalWrite(myled[randomnum], HIGH);
  delay(delay50);
  digitalWrite(myled[randomnum], LOW);
  delay(delay50);
}

//EFECTO RANDOM 2
void pattern15() {
  int randomonn = random(0, num_of_leds + 1);
  digitalWrite(myled[randomonn], HIGH);
  delay(delay50);
}

// MITAD Y MITAD
void pattern16() {
  for (int i = 0; i < num_of_leds; i++) {
    if(i<num_of_leds/2) {
      digitalWrite(myled[i], HIGH);
    } 
  }  
  delay(500);
  ledoff();   
  for (int i = 0; i < num_of_leds; i++) {
    if(i>=num_of_leds/2) {
      digitalWrite(myled[i], HIGH);
    } 
  }  
  delay(500);
  ledoff();   
}
