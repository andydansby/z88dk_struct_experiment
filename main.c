
// compile with 
// zcc +zx -m -create-app -startup=1 -clib=new  main.c -o output

//--------------------- MACROS
#define memory_bpeek(a)    (*(unsigned char *)(a))

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
		
		//printf("\nbaddies array BEFORE");
		//print_baddies_array();
		
		clean_baddies_array();
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



