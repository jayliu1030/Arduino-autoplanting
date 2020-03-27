#define Water A0    //定義AO 引腳 為 IO-A0
#define Moisture A1 //定義A1 引腳 為 IO-A1
#define DO 7        //定義DO 引腳 為 IO-7
#define PUMP 8        //定義DO 引腳 為 IO-7

void setup() {
  pinMode(Water, INPUT);//定義A0為輸入模式
  pinMode(Moisture, INPUT);//定義A1為輸入模式
  pinMode(DO, INPUT);
  pinMode(PUMP, OUTPUT);
  Serial.begin(9600);
}

void loop()  /*迴圈*/
{
  pump_start();
}

int water_check()
{

}

void pump_start()
{
  digitalWrite(PUMP, HIGH); // sets the digital pin on
  delay(3000);            // waits for a second
  digitalWrite(PUMP, LOW);  // sets the digital pin off
  delay(5000);            // waits for a second
}
