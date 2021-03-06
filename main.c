
// compile with 
// zcc +zx -m -create-app -startup=1 -clib=new  main.c -o output

//--------------------- MACROS
#define memory_bpeek(a)    (*(unsigned char *)(a))

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


#define MAX_ENEMIES 255
#define MAX_ENEMIES_ON_SCREEN 6
//MAX_ENEMIES_ON_SCREEN should be the number of enemies you want to see on screen + 1
#define NEAR_PLAYER 2

#define UNSIGNED_CHAR_MAX 255
#define MAX_U_CHAR 255
#define MAX_PLAYER_POS 250
//--------------------- MACROS

#include <stdio.h>//standard input output
#include <stdlib.h> // for atoi
#include <string.h>


#include <input.h>

#include <arch/spectrum.h>

#include <intrinsic.h>//temp to place labels	powerful troubleshooting tool

#include "globalVariables.h"
#include "functions.h"



void Manual_test (void)
{
	player_start_location();		
	player_x_position = playerStart;
		
	//look at enemy_locations[]
	fill_enemy_location_array (); // this is large array filled in with level info
	//print_enemy_location_array();
	
	while (1)
	{
		printf("Player currently at = %d\n", player_x_position);
		
		//search_near_to_player(); //sets playerLow and playerHigh
		
		fill_baddies_array();
		print_baddies_array();

		enter_enemy_to_delete();//<--WORKING ON
		index_cleared_baddies();
		
		printf("number of entries in index %d\n", number_of_index_baddies);
		
		//clean_baddies_array();
		printf("\nclean_baddies_array         ");
		
		//printf("\nbaddies array AFTER");
		//print_baddies_array();
		
		clean_enemy_array();
		printf("clean_enemy_array");

		print_arrays ();
		
		player_x_position ++;
		
		if (player_x_position > 250)
		{
			break;
		}
	}
		//pauseWipe();
}


void Speed_test (void)
{
	player_x_position = 0;
	
	fill_enemy_location_array (); // this is large array filled in with level info
	
	ms_start = timer();//just before our loop
	
	//44070 with nothing but loop
	//44099 with everything in loop
	while (player_x_position < 250)
	{
		fill_baddies_array();

		decision = xorshift8() %6;
		//decision = 3;
		//min is 0 and 5 is max with %6
		
		auto_enemy_to_delete();
		
		index_cleared_baddies();
		//clean_baddies_array();
		
		clean_enemy_array();

		++ player_x_position;
	}
	ms_end = timer();
	ms_diff = ms_end - ms_start;

	printf("finished in  %ld ms\n",ms_diff);
}

//xorshift8 takes 12 ms to run
//full = 44149
//fill_baddies_array(); = 44146 = 3 ms
//auto_enemy_to_delete = 44139 = 7 ms
//index_cleared_baddies = 44146 = 3 ms
//clean_baddies_array = 44146 = 3 ms
//clean_enemy_array = 44146 = 3 ms

//44129 with adjustment in fill_baddies_array()
//	player_x_position ++;	44145
//	++ player_x_position;	44144


void main (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	enemies_per_level =  memory_bpeek(pointerAddy);
	
	zx_cls(INK_BLACK | PAPER_WHITE);
	puts("\x16\x01\x02");
	//		\x16 == set cursor position
	//		\x01 = x position (01) in hex
	//		\x02 = y position (0C) in hex
		
	printf("Welcome to the most boring game ever\n");
	
	printf("\n1 for Manual Entry Test");	
	printf("\n2 for the Speed Test");
		
	while (1)
	{
		if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{
			in_wait_nokey();
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			Manual_test();
		}			
		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{
			in_wait_nokey();
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			Speed_test();
		}
	}
	
	
}
	
		
	


