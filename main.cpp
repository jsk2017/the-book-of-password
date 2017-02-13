#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "map"
#include "string"
#include "source.h"
#include "windows.h"
//#include "memwatch.h"
using namespace std;

int main(void)
{
	int select;
	while (1)
	{
		Start();
		scanf("%d",&select);
		switch (select)
		{
		case 1:
		AddItem();
			break;
		case 2:
		DeleteItem();
			break;
		case 3:
		ChangeItem();
			break;
		case 4:
		CheckItem();
			break;
		case 5:
		ClearItem();
			break;
		case 6:
		Quit();
			break;
		default:
			break;
		}
	
	}
	system("pause");
}