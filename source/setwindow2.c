#include <gba_systemcalls.h>
#include <stdio.h>
#include <stdlib.h>
#include <gba_base.h>
#include <gba_input.h>

#include "ez_define.h"
#include "lang.h"
#include "ezkernel.h"
#include "RTC.h"
#include "draw.h"
#include "Ezcard_OP.h"



u16 auto_save_sel;
u16 ModeB_INIT;
u16 led_open_sel;

u16 Breathing_R;
u16 Breathing_G;
u16 Breathing_B;

u16 SD_R;
u16 SD_G;
u16 SD_B;

extern u16 gl_auto_save_sel;
extern u16 gl_ModeB_init;

extern u16 gl_led_open_sel;
extern u16 gl_Breathing_R;
extern u16 gl_Breathing_G;
extern u16 gl_Breathing_B;

extern u16 gl_SD_R;
extern u16 gl_SD_G;
extern u16 gl_SD_B;

void save_set2_info(void);
extern void Draw_select_icon(u32 X,u32 Y,u32 mode);
extern void IWRAM_CODE Set_LED_control(u16  status);

extern void CheckSwitch(void);
//---------------------------------------------------------------------------------
/*void Draw_select_icon(u32 X,u32 Y,u32 mode)
{
	
	Clear(X+2, Y+2, 8, 8, gl_color_text, 1);
	Clear(X+3, Y+3, 6, 6, RGB(4,8,12), 1);
	if(mode)
		Clear(X+4, Y+4, 4, 4, gl_color_selected, 1);
}*/
//---------------------------------------------------------------------------------
u32 Setting_window2(void)
{
	u16 keys;
	u32 line;
	u32 select;
	u32 Set_OK=0;
	u32 Set_OK_line=0;
	
	//u8 edit_pos=0;
	//u32 i; 
	u32 currstate=0;
	
	char msg[128];
	u16 clean_color;
	//u16 clean_pos;
	//u16 clean_w;
	u32 re_show=1;


	u8 line_total;
	u8 auto_save_pos = 1;			
	u8 led_pos = 1; 

	u8 ModeB_pos = 3;
	
	select = 0;
	u32 y_offset = 24;
	u32 set_offset = 1;
	u32 x_offset = set_offset+9*6+3;
	
	u32 line_x = 17;		


	/*gl_auto_save_sel = Read_SET_info(assress_auto_save_sel);
	gl_ModeB_init = Read_SET_info(assress_ModeB_INIT);
	
	gl_led_open_sel = Read_SET_info(assress_led_open_sel);
	gl_Breathing_R = Read_SET_info(assress_Breathing_R);
	gl_Breathing_G = Read_SET_info(assress_Breathing_G);
	gl_Breathing_B = Read_SET_info(assress_Breathing_B);
	gl_SD_R = Read_SET_info(assress_SD_R);
	gl_SD_G = Read_SET_info(assress_SD_G);
	gl_SD_B = Read_SET_info(assress_SD_B);*/
	CheckSwitch();
	
	auto_save_sel = gl_auto_save_sel;
	ModeB_INIT = gl_ModeB_init;
	
	led_open_sel = gl_led_open_sel;
	Breathing_R = gl_Breathing_R;
	Breathing_G = gl_Breathing_G;
	Breathing_B = gl_Breathing_B;
	SD_R = gl_SD_R;
	SD_G = gl_SD_G;
	SD_B = gl_SD_B;
	
	while(1)
	{
		VBlankIntrWait(); 	
		
		if(re_show)
		{	

			//
			VBlankIntrWait();			
			sprintf(msg,"%s",gl_save);
			DrawHZText12(msg,0,set_offset,y_offset+line_x*0,gl_color_selected,1);
			Draw_select_icon(x_offset,y_offset+line_x*0,(auto_save_sel == 0x1));
			sprintf(msg,"%s",gl_auto_save);
			DrawHZText12(msg,0,x_offset+15,y_offset+line_x*0,(auto_save_pos==0)?gl_color_selected:gl_color_text,1);	

			sprintf(msg,"%s",gl_modeB_INITstr);
			DrawHZText12(msg,0,set_offset,y_offset+line_x*1,gl_color_selected,1);
			
				Draw_select_icon(x_offset,y_offset+line_x*1,(ModeB_INIT == 0x0));
				sprintf(msg,"%s",gl_modeB_RUMBLE);
				DrawHZText12(msg,0,x_offset+15,y_offset+line_x*1,(ModeB_pos==0)?gl_color_selected:gl_color_text,1);	
					
				Draw_select_icon(x_offset+9*6,y_offset+line_x*1,(ModeB_INIT == 0x1));
				sprintf(msg,"%s",gl_modeB_RAM);
				DrawHZText12(msg,0,x_offset+9*6+15,y_offset+line_x*1,(ModeB_pos==1)?gl_color_selected:gl_color_text,1);			
				
				Draw_select_icon(x_offset+17*6,y_offset+line_x*1,(ModeB_INIT == 0x2));
				sprintf(msg,"%s",gl_modeB_LINK);
				DrawHZText12(msg,0,x_offset+17*6+15,y_offset+line_x*1,(ModeB_pos==2)?gl_color_selected:gl_color_text,1);	
												
			sprintf(msg,"%s",gl_led);
			DrawHZText12(msg,0,set_offset,y_offset+line_x*2,gl_color_selected,1);
			Draw_select_icon(x_offset,y_offset+line_x*2,(led_open_sel == 0x1));
			sprintf(msg,"%s",gl_led_open);
			DrawHZText12(msg,0,x_offset+15,y_offset+line_x*2,(led_pos==0)?gl_color_selected:gl_color_text,1);	
			
			if(led_open_sel == 0x1){
				sprintf(msg,"%s",gl_Breathing_light);
				DrawHZText12(msg,0,set_offset,y_offset+line_x*3,gl_color_selected,1);
				
				Draw_select_icon(x_offset,y_offset+line_x*3,(Breathing_R == 0x1));
				sprintf(msg,"%s","R");
				DrawHZText12(msg,0,x_offset+15,y_offset+line_x*3,(led_pos==2)?gl_color_selected:gl_color_text,1);
				
				Draw_select_icon(x_offset+5*6+15,y_offset+line_x*3,(Breathing_G == 0x1));
				sprintf(msg,"%s","G");
				DrawHZText12(msg,0,x_offset+5*6+15+15,y_offset+line_x*3,(led_pos==3)?gl_color_selected:gl_color_text,1);	
				
				Draw_select_icon(x_offset+5*6+5*6+15+15,y_offset+line_x*3,(Breathing_B == 0x1));
				sprintf(msg,"%s","B");
				DrawHZText12(msg,0,x_offset+5*6+5*6+15+15+15,y_offset+line_x*3,(led_pos==4)?gl_color_selected:gl_color_text,1);					

				
				sprintf(msg,"%s",gl_SD_working);
				DrawHZText12(msg,0,set_offset,y_offset+line_x*4,gl_color_selected,1);
				//Draw_select_icon(x_offset,y_offset+line_x*4,(led_open_sel == 0x1));
					
				Draw_select_icon(x_offset,y_offset+line_x*4,(SD_R == 0x1));
				sprintf(msg,"%s","R");
				DrawHZText12(msg,0,x_offset+15,y_offset+line_x*4,(led_pos==5)?gl_color_selected:gl_color_text,1);
				VBlankIntrWait();					
				Draw_select_icon(x_offset+5*6+15,y_offset+line_x*4,(SD_G == 0x1));
				sprintf(msg,"%s","G");
				DrawHZText12(msg,0,x_offset+5*6+15+15,y_offset+line_x*4,(led_pos==6)?gl_color_selected:gl_color_text,1);	

				Draw_select_icon(x_offset+5*6+5*6+15+15,y_offset+line_x*4,(SD_B == 0x1));
				sprintf(msg,"%s","B");
				DrawHZText12(msg,0,x_offset+5*6+5*6+15+15+15,y_offset+line_x*4,(led_pos==7)?gl_color_selected:gl_color_text,1);	
				line_total = 3;			
			}
			else{
				
				ClearWithBG((u16*)gImage_SET2,0, y_offset+line_x*3, 240, 160-(y_offset+line_x*2), 1);
				line_total = 3;	
			}
			u32 offsety;

			for(line=0;line<line_total;line++)
			{
				if(Set_OK==1)
				{
					if( (line== select) && (0== select) && (auto_save_pos==1)) 
						clean_color = gl_color_btn_clean;	
					else if((line== select) && (1== select) && (ModeB_pos==3)) 
						clean_color = gl_color_btn_clean;	
					else if((line== select) && (2== select) && (led_pos==1)) 
						clean_color = gl_color_btn_clean;							
					else 
						clean_color = gl_color_MENU_btn;
				}		
				else
				{
					if(line== select)
						clean_color = gl_color_btn_clean;
					else 
						clean_color = gl_color_MENU_btn;
				}	
				offsety = y_offset + line*line_x;
				//if(line>1) offsety += line_x; 
					
				Clear(202,offsety-2 ,30,14,clean_color,1);	
				
				if(Set_OK && (line == Set_OK_line)){
					sprintf(msg,"%s",gl_ok_btn);
				}
				else {
					sprintf(msg,"%s",gl_set_btn);
				}
				DrawHZText12(msg,0,200+5,offsety,gl_color_text,1);	
				VBlankIntrWait();		
			}
			VBlankIntrWait();	
		}		
			
		currstate=Set_OK;		
		switch(currstate) {
			case 0: //initial state
				re_show = 0;		
				scanKeys();
				keys = keysDown();
				if (keys & KEY_A) {//set
					Set_OK_line = select;
					Set_OK = 1;//!Set_OK;
					re_show=1;
	
					if(select == 1){
						ModeB_pos = 0;
					}
					else if(select==2)
					{
						led_pos = 0;
					}
				}
				else if (keys  & KEY_DOWN){  
					if(select < line_total-1){
						select++;		
						re_show=1;
					}
				}
				else if(keys & KEY_UP){
					if(select){
						select--;
						re_show=1;
					}
				}  		
				else if(keys & KEY_L) {
					return 0;
				}
				else if(keys & KEY_R) {
					return 1;
				}		
				break	;
			case 1: //edit state														
					VBlankIntrWait();	
					
					re_show = 0;		
					scanKeys();
					keys = keysDown();
					u16 keys_released = keysUp();
					//u16 keysrepeat = keysDownRepeat();
					if(keys_released & KEY_UP) {						 
							if(led_pos>4)
								led_pos -= 3; 				
							else if(led_pos>1)
								led_pos = 0; 
						re_show = 1;								
					} else if(keys_released & KEY_DOWN) {
						if((select ==2) && (led_open_sel == 0x1))
						{
							if(led_pos<2)
								led_pos = 2; 
							else if(led_pos<5)
								led_pos += 3;
								
							re_show = 1;			 
						}						
					} else if(keys & KEY_RIGHT) {
						if(select ==0)
						{
							auto_save_pos = 1;
						}
						else if(select ==1)
						{
							if(ModeB_pos<4)
								ModeB_pos++;
						}
						else if(select ==2)
						{
							if((led_pos==0) || (led_pos==4 ) || (led_pos==7)) 
								led_pos = 1; 
							else if((led_pos<4) && (led_pos>1) )
								led_pos ++; 
							else if((led_pos<7) && (led_pos>1))
								led_pos ++; 	
						}
						re_show = 1;	
					} else if(keys & KEY_LEFT) {
						
						if(select ==0)
						{
							auto_save_pos = 0;
						}
						else if(select ==1)
						{
							if(ModeB_pos>0)
								ModeB_pos--;
						}
						else if(select ==2)
						{
							if(led_pos==1)
								led_pos = 0; 
							else if(led_pos>5)
								led_pos--;
							else if(led_pos>2)
								led_pos--;						
						}
						re_show = 1;	
					} 
					else if(keys & KEY_A) {
						
						if(select == 0) 
						{
							switch(auto_save_pos)
							{
								case 0:auto_save_sel = !auto_save_sel;break;
								case 1:
									{
										save_set2_info();
										Set_OK = 0;	
										//gl_auto_save_sel = Read_SET_info(11);
										if( (gl_auto_save_sel != 0x0) && (gl_auto_save_sel != 0x1))
										{
											gl_auto_save_sel = 0x1;
										}
										break;							
									}
							}	
						}
						else if(select == 1) 
						{
							switch(ModeB_pos)
							{
								case 0:ModeB_INIT = 0;break;
								case 1:ModeB_INIT = 1;break;
								case 2:ModeB_INIT = 2;break;	
								case 3:
									{
										save_set2_info();
										Set_OK = 0;	
										break;
									}
							}
						}				
						else if(select == 2) 
						{
							switch(led_pos)
							{
								case 0:led_open_sel = !led_open_sel;break;
								case 1:
									{
										save_set2_info();
										Set_OK = 0;	
										/*gl_led_open_sel = Read_SET_info(11);
										if( (gl_led_open_sel != 0x0) && (gl_led_open_sel != 0x1))
										{
											gl_led_open_sel = 0x1;
										}*/
										break;							
									}
								case 2:Breathing_R = !Breathing_R;break;
								case 3:Breathing_G = !Breathing_G;break;
								case 4:Breathing_B = !Breathing_B;break;
								case 5:SD_R = !SD_R;break;
								case 6:SD_G = !SD_G;break;
								case 7:SD_B = !SD_B;break;	
							}	
						}
						re_show = 1;
					}
				break	;			
		}//end switch 		
	}//end while(1)
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
extern u16 SET_info_buffer [0x200]EWRAM_BSS;
void save_set2_info(void)
{
	u32 address;
	for(address=0;address < assress_max;address++)
	{
		SET_info_buffer[address] = Read_SET_info(address);
	}
	SET_info_buffer[assress_auto_save_sel] = auto_save_sel;
	SET_info_buffer[assress_ModeB_INIT] = ModeB_INIT;
	SET_info_buffer[assress_led_open_sel] = led_open_sel;
	SET_info_buffer[assress_Breathing_R] = Breathing_R;
	SET_info_buffer[assress_Breathing_G] = Breathing_G;
	SET_info_buffer[assress_Breathing_B] = Breathing_B;
	SET_info_buffer[assress_SD_R] = SD_R;
	SET_info_buffer[assress_SD_G] = SD_G;
	SET_info_buffer[assress_SD_B] = SD_B;

	
	//save to nor 
	Save_SET_info(SET_info_buffer,0x200);
	u16 led_status = (led_open_sel<<7) | (Breathing_R<<5) | (Breathing_G<<4) | (Breathing_B<<3) | (SD_R<<2) | (SD_G<<1) | (SD_B) ;
	Set_LED_control(led_status);
}