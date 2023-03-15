//------------SPEED-----------------------------------------------------
int enA = 5;//right motors
int enB = 3;//left motors
int speed=150;

//------------MOTORS----------------------------------------------------
//POSITIVE VOLTAGE TO POSITIVE VARAIBLE => FORWARD (ROTATION)
int right_positive = 2;//IN1 ----- TERMINALS FOR RIGHT MOTOR
int right_negative = 4;//IN2
int left_negative = 7;//IN3 ------ TERMINALS FOR LEFT MOTOR
int left_positive = 8;//IN4

//------------SENSORS---------------------------------------------------
int left_most_sensor = A0;//left sensor pair
int left_sensor = A1;
int middle_sensor = A2;// extended sensor 
int right_sensor = A3;// right sensor pair
int right_most_sensor = A4;

//------------READINGS--------------------------------------------------
int blak = 1;// REFLECT and NOT REFLECT values
int whit = 0;
int l=0,lm=0,m=0,rm=0,r=0;

float kp =50, kd =25, ki = 0;                   //-------- Values to be fine tuned
float per = 0;
float er = 0;
float I = 0;
float adj =0;

void setup()//----------------------------------------------------------
{
pinMode(enA,OUTPUT);
pinMode(right_positive,OUTPUT);
pinMode(right_negative,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(left_positive,OUTPUT);
pinMode(left_negative,OUTPUT);
pinMode(middle_sensor,INPUT);
pinMode(left_sensor,INPUT);
pinMode(left_most_sensor,INPUT);
pinMode(right_sensor,INPUT);
pinMode(right_most_sensor,INPUT);

}

void move(int lp,int ln,int rn,int rp){
  digitalWrite(left_positive,lp);
  digitalWrite(left_negative,ln);
  digitalWrite(right_negative,rn);
  digitalWrite(right_positive,rp);
  }

void read(){
  l=digitalRead(left_most_sensor);
  lm=digitalRead(left_sensor);
  m=digitalRead(middle_sensor);
  rm=digitalRead(right_sensor);
  r=digitalRead(right_most_sensor);
}

void check(){
  if((l== whit )&&(lm== whit )&&(m== whit )&&(rm== whit )&&(r== blak )) er = 4;            

else if((l== whit )&&(lm== whit )&&(m== whit )&&(rm== blak )&&(r== blak )) er = 3; 

else if((l== whit )&&(lm== whit )&&(m== whit )&&(rm== blak )&&(r== whit )) er = 2;

else if((l== whit )&&(lm== whit )&&(m== blak )&&(rm== blak )&&(r== whit )) er = 1;

else if((l== whit )&&(lm== whit )&&(m== blak )&&(rm== whit )&&(r== whit )) er = 0;

else if((l== whit )&&(lm== blak )&&(m== blak )&&(rm== whit )&&(r== whit )) er = -1;

else if((l== whit )&&(lm== blak )&&(m== whit )&&(rm== whit )&&(r== whit )) er = -2;

else if((l== blak )&&(lm== blak )&&(m== whit )&&(rm== whit )&&(r== whit )) er = -3;

else if((l== blak )&&(lm== whit )&&(m== whit )&&(rm== whit )&&(r== whit )) er = -4;
}

void set_speed(int left_speed,int right_speed){
  analogWrite(enA,right_speed);
  analogWrite(enB,left_speed);
}

void loop() {
  // put your main code here, to run repeatedly:
  read();
  per = er;
  check();
  I = I + er;
  adj = (kp*er) + (ki*I) + (kd*(er-per));       //---------- Adjustment PID
  if (er==4){
    set_speed(speed+adj,speed+adj);           //------------ Sharp Right
    move(1,0,1,0);
  }
  else if (er==(-4)){
    set_speed(255,255);           //------------- Sharp Left
    move(0,1,0,1);
  }
  else{
    set_speed(speed+adj,speed-adj);           //-------------- Everything else (forward and slight turns)
    move(1,0,0,1);
  }
  
}
