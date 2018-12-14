#include<wiringPi.h>
void set();
void output(int);
int num[8][7];
int main(void)
{
  wiringPiSetup() ;
  set(num);
  pinMode (12, OUTPUT) ;//B
  pinMode (13, OUTPUT) ;//A
  pinMode (14, OUTPUT) ;//F
  pinMode (30, OUTPUT) ;//G
  pinMode (21, OUTPUT) ;//C
  pinMode (22, OUTPUT) ;//D
  pinMode (23, OUTPUT) ;//E
  pinMode (2, INPUT);  //7
  pinMode (3, INPUT);  //8
    digitalWrite(13,1);
    digitalWrite(12,1);
    digitalWrite(21,1);
    digitalWrite(22,0);
    digitalWrite(23,1);
    digitalWrite(14,1);
    digitalWrite(30,1);
  int i=0;
  while(1)
  {
          if(digitalRead(2)) //next one
       {
          if(i==7)
          i=-1;
	  i++;
          output(i);	
          delay(200);	
      }
      else if(digitalRead(3))   //last one
     {
        if(i==0)
       i=8;
        i--;
       output(i);
	delay(200);
     }
  }
}
void output(int i)
{
    digitalWrite(13,num[i][0]);
    digitalWrite(12,num[i][1]);
    digitalWrite(21,num[i][2]);
    digitalWrite(22,num[i][3]);
    digitalWrite(23,num[i][4]);
    digitalWrite(14,num[i][5]);
    digitalWrite(30,num[i][6]);
 
}
void set()
{
    num[0][0]=1; //a
    num[0][1]=1;
    num[0][2]=1;
    num[0][3]=0;
    num[0][4]=1;
    num[0][5]=1;
    num[0][6]=1;
    
    num[1][0]=1; //b
    num[1][1]=1;
    num[1][2]=1;
    num[1][3]=1;
    num[1][4]=1;
    num[1][5]=1;
    num[1][6]=1;

    num[2][0]=1; //c
    num[2][1]=0;
    num[2][2]=0;
    num[2][3]=1;
    num[2][4]=1;
    num[2][5]=1;
    num[2][6]=0;
    
    num[3][0]=1; //d
    num[3][1]=1;
    num[3][2]=1;
    num[3][3]=1;
    num[3][4]=1;
    num[3][5]=1;
    num[3][6]=0;

    num[4][0]=1; //e
    num[4][1]=0;
    num[4][2]=0;
    num[4][3]=1;
    num[4][4]=1;
    num[4][5]=1;
    num[4][6]=1;

    num[5][0]=1; //f
    num[5][1]=0;
    num[5][2]=0;
    num[5][3]=0;
    num[5][4]=1;
    num[5][5]=1;
    num[5][6]=1;
   
    num[6][0]=1; //g
    num[6][1]=0;
    num[6][2]=1;
    num[6][3]=1;
    num[6][4]=1;
    num[6][5]=1;
    num[6][6]=1;
   
    num[7][0]=0; //h
    num[7][1]=1;
    num[7][2]=1;
    num[7][3]=0;
    num[7][4]=1;
    num[7][5]=1;
    num[7][6]=1;
}	







