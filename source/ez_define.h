#define MAX_pReadCache_size 0x20000
#define MAX_files     0x200
#define MAX_folder    0x100
#define MAX_NOR				0x40

#define MAX_path_len 0x100

#define FAT_table_size 0x400
//#define FAT_table_SAV_offset 0x200
#define FAT_table_RTS_offset 0x300

#define DEBUG

#define VideoBuffer    (u16*)0x6000000
#define Vcache         (u16*)pReadCache
#define RGB(r,g,b) ((r)+(g<<5)+(b<<10))

#define PSRAMBase_S98			(void*)0x08800000
#define FlashBase_S98 		(u32)0x09000000
#define FlashBase_S98_end (u32)0x09800000

#define SAVE_sram_base (u32)0x0E000000
#define SRAMSaver		   (u32)0x0E000000

#define UNBCD(x) (((x) & 0xF) + (((x) >> 4) * 10))
#define _BCD(x) ((((x) / 10)<<4) + ((x) % 10))
#define _YEAR	0
#define _MONTH	1
#define _DAY	2
#define _WKD	3
#define _HOUR	4
#define _MIN	5
#define _SEC	6

#define	_UnusedVram 		(void*)0x06012c00

#define FlashBase_S71		(void*)0x08000000

#define SAVE_info_offset 0x790000
#define NOR_info_offset 0x7A0000
#define SET_info_offset 0x7B0000


#define SAVER_FOLDER "/SAVER"

#define  DMA_COPY_MODE 0X1
#define  SET_PARAMETER_MODE  0x2

#define gImage_Chinese_manual 	(void*)0x08100000
#define gImage_English_manual 	(void*)0x08102648
#define gImage_splash						(void*)0x08104C90
#define gImage_SD 							(void*)0x08117890
#define gImage_NOR 							(void*)0x0812A490
#define gImage_SET 							(void*)0x0813D090
#define gImage_SET2 						(void*)0x0814FC90
#define gImage_HELP 						(void*)0x08162890
#define gImage_RECENTLY 				(void*)0x08175490
#define gImage_NOTFOUND 				(void*)0x08188090 
#define gImage_icon_gba 				(void*)0x0818CB90
#define gImage_icon_folder 			(void*)0x0818CD50
#define gImage_icon_other 			(void*)0x0818CF10
#define gImage_icon_FC					(void*)0x0818D0D0
#define gImage_icon_GB					(void*)0x0818D290
#define gImage_icon_nor					(void*)0x0818D450
#define gImage_MENU							(void*)0x0818D610



#define gl_color_text 				(*(u16*)0x08194410)  //= RGB(31,31,31);
#define gl_color_selectBG_sd 	(*(u16*)0x08194412)  //= RGB(00,00,31);
#define gl_color_selectBG_nor (*(u16*)0x08194414)  //= RGB(10,10,10);
#define gl_color_cheat_black  (*(u16*)0x08194416)  //= RGB(00,00,00);

#define gl_color_MENU_btn			(*(u16*)0x0819441C)  //= RGB(20,20,20);
#define gl_color_selected 		(*(u16*)0x0819441E)  //= RGB(00,20,26);
#define gl_color_cheat_count  (*(u16*)0x08194420)  //= RGB(00,31,00);
#define gl_color_NORFULL      (*(u16*)0x08194422)  //= RGB(31,00,00);
#define gl_color_btn_clean    (*(u16*)0x08194424)  //= RGB(00,00,31);






#define assress_language 0
#define assress_v_reset 1
#define assress_v_rts	2
#define assress_v_sleep 3
#define assress_v_cheat 4
#define assress_edit_sleephotkey_0 5
#define assress_edit_sleephotkey_1 6
#define assress_edit_sleephotkey_2 7  
#define assress_edit_rtshotkey_0 8
#define assress_edit_rtshotkey_1 9
#define assress_edit_rtshotkey_2 10
#define assress_engine_sel  11
#define assress_show_Thumbnail 12
#define assress_ingame_RTC_open_status 13
#define assress_auto_save_sel 14
#define assress_ModeB_INIT 15
#define assress_led_open_sel 16
#define assress_Breathing_R 17
#define assress_Breathing_G 18
#define assress_Breathing_B 19
#define assress_SD_R 20
#define assress_SD_G 21
#define assress_SD_B 22

#define assress_saveMODE 64
#define assress_max 65

#define newomega_top_bin_size  0x535bc////0x536d0//0x534A8//
#define newomega_top_bin_address (void*)0x08195000