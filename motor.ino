#include <Servo.h>
Servo myservo;
Servo myservo1;
int left1=1,left2=2;
int right1=3,right2=4;
int leftbutton=5,rightbutton=6;
int lx,ly;
int rx,ry;
int lb,rb;
void setup()
{
	pinMode(leftbutton, INPUT);
  	pinMode(rightbutton, INPUT);
 	myservo.attach(9);  // 9号引脚输出电机控制信号
  	myservo1.attach(10);
  	Serial.begin(9600);         //仅能使用9、10号引脚
  	Mouse.begin();
}
void loop()
{
	lb=digitalRead(leftbutton);
	rb=digitalRead(rightbutton);
	if(lb==LOW){
		Mouse.move(10,0,0);
		// Serial.println("left button");
	}
	if(rb==LOW){
		Serial.println("Rigth button");
	}
	// Serial.print("left x:");
	// Serial.println(lx);
	// delay(15);
	// Serial.print("left y");
	// Serial.println(ly);
	// delay(15);
	// Serial.print("right x:");
	// Serial.println(rx);
	// delay(15);
	// Serial.print("right y");
	// Serial.println(ry);
	lx=analogRead(left1);
	ly=analogRead(left2);
	rx=analogRead(right1);
	ry=analogRead(right2);
	lx = map(lx, 0, 1023, 0, 179);
	ly = map(ly, 0, 1023, 0, 179);
	rx = map(rx, 0, 1023, 0, 179); 
	ry = map(ry, 0, 1023, 0, 179);
	// myservo.write(lx);
 //  	myservo1.write(ly);
	// myservo.write(rx);
 //  	myservo1.write(ry);
  	delay(15);
 //  Serial.print("servo:");
 //  Serial.println(val);
 //  delay(15);
 //  Serial.print("servo1:");
 //  Serial.println(val1);
 //  val = analogRead(analogPin);
 //  val1 = analogRead(analogPin1);
 // // 读取来自可变电阻的模拟值（0到1023之间）
 //  val = map(val, 0, 1023, 0, 179);     // 利用“map”函数缩放该值，得到伺服电机需要的角度（0到180之间）
 //  val1 = map(val1, 0, 1023, 0, 179);
 //  myservo.write(val);     // 设定伺服电机的位置
 //  myservo1.write(val1);
 //  delay(15);             // 等待电机旋转到目标角度
}

