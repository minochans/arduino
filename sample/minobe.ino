#include <TM1637Display.h>



static boolean dropball = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  enum SEG{
    SEG1_PORT1 = 22,
    SEG1_PORT2 = 24,
    SEG1_PORT3 = 26,
    SEG1_PORT4 = 28,

    SEG2_PORT1 = 23,
    SEG2_PORT2 = 25,
    SEG2_PORT3 = 27,
    SEG2_PORT4 = 29,

    SEG3_PORT1 = 30,
    SEG3_PORT2 = 32,
    SEG3_PORT3 = 34,
    SEG3_PORT4 = 36,
  };

//  pinMode(SEG1_PORT1, OUTPUT);
//  pinMode(SEG1_PORT2, OUTPUT);
//  pinMode(SEG1_PORT3, OUTPUT);
//  pinMode(SEG1_PORT4, OUTPUT);
//
//  pinMode(SEG2_PORT1, OUTPUT);
//  pinMode(SEG2_PORT2, OUTPUT);
//  pinMode(SEG2_PORT3, OUTPUT);
//  pinMode(SEG2_PORT4, OUTPUT);
//
//  pinMode(SEG3_PORT1, OUTPUT);
//  pinMode(SEG3_PORT2, OUTPUT);
//  pinMode(SEG3_PORT3, OUTPUT);
//  pinMode(SEG3_PORT4, OUTPUT);


pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
pinMode(26,OUTPUT);
pinMode(27,OUTPUT);
pinMode(28,OUTPUT);

pinMode(52,INPUT_PULLUP);
}

void loop() {  
  // put your main code here, to run repeatedly:
  Disp7seg(7,40,false);
  Disp7seg(0,41,false);
  Disp7seg(50,42,false);

  roulette0();
  

}


void roulette0(){
  int value;
  int LED;

  value = LOW;

  while(value == LOW){
    value = digitalRead(52); 
  }

  LED = roulette() + 22;
  
  digitalWrite(LED,HIGH);
}


char roulette(){
  int count = 0;
  char roulette_point = 0;
  int value;
  int LED;
  
  value = digitalRead(52);

  while(value == HIGH){
    value = digitalRead(52);
  }

  while(value == LOW){
    if(count == 100){
      if(6 != roulette_point){
        roulette_point++;
        count = 0;
      }else if(6 == roulette_point){
        roulette_point = 0;
        count = 0;
      }
    Serial.write(45); // 1バイトのデータ(45)を送信
    int n = Serial.write("ok3=");
    Serial.print(value);
    Serial.println("");
    }
    count++;

    LED = roulette_point + 22;

    digitalWrite(LED,HIGH);

    Serial.write(45); // 1バイトのデータ(45)を送信
    int n = Serial.write("ok4=");
    Serial.print(value);
    Serial.println("");

    
    if(22 != LED){
      digitalWrite(LED - 1,LOW);
    }else if(22 == LED){
      digitalWrite(28,LOW);
    }
  }

  return roulette_point;
}

void Disp7seg(int DispNum,int PortNum,boolean Flashing){
  TM1637Display display(21, PortNum);
//  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);
  display.showNumberDecEx(DispNum,0x00,false);
}