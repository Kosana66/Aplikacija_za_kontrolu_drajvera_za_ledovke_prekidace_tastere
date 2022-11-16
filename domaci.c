#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
int main () {




        FILE *fp;
        unsigned int br1, br2, res;
        unsigned int novo, staro = 0;
        char *str;
        char lval1,lval2,lval3,lval4;
        char tval4;
        char sval1,sval2,sval3,sval4;
        size_t num_of_bytes = 6;
        while(1)

                {


                //Citanje vrednosti tastera
                fp = fopen ("/dev/button", "r");
                if(fp==NULL)
                {
                        puts("Problem pri otvaranju /dev/button\n");
                        return -1;
                }
                str = (char *)malloc(num_of_bytes+1);
                getline(&str, &num_of_bytes, fp);
                if(fclose(fp))
                {
                        puts("Problem pri zatvaranju /dev/button\n");
                        return -1;
                }
                tval4 = str[5] - 48;
                free(str);


     		novo=0;
                if(tval4)
                     novo=1;


                if( novo!=0 && novo!=staro )
     		{

					 printf("---------------------------------------\n");
                                        //Citanje vrednosti dioda
                                        fp = fopen ("/dev/led", "r");
                                        if(fp==NULL)
                                        {
                                                puts("Problem pri otvaranju /dev/led\n");
                                                return -1;
                                        }
                                        str = (char *)malloc(num_of_bytes+1);
                                        getline(&str, &num_of_bytes, fp);
                                        if(fclose(fp))
                                        {
                                                puts("Problem pri zatvaranju /dev/led\n");
                                                return -1;
                                        }
			
			
					lval1 = str[2] - 48;
                                        lval2 = str[3] - 48;
                                        lval3 = str[4] - 48;
                                        lval4 = str[5] - 48;
                                        free(str);
                                        printf("Vrednosti ledovke su: %d %d %d %d \n", lval1, lval2, lval3, lval4);

                                        if(lval1==0 && lval2==0 && lval3==0 && lval4==0 )
                                                br1=0;
                                        else if(lval1==0 && lval2==0 && lval3==0 && lval4==1 )
                                                br1=1;
                                        else if(lval1==0 && lval2==0 && lval3==1 && lval4==0 )
                                                br1=2;
                                        else if(lval1==0 && lval2==0 && lval3==1 && lval4==1 )
                                                br1=3;
                                        else if(lval1==0 && lval2==1 && lval3==0 && lval4==0 )
                                                br1=4;
                                        else if(lval1==0 && lval2==1 && lval3==0 && lval4==1 )
                                                br1=5;
                                        else if(lval1==0 && lval2==1 && lval3==1 && lval4==0 )
                                                br1=6;
                                        else if(lval1==0 && lval2==1 && lval3==1 && lval4==1 )
                                                br1=7;
                                        else if(lval1==1 && lval2==0 && lval3==0 && lval4==0 )
                                                br1=8;
                                        else if(lval1==1 && lval2==0 && lval3==0 && lval4==1 )
                                                br1=9;
                                        else if(lval1==1 && lval2==0 && lval3==1 && lval4==0 )
                                                br1=10;
                                        else if(lval1==1 && lval2==0 &&lval3==1 && lval4==1 )
						br1=11;
                                        else if(lval1==1 && lval2==1 && lval3==0 && lval4==0 )
                                                br1=12;
                                        else if(lval1==1 && lval2==1 && lval3==0 && lval4==1 )
                                                br1=13;
                                        else if(lval1==1 && lval2==1 && lval3==1 && lval4==0 )
                                                br1=14;
                                        else if(lval1==1 && lval2==1 && lval3==1 && lval4==1 )
                                                br1=15;
                                        printf(" broj 1 je : %d \n", br1);
			
                                        //Citanje vrednosti prekidaca
                                        fp = fopen ("/dev/switch", "r");
                                        if(fp==NULL)
                                        {
                                                puts("Problem pri otvaranju /dev/switch\n");
                                                return -1;
                                        }
                                        str = (char *)malloc(num_of_bytes+1);
                                        getline(&str, &num_of_bytes, fp);
                                        if(fclose(fp))
                                        {
                                                puts("Problem pri zatvaranju /dev/switch\n");
                                                return -1;
                                        }
                                        sval1 = str[2] - 48;
                                        sval2 = str[3] - 48;
                                        sval3 = str[4] - 48;
                                        sval4 = str[5] - 48;
                                        free(str);
                                        printf("Vrednosti prekidaca su: %d %d %d %d \n", sval1, sval2, sval3, sval4);
			
					if(sval1==0 && sval2==0 )
                                                br2=0;
                                        else if(sval1==0 && sval2==1 )
                                                br2=1;
                                        else if(sval1==1 && sval2==0 )
                                                br2=2;
                                        else if(sval1==1 && sval2==1 )
                                                br2=3;
                                        printf(" broj 2 je : %d \n", br2);
			
                                        if(sval3==0 && sval4==0 )
                                                br1 = br1 + br2;
                                        else if(sval3==0 && sval4==1 )
                                                br1 = br1 - br2;
                                        else if(sval3==1 && sval4==0 )
                                                br1 = br1 * br2;
                                        else if(sval3==1 && sval4==1 )
                                                br1 = br1 / br2;
                                        printf(" resenje je : %d \n", br1);
			
                                        fp = fopen ("/dev/led", "w");
                                        if(fp==NULL)
                                        {
                                                puts("Problem pri otvaranju /dev/led tokom upisa\n ");
                                                return -1;
                                        }
					
					if(br1==0)
                                                fputs("0x00", fp);
                                        if(br1==1)
                                                fputs("0x01", fp);
                                        if(br1==2)
                                                fputs("0x02", fp);
                                        if(br1==3)
                                                fputs("0b03", fp);
                                        if(br1==4)
                                                fputs("0x04", fp);
                                        if(br1==5)
                                                fputs("0x05", fp);
                                        if(br1==6)
                                                fputs("0x06", fp);
                                        if(br1==7)
                                                fputs("0x07", fp);
                                        if(br1==8)
                                                fputs("0x08", fp);
                                        if(br1==9)
                                                fputs("0x09", fp);
                                        if(br1==10)
                                                fputs("0x0A", fp);
                                        if(br1==11)
                                                fputs("0x0B", fp);
                                        if(br1==12)
                                                fputs("0x0C", fp);
                                        if(br1==13)
                                                fputs("0x0D", fp);
                                        if(br1==14)
                                                fputs("0x0E", fp);
                                        if(br1==15)
                                                fputs("0x0F", fp);
					
					 if(fclose(fp))
                                        {
                                                puts("Problem pri zatvaranju /dev/led tokom upisa\n");
                                                return -1;
                                        }

                                        printf("---------------------------------------\n");
		}
		staro=novo;
		usleep(1000);
        }
}

