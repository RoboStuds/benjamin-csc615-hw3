/*
Benjamin Fletes 
917352025
This will demonstrate how motors work. using forward and backwards. Being able to change the speed.
*/

#include <wiringPi.h>
#include <softPwm.h>
const int MOTORCOUNT = 2;

// enable fwd reverse
const int MOTORS[2][3] = {{0, 2, 3},
                          {6, 4, 5}}; // for the pins

int moveMotors(int fwd, int reverse, int speed, int range)
{
    for (int motorNum = 0; motorNum < MOTORCOUNT; motorNum++)
    {
      // depending on moving fwd and reverse if fwd 1 is 1 then it is moving forward. 
        digitalWrite(MOTORS[motorNum][0], 1); // e
        digitalWrite(MOTORS[motorNum][1], fwd); // fwd
        digitalWrite(MOTORS[motorNum][2], reverse); // reverse
    }
    // determine the speed
    softPwmWrite(MOTORS[0][0], speed);
    softPwmWrite(MOTORS[1][0], speed);
    delay(2000); // 2 seconds of spinning
    for (int off = 0; off < MOTORCOUNT; off++)
    {
        digitalWrite(MOTORS[off][0], 0); // e
        digitalWrite(MOTORS[off][1], 0); // fwd
        digitalWrite(MOTORS[off][2], 0); // reverse
    }
    delay(3000); // 3 seconds of letting cool then again
    return 0;
}
int main (void)
{
    if (wiringPiSetup() == -1)
    {
        return 0;
    }
    for (int i = 0; i < MOTORCOUNT; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            
            pinMode (MOTORS[i][j], OUTPUT);
            digitalWrite(MOTORS[i][j], LOW);
        }
    }
  if (softPwmCreate(MOTORS[0][0], 0, 100) != 0 && softPwmCreate(MOTORS[1][0], 0, 100) != 0)
    {
        return -1;
    }
    if (moveMotors(1, 0, 20, 100) == -1 || moveMotors(1, 0, 10, 100) == -1)
    {
        return 0;
    }
    if (moveMotors(0, 1, 20, 100) == -1 || moveMotors(0, 1, 10, 100) == -1)
    {
        return 0;
    }
    
        
    return 0 ;
}
