
void fill_baddies_array94 (void)
{
	temp2 = 0;//no more than 6 entries
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	for (temp1 = 0; temp1 < enemies_per_level; ++ temp1)
	{
		if (enemy_locations[temp1].x != 0) 
		{
			if(enemy_locations[temp1].x <= playerHigh)
			{
				if (enemy_locations[temp1].x >= playerLow)
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
			}
			
			else if (temp2 > MAX_ENEMIES_ON_SCREEN) 
			{
				break;//no more than 5 entries
			}
		}
	}
}


void fill_baddies_array95 (void)
{
	temp2 = 0;//no more than 6 entries
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	for (temp1 = 0; temp1 < enemies_per_level; ++ temp1)
	{
		//string = (time < 18) ? "Good day." : "Good evening.";
		temp3 = enemy_locations[temp1].x;
		
		if (temp3 != 0)		
		{
			if(temp3 <= playerHigh)
			{
				if (temp3 >= playerLow) 
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
			}
			
			else if (temp2 > MAX_ENEMIES_ON_SCREEN) 
			{
				break;//no more than 5 entries
			}
		}
	}
}



void fill_baddies_array96 (void)
{
	temp2 = 0;//no more than 6 entries
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	for (temp1 = 0; temp1 < enemies_per_level; ++ temp1)
	{
		if (enemy_locations[temp1].x != 0)		
		{
			if( (enemy_locations[temp1].x <= playerHigh) && (enemy_locations[temp1].x >= playerLow) )
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
}

//good working DO NOT ALTER
void fill_baddies_array97 (void)
{
	temp2 = 0;//no more than 6 entries
	temp1 = 0;
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	while (temp1 < enemies_per_level)
	{
		temp3 = enemy_locations[temp1].x;
		if (temp3 != 0)		
		{
			if(temp3 <= playerHigh)
			{
				if (temp3 >= playerLow) 
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
			}
			
			else if (temp2 > MAX_ENEMIES_ON_SCREEN) 
			{
				break;//no more than 5 entries
			}
		}
		temp1 ++;
	} 
}

//good working DO NOT ALTER
void fill_baddies_array98 (void)
{
	temp2 = 0;//no more than 6 entries
	temp1 = 0;
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	do
	{
		if (enemy_locations[temp1].x != 0)		
		{
			if(enemy_locations[temp1].x <= playerHigh)
			{
				if (enemy_locations[temp1].x >= playerLow) 
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
			}
			
			else if (temp2 > MAX_ENEMIES_ON_SCREEN) 
			{
				break;//no more than 5 entries
			}
		}
		temp1 ++;
	} while (temp1 < enemies_per_level);
}

//good working DO NOT ALTER
void fill_baddies_array99 (void)
{
	temp2 = 0;//no more than 6 entries
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	for (temp1 = 0; temp1 < enemies_per_level; ++ temp1)
	{
		if (enemy_locations[temp1].x != 0)		
		{
			if(enemy_locations[temp1].x <= playerHigh)
			{
				if (enemy_locations[temp1].x >= playerLow) 
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
			}
			
			else if (temp2 > MAX_ENEMIES_ON_SCREEN) 
			{
				break;//no more than 5 entries
			}
		}
	}
}


void fill_baddies_array (void)
{
	temp2 = 0;//no more than 6 entries
	
	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	for (temp1 = 0; temp1 < enemies_per_level; ++ temp1)
	{
		if (enemy_locations[temp1].x != 0) 
		{
			if(enemy_locations[temp1].x <= playerHigh)
			{
				if (enemy_locations[temp1].x >= playerLow)
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
			}
			
			else if (temp2 > MAX_ENEMIES_ON_SCREEN) 
			{
				break;//no more than 5 entries
			}
		}
	}
}
