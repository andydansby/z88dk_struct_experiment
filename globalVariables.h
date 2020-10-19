
//enemy struct is used to collect Data from assembly
//enemylocations.asm
//the reason its important to keep a seperate array 
//is on game over status, we can reload the 
//enemies over again
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
} Enemy_structure[MAX_ENEMIES];

//instead of refreshing the much larger struct 
//Enemy_structure, we refresh this smaller array
//baddies  doing so allows a quick refresh
// this struct is refreshed at the end of each cycle
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

//this array is used to capture the index of each
//deleted enemy
// it is then used to reference the Enemy_structure
// struct and set those entries back to 0
unsigned char indexToDelete [MAX_ENEMIES_ON_SCREEN];
//-------------------------------------------------

unsigned char temp1 = 0;
unsigned char temp2 = 0;
unsigned char temp3 = 0;

unsigned char enemies_per_level = 0;

//-----------------------------------------------------------------------

unsigned int pointerAddy;
unsigned int keypress;

unsigned int arrayInput[5];


int player_x_position = 0;
int playerLow = 0;
int playerHigh = 0;
int playerStart = 0;

unsigned char enemyToDelete = 254;