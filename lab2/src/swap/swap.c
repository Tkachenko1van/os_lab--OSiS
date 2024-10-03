#include "swap.h"

void Swap(char *left, char *right)
{
	char ch = *left;
	*left = *right;
	*right = ch;
}
