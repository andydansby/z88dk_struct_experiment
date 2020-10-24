//-----------------------------------------------------------------------
//	obsolete routines
//-----------------------------------------------------------------------
void enter_player_location (void)
{
	printf("Enter in your ship's location\n0 - 254\n");
	
	fgets(arrayInput,sizeof(arrayInput),stdin);	
	player_x_position = atoi(arrayInput);
	printf("\n\n");
	in_pause(200);
}

void print_player_location (void)
{
	printf("Player position = %d\n", player_x_position);	
	printf("Press a Key");
	printf("\n\n");
	in_pause(400);
}

void print_pointer_address()
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;		
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;
	
	printf(" LEVEL_1_ENEMIES_LOCATIONS\n pointer address\n\n");
	
	printf("%u\n", pointerAddy);
	printf("%x\n", pointerAddy);
	
	
	printf("\nPress the ANY key\nWherever that is");
}

void search_exact_to_player (void)
{
	//player_x_position  = where the player is
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer	
	//enemies_per_level =  memory_bpeek(pointerAddy);

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
		if (enemy_locations[temp1].x	 == player_x_position)
		{
			printf("%d\n", enemy_locations[temp1].x);
			printf("%d\n", enemy_locations[temp1].x_desp);
			printf("%d\n", enemy_locations[temp1].y);
			printf("%d\n", enemy_locations[temp1].sprnum);
			printf("%d\n", enemy_locations[temp1].movement);
			printf("%d\n", enemy_locations[temp1].energy);
			printf("%d\n", enemy_locations[temp1].param1);
			printf("%d\n", enemy_locations[temp1].param2);
			printf("---------\n");
		}
	}
	printf("\n\nPress a Key");
}


void print_enemy_location_array (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer	
	//enemies_per_level =  memory_bpeek(pointerAddy);	//how many enemies in array
	
	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
		printf("enemy_locations Struct Members\n");
		
		printf("%d\n", enemy_locations[temp1].x);
		printf("%d\n", enemy_locations[temp1].x_desp);
		printf("%d\n", enemy_locations[temp1].y);
		printf("%d\n", enemy_locations[temp1].sprnum);
		printf("%d\n", enemy_locations[temp1].movement);
		printf("%d\n", enemy_locations[temp1].energy);
		printf("%d\n", enemy_locations[temp1].param1);
		printf("%d\n", enemy_locations[temp1].param2);
		
		printf("Array number %d\n", temp1);
		printf("\nPress a key\n");
	}
}

void delete_single_baddy (void)
{
	for (temp1 = enemyToDelete; temp1 < MAX_ENEMIES_ON_SCREEN -1; temp1 ++)
	{
		baddies[temp1].x = baddies[temp1 + 1].x;
		baddies[temp1].x_desp = baddies[temp1 + 1].x_desp;
		baddies[temp1].y = baddies[temp1 + 1].y;
		baddies[temp1].sprnum = baddies[temp1 + 1].sprnum;
		baddies[temp1].movement = baddies[temp1 + 1].movement;
		baddies[temp1].energy = baddies[temp1 + 1].energy;
		baddies[temp1].param1 = baddies[temp1 + 1].param1;
		baddies[temp1].param2 = baddies[temp1 + 1].param2;
	}
}

void print_nearest_baddies(void)
{
	printf("Nearest Baddies\n");

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
		if ((enemy_locations[temp1].x >= playerLow) && (enemy_locations[temp1].x <= playerHigh) )
		{
			printf("%d)---", temp1);
			printf("%d    ", enemy_locations[temp1].x);
			printf("%d    ", enemy_locations[temp1].x_desp);
			printf("%d    ", enemy_locations[temp1].y);
			printf("%d    ", enemy_locations[temp1].sprnum);
			//printf("\n");
			printf("%d    ", enemy_locations[temp1].movement);
			printf("%d    ", enemy_locations[temp1].energy);
			printf("%d    ", enemy_locations[temp1].param1);
			printf("%d    ", enemy_locations[temp1].param2);
			printf("\n");
			printf("----------------------------------------------------\n");
		}
	}
	printf("\n\nPress a Key");
}

void search_near_to_player (void)
{
	//#define memory_bpeek(a)    (*(unsigned char *)(a))
	//player_x_position  = where the player is
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer	
	//enemies_per_level =  memory_bpeek(pointerAddy);
	
	playerLow = player_x_position - 2;
	playerHigh = player_x_position + 2;
	
	if (playerLow < 0)
		playerLow = 0;
	if (playerHigh > 254)
		playerHigh = 254;	
}


//-----------------------------------------------------------------------
//	obsolete routines
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
//	other routines
//-----------------------------------------------------------------------

//keep
void pauseWipe (void)
{
	in_wait_key();
	in_pause(100);
	zx_cls(INK_BLACK | PAPER_WHITE);
	puts("\x16\x01\x02");
}

//-------------------------------------------------------------
//	other routines
//-------------------------------------------------------------

void player_start_location (void)
{
	printf("Enter in player start location    0 - 254    ");
	fgets(arrayInput,sizeof(arrayInput),stdin);
	playerStart = atoi(arrayInput);
	printf("\n");
	in_pause(600);
}

//keep
void fill_enemy_location_array (void)
{	
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;	
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	
	//enemies_per_level =  memory_bpeek(pointerAddy);
	//intrinsic_label(enemies_per_level_results);
	
	pointerAddy ++;

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
		enemy_locations[temp1].x					= memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].x_desp			= memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].y				= memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].sprnum			= memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].movement	= memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].energy			= memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].param1		= memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].param2		= memory_bpeek(pointerAddy);
		pointerAddy ++;
	}	
}


void purge_baddies_array (void)
{
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; temp1 ++)
	{
		//clean baddies array
		baddies[temp1].x = 0;
		baddies[temp1].x_desp = 0;
		baddies[temp1].y = 0;
		baddies[temp1].sprnum = 0;
		baddies[temp1].movement = 0;
		baddies[temp1].energy = 0;
		baddies[temp1].param1 = 0;
		baddies[temp1].param2 = 0;
		baddies[temp1].wherefrom = 0;
	}
}


void fill_baddies_array (void)
{
	//address of pointer
	//enemies_per_level =  memory_bpeek(pointerAddy);
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;
	
	//if (playerLow < 1)
	//	playerLow = 0;
	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;
	
	temp2 = 0;//no more than 10 entries

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
		//if ((enemy_locations[temp1].x >= playerLow) && (enemy_locations[temp1].x <= playerHigh)  && (enemy_locations[temp1].x != 0) )
			//enemy_locations


		if (enemy_locations[temp1].x >= playerLow) 
			if(enemy_locations[temp1].x <= playerHigh)
				if (enemy_locations[temp1].x != 0)//<----
				{
					//copy to baddies struct
					baddies[temp2].x = enemy_locations[temp1].x;
					baddies[temp2].x_desp = enemy_locations[temp1].x_desp;
					baddies[temp2].y = enemy_locations[temp1].y;
					baddies[temp2].sprnum = enemy_locations[temp1].sprnum;
					baddies[temp2].movement = enemy_locations[temp1].movement;
					baddies[temp2].energy = enemy_locations[temp1].energy;
					baddies[temp2].param1 = enemy_locations[temp1].param1;
					baddies[temp2].param2 = enemy_locations[temp1].param2;
					baddies[temp2].wherefrom = temp1;
					temp2 ++;
				}
			
			else if (temp2 > MAX_ENEMIES_ON_SCREEN) 
			{
				break;//no more than 5 entries
			}
	}
}


void print_baddies_array (void)
{
	printf("\nBaddies Array\n");
	
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
			printf("%d)---", temp1);
			printf("%d    ", baddies[temp1].x);
			printf("%d    ", baddies[temp1].x_desp);
			printf("%d    ", baddies[temp1].y);
			printf("%d    ", baddies[temp1].sprnum);
			//printf("\n");
			printf("%d    ", baddies[temp1].movement);
			printf("%d    ", baddies[temp1].energy);
			printf("%d    ", baddies[temp1].param1);
			printf("%d    ", baddies[temp1].param2);
			printf("%d    ", baddies[temp1].wherefrom);
			//wherefrom
			printf("\n");
			//printf("----------------------------------------------------\n");
	}
	//printf("\n\nPress a Key");
}


void enter_enemy_to_delete (void)
{
	//unsigned int arrayInput[5];
	enemyToDelete = 254;
	printf("Enter in enemy to kill    0 - 5    Enter = none  ");	
	//fgets(arrayInput,sizeof(arrayInput),stdin);
	gets(arrayInput);
	
	in_wait_nokey();
	
	if (strlen(arrayInput) == 0)
	{
		printf("\nNone selected \n");
		enemyToDelete = MAX_U_CHAR;
		printf("\n NONE Selected for removal \n");
   }
	else
   {	
		enemyToDelete = atoi(arrayInput);	
		printf("\n Variable enemyToDelete = %d", enemyToDelete);
		printf("\n %d Selected for removal \n", baddies[enemyToDelete].x);
   }

	in_pause(500);
	
	//tag baddy entry
	baddies[enemyToDelete].x = 0;//<---
	baddies[enemyToDelete].x_desp	= 0;
	baddies[enemyToDelete].y = 0;
	baddies[enemyToDelete].sprnum = MAX_U_CHAR;
	baddies[enemyToDelete].movement = 0;
	baddies[enemyToDelete].energy = 0;
	baddies[enemyToDelete].param1 = 0;
	baddies[enemyToDelete].param2 = 0;
	//enemyToDelete = baddies[enemyToDelete].wherefrom;
}

void index_cleared_baddies (void)
{
	temp2 = 0;
	temp3 = 0;
	
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
		if (baddies[temp1].sprnum == MAX_U_CHAR)//<---
		{
			indexToDelete[temp2] = baddies[enemyToDelete].wherefrom;
			temp3 ++;
		}
		else
		{
			indexToDelete[temp2] = MAX_U_CHAR;
		}
		temp2 ++;		
	}
	
	printf("number of entries in index %d\n", temp3);
}



void clean_baddies_array (void)
{
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
		//if (indexToDelete[temp1] != 255)
		{
			baddies[temp1].x = 0;
			baddies[temp1].x_desp = 0;
			baddies[temp1].y =  0;
			baddies[temp1].sprnum = 0;
			baddies[temp1].movement = 0;
			baddies[temp1].energy = 0;
			baddies[temp1].param1 = 0;
			baddies[temp1].param2 = 0;
			baddies[temp1].wherefrom = 0;			
		}
	}
}

//enemy_locations is large array 
void clean_enemy_array (void)
{
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{		
		if (indexToDelete[temp1] != MAX_U_CHAR)
		{
			enemyToDelete = indexToDelete[temp1];
			
			enemy_locations[enemyToDelete].x = 0;
			enemy_locations[enemyToDelete].x_desp	= 0;
			enemy_locations[enemyToDelete].y = 0;
			enemy_locations[enemyToDelete].sprnum = 0;
			enemy_locations[enemyToDelete].movement = 0;
			enemy_locations[enemyToDelete].energy = 0;
			enemy_locations[enemyToDelete].param1 = 0;
			enemy_locations[enemyToDelete].param2 = 0;
		}
		
		
		
		/*
		baddies[temp1].x = 0;
		baddies[temp1].x_desp = 0;
		baddies[temp1].y =  0;
		baddies[temp1].sprnum = 0;
		baddies[temp1].movement = 0;
		baddies[temp1].energy = 0;
		baddies[temp1].param1 = 0;
		baddies[temp1].param2 = 0;
		//indexToDelete[temp1] = 0;
		*/
		
		/*
		if (indexToDelete[temp1] != MAX_U_CHAR)
		{
			enemyToDelete = indexToDelete[temp1];
			
			enemy_locations[enemyToDelete].x = 0;
			enemy_locations[enemyToDelete].x_desp	= 0;
			enemy_locations[enemyToDelete].y = 0;
			enemy_locations[enemyToDelete].sprnum = 0;
			enemy_locations[enemyToDelete].movement = 0;
			enemy_locations[enemyToDelete].energy = 0;
			enemy_locations[enemyToDelete].param1 = 0;
			enemy_locations[enemyToDelete].param2 = 0;
		}*/
	}
}


void print_entire_enemy_array (void)
{
	printf("\nPress x to quit\n\n");
	for (temp1 = 0; temp1 < MAX_ENEMIES; ++ temp1)
	{		
		printf("%d)---", temp1);
		printf("%d    ", enemy_locations[temp1].x);
		printf("%d    ", enemy_locations[temp1].x_desp);
		printf("%d    ", enemy_locations[temp1].y);
		printf("%d    ", enemy_locations[temp1].sprnum);
			//printf("\n");
		printf("%d    ", enemy_locations[temp1].movement);
		printf("%d    ", enemy_locations[temp1].energy);
		printf("%d    ", enemy_locations[temp1].param1);
		printf("%d    ", enemy_locations[temp1].param2);
		printf("\n");
		
		if (in_key_pressed( IN_KEY_SCANCODE_x ))
		{
			break;
		}
	}
	printf("\nPress ENTER\n");
	in_wait_nokey();
}


void print_delete_index (void)
{
	temp2 = 0;
	temp3 = 0;
	
	printf("\n");
		
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
		printf("%d ) indexed entry %d\n", temp1, indexToDelete[temp1]);
		
		if (indexToDelete[temp1] == MAX_U_CHAR )
		{
			temp2 ++;
		}
		else
		{
			temp3 ++;
		}
	}
	
	printf("number of entries %d\n", temp3);
}

void print_arrays (void)
{
	printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
	while (1)
	{
		if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			print_entire_enemy_array();
			printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
		}			
		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			print_baddies_array();
			printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
		}
		if (in_key_pressed( IN_KEY_SCANCODE_3 ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			print_delete_index();
			printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
		}
			//print_delete_index
		if (in_key_pressed( IN_KEY_SCANCODE_ENTER ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			break;
		}
	}
	in_wait_nokey();
}











