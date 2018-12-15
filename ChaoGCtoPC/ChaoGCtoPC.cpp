// ChaoGCtoPC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "structs.h"

ChaoData* data;

float ToBigEndian(float inFloat) //https://stackoverflow.com/questions/2782725/converting-float-values-from-big-endian-to-little-endian
{
	float retVal;
	char *floatToConvert = (char*)& inFloat;
	char *returnFloat = (char*)& retVal;

	// swap the bytes into a temporary buffer
	returnFloat[0] = floatToConvert[3];
	returnFloat[1] = floatToConvert[2];
	returnFloat[2] = floatToConvert[1];
	returnFloat[3] = floatToConvert[0];

	return retVal;
}
__int16 ToBigEndian(__int16 num) //edited the above one to work like this
{
	__int16 retVal;
	char *floatToConvert = (char*)& num;
	char *returnFloat = (char*)& retVal;

	// swap the bytes into a temporary buffer
	returnFloat[0] = floatToConvert[1];
	returnFloat[1] = floatToConvert[0];

	return retVal;
}
int ToBigEndian(int num) //same here
{
	int retVal;
	char *floatToConvert = (char*)& num;
	char *returnFloat = (char*)& retVal;

	// swap the bytes into a temporary buffer
	returnFloat[0] = floatToConvert[3];
	returnFloat[1] = floatToConvert[2];
	returnFloat[2] = floatToConvert[1];
	returnFloat[3] = floatToConvert[0];

	return retVal;
}

unsigned char ChaoFileSig[64] = {
	0x14, 0x28, 0xB7, 0x52, 0xAD, 0x34, 0xF3, 0xC4, 0xC4, 0xFA, 0x25, 0x49,
	0x04, 0xFF, 0x1B, 0x24, 0x13, 0x0C, 0x26, 0x4F, 0x6F, 0xB5, 0x29, 0xA5,
	0x7C, 0x87, 0x78, 0x89, 0x08, 0xBC, 0x2E, 0xE6, 0xAB, 0x3E, 0x55, 0x4F,
	0xDD, 0x35, 0x68, 0x75, 0xF5, 0xF7, 0xA8, 0x2B, 0x27, 0x67, 0xCA, 0x74,
	0x4F, 0x28, 0xE1, 0x56, 0x1F, 0x69, 0xDB, 0xBE, 0xF3, 0x4D, 0xA6, 0xD3,
	0xB1, 0xE7, 0x21, 0x00
};

char buffer[0x840];
void ToChaoFile(ChaoData* data, int index)
{
	memcpy(buffer, ChaoFileSig, 64);
	memcpy(&buffer[64], data, sizeof(ChaoData));

	char filename[10];
	sprintf_s(filename, 10, "%d.chao", index);

	FILE *file; 
	fopen_s(&file, filename, "w");
	
	for(int i = 0; i < 0x840; i ++)
		fputc(buffer[i], file); //lmao I bet there's a better way to do it, 
								//fputs didnt work because of the 0x00 
								//at the end of the ChaoFileSig
	fclose(file);
}

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("Drag .GCI SA2B save file onto the executable.");
		return 0;
	}

	FILE* file;
	fopen_s(&file, argv[1], "rb");

	printf("%d", sizeof(ChaoData));

	data = (ChaoData*)malloc(24 * sizeof(ChaoData));
	
	int ChaoDataStartOffset = 0x40 + 0x3AA4; //0x40 - skip GCI header, 0x3AA4 - start of ChaoData in SA2 savefile
	fseek(file, ChaoDataStartOffset, SEEK_SET);
	
	fread((void*)data, sizeof(ChaoData) ,24 , file);

	for(int i = 0; i < 24; i++)
	{
		ChaoData* dataSelected = &data[i];
		for(int i = 0; i < 8; i++)
		{
			dataSelected->data.StatPoints[i] = ToBigEndian(dataSelected->data.StatPoints[i]);
		}
		//i could've did this a lot simpler with pointers oh well too late now
		dataSelected->data.Happiness = ToBigEndian(dataSelected->data.Happiness);
		//dataSelected->data.InKindergarten = ToBigEndian(dataSelected->data.InKindergarten);
		dataSelected->data.ClockRollovers = ToBigEndian(dataSelected->data.ClockRollovers);
		dataSelected->data.field_88 = ToBigEndian(dataSelected->data.field_88);
		dataSelected->data.Lifespan = ToBigEndian(dataSelected->data.Lifespan);
		dataSelected->data.Lifespan2 = ToBigEndian(dataSelected->data.Lifespan2);
		dataSelected->data.Reincarnations = ToBigEndian(dataSelected->data.Reincarnations);

		dataSelected->data.EvolutionProgress = ToBigEndian(dataSelected->data.EvolutionProgress);
		dataSelected->data.PowerRun = ToBigEndian(dataSelected->data.PowerRun);
		dataSelected->data.FlySwim = ToBigEndian(dataSelected->data.FlySwim);
		dataSelected->data.Alignment = ToBigEndian(dataSelected->data.Alignment);

		if (dataSelected->data.SA2BEarType == SA2BAnimal_Rabbit)
			printf("debug: rabbit ear test");

		dataSelected->data.DoctorMedal = ToBigEndian(dataSelected->data.DoctorMedal);
		dataSelected->data.SA2AnimalBehavior = ToBigEndian(dataSelected->data.SA2AnimalBehavior);

		dataSelected->data.Emotion.field_124 = ToBigEndian(dataSelected->data.Emotion.field_124);
		dataSelected->data.Emotion.Category1Timer = ToBigEndian(dataSelected->data.Emotion.Category1Timer);
		dataSelected->data.Emotion.SicknessTimer = ToBigEndian(dataSelected->data.Emotion.SicknessTimer);
		dataSelected->data.Emotion.Category2Timer = ToBigEndian(dataSelected->data.Emotion.Category2Timer);

		dataSelected->data.Emotion.Sleepiness = ToBigEndian(dataSelected->data.Emotion.Sleepiness);
		dataSelected->data.Emotion.Tiredness = ToBigEndian(dataSelected->data.Emotion.Tiredness);
		dataSelected->data.Emotion.Hunger = ToBigEndian(dataSelected->data.Emotion.Hunger);
		dataSelected->data.Emotion.MateDesire = ToBigEndian(dataSelected->data.Emotion.MateDesire);
		dataSelected->data.Emotion.Boredom = ToBigEndian(dataSelected->data.Emotion.Boredom);
		dataSelected->data.Emotion.Lonely = ToBigEndian(dataSelected->data.Emotion.Lonely);
		dataSelected->data.Emotion.Tire = ToBigEndian(dataSelected->data.Emotion.Tire);
		dataSelected->data.Emotion.Stress = ToBigEndian(dataSelected->data.Emotion.Stress);
		dataSelected->data.Emotion.Nourish = ToBigEndian(dataSelected->data.Emotion.Nourish);
		dataSelected->data.Emotion.Conditn = ToBigEndian(dataSelected->data.Emotion.Conditn);
		dataSelected->data.Emotion.Energy = ToBigEndian(dataSelected->data.Emotion.Energy);
		
		dataSelected->data.SA2BToys = ToBigEndian(dataSelected->data.SA2BToys);
		dataSelected->data.field_166 = ToBigEndian(dataSelected->data.field_166);
		dataSelected->data.field_168 = ToBigEndian(dataSelected->data.field_168);
		dataSelected->data.field_16A = ToBigEndian(dataSelected->data.field_16A);

		for (int i = 0; i < 6; i++)
		{
			dataSelected->data.SA2BCharacterBonds[i].field_2 = ToBigEndian(dataSelected->data.SA2BCharacterBonds[i].field_2);
			dataSelected->data.SA2BCharacterBonds[i].field_4 = ToBigEndian(dataSelected->data.SA2BCharacterBonds[i].field_4);
		}

		if (dataSelected->data.Type != 0)
			ToChaoFile(dataSelected, i);
	}

	fclose(file);

	return 0;
}
