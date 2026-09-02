#include <lpc21xx.h>
#include "CAN.h"
#include "CAN_defines.h"
#include "LCD.h"
#include "DS18B20.h"
#include "EINT.h"
#include "delay.h"

int integer, decimal;
int temp;

// CG RAM functions

void load_right_arrow()
{
    cmd_LCD(0x40);   // CGRAM location 0

    char_LCD(0x04);  // 00100
    char_LCD(0x06);  // 00110
    char_LCD(0x1F);  // 11111
    char_LCD(0x1F);  // 11111
    char_LCD(0x06);  // 00110
    char_LCD(0x04);  // 00100
    char_LCD(0x00);
    char_LCD(0x00);
}

void load_left_arrow()
{
    cmd_LCD(0x48);   // CGRAM location 1

    char_LCD(0x04);  // 00100
    char_LCD(0x0C);  // 01100
    char_LCD(0x1F);  // 11111
    char_LCD(0x1F);  // 11111
    char_LCD(0x0C);  // 01100
    char_LCD(0x04);  // 00100
    char_LCD(0x00);
    char_LCD(0x00);
}
void left_arrow_move()
{
    int pos;

    // Display one by one
    for(pos = 8; pos >= 6; pos--)
    {
        cmd_LCD(0xD4 + pos);
        char_LCD(1);

        delay_ms(200);
    }

    // Clear after all displayed
    for(pos = 8; pos >= 6; pos--)
    {
        cmd_LCD(0xD4 + pos);
        char_LCD(' ');
    }
}

void right_arrow_move()
{
    int pos;

    // Display one by one
    for(pos = 17; pos <= 19; pos++)
    {
        cmd_LCD(0xD4 + pos);
        char_LCD(0);

        delay_ms(200);
    }

    //delay_ms(300);

    // Clear after all displayed
    for(pos = 17; pos <= 19; pos++)
    {
        cmd_LCD(0xD4 + pos);
        char_LCD(' ');
    }
}

void Vehicle_Dashboard(void)
{
        cmd_LCD(0x80);
        str_LCD("** VEH DASHBOARD  **");
        cmd_LCD(0xC0);
        str_LCD("TEM:");
        temp= ReadTemp();
        integer=(temp)/16;
        decimal=(((int)temp%16) *10)/16;
        num_LCD(integer);
        char_LCD('.');
        num_LCD(decimal);
        char_LCD(0xDF);
        char_LCD('C');
        cmd_LCD(0xC0 + 10);
        str_LCD("  MOD: FWD");
        cmd_LCD(0x94);
        str_LCD("ENGINE STATUS:");
        cmd_LCD(0xD4);
        str_LCD("IND : ");
        cmd_LCD(0xd4 + 6 );
        char_LCD(1);
        char_LCD(1);
        char_LCD(1);
        cmd_LCD(0xd4 + 9 );
        str_LCD(" L    R ");
        cmd_LCD(0xd4 + 17 );
        char_LCD(0);
        char_LCD(0);
        char_LCD(0);
        cmd_LCD(0x94 + 14);
        if(integer<40) str_LCD("  SAFE");
        else if(integer>=40 && integer<70) str_LCD(" WARM!");
        else {
                str_LCD(" HOT!!");
                delay_s(1);
                cmd_LCD(0x01);
                cmd_LCD(0xc0);
                str_LCD("ENGINE OVERHEATED !!");
                cmd_LCD(0x94);
                str_LCD("! STOP VEHICLE NOW !");
                delay_s(1);
                cmd_LCD(0x01);
        }
}

void Right_Indicator(void){
        cmd_LCD(0x80);
        str_LCD("** VEH DASHBOARD  **");
        cmd_LCD(0xC0);
        str_LCD("TEM:");
        temp= ReadTemp();
        integer=(temp)/16;
        decimal=(((int)temp%16) *10)/16;
        num_LCD(integer);
        char_LCD('.');
        num_LCD(decimal);
        char_LCD(0xDF);
        char_LCD('C');
        cmd_LCD(0xC0 + 10);
        str_LCD("  MOD: FWD");
        cmd_LCD(0x94);
        str_LCD("ENGINE STATUS:");
        cmd_LCD(0xD4);
        str_LCD("IND : ");
        cmd_LCD(0xd4 + 6 );
        char_LCD(1);
        char_LCD(1);
        char_LCD(1);
        cmd_LCD(0xd4 + 9 );
        str_LCD(" L    R ");
        cmd_LCD(0x94 + 14);
        if(integer<40) str_LCD("  SAFE");
        else if(integer>=40 && integer<70) str_LCD(" WARM!");
        else {
                str_LCD(" HOT!!");
                cmd_LCD(0xd4 + 17 );
                char_LCD(0);
                char_LCD(0);
                char_LCD(0);
                delay_s(1);
                cmd_LCD(0x01);
                cmd_LCD(0xc0);
                str_LCD("ENGINE OVERHEATED !!");
                cmd_LCD(0x94);
                str_LCD("! STOP VEHICLE NOW !");
                delay_s(1);
                cmd_LCD(0x01);
        }
        if(integer<70)
                right_arrow_move();
}

void Left_Indicator(void){
        cmd_LCD(0x80);
        str_LCD("** VEH DASHBOARD  **");
        cmd_LCD(0xC0);
        str_LCD("TEM:");
        temp= ReadTemp();
        integer=(temp)/16;
        decimal=(((int)temp%16) *10)/16;
        num_LCD(integer);
        char_LCD('.');
        num_LCD(decimal);
        char_LCD(0xDF);
        char_LCD('C');
        cmd_LCD(0xC0 + 10);
        str_LCD("  MOD: FWD");
        cmd_LCD(0x94);
        str_LCD("ENGINE STATUS:");
        cmd_LCD(0xD4);
        str_LCD("IND : ");
        cmd_LCD(0xd4 + 9 );
        str_LCD(" L    R ");
        cmd_LCD(0xd4 + 17 );
        char_LCD(0);
        char_LCD(0);
        char_LCD(0);
        cmd_LCD(0x94 + 14);
        if(integer<40) str_LCD("  SAFE");
        else if(integer>=40 && integer<70) str_LCD(" WARM!");
        else {
                str_LCD(" HOT!!");
                cmd_LCD(0xd4 + 6 );
                char_LCD(1);
                char_LCD(1);
                char_LCD(1);
                delay_s(1);
                cmd_LCD(0x01);
                cmd_LCD(0xc0);
                str_LCD("ENGINE OVERHEATED !!");
                cmd_LCD(0x94);
                str_LCD("! STOP VEHICLE NOW !");
                delay_s(1);
                cmd_LCD(0x01);
        }
        if(integer<70)
                left_arrow_move();
}

void vehicle(void)
{
        cmd_LCD(0xc0);
        str_LCD("   VEHICLE SYSTEM   ");
        cmd_LCD(0x94);
        str_LCD("   INITIALISING.... ");
        delay_s(2);
}
