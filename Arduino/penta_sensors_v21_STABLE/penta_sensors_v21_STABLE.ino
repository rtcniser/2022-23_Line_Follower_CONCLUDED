//------------SPEED-----------------------------------------------------
int enA = 5;//right motors
int enB = 3;//left motors
int speed=60;

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

float kp = 6.5, kd = 4,ki = 0;
int per = 0;
int er = 0;
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
  i[0]=digitalRead(left_most_sensor);
  i[1]=digitalRead(left_sensor);
  i[2]=digitalRead(middle_sensor);
  i[3]=digitalRead(right_sensor);
  i[4]=digitalRead(right_most_sensor);
  i[0]+=digitalRead(left_most_sensor);
}

void check(){
  if((i[0]== 0 )&&(i[1]>= 0 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]== 1 )) er = 4;            

else if((i[0]== 0 )&&(i[1]>= 0 )&&(i[2]== 0 )&&(i[3]== 1 )&&(i[4]== 1 )) er = 3; 

else if((i[0]== 0 )&&(i[1]>= 0 )&&(i[2]== 0 )&&(i[3]== 1 )&&(i[4]== 0 )) er = 2;

else if((i[0]== 0 )&&(i[1]>= 0 )&&(i[2]== 1 )&&(i[3]== 1 )&&(i[4]== 0 )) er = 1;

else if((i[0]== 0 )&&(i[1]>= 0 )&&(i[2]== 1 )&&(i[3]== 0 )&&(i[4]== 0 )) er = 0;

else if((i[0]== 0 )&&(i[1]>= 1 )&&(i[2]== 1 )&&(i[3]== 0 )&&(i[4]== 0 )) er =- 1;

else if((i[0]== 0 )&&(i[1]>= 1 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]== 0 )) er = -2;

else if((i[0]== 1 )&&(i[1]>= 1 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]== 0 )) er = -3;

else if((i[0]== 1 )&&(i[1]>= 0 )&&(i[2]== 0 )&&(i[3]== 0 )&&(i[4]== 0 )) er = -4;
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

  adj = (kp*er) + (kd*(er-per));
  if (er==4){
    set_speed(speed+adj,speed+adj);           //------------ Sharp Right
    move(1,0,1,0);
  }
  else if (er==(-4)){
    set_speed(speed-adj,speed-adj);           //------------- Sharp Left
    move(0,1,0,1);
  }
  else{
    set_speed(speed+adj,speed-adj);           //-------------- Everything else (forward and slight turns)
    move(1,0,0,1);
  }
  
}
