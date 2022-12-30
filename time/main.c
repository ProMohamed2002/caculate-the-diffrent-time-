#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
 typedef struct
{
    int hours;
    int min;
    int sec;

}game;
 game game_time;
 game time1;
 game time2;
 game timegame(struct game a,struct game b);

int main()
{
    game st;

   st=start();


    sleep(2);////assume the game take 60 sec//
    game  et;
    et=end();
    game_time=timegame(st,et);///after the end of the game to print the time of the game//

    printf("hours:  %d/mints:  %d/seconds:  %d",game_time.hours, game_time.min, game_time.sec);


}
 game timegame(struct game a,struct game b)
{

  struct game po;
   if(a.sec>b.sec)
   {
       b.sec+=60;
       --b.min;
   }

  if(a.min>b.min)
  {
      b.min+=60;
      --b.hours;
  }
    po.sec=abs(b.sec-a.sec);
    po.min=abs(b.min-a.min);
    po.hours=abs(b.hours-a.hours);
    return po;

}
 game start()
{
    time_t start=time(NULL);
    struct tm *t1=localtime(&start);
    time1.hours=t1->tm_hour;
    time1.min=t1->tm_min;
    time1.sec=t1->tm_sec;
    return time1;
}
 game end(){

 time_t stop=time(NULL);
  struct tm  *t2=localtime(&stop);
    time2.hours=t2->tm_hour;
    time2.min=t2->tm_min;
    time2.sec=t2->tm_sec;
    return time2;


 }
