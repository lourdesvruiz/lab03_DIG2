

// Declaración de variables
const int boton_restart = PB_5;
const int boton_J1 = PF_4;  //PUSH1
const int boton_J2 = PF_0;  //PUSH2

int antirrebote1;
int antirrebote2;
int antirrebote3;

int stops;
int game_start;

int contador1 = 0;
int contador2 = 0;

//LEDs de semáforo
#define LEDR RED_LED
#define LEDB BLUE_LED
#define LEDG GREEN_LED

//LEDs de jugadores
#define J1_1 PB_0 //3
#define J1_2 PB_1 //4
#define J1_3 PE_4 //5
#define J1_4 PE_5 //6
#define J1_5 PB_4 //7
#define J1_6 PA_5 //8
#define J1_7 PA_6 //9
#define J1_8 PA_7 //10

#define J2_1 PD_0 //23
#define J2_2 PD_1 //24
#define J2_3 PD_2 //25
#define J2_4 PD_3 //26
#define J2_5 PE_1 //27
#define J2_6 PE_2 //28
#define J2_7 PE_3 //29
#define J2_8 PB_3 //38

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //se inicia la comunicación serial

  //Se declaran los pushbuttons con resistencias pull-up (lógica negada)
  pinMode(boton_restart, INPUT_PULLUP);
  pinMode(boton_J1, INPUT_PULLUP);
  pinMode(boton_J2, INPUT_PULLUP);

  //LEDs como salidas
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  
  pinMode(J1_1, OUTPUT);
  pinMode(J1_2, OUTPUT);
  pinMode(J1_3, OUTPUT);
  pinMode(J1_4, OUTPUT);
  pinMode(J1_5, OUTPUT);
  pinMode(J1_6, OUTPUT);
  pinMode(J1_7, OUTPUT);
  pinMode(J1_8, OUTPUT);

  pinMode(J2_1, OUTPUT);
  pinMode(J2_2, OUTPUT);
  pinMode(J2_3, OUTPUT);
  pinMode(J2_4, OUTPUT);
  pinMode(J2_5, OUTPUT);
  pinMode(J2_6, OUTPUT);
  pinMode(J2_7, OUTPUT);
  pinMode(J2_8, OUTPUT);

  stops = 0;   //revisa si el semáforo está en funcionamiento (0 si no lo está y 1 si ya inició)
  game_start = 0;  //se pone en 1 luego que el semáforo esté en verde y habilita los pushbuttons de jugadores
}

void loop() {
  // put your main code here, to run repeatedly: 
  semaforo();
  carrera1();
  carrera2();
}

void semaforo (){
  //antirrebote de pushbutton
  if (stops == 0 && digitalRead(boton_restart) == 0){  //revisa si el semáforo no ha sido iniciado y si hay un botonazo
    antirrebote1 = 1;
  }

  if (antirrebote1 == 1 && digitalRead(boton_restart) == 1){  //revisa si ya se prendió la bandera y si ya se soltó el button
    stops = 1;

    //Se reinicia el juego (LEDs apagadas)
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDG, LOW);

    digitalWrite(J1_1, LOW);
    digitalWrite(J1_2, LOW);
    digitalWrite(J1_3, LOW);
    digitalWrite(J1_4, LOW);
    digitalWrite(J1_5, LOW);
    digitalWrite(J1_6, LOW);
    digitalWrite(J1_7, LOW);
    digitalWrite(J1_8, LOW);

    digitalWrite(J2_1, LOW);
    digitalWrite(J2_2, LOW);
    digitalWrite(J2_3, LOW);
    digitalWrite(J2_4, LOW);
    digitalWrite(J2_5, LOW);
    digitalWrite(J2_6, LOW);
    digitalWrite(J2_7, LOW);
    digitalWrite(J2_8, LOW);

    contador1 = 0;
    contador2 = 0;

    //Secuencia de semáforo
    digitalWrite(LEDR, HIGH);
    delay(1000);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    delay(1000);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    
    delay(1000);
    digitalWrite(LEDG, LOW);
    antirrebote1 = 0;
    //stops = 0;
    game_start = 1;   //inicia el juego
  }
}

void carrera1() {
    if (game_start == 1 && digitalRead(boton_J1) == 0){
      antirrebote2 = 1;
    }

    if (antirrebote2 == 1 && digitalRead(boton_J1) == 1){
      
      //cada botonza se incrementa el contador de jugador
      contador1 = contador1+1;
      Serial.print("Jugador 1: ");
      Serial.println(contador1);
      delay(200);

      //Switch case que controla el contador de décadas 
      switch(contador1){
        case 0:
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

        case 1: 
          digitalWrite(J1_1, HIGH);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

       case 2: 
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, HIGH);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

      case 3: 
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, HIGH);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

      case 4: 
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, HIGH);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

      case 5: 
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, HIGH);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

      case 6: 
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, HIGH);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

      case 7: 
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, HIGH);
          digitalWrite(J1_8, LOW);
          antirrebote2 = 0;
          break;

      case 8: 
          digitalWrite(J1_1, LOW);
          digitalWrite(J1_2, LOW);
          digitalWrite(J1_3, LOW);
          digitalWrite(J1_4, LOW);
          digitalWrite(J1_5, LOW);
          digitalWrite(J1_6, LOW);
          digitalWrite(J1_7, LOW);
          digitalWrite(J1_8, HIGH);
          antirrebote2 = 0;
          break;
      }
      //función de comparación 
      ganar();
    }

}

void carrera2() {
    if (game_start == 1 && digitalRead(boton_J2) == 0){
      antirrebote3 = 1;
    }

    if (antirrebote3 == 1 && digitalRead(boton_J2) == 1){
      contador2 = contador2+1;
      Serial.print("Jugador 2: ");
      Serial.println(contador2);
      delay(200);
      
      switch(contador2){
        case 0:
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

        case 1: 
          digitalWrite(J2_1, HIGH);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

       case 2: 
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, HIGH);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

      case 3: 
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, HIGH);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

      case 4: 
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, HIGH);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

      case 5: 
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, HIGH);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

      case 6: 
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, HIGH);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

      case 7: 
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, HIGH);
          digitalWrite(J2_8, LOW);
          antirrebote3 = 0;
          break;

      case 8: 
          digitalWrite(J2_1, LOW);
          digitalWrite(J2_2, LOW);
          digitalWrite(J2_3, LOW);
          digitalWrite(J2_4, LOW);
          digitalWrite(J2_5, LOW);
          digitalWrite(J2_6, LOW);
          digitalWrite(J2_7, LOW);
          digitalWrite(J2_8, HIGH);
          antirrebote3 = 0;
          break;
      }
      ganar();
    }

}

//Función que chequea si algún contador ha llegado a 8
void ganar (){
  if(contador1 == 8){           //si llega a 8, se prende un LED del RGB indicando quién ganó
    digitalWrite(LEDB, HIGH);
    Serial.print("¡Gana Jugador 1! ");
    Serial.print('\n');

    game_start = 0;           //se dehabilitan los pushbuttons de los jugadores
    stops = 0;                //se puede volver a iniciar el juego (secuencia de semáforo) 
    antirrebote2 = 0;
    antirrebote3 = 0;
    delay(10);
  }

  if(contador2 == 8){
    digitalWrite(LEDG, HIGH);
    Serial.print("¡Gana Jugador 2! ");
    Serial.print('\n');

    game_start = 0;
    stops = 0;
    antirrebote2 = 0;
    antirrebote3 = 0;
    delay(10);
    
  }
}
