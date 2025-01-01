 /* Datum.c                                    *
 * Datum gibt das aktuelle Datum und die Zeit *
 * in deutschem Format aus                    */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

char Monat[12] [10] = {"Januar", "Februar", "MÃƒÂ¤rz", "April", "Mai", "Juni",
      "Juli", "August", "September", "Oktober", "November", "Dezember"};
char Wochentag[7] [12] = {"Sonntag", "Montag", "Dienstag", "Mittwoch",
      "Donnerstag", "Freitag", "Samstag"};

int Woche,Tag,Mon,Jahr,Stunde,Minute,Sekunde;
char Begr[80];                                /* Variable für die Begrüßung */
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

   /*            Zeit wird ausgewertet und die Begráung gesetzt:            */
   if (Stunde>=0 && Stunde<=3)
                    strcpy(Begr, "Hi, so sp„ht noch aktiv, ");
   if (Stunde>3  && Stunde<=6)
                    strcpy(Begr, "So frh am Computer? Geh' lieber ins Bett, ");
   if (Stunde>6  && Stunde<=8)
                    strcpy(Begr, "Guten Morgen! Schon so frh auf, ");
   if (Stunde>8  && Stunde<=12)
                    strcpy(Begr, "Guten Morgen, ");
   if (Stunde>12 && Stunde<=18)
                    strcpy(Begr, "Guten Tag, ");
   if (Stunde>18 && Stunde<=23)
                    strcpy(Begr, "Guten Abend, ");
   strcat(Begr, User);
   if (Mon==11 && Tag==24)
   {
                    strcat(Begr, "\nFrohe Weihnachten ");
                    strcat(Begr, User);
   }
   if (Mon==11 && Tag==31)
                    strcat(Begr, "\nIch wnsche eine feuchtfr”hliche Silvester-Party!");
   /*   BegrÃƒÂ¼ÃƒÅ¸ung, Datum und Uhrzeit werden auf StandardgerÃƒÂ¤t ausgegeben:   */
   printf("\n%s\n", Begr);
   printf("\nHeute ist %s, der %d. %s %d. Es ist %02d:%02d:%02d Uhr\n\n", Wochentag[Woche], Tag,
       Monat[Mon], Jahr, Stunde, Minute, Sekunde);
   return(0);
}
