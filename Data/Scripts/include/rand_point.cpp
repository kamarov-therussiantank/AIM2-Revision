//#include "include\AIM.cpp"

void proc point() // ќпредел€ем точку где по€витьс€ контейнер
{
	char location;
	location = GetArea();
	switch(location)
	{
		case "location1":
		{
			int random2;
			random2 = RandomInt(21)+1;
			int random3;
			random3 = RandomInt(20)+1;
			
			if (RandomInt(2) == 1)
				SetVarChar("poindid", "P_L1_ALL_START"+char(random2));
			else
				SetVarChar("poindid", "P_L1_KON_START"+char(random3));
		}
		case "location2":
		{
			int random2;
			random2 = RandomInt(20)+1;
			int random3;
			random3 = RandomInt(20)+1;
			
			if (RandomInt(2) == 1)
				SetVarChar("poindid", "P_L2_ALL_START"+char(random2));
			else
				SetVarChar("poindid", "P_L2_KON_START"+char(random3));
		}
		case "location3":
		{
			int random2;
			random2 = RandomInt(20)+1;
			int random3;
			random3 = RandomInt(20)+1;
			
			if (RandomInt(2) == 1)
				SetVarChar("poindid", "P_L3_ALL_START"+char(random2));
			else
				SetVarChar("poindid", "P_L3_KON_START"+char(random3));
		}
		case "location5":
		{
			int random2;
			random2 = RandomInt(20)+1;
			int random3;
			random3 = RandomInt(20)+1;
			
			if (RandomInt(2) == 1)
				SetVarChar("poindid", "P_L5_ALL_START"+char(random2));
			else
				SetVarChar("poindid", "P_L5_KON_START"+char(random3));
		}
		case "location6":
		{
			int random2;
			random2 = RandomInt(20)+1;
			int random3;
			random3 = RandomInt(20)+1;
			
			if (RandomInt(2) == 1)
				SetVarChar("poindid", "P_L6_ALL_START"+char(random2));
			else
				SetVarChar("poindid", "P_L6_KON_START"+char(random3));
		}
		case "location9":
		{
			int random3;
			random3 = RandomInt(20)+1;
			SetVarChar("poindid", "P_L9_KON_START"+char(random3));
		}
		case "location10":
		{
			int random2;
			random2 = RandomInt(15)+1;
			int random3;
			random3 = RandomInt(20)+1;
			
			if (RandomInt(2) == 1)
				SetVarChar("poindid", CONCAT("P_L10_ALL_START", char(random2)));
			else
				SetVarChar("poindid", CONCAT("P_L10_KON_START", char(random3)));
		}
		case "location11":
		{
			int random2;
			random2 = RandomInt(20)+1;
			SetVarChar("poindid", CONCAT("P_L11_ALL_START", char(random2)));
		}
		case "demo_map":
		{
			int random2;
			random2 = RandomInt(5)+1;
			SetVarChar("poindid", CONCAT("P_LT_KON_START", char(random2)));
		}
	}//end case
}

void proc glid_point() // ќпредел€ем точку где по€витьс€ глайдер
{
	char location;
	location = GetArea(); 
	switch(location)
	{
		case "location1":
		{
			int random;
			random = RandomInt(21)+1;
			SetVarChar("poindid", CONCAT("P_L1_ALL_START", char(random)));
		}
		case "location2":
		{
			int random;
			random = RandomInt(20)+1;
			SetVarChar("poindid", CONCAT("P_L2_ALL_START", char(random)));
		}
		case "location3":
		{
			int random;
			random = RandomInt(20)+1;
			SetVarChar("poindid", CONCAT("P_L3_ALL_START", char(random)));
		}
		case "location5":
		{
			int random;
			random = RandomInt(20)+1;
			SetVarChar("poindid", CONCAT("P_L5_ALL_START", char(random)));
		}
		case "location6":
		{
			int random;
			random = RandomInt(20)+1;
			SetVarChar("poindid", CONCAT("P_L6_ALL_START", char(random)));
		}
		case "location9":
		{
			int random3;
			random3 = RandomInt(20)+1;
			SetVarChar("poindid", CONCAT("P_L9_KON_START", char(random3)));
		}
		case "location10":
		{
			int random;
			random = RandomInt(15)+1;
			SetVarChar("poindid", CONCAT("P_L10_ALL_START", char(random)));
		}
		case "location11":
		{
			int random;
			random = RandomInt(20)+1;
			SetVarChar("poindid", CONCAT("P_L11_ALL_START", char(random)));
		}
	}//end case
}

void proc end_glider_point() // ќпредел€ем точку куда нужно сопроводить глайдер
{
	char location;
	location = GetArea(); 
	switch(location)
	{
		case "location1":
		{
			int random;
			random = RandomInt(14)+1;
			switch(random)
			{
				case 1: SetVarChar("end_poindid", "B_L1_BLT_MINE1");
				case 2: SetVarChar("end_poindid", "B_L1_BLT_MINE2");
				case 3: SetVarChar("end_poindid", "B_L1_BLT_BASE1");
				case 4: SetVarChar("end_poindid", "B_L1_BLT_BASE2");
				case 5: SetVarChar("end_poindid", "B_L1_BLT_FEEDSTOCK");
				case 6: SetVarChar("end_poindid", "B_L1_BLT_ZAR1");
				case 7: SetVarChar("end_poindid", "B_L1_BLT_ZAR2");
				case 8: SetVarChar("end_poindid", "B_L1_BLT_TUNNEL");
				case 9: SetVarChar("end_poindid", "B_L1_BLT_KA");
				case 10: SetVarChar("end_poindid", "B_L1_BLT_PLANT_PF");
				case 11: SetVarChar("end_poindid", "B_L1_BLT_PLANT_RECYCLE");
				case 12: SetVarChar("end_poindid", "B_L1_BLT_PLANT_RM");
				case 13: SetVarChar("end_poindid", "B_L1_BLT_BASE3");
				case 14: SetVarChar("end_poindid", "B_L1_BLT_BASE4");
			}
		}
		case "location2":
		{
			int random;
			random = RandomInt(17)+1;
			switch(random)
			{
				case 1: SetVarChar("end_poindid", "B_L2_BLT_SPHERE");
				case 2: SetVarChar("end_poindid", "B_L2_BLT_IK");
				case 3: SetVarChar("end_poindid", "B_L2_BLT_ENTRANCE");
				case 4: SetVarChar("end_poindid", "B_L2_BLT_MINE1");
				case 5: SetVarChar("end_poindid", "B_L2_BLT_MINE2");
				case 6: SetVarChar("end_poindid", "B_L2_BLT_BASE1");
				case 7: SetVarChar("end_poindid", "B_L2_BLT_BASE2");
				case 8: SetVarChar("end_poindid", "B_L2_BLT_BASE3");
				case 9: SetVarChar("end_poindid", "B_L2_BLT_FEEDSTOCK");
				case 10: SetVarChar("end_poindid", "B_L2_BLT_ZAR1");
				case 11: SetVarChar("end_poindid", "B_L2_BLT_ZAR2");
				case 12: SetVarChar("end_poindid", "B_L2_BLT_ZAR3");
//				case 13: SetVarChar("end_poindid", "B_L2_BLT_ZAR3");
				case 13: SetVarChar("end_poindid", "B_L2_BLT_TUNNEL");
				case 14: SetVarChar("end_poindid", "B_L2_BLT_KA");
				case 15: SetVarChar("end_poindid", "B_L2_BLT_PLANT_PF");
				case 16: SetVarChar("end_poindid", "B_L2_BLT_PLANT_RECYCLE");
				case 17: SetVarChar("end_poindid", "B_L2_BLT_PLANT_RM");
			}
		}
		case "location3":
		{
			int random;
			random = RandomInt(15)+1;
			switch(random)
			{
				case 1: SetVarChar("end_poindid", "B_L3_BLT_MINE1");
				case 2: SetVarChar("end_poindid", "B_L3_BLT_MINE2");
				case 3: SetVarChar("end_poindid", "B_L3_BLT_BASE1");
				case 4: SetVarChar("end_poindid", "B_L3_BLT_BASE2");
				case 5: SetVarChar("end_poindid", "B_L3_BLT_BASE3");
				case 6: SetVarChar("end_poindid", "B_L3_BLT_FEEDSTOCK");
				case 7: SetVarChar("end_poindid", "B_L3_BLT_ZAR1");
				case 8: SetVarChar("end_poindid", "B_L3_BLT_ZAR2");
				case 9: SetVarChar("end_poindid", "B_L3_BLT_ZAR3");
				case 10: SetVarChar("end_poindid", "B_L3_BLT_TUNNEL");
				case 11: SetVarChar("end_poindid", "B_L3_BLT_KA");
				case 12: SetVarChar("end_poindid", "B_L3_BLT_PLANT_PF");
				case 13: SetVarChar("end_poindid", "B_L3_BLT_PLANT_RECYCLE");
				case 14: SetVarChar("end_poindid", "B_L3_BLT_PLANT_RM");
				case 15: SetVarChar("end_poindid", "B_L3_BLT_BASE4");
				//case 15: SetVarChar("end_poindid", "B_L3_BLT_BUNKER");
				//case 16: SetVarChar("end_poindid", "B_L3_BLT_OBELISK");
			}
		}
		case "location5":
		{
			int random;
			random = RandomInt(15)+1;
			switch(random)
			{
				case 1: SetVarChar("end_poindid", "B_L5_BLT_BASE1");
				case 2: SetVarChar("end_poindid", "B_L5_BLT_BASE2");
				case 3: SetVarChar("end_poindid", "B_L5_BLT_BASE3");
				case 4: SetVarChar("end_poindid", "B_L5_BLT_FEEDSTOCK");
				case 5: SetVarChar("end_poindid", "B_L5_BLT_KA");
				case 6: SetVarChar("end_poindid", "B_L5_BLT_MINE1");
				case 7: SetVarChar("end_poindid", "B_L5_BLT_PLANT_PF");
				case 8: SetVarChar("end_poindid", "B_L5_BLT_PLANT_RECYCLE");
				case 9: SetVarChar("end_poindid", "B_L5_BLT_PLANT_RM");
				case 10: SetVarChar("end_poindid", "B_L5_BLT_SBUNKER");
				case 11: SetVarChar("end_poindid", "B_L5_BLT_TUNNEL");
				case 12: SetVarChar("end_poindid", "B_L5_BLT_ZAR1");
				case 13: SetVarChar("end_poindid", "B_L5_BLT_ZAR2");
				case 14: SetVarChar("end_poindid", "B_L5_BLT_BASE4");
				case 15: SetVarChar("end_poindid", "B_L5_BLT_BASE5");
			}
		}
		case "location6":
		{
			int random;
			random = RandomInt(13)+1;
			switch(random)
			{
				case 1: SetVarChar("end_poindid", "B_L6_BLT_BASE1");
				case 2: SetVarChar("end_poindid", "B_L6_BLT_BASE2");
				case 3: SetVarChar("end_poindid", "B_L6_BLT_FEEDSTOCK");
				case 4: SetVarChar("end_poindid", "B_L6_BLT_IK");
				case 5: SetVarChar("end_poindid", "B_L6_BLT_KA");
				case 6: SetVarChar("end_poindid", "B_L6_BLT_PLANT_PF");
				case 7: SetVarChar("end_poindid", "B_L6_BLT_PLANT_RECYCLE");
				case 8: SetVarChar("end_poindid", "B_L6_BLT_PLANT_RM");
				case 9: SetVarChar("end_poindid", "B_L6_BLT_TUNNEL");
				case 10: SetVarChar("end_poindid", "B_L6_BLT_ZAR1");
				case 11: SetVarChar("end_poindid", "B_L6_BLT_ZAR3");
				case 12: SetVarChar("end_poindid", "B_L6_BLT_BASE1");
				case 13: SetVarChar("end_poindid", "B_L6_BLT_BASE2");

			}
		}
		case "location9":
		{
			int random;
			random = RandomInt(6)+1;
			switch(random)
			{
				case 1: SetVarChar("end_poindid", "B_L9_BLT_TUNNEL");
				case 2: SetVarChar("end_poindid", "B_L9_BLT_BASE1");
				case 3: SetVarChar("end_poindid", "B_L9_BLT_BASE2");
				case 4: SetVarChar("end_poindid", "B_L9_BLT_BASE3");
				case 5: SetVarChar("end_poindid", "B_L9_BLT_BASE4");
				case 6: SetVarChar("end_poindid", "B_L9_BLT_BASE5");
			}
		}
		case "location10":
		{
			int random;
			random = RandomInt(18)+1;
			switch(random)
			{
				case 1: SetVarChar("end_poindid", "B_L10_BLT_IK");
				case 2: SetVarChar("end_poindid", "B_L10_BLT_ENTRANCE");
				case 3: SetVarChar("end_poindid", "B_L10_BLT_MINE1");
				case 4: SetVarChar("end_poindid", "B_L10_BLT_MINE2");
				case 5: SetVarChar("end_poindid", "B_L10_BLT_BASE1");
				case 6: SetVarChar("end_poindid", "B_L10_BLT_BASE2");
				case 7: SetVarChar("end_poindid", "B_L10_BLT_BASE3");
				case 8: SetVarChar("end_poindid", "B_L10_BLT_BASE4");
				case 9: SetVarChar("end_poindid", "B_L10_BLT_FEEDSTOCK");
				case 10: SetVarChar("end_poindid", "B_L10_BLT_ZAR1");
				case 11: SetVarChar("end_poindid", "B_L10_BLT_ZAR2");
				case 12: SetVarChar("end_poindid", "B_L10_BLT_ZAR3");
				case 13: SetVarChar("end_poindid", "B_L10_BLT_TUNNEL");
				case 14: SetVarChar("end_poindid", "B_L10_BLT_KA");
				case 15: SetVarChar("end_poindid", "B_L10_BLT_PLANT_PF");
				case 16: SetVarChar("end_poindid", "B_L10_BLT_PLANT_RECYCLE");
				case 17: SetVarChar("end_poindid", "B_L10_BLT_PLANT_RM");
				case 18: SetVarChar("end_poindid", "B_L10_BLT_ZAR4");
			}
		}
	}//end case
}


// ќпредел€ем точку куда нужно сопроводить глайдер
void proc end_glider_point2(char math)
{
	//end_glider_point();
	while (GetVarChar("end_poindid") == math)
	   end_glider_point();
}
