#define Water A0    //定義AO 引腳 為 IO-A0
#define Moisture A1 //定義A1 引腳 為 IO-A1
#define DO 7        //定義DO 引腳 為 IO-7
#define PUMP 8        //定義DO 引腳 為 IO-7

int water_level,moisture_level;

void setup() {
  pinMode(Water, INPUT);//定義A0為輸入模式
  pinMode(Moisture, INPUT);//定義A1為輸入模式
  pinMode(DO, INPUT);
  pinMode(PUMP, OUTPUT);
  Serial.begin(9600);
}

void loop()  /*迴圈*/
{
  Serial.println("water_check start");
  water_check();

  Serial.println("moisture_check start");
  moisture_check();

  if(water_level>300)
    if(moisture_level==1)
      {
        Serial.println("pump_start start");
        pump_start();
      }
    else
      Serial.println("!!!!!!!!!moisture_level !=1");
  else
    Serial.println("!!!!!!!!!!!!!water_level < 300");    
  
  Serial.println("loop end");
  delay(10000);
}

void moisture_check()
{
  Serial.print("Moisture=");
  Serial.print(analogRead(Moisture));//讀取AO的數值
  Serial.print("|DO=");
  Serial.println(digitalRead(DO));//讀取DO的數值
  moisture_level=digitalRead(DO);
  delay(3000);
}

void water_check()
{
  water_level=analogRead(Water);
  Serial.print("water level = ");
  Serial.println(water_level);
  delay(3000);
}

void pump_start()
{
  digitalWrite(PUMP, HIGH); // sets the digital pin on
  delay(1000);            // waits for a second
  digitalWrite(PUMP, LOW);  // sets the digital pin off
  delay(5000);            // waits for a second
}
