#include "Utility.h"

int Utility::respectiveWaterLevel(int hour)
{
	int waterHeight;

	switch (hour) {
		case 0: waterHeight = 100; break;
		case 1: waterHeight = 125; break;
		case 2: waterHeight = 150; break;
		case 3: waterHeight = 175; break;
		case 4: waterHeight = 200; break;
		case 5: waterHeight = 225; break;
		case 6: waterHeight = 250; break;
		case 7: waterHeight = 225; break;
		case 8: waterHeight = 200; break;
		case 9: waterHeight = 175; break;
		case 10: waterHeight = 150; break;
		case 11: waterHeight = 125; break;
		case 12: waterHeight = 100; break;
		case 13: waterHeight = 125; break;
		case 14: waterHeight = 150; break;
		case 15: waterHeight = 175; break;
		case 16: waterHeight = 200; break;
		case 17: waterHeight = 225; break;
		case 18: waterHeight = 250; break;
		case 19: waterHeight = 225; break;
		case 20: waterHeight = 200; break;
		case 21: waterHeight = 175; break;
		case 22: waterHeight = 150; break;
		case 23: waterHeight = 125; break;
	}
	return waterHeight;
}
