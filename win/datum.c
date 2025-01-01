 /* Datum.c                                    *
 * Datum gibt das aktuelle Datum und die Zeit *
 * in deutschem Format aus                    */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

char Monat[12] [10] = {"Januar", "Februar", "März", "April", "Mai", "Juni",
      "Juli", "August", "September", "Oktober", "November", "Dezember"};
char Wochentag[7] [12] = {"Sonntag", "Montag", "Dienstag", "Mittwoch",
      "Donnerstag", "Freitag", "Samstag"};

int Woche,Tag,Mon,Jahr,Stunde,Minute,Sekunde;
char Begr[80];                                /* Variable für die Begrüßung */
char Greetings[40];
char User[20];
struct tm *tp;                                /*   Variablenstruktur für    */
time_t t;                                     /*          die Zeit          */

int main(void)
{
   strcpy(User, getenv("USERNAME"));

   time(&t);                                     /*        Zeit        */
   tp=localtime(&t);                             /*     wird geholt    */
   Woche=tp->tm_wday;                            /* Wochentag als Zahl */
   Tag=tp->tm_mday;                              /*        Datum       */
   Mon=tp->tm_mon;                               /*   Monat als Zahl   */
   Jahr=1900+tp->tm_year;                        /*        Jahr        */
   Stunde=tp->tm_hour;                           /*   aktuelle Stunde  */
   Minute=tp->tm_min;                            /*   aktuelle Minute  */
   Sekunde=tp->tm_sec;                           /*  aktuelle Sekunde  */

   /*            Zeit wird ausgewertet und die Begrüßung gesetzt:            */
   if (Stunde>=0 && Stunde<=3)
                    sprintf(Begr, "Hi %s, so spät noch aktiv?", User);
   if (Stunde>3  && Stunde<=6)
                    sprintf(Begr, "So früh am Computer %s? Geh' lieber ins Bett", User);
   if (Stunde>6  && Stunde<=8)
                    sprintf(Begr, "Guten Morgen %s! Schon so früh auf?", User);
   if (Stunde>8  && Stunde<=12)
                    sprintf(Begr, "Guten Morgen %s", User);
   if (Stunde>12 && Stunde<=18)
                    sprintf(Begr, "Guten Tag %s", User);
   if (Stunde>18 && Stunde<=23)
                    sprintf(Begr, "Guten Abend %s", User);

   if (Mon==11 && Tag==24)
   {
                    sprintf(Greetings, "\nFrohe Weihnachten %s", User);
                    strcat(Begr, Greetings);
   }
   if (Mon==11 && Tag==31)
                    strcat(Begr, "\nIch wünsche eine feuchtfröhliche Silvester-Party!");
   /*   Begrüßung, Datum und Uhrzeit werden auf Standardgerät ausgegeben:   */
   printf("\n%s\n", Begr);
   printf("\nHeute ist %s, der %d. %s %d. Es ist %02d:%02d:%02d Uhr\n\n", Wochentag[Woche], Tag,
       Monat[Mon], Jahr, Stunde, Minute, Sekunde);
   return(0);
}
