//http://forum.arduino.cc/index.php?topic=258091.0

//  分辨率按显示器最低分辨率来计算，行程均为分辨率的一半
const int ScreenWidth = 800;
const int ScreenHeight = 600;
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

  // Move to that position
  Mouse.moveAbs((int)X, (int)Y, 0);
}

const int xAxis = 1;         //analog sensor for X axis
const int yAxis = 2;         // analog sensor for Y axis
int range = 12;               // output range of X or Y movement
int responseDelay = 0;       // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value
int minima[] = {
  1023, 1023
};                // actual analogRead minima for {x, y}
int maxima[] = {
  0, 0
};                       // actual analogRead maxima for {x, y}
int axis[] = {
  xAxis, yAxis
};              // pin numbers for {x, y}
int mouseReading[2];          // final mouse readings for {x, y}

/*
  reads an axis (0 or 1 for x or y) and scales the
  analog input range to a range from 0 to <range>
  */

int readAxis(int axisNumber) {
  int distance = 0;    // distance from center of the output range

  // read the analog input:
  int reading = analogRead(axis[axisNumber]);


  // map the reading from the analog input range to the output range:
  reading = map(reading, minima[axisNumber], maxima[axisNumber], 0, range);
  // if the output reading is outside from the
  // rest position threshold,  use it:
  if (abs(reading - center) > threshold) {
    distance = (reading - center);
  }

  // the Y axis needs to be inverted in order to
  // map the movemment correctly:
  if (axisNumber == 1) {
    distance = -distance;
  }

  // return the distance for this axis:
  return distance;
}

void setup() {
  // put your setup coude here, to run once:
  Mouse.begin();
  Serial.begin(9600);
}

void loop() {
  int xReading = readAxis(0);
  int yReading = readAxis(1);
  moveTo(600+xReading, 150+yReading);
  //  int i=0,j=0;
  //  for (int j = 0; j < 600/2; j ++) {
  //    for (int i = 800/2; i < 800; i++) {
  //      moveTo(i, j);
  //      delay(10);
  //    }
  //  }
}
