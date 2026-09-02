#include <lpc21xx.h>
#include "CAN.h"
#include "CAN_defines.h"
#include "LCD.h"
#include "DS18B20.h"
#include "EINT.h"
#include "delay.h"
#include "pro_funcs.h"

volatile unsigned char f1 = 0, f2 = 0, f3 = 0;        // Flags updated by interrupts
struct CAN_Frame TX_frame1, TX_frame2, Rx_frame;

int main()
{
	// Intializations
	Init_CAN1();
  init_LCD();
  Interrupt_Init();
  load_right_arrow();
  load_left_arrow();
  IODIR0|=1<<21;
  IOSET0=1<<21;
  TX_frame1.ID=1;
  TX_frame1.vbf.RTR=0;
  TX_frame1.vbf.DLC=4;

  vehicle();
  cmd_LCD(0x01);

  while(1)
	{
		if(f1==1 && f2==0 && f3==0)
		{
			Left_Indicator();
      // CAN transmition
      TX_frame1.Data1=1;
      TX_frame1.Data2=0;
      CAN1_Tx(TX_frame1);
    }

    else if(f2==1 && f1==0 && f3==0)
		{
      Right_Indicator();
      // CAN transmition
      TX_frame1.Data1=2;
      TX_frame1.Data2=0;
      CAN1_Tx(TX_frame1);
    }

    else if(f3==1 && f2==0 && f1==0)
		{
      cmd_LCD(0x80);
      str_LCD("* REVERSE MODE ON  *");
      TX_frame2.ID=2;
      TX_frame2.vbf.RTR=0;
      TX_frame2.vbf.DLC=8;
      TX_frame2.Data1=1;
      TX_frame2.Data2=0;
      CAN1_Tx(TX_frame2);

      if(C1GSR & 0x01)
			{
				CAN1_Rx(&Rx_frame);
        if(Rx_frame.ID==3)
				{
					cmd_LCD(0xc0);
          str_LCD(" DISTANCE : ");
          num_LCD(Rx_frame.Data1);
          cmd_LCD(0xC0 + 15);
          char_LCD(' ');
          cmd_LCD(0xc0 + 16);
          str_LCD("CM  ");
          if(Rx_frame.Data1 > 50)
					{
						cmd_LCD(0x94);
            str_LCD("   PATH IS CLEAR    ");
            cmd_LCD(0xD4);
            str_LCD("    MOVE SLOWLY     ");
          }
          
					else if(Rx_frame.Data1 <= 50 && Rx_frame.Data1 > 20)
					{
						cmd_LCD(0x94);
            str_LCD("   OBJECT NEARBY    ");
            cmd_LCD(0xD4);
            str_LCD("   DRIVE CAREFUL    ");
          }
          
					else if(Rx_frame.Data1 <= 20 && Rx_frame.Data1 > 10)
					{
						cmd_LCD(0x94);
            str_LCD("  OBJECT DETECTED   ");
            cmd_LCD(0xD4);
            str_LCD("    SLOW DOWN !!    ");
          }
          
					else
					{
						IOCLR0=1<<21;
            delay_ms(400);
            IOSET0=1<<21;
            cmd_LCD(0x94);
            str_LCD("    !! WARNING !!   ");
            cmd_LCD(0xD4);
            str_LCD("    STOP VEHICLE    ");
          }
          cmd_LCD(0xc0 + 13);
          str_LCD("  ");
        }
      }
    }
    else
		{
			Vehicle_Dashboard();
      //TX_frame1.Data1=0;
      //TX_frame1.Data2=0;
      //CAN1_Tx(TX_frame1);
    }
  }
}
