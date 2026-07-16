//#include "include\AIM.src"

int proc Caward(int iBase, int iAdd=0)
{
	int iArea = 1;
	int iBonus;
	iBonus = 1;
	iBonus = iBonus * (5+3*GetRating(RATING_QUEST))/8;
	iBonus = int(iBonus*iBase+iAdd);
	return iBonus;
}//end proc

int proc RaitingAward(int iBase, int iAdd=0)
{
	int iArea = 1;
	int iBonus;
	iBonus = 1;
	iBonus = iBonus * (5+3*GetRating(RATING_QUEST))/8;
	iBonus = int(iBonus*iBase+iAdd);
	return iBonus;
}//end proc
