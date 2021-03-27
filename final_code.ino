
/*!
* @file DFRobot_Heartrate.h
* @brief DFRobot_Heartrate.h detailed description for Heartrate.cpp 
*
*  This is written for the heart rate sensor the company library. Mainly used for real 
*  time measurement of blood oxygen saturation, based on measured values calculate heart rate values.
* 
* @author linfeng(Musk.lin@dfrobot.com)
* @version  V1.1
* @date  2016-8-16
* @version  V1.0
* @date  2015-12-24
*/
#define heartratePin A1
#include "DFRobot_Heartrate.h"

const int GSR=A0;
int sensorValue=0;
int gsr_average=0;
int Heartrate=0;
DFRobot_Heartrate heartrate(DIGITAL_MODE); ///< ANALOG_MODE or DIGITAL_MODE

void setup() {
  Serial.begin(9600);
}

void loop() {
  long sum=0;
  long starttime,stoptime;;
  starttime=millis();
  for(int j=0;j<50;j++)
  {
  uint8_t rateValue;
  heartrate.getValue(heartratePin); ///< A1 foot sampled values
  rateValue = heartrate.getRate(); ///< Get heart rate value 
  if(rateValue)  {
    Heartrate=rateValue;
  }
  delay(15);
  }
  Serial.println(Heartrate);
  for(int i=0;i<10;i++)           //Average the 10 measurements to remove the glitch
      {
      sensorValue=analogRead(GSR);
      sum += sensorValue;
      }
   gsr_average = sum/10;
   Serial.println(gsr_average);
   do{
    stoptime=millis();
   }while(stoptime-1000<starttime);
      
}

/******************************************************************************
  Copyright (C) <2015>  <linfeng>
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  Contact: Musk.lin@dfrobot.com
 ******************************************************************************/
