
// Array of enemy locations in the game
// We use the same Entity structure, with just one difference: X now means the tile

struct Enemy
{
	unsigned char x;        // Tile in X
	unsigned char x_desp;   // Displacement in tile (0-23)
	unsigned char y;        // Y position
	unsigned char sprnum;	// Number of the enemy sprite: if 0, this enemy is not active
	unsigned char movement;	// movement type, from one of the predefined ones
	unsigned char energy;
	unsigned char param1;
	unsigned char param2;	// Two parameters, to store some information that is entity-specific
} enemy_locations[MAX_ENEMIES];

struct baddies
{
	unsigned char x;        // Tile in X
	unsigned char x_desp;   // Displacement in tile (0-23)
	unsigned char y;        // Y position
	unsigned char sprnum;	// Number of the enemy sprite: if 0, this enemy is not active
	unsigned char movement;	// movement type, from one of the predefined ones
	unsigned char energy;
	unsigned char param1;
	unsigned char param2;	// Two parameters, to store some information that is entity-specific
	signed int wherefrom;
} baddies[MAX_ENEMIES_ON_SCREEN];


unsigned char indexToDelete [MAX_ENEMIES_ON_SCREEN];
//--------------------------------------------------------------

unsigned char temp1 = 0;
unsigned char temp2 = 0;
unsigned char temp3 = 0;

unsigned char number_of_index_baddies = 0;

static unsigned char y8 = 1;//used in randomizer can be any 8 bit number

unsigned char decision;

unsigned char enemies_per_level = 0;

int ms_start, ms_end, ms_diff = 0;
unsigned char clock_1 = 0;
unsigned char clock_2 = 0;
unsigned char clock_3 = 0;
unsigned int clock_4 = 0;
//-----------------------------------------------------------------------

unsigned int pointerAddy;
unsigned int keypress;

unsigned int arrayInput[5];


int player_x_position = 0;
int playerLow = 0;
int playerHigh = 0;
int playerStart = 0;

unsigned char enemyToDelete = 254;