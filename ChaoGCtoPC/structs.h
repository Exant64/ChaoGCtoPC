
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

/* 10990 */
struct CHAO_ID
{
	unsigned int gid[2];
	unsigned int id[2];
	unsigned int num;
};

/* 10979 */
struct __declspec(align(2)) AL_BODY_INFO
{
	float HPos;
	float VPos;
	float APos;
	float AimHPos;
	float AimVPos;
	float AimAPos;
	float growth;
	float EyePos;
	float EyeScl;
	float EyeRatio;
	char EyeColor;
	char DefaultEyeNum;
	char DefaultMouthNum;
	char HonbuNum;
	char HonbuColorNum;
	char ObakeHead;
	char ObakeBody;
	char MedalNum;
	char ColorNum;
	char NonTex;
	char JewelNum;
	char MultiNum;
	char EggColor;
	char FormNum;
	char FormSubNum;
};

/* 10980 */
struct AL_TIME
{
	char minute;
	char second;
	char frame;
};

/* 10988 */
struct AL_RACE_PERSONAL_INFO
{
	AL_TIME PersonalRecord[10];
	char nbWin[10];
	unsigned __int16 MedalFlag;
};

/* 10992 */
struct AL_KARATE_PERSONAL_INFO
{
	char rank;
	char level;
	char tournament;
	unsigned __int16 nbBattle;
	unsigned __int16 nbWin;
	unsigned __int16 nbLose;
	unsigned __int16 nbDraw;
};

/* 10978 */
struct AL_PARTS
{
	unsigned int MinimalFlag;
	char MinimalParts[8];
};

/* 10983 */
struct AL_EMOTION
{
	unsigned __int16 Flag;
	unsigned __int16 MoodTimer;
	unsigned __int16 IllTimer;
	unsigned __int16 Timer;
	char Mood[8];
	unsigned __int16 State[11];
	char Personality[13];
	char Taste;
	char Tv;
	char Music;
	char IllState[6];
};

/* 10976 */
struct AL_KNOWLEDGE_PLAYER
{
	char like;
	char fear;
	unsigned __int16 distance;
	unsigned __int16 meet;
};

/* 10993 */
struct __declspec(align(4)) AL_KNOWLEDGE_CHAO
{
	CHAO_ID id;
	char like;
	char fear;
	unsigned __int16 distance;
	unsigned __int16 meet;
};

/* 10987 */
struct AL_KNOWLEDGE_OTHER
{
	char like;
};

/* 10994 */
struct AL_KNOWLEDGE_BTL
{
	char ArtFlag;
	char DanceFlag;
	char SongFlag;
	char MusicFlag;
	unsigned __int16 SToyFlag;
	unsigned __int16 LToyFlag;
	int KwTimer;
	AL_KNOWLEDGE_PLAYER player[6];
	AL_KNOWLEDGE_CHAO chao[20];
	AL_KNOWLEDGE_OTHER bhv[120];
};

/* 10991 */
struct AL_GENE
{
	char IsAnalyzed;
	char EggColor;
	CHAO_ID MotherID;
	CHAO_ID FatherID;
	char MotherName[8];
	char FatherName[8];
	char MGroundMotherName[8];
	char MGroundFatherName[8];
	char FGroundMotherName[8];
	char FGroundFatherName[8];
	char Abl[8][2];
	char LifeTime[2];
	char HPos[2];
	char VPos[2];
	char APos[2];
	char Personality[13][2];
	char Taste[2];
	char Tv[2];
	char Music[2];
	char Color[2];
	char NonTex[2];
	char Jewel[2];
	char Multi[2];
	char EyePos[2];
	char EyeScl[2];
	char EyeRatio[2];
	char EyeColor[2];
};

/* 10981 */
struct AL_RACE_PERSONAL_INFO_DX
{
	AL_TIME PersonalRecord[5];
};

/* 10977 */
struct AL_KNOWLEDGE_DX
{
	AL_KNOWLEDGE_PLAYER player[6];
};

/* 10995 */
struct CHAO_PARAM_GC
{
	char GBAChao;
	char GBAEgg;
	char GBABerry[8];
	char padding0;
	char padding1;
	unsigned int GBARing;
	char BootMethod;
	char Birthplace;
	char name[7];
	char GBAType;
	char GBASkin;
	char GBAMood;
	char GBABelly;
	char GBASleepy;
	char GBALonelyness;
	char padding2;
	char Exp[8];
	char Abl[8];
	char Lev[8];
	unsigned __int16 Skill[8];
	unsigned __int16 GBAPalette[16];
	char rmsg[16];
	unsigned int runaway;
	char dummy[4];
	char type;
	char place;
	__int16 like;
	char ClassNum;
	unsigned __int16 age;
	unsigned __int16 old;
	unsigned __int16 life;
	unsigned __int16 LifeMax;
	unsigned __int16 nbSucceed;
	CHAO_ID ChaoID;
	unsigned int LifeTimer;
	AL_BODY_INFO body;
	AL_RACE_PERSONAL_INFO race;
	AL_KARATE_PERSONAL_INFO karate;
	AL_PARTS PartsBTL;
	AL_EMOTION emotion;
	AL_KNOWLEDGE_BTL knowledgeBTL;
	AL_GENE gene;
	int IsInitializedDX;
	AL_PARTS partsDX;
	AL_RACE_PERSONAL_INFO_DX raceDX;
	AL_KNOWLEDGE_DX knowledgeDX;
};

/* 11007 */
struct chao_save_info
{
	CHAO_PARAM_GC param;
	char dummy[736];
};

struct GARDEN_ID
{
	unsigned int id[2];
};

struct TREE_SAVE_INFO
{
	char kind;
	char state;
	char param;
	char water;
	char FruitGrowth[3];
	char angy_pos;
};

struct NJS_POINT3
{
	float x;
	float y;
	float z;
};

struct ITEM_SAVE_INFO
{
	__int16 kind;
	__int16 place;
	__int16 status;
	__int16 nbVisit;
	NJS_POINT3 pos;
};

struct AL_SHAPE_ELEMENT
{
	char type;
	char DefaultEyeNum;
	char DefaultMouthNum;
	char HonbuNum;
	char ObakeHead;
	char ObakeBody;
	char MedalNum;
	char ColorNum;
	char NonTex;
	char JewelNum;
	char MultiNum;
	char MinimalParts[8];
	__int16 HPos;
	__int16 VPos;
	__int16 APos;
	__int16 Growth;
	char name[8];
	unsigned __int16 Skill[8];
};

struct AL_RECORD
{
	char RecordFlag;
	AL_TIME time;
	AL_SHAPE_ELEMENT ShapeElement;
};

struct __declspec(align(4)) race_save_info_btl
{
	char RaceActiveFlag[6];
	__int16 field_6;
	int filler[5];
	__int16 filler2;
	AL_RECORD CourseRecord[10];
};

struct KARATE_SAVE_INFO
{
	char free[32];
};

struct SAlItem
{
	char mCategory;
	char mId;
};

struct __declspec(align(4)) KINDER_SAVE_INFO
{
	char LessonNum[4];
	int LessonStartTime[4];
	char free[8];
	int NextBuyListChangeTime;
	int gAlItemBuyNum;
	int gAlItemHaveNum;
	SAlItem gAlItemBuyList[32];
	char dummy[12];
};

struct SAVE_DATA_CRC
{
	char crc1;
	char pre0;
	char crc3;
	char post;
	char pre1;
	char crc0;
	char pre2;
	char crc2;
};

struct __declspec(align(4)) CHAO_GARDEN_INFO_BTL
{
	GARDEN_ID GardenID;
	int oneMoreField;
	unsigned int flag;
	unsigned int ToyGetFlag;
	unsigned int timer;
	unsigned int nbVisit;
	unsigned int nbBorn;
	TREE_SAVE_INFO tree[3][7];
	ITEM_SAVE_INFO fruit[40];
	ITEM_SAVE_INFO seed[12];
	ITEM_SAVE_INFO mask[24];
	ITEM_SAVE_INFO minimal[10];
	race_save_info_btl race;
	KARATE_SAVE_INFO karate;
	KINDER_SAVE_INFO kinder;
	chao_save_info chao[24];
	SAVE_DATA_CRC crc;
};
