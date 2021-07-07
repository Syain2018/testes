#pragma once
#include "char.h"
#include"main.h"

int Hit(float x, float y)
{
	if ((((x - 82) * (x - 82)) + ((y - 390) * (y - 390))) < 41 * 41)
	{
		return 1;
	}

	else if ((((x - 162) * (x - 162)) + ((y - 520) * (y - 520))) < 41 * 41)
	{
		return 2;
	}

	else if ((((x - 242) * (x - 242)) + ((y - 390) * (y - 390))) < 41 * 41)
	{
		return 3;
	}

	else if ((((x - 320) * (x - 320)) + ((y - 520) * (y - 520))) < 41 * 41)
	{
		return 4;
	}

	else if ((((x - 402) * (x - 402)) + ((y - 390) * (y - 390))) < 41 * 41)
	{
		return 5;
	}

	else if ((((x - 480) * (x - 480)) + ((y - 520) * (y - 520))) < 41 * 41)
	{
		return 6;
	}

	else if ((((x - 562) * (x - 562)) + ((y - 390) * (y - 390))) < 41 * 41)
	{
		return 7;
	}

	else if ((((x - 642) * (x - 642)) + ((y - 520) * (y - 520))) < 41 * 41)
	{
		return 8;
	}

	else if ((((x - 710) * (x - 710)) + ((y - 390) * (y - 390))) < 41 * 41)
	{
		return 9;
	}

	else
	{
		return 0;
	}
}