
// compile with 
// zcc +zx -m -create-app -startup=1 -clib=new  main.c -o output

//--------------------- MACROS
#define memory_bpeek(a)    (*(unsigned char *)(a))

#define MAX_ENEMIES 255
#define MAX_ENEMIES_ON_SCREEN 6
//MAX_ENEMIES_ON_SCREEN should be the number of enemies you want to see on screen + 1
#define NEAR_PLAYER 2

#define UNSIGNED_CHAR_MAX 255
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

		enter_enemy_to_delete();
		index_cleared_baddies();
		clean_baddies_array();
		
		
		clean_enemy_array();
					
		printf("\nPress ENTER for next\n1 for the entire enemy array\n2 for the baddies array");
			
		while (1)
		{
			if (in_key_pressed( IN_KEY_SCANCODE_1 ))
			{
				//printf("\n WTF");
				print_entire_enemy_array();
				break;
			}			
			if (in_key_pressed( IN_KEY_SCANCODE_2 ))
			{
				//printf("\n WTF");
				print_baddies_array();
				break;
			}
			if (in_key_pressed( IN_KEY_SCANCODE_ENTER ))
			{
				break;
			}
			in_pause(100);
				
		}
		player_x_position ++;
		//if (player_x_position > 255)
		//	break;
			
		pauseWipe();
	}

		//pauseWipe();
}



