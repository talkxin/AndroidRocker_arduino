//  Specify pixel positions for a 640x480 screen
const int ScreenWidth = 1366;
const int ScreenHeight = 768;
const int ScreenXLeft = 0;
const int ScreenXRight = ScreenWidth - 1;
const int ScreenYBottom = 0;
const int ScreenYTop = ScreenHeight - 1;

void moveTo(int absoluteX, int absoluteY) {
  // Do the math in long integers to avoid integer overflow problems

  // Constrain the position to keep it within the screen area
  long int X = constrain(absoluteX, ScreenXLeft, ScreenXRight);
  long int Y = constrain(absoluteY, ScreenYBottom, ScreenYTop);
  // Map the coordinates to the range of all integers
  X = map(X, (long) ScreenXLeft, (long) ScreenXRight, -32768L, 32767L);
  Y = map(Y, (long) ScreenYTop, (long) ScreenYBottom, -32768L, 32767L);
  Serial.println(X);
  Serial.println(Y);
  // Move to that position
  Mouse.move((int)X, (int)Y, 0);
}
void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  Serial.begin(9600);
  delay(2000);
}
void loop() {
  //得出x轴为分辨率二分之一的80%的比率
  //得出y轴为分辨率四分之一的60%的比率
  Mouse.move(0,-32767);
  Mouse.move(0,768/4/0.6);
  delay(100000);
//  for(int i=0;i<32767L;i++){
//    Mouse.move(-32767,0);
//    Mouse.move(i,0);
//    Serial.println(i);
//    delay(1000);
//  }
}
