//------------SPEED-----------------------------------------------------
int enA = 5;//right motors
int enB = 3;//left motors
int speed=55;       //--------the bare minimum is around 60

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
int i[5];

float kp = 2, kd = 7,ki = 0.7;
float per = 0;
float er = 0;
float I = 0;
float adjL =0,adjR =0;

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
  i[0]=digitalRead(left_most_sensor);
  i[4]=digitalRead(right_most_sensor);
  i[1]=digitalRead(left_sensor);
  i[2]=digitalRead(middle_sensor);
  i[2]+=digitalRead(middle_sensor);
  i[0]+=digitalRead(left_most_sensor);
  i[3]=digitalRead(right_sensor);
  i[4]+=digitalRead(right_most_sensor);
  i[1]+=digitalRead(left_sensor);
  i[3]+=digitalRead(right_sensor);
}

void check(){
  if((i[0]== 0 )&&(i[1]== 0 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]>= 1 )) er = 2;            

else if((i[0]== 0 )&&(i[1]== 0 )&&(i[2]== 0 )&&(i[3]>= 1 )&&(i[4]>= 1 )) er = 1.8; 

else if((i[0]== 0 )&&(i[1]== 0 )&&(i[2]== 0 )&&(i[3]>= 1 )&&(i[4]== 0 )) er = 1.4;

else if((i[0]== 0 )&&(i[1]== 0 )&&(i[2]>= 1 )&&(i[3]>= 1 )&&(i[4]== 0 )) er = 1;

else if((i[0]== 0 )&&(i[1]== 0 )&&(i[2]>= 1 )&&(i[3]== 0 )&&(i[4]== 0 )) er = 0;

else if((i[0]== 0 )&&(i[1]>= 1 )&&(i[2]>= 1 )&&(i[3]== 0 )&&(i[4]== 0 )) er =-1;

else if((i[0]== 0 )&&(i[1]>= 1 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]== 0 )) er = -1.4;

else if((i[0]>= 1 )&&(i[1]>= 1 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]== 0 )) er = -1.8;

else if((i[0]>= 1 )&&(i[1]== 0 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]== 0 )) er = -2;
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
  adjR = (kp*er) + (ki*I) + (kd*(er-per));
  adjL = ((kp+0.1)*er) + (ki*I) + (kd*(er-per));
  if (er==2){
    set_speed(speed+adjL,speed+adjR);           //------------ Sharp Right
    move(1,0,1,0);
  }
  else if (er==(-2)){
    set_speed(speed-adjL,speed-adjR);           //------------- Sharp Left
    move(0,1,0,1);
  }
  else{
    adjR = (kp*er)  + (kd*(er-per));
    adjL = (kp*er)  + (kd*(er-per));
    set_speed(speed+adjL,speed-adjR);           //-------------- Everything else (forward and slight turns)
    move(1,0,0,1);
  }
  
}
