/*
LED_Driver_TLC59281
This is an sketch for LED Dirier Test. The chip is TLC59281


  modified 2014年10月7日
  by luo xiaoxiang
 */
char GS[64] = {
                    1,1,1,1,1,1,1,1,
                    1,1,1,1,1,1,1,0,
                    
                    1,1,1,1,1,1,1,1,
                    1,1,1,1,1,1,1,1
               
              };
char GS2[64] = {
                    1,1,1,1,1,1,1,1,
                    1,1,1,1,1,1,1,0,
                    
                    1,1,1,1,1,1,1,1,
                    1,1,1,0,0,0,0,0
               
              };
int CLK = 7;
int Data = 6;
int LAT = 5;
int BLANK = 4;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(CLK, OUTPUT);
  pinMode(Data, OUTPUT);
  pinMode(LAT, OUTPUT);
  pinMode(BLANK, OUTPUT);
  
  digitalWrite(CLK, LOW);   // 
  digitalWrite(Data, LOW);   // 
  digitalWrite(LAT, LOW);   // 
  digitalWrite(BLANK, LOW);   // 
}

// the loop function runs over and over again forever
void loop() {
  updata1();
  //updata2();
  //Serial.println("");
  delay(1000);              // wait for a second
  updata3();
  delay(1000);
  
}

void Write_bit(char Status)
{
  //digitalWrite(CLK, LOW);
 // digitalWrite(CLK, HIGH);
  digitalWrite(CLK, LOW);
  if(Status == 1)
     {
       digitalWrite(Data, HIGH);   // 
     }
  else
     {
       digitalWrite(Data, LOW);   // 
     }
   digitalWrite(CLK, HIGH);
   digitalWrite(CLK, LOW);
  // Serial.print(Status);
}


void updata1()//上传数据 把每一个比特位写入
{
  digitalWrite(BLANK, HIGH);
  for(int j = 0; j<32;j++)
    Write_bit(GS[j]);
  digitalWrite(LAT, HIGH);
  digitalWrite(LAT, LOW);
 // delay(1000);
  digitalWrite(BLANK, LOW);  // Open the LEDs
  
//  digitalWrite(CLK, LOW);
}



void updata2()//上传数据 把每一个比特位写入
{
  digitalWrite(LAT, LOW);
  //digitalWrite(LAT, HIGH);
  for(int j = 16;j>=0;j--)
    Write_bit(GS[j]);
    digitalWrite(LAT, HIGH);
  digitalWrite(LAT, LOW);
//  digitalWrite(CLK, LOW);
}




void updata3()//上传数据 把每一个比特位写入
{
  digitalWrite(BLANK, HIGH);

  for(int j = 0; j<32;j++)
    Write_bit(GS2[j]);
  digitalWrite(LAT, HIGH);
  digitalWrite(LAT, LOW);
  digitalWrite(BLANK, LOW);  // Open the LEDs
}

