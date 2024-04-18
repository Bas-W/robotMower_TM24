#include <Wire.h>
#include <NewPing.h>

#define MAX_DISTANCE 200  // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define lTrig 10   // Analog pin A5
#define lEcho 9        // Analog pin A7
NewPing lSonar(lTrig, lEcho, MAX_DISTANCE);
unsigned int lDist = 0;


#define mTrig 8
#define mEcho 7
NewPing mSonar(mTrig, mEcho, MAX_DISTANCE);
unsigned int mDist = 0;

#define rTrig 5
#define rEcho 3
NewPing rSonar(rTrig, rEcho, MAX_DISTANCE);
unsigned int rDist = 0;


void setup() {
  Wire.begin(8);
  Wire.onRequest(requestEvent);

}

void loop() {
  sensorReadout();
}

void sensorReadout() {
  lDist = lSonar.ping_cm();
  delay(50);

  mDist = mSonar.ping_cm();
  delay(50);

  rDist = rSonar.ping_cm();
  delay(50);

  return;
}

void requestEvent() {
  String leftValueString = ".";
  String middleValueString = ".";
  String rightValueString = ".";

  if (lDist < 10) {
    leftValueString = "00" + String(lDist);
  } else if (lDist < 100) {
    leftValueString = "0" + String(lDist);
  }

  if (mDist < 10) {
    middleValueString = "00" + String(mDist);
  } else if (mDist < 100) {
    middleValueString = "0" + String(mDist);
  }

  if (rDist < 10) {
    rightValueString = "00" + String(rDist);
  } else if (rDist < 100) {
    rightValueString = "0" + String(rDist);
  }

  String message = leftValueString + "|" + middleValueString + "|" + rightValueString;
  Wire.write(message.c_str());
}
