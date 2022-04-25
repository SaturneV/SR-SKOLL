#include <Wire.h>
#include <MPU6050.h>
#include <Adafruit_BMP280.h>

MPU6050 mpu;
Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);
  Serial.println("Initialisation MPU6050");
  if(!mpu.begin)
  {
    Serial.println("Problème à l'initialisation du MPU!");
  }

  Serial.begin(9600);
  Serial.println("Initialisation BMP280");
  if(!bmp.begin)
  {
    Serial.println("Problème à l'initialisation du BMP!");
  }

  mpu.calibrateGyro(); //SHOULD BE STATIC
  mpu.setThreshold(3);
  
}

void loop() {
 Vector normAccel = mpu.readNormalizeAccel();
 Vector normGyro = mpu.readNormalizeGyro();

 String dataString = millis();
 dataString += (', ' + normAccel.XAxis);
 dataString += (', ' + normAccel.YAxis);
 dataString += (', ' + normAccel.ZAxis);
 dataString += (', ' + normGyro.XAxis);
 dataString += (', ' + normGyro.YAxis);
 dataString += (', ' + normGyro.ZAxis);
 dataString += (', ' + bmp.readTemperature());
 dataString += (', ' + bmp.readPressure());
 dataString += (', ' + bmp.readAltitude(1010.44));
}
