                                                  #include <Adafruit_TCS34725.h>
#include <Servo.h>
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);
Servo miservo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
tcs.begin();
miservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
float red,green,blue;
tcs.getRGB(&red,&green,&blue);
int R= int(red);
int G = int(green);
int B = int (blue);
String color ="";
  if ((R-G>100)&(R-B>100)){
    color="Rojo";

    miservo.write(30);
                    delay(1500);

  }
  if ((R-G>20)&(R-B<100)){
    color="verde";
        miservo.write(90);
                            delay(1500);

  }
  if(B>90){
    color="azul";
        miservo.write(150);
         delay(1500);


  }
  if((R-B>100)&(G-B>30)){
    color="amarillo";
            miservo.write(0);
            delay(1500);


  }
Serial.print("R: ");Serial.print(int(red));
Serial.print("   G: ");Serial.print(int(green));
Serial.print("   B: ");Serial.print(int(blue));
Serial.print (" Color:  "); Serial.print(color);

Serial.println();
}
