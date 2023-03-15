//------------SPEED-----------------------------------------------------
int enA = 5;//right motors
int enB = 3;//left motors
int speed=65;
//------------MOTORS----------------------------------------------------
//POSITIVE VOLTAGE TO POSITIVE VARAIBLE => FORWARD (ROTATION)
int right_positive = 2;//IN1 ----- TERMINALS FOR RIGHT MOTOR
int right_negative = 4;//IN2
int left_negative = 8;//IN3 ------ TERMINALS FOR LEFT MOTOR
int left_positive = 7;//IN4
//------------SENSORS---------------------------------------------------
int left_most_sensor = A0;//left sensor pair
int left_sensor = A1;
int middle_sensor = A2;// extended sensor 
int right_sensor = A3;// right sensor pair
int right_most_sensor = A4;
//------------READINGS--------------------------------------------------
int blak = 1;// LOW and HIGH values
int whit = 0;
int iq = 0;// experimental anti loop
int lm,l,m,r,rm;
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

//------------------------CASE CHECK-------------------------------------------------
void check(int lm, int l, int m, int r, int rm){
  if (l==whit and lm==whit and r==whit and rm==whit and m==blak){
    analogWrite(enA,speed-12);
    analogWrite(enB,speed-12);
    move(1,0,0,1);
    delay(30);
  }

  if (l==blak and lm==blak and r==blak and rm==blak and m==blak){
    move(0,0,0,0);
  }
  else if (lm==blak and m==whit){           //sharp left
    move(0,1,0,1);
    delay(20);
    }
  else if (rm==blak and m==whit){      //sharp right
    move(1,0,1,0);
    delay(20);
    }                                                            
  else if (l==blak){          //slight left
    move(0,0,0,1);
    delay(10);
    }
  else if (r==blak){          //slight right
    move(1,0,0,0);    
    delay(10);
    }
  else if (l==blak and lm==blak and r==blak and rm==blak){
    if (m==whit){         //----- T-intersect
      move(0,0,0,0);
      }
    /*else{                            //----- Plus shaped intersect
      if (iq==0){
        iq = ! iq;
        move();
        }
      else{
        iq = ! iq;
        move();
        }
      }*/
    }
  else{
    move(0,0,0,0);
    }
  }
void loop()//------------------------------------------------------------------------
{
analogWrite(enA,speed+15);
analogWrite(enB,speed);
//
lm=digitalRead(left_most_sensor);
l=digitalRead(left_sensor);
m=digitalRead(middle_sensor);
r=digitalRead(right_sensor);
rm=digitalRead(right_most_sensor);
//
check(lm,l,m,r,rm);
}
