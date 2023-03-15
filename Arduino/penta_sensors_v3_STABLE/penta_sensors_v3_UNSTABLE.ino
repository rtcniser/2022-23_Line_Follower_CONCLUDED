//------------SPEED-----------------------------------------------------
int enA = 5;//right motors
int enB = 3;//left motors
int speed=85;
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
int lm,l,m,r,rm;
float turn=0.1,s=0; //1.turn counter,2.speed/delay variable based on turn counter  (There is a bit of bias in the turn purposefully)
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

//------------MAIN INSTRUCTIONS------------------------------------------
void move(int lp,int ln,int rn,int rp){
  digitalWrite(left_positive,lp);
  digitalWrite(left_negative,ln);
  digitalWrite(right_negative,rn);
  digitalWrite(right_positive,rp);
  }

void read(){
  lm=digitalRead(left_most_sensor);
  l=digitalRead(left_sensor);
  m=digitalRead(middle_sensor);
  r=digitalRead(right_sensor);
  rm=digitalRead(right_most_sensor);
}

void set_speed(int left_speed,int right_speed){
  analogWrite(enA,right_speed);
  analogWrite(enB,left_speed);
}

//------------------------CASE CHECK-------------------------------------------------
void check(int lm, int l, int m, int r, int rm){
  if (lm==whit and l==whit and m==blak and r==whit and rm==whit){         // forward
    set_speed(speed+15,speed+15);
    move(1,0,0,1);
    delay(100);
    turn=0;
  }
  s=min((abs(turn))*0.8,20.0);
  if (l==blak and lm==blak and r==blak and rm==blak and m==blak){         // all black stop (might edit later during competion)
    move(0,0,0,0);
  }
  else if (lm==blak and m==whit){           //sharp left
    (speed+14+s,speed+4+s);
    move(0,1,0,1);
    delay(10+s);
    turn-=0.9;
    }
  else if (rm==blak and m==whit){      //sharp right
    (speed+4+s,speed+14+s);
    move(1,0,1,0);
    delay(10+s);
    turn+=0.9;
    }
  else if (l==blak and m==blak){          //slight left
    set_speed(speed-20,speed-10);
    delay(5);
    }
  else if (r==blak and m==blak){          //slight right
    set_speed(speed-10,speed-20);
    delay(5);
    }
  else if (l==blak){          //left
    set_speed(speed,speed);
    move(0,1,0,1);
    delay(s);
    turn-=0.3;
    }
  else if (r==blak){          //right
    set_speed(speed,speed);
    move(1,0,1,0);    
    delay(s);
    turn+=0.3;
    }
  if (l==whit and lm==whit and r==whit and rm==whit and m==whit){          //----- all white: backtracker
    set_speed(speed,speed);
    move(0,1,1,0);
    delay(15+s);
    if (turn<=0){
      set_speed(speed+s,speed+s);
      move(0,1,0,1);
      turn-=0.6;
      delay(14+s);
      }
    else{
      set_speed(speed+s,speed+s);
      move(1,0,1,0);
      turn+=0.6;
      delay(14+s);
      }
   }
  
  }
void loop()//------------------------------------------------------------------------
{
set_speed(speed,speed);
read();
check(lm,l,m,r,rm);
}
