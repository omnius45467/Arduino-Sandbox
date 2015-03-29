//Walk in a straight line
//Hard-coded for driving 6 servos with the Arduino UNO
//08/05/2013
//Work of Patrick Emami

#include <Servo.h> 

//servo objects for my 6 servo robot
Servo rightankle;
Servo leftankle; 
Servo leftknee; 
Servo rightknee; 
Servo lefthip; 
Servo righthip;
Servo leftlowerankle;
Servo rightlowerankle;
Servo leftwaist;
Servo rightwaist;

//pins
int head = 2;

int rShoulder = A3;
int lShoulder = A2;

int rArm = A4;
int lArm = A1;

int rElbow = A5;
int lElbow = A0;

int rHip = 4;
int lHip = 9;

int rUTh = 5;
int lUTh = 10;

int rLTh = 6;
int lLTh = 11;

int rUAnkel = 7;
int lUAnkel = 12;

int rLAnkel = 8;
int lLAnkel = 13;


//stores position of each servo, initials of servo name
double RA = 90; 
double LA = 90; 
double RLA = 90;
double LLA = 90;
double LK = 90; 
double RK = 100; 
double LH = 100; 
double RH = 90; 
double LW = 90;
double RW = 90;

double joints[10] = {RLA, LLA, RA, LA, LK, RK, LH, RH, LW, RW};

       
void setup() {
//attach pins to servo

//left side
leftwaist.attach(lHip);  
lefthip.attach(lUTh);
leftknee.attach(lLTh);
leftankle.attach(lUAnkel);  
leftlowerankle.attach(lLAnkel);

//right side
rightwaist.attach(rHip);
righthip.attach(rUTh); 
rightknee.attach(rLTh);
rightankle.attach(rUAnkel);  
rightlowerankle.attach(rLAnkel);

//init write
rightankle.write(joints[0]);
leftankle.write(joints[1]);

leftknee.write(joints[2]); 
rightknee.write(joints[3]); 

lefthip.write(joints[4]); 
righthip.write(joints[5]);  
  
  delay(5000);
  
  // initial shift of COG to right side
  for(double i = 0; i < 50; i += 1) {
   
    joints[0] += 0.2; 
    joints[1] += 0.2; 
     
    rightankle.write(joints[0]);
    leftankle.write(joints[1]); 
  }
  
  delay(200);
  
    //initally swings out left leg while bending left knee
  for(int j = 0; j < 200; j+= 1) {
   
      joints[2] += 0.2; 
      joints[3] += 0.2;   
      joints[4] += 0.2; 
      joints[5] += 0.2;
           
      leftknee.write(joints[2]); 
      rightknee.write(joints[3]); 
      lefthip.write(joints[4]); 
      righthip.write(joints[5]);  
   } 
}


void loop() {
        
  delay(200); 
  
 //switches COG to other half of robot 
 for(double k = 100; k > 0; k -= 1) {
    
    joints[0] -= 0.2; 
    joints[1] -= 0.2; 
     
    rightankle.write(joints[0]);
    leftankle.write(joints[1]);
     
   }
    
  delay(200);
 
 //Swings out right leg and bends knee while moving left leg 
   for(int l = 400; l > 0; l -= 1) {
   
      joints[2] -= 0.2; 
      joints[3] -= 0.2;   
      joints[4] -= 0.2; 
      joints[5] -= 0.2;
           
      leftknee.write(joints[2]); 
      rightknee.write(joints[3]); 
      lefthip.write(joints[4]); 
      righthip.write(joints[5]);  
   } 
  
  delay(2000); 
  
 // initial shift of COG to right side
  for(double i = 0; i < 100; i += 1) {
   
    joints[0] += 0.2; 
    joints[1] += 0.2; 
     
    rightankle.write(joints[0]);
    leftankle.write(joints[1]); 
  }
  
  delay(2000); 
  
  //Swings out left leg
  for(int j = 0; j < 400; j+= 1) {
   
      joints[2] += 0.2; 
      joints[3] += 0.2;   
      joints[4] += 0.2; 
      joints[5] += 0.2;
           
      leftknee.write(joints[2]); 
      rightknee.write(joints[3]); 
      lefthip.write(joints[4]); 
      righthip.write(joints[5]);  
   } 
 
}
