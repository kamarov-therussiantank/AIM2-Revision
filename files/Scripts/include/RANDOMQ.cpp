#include "include\AIM.cpp"
#include "include\rand_point.cpp"
#include "include\fail.cpp"

//Выдача награды на генерируемый квест
void proc award_take()
{
	int var_award;
	var_award = GetVar("g_award");
	AddAmount(AMOUNT_ENERGY, var_award);
	AddAmount(AMOUNT_RATING_QUEST, var_award/100);
	SetVar("gen_q", 0);
	CompleteQuest(GetVarChar("g_questid"));								
}

//Генерируем сумму которую игрок получит за выполнение задания
void proc award(float fKoef, float fAdd=0)
{
	float fArea = 1.0;
	float fBonus;
	fBonus = 1.0+RandomInt(10)/10.0;

	fBonus = fBonus * float(10+5*GetRating(RATING_QUEST));
   
	switch(GetArea())
	{
		case "location1":  fArea = 2.0;
		case "location2":  fArea = 2.0;
		case "location3":  fArea = 3.0;
		case "location5":  fArea = 1.0;
		case "location6":  fArea = 3.0;
		case "location9":  fArea = 3.0;
		case "location10": fArea = 3.0;
		case "location11": fArea = 3.0;
		case "demo_map":   fArea = 3.0;
	}//end case
	SetVar("g_award", int(fArea*fBonus*fKoef*50.0+fAdd) );
}//end proc

//Генерируем значения переменных для коректного вывода текста задания
void proc gen_quest(char item)
{
	bool bMyClan;
	bMyClan = GetBuildOwner(GetVarChar("CurrentBuild"))==GetMechClan("PLAYER");
	float fKoef;

	//Клановые квесты (только для своего клана)
	if (bMyClan)
	{
		SetVarChar("g_questid", item+"_K");
		fKoef = 1.5;
	}
	else
	{
		SetVarChar("g_questid", item);
		fKoef = 1.0;
	}
	SetVarChar("g_orgname", GetBuildOwner(GetVarChar("CurrentBuild")));
	SetVarChar("g_buildstart", GetVarChar("CurrentBuild"));

	switch(item)
	{
		case "GEN_DELIVER":
		{
			// - привести груз в это здание
			int iTime;
			iTime = RandomInt(25)+8;
			SetVar("g_time", iTime);
			char goods;
			goods = GetRandomGoods(GetVarChar("CurrentBuild"));
			int iCount;
			iCount = RandomInt(20)+4;
			iCount = iCount/(GetGoodsType(goods)+1);
			SetVarChar("g_buildtarget", GetVarChar("CurrentBuild"));
			award(1.1*(1.0+float(iCount)/5.0)*fKoef, 
				  float(iCount)*float(GetGoodsPrice(goods))*2.0);
						
			SetVar("g_itemcount", iCount);
			SetVar("g_itemrest", iCount);
			SetVar("g_QuestSuggest", 1);
			SetVarChar("g_itemid", goods);
		}
		case "GEN_DELIVER_1": 
		{
			// - отвезти груЗ
			int iTime;
			iTime = RandomInt(20)+10;
			SetVar("g_time", iTime);

			SetVarChar("g_buildtarget", GetRandomBuild(GetVarChar("CurrentBuild")));
			char goods;
			goods = GetRandomGoods(GetVarChar("g_buildtarget"));
			int iCount;
			iCount = RandomInt(20)+4;
			iCount = iCount/(GetGoodsType(goods)+1);
			award(1.0*(1.0+float(iCount)/5.0)*fKoef, 
				  float(iCount)*float(GetGoodsPrice(goods))*2.0);
						
			SetVar("g_itemcount", iCount);
			SetVar("g_itemrest", iCount);
			SetVar("g_QuestSuggest", 2);
			SetVarChar("g_itemid", goods);
		}
		case "GEN_DELIVER_2": 
		{
			// отвезти механойда
			SetVarChar("g_glidertarget", "TOV_MECH_GEN");
			SetVarChar("g_buildtarget", GetRandomBuild(GetVarChar("CurrentBuild")));
			SetVar("g_time", RandomInt(3)+5);
			award(0.5*fKoef);
			SetVar("g_QuestSuggest", 3);
		}
		case "GEN_FIND": 
		{
			//- найти и привезти контейнер
			point();
			SetVarChar("g_target", GetVarChar("poindid"));
			award(0.6*fKoef);
			SetVar("g_QuestSuggest", 4);
			SetVarChar("g_buildtarget", GetVarChar("CurrentBuild"));
		}
		case "GEN_KILL": 
		{
			//привезти врага
			char build;
			build = GetVarChar("CurrentBuild");
			SetVarChar("g_glidertarget", GetRandomGlider(GetBuildOwner(build)));
			SetVarChar("g_buildtarget", build);
			SetVar("g_time", RandomInt(12)+5);
			award(3.0*fKoef);
			if (GetVarChar("g_glidertarget")!="")
				SetVar("g_QuestSuggest", 5);
		}
		case "GEN_KILL_1": 
		{
			// - уничтожить глайдер врага
			char build;
			build = GetVarChar("CurrentBuild");
			SetVarChar("g_glidertarget", GetRandomGlider(GetBuildOwner(build)));
			SetVarChar("g_buildtarget", GetVarChar("CurrentBuild"));
			SetVar("g_time", RandomInt(6)+5);
			award(2.5*fKoef);
			if (GetVarChar("g_glidertarget")!="")
				SetVar("g_QuestSuggest", 6);
		}
		case "GEN_KILL_2":
		{
			// - уничтожить глайдер врага и привезти механойда
			char build;
			build = GetRandomBuild(GetVarChar("CurrentBuild"));
			SetVarChar("g_glidertarget", GetRandomGlider(GetBuildOwner(build)));
			SetVarChar("g_buildtarget", build);
			SetVar("g_time", RandomInt(12)+5);
			award(3.5*fKoef);
			if (GetVarChar("g_glidertarget")!="")
				SetVar("g_QuestSuggest", 7);
		}
		case "GEN_KILL_3":
		{
			// - довести врага до переноса
			char build;
			build = GetVarChar("CurrentBuild");
			SetVarChar("g_glidertarget", GetRandomGlider(GetBuildClan(build)));
			int iRating;
			iRating = GetGliderR( GetVarChar("g_glidertarget") );
			SetVarChar("g_buildtarget", build);
			award(5.0*fKoef*iRating);
			if (GetVarChar("g_glidertarget")!="")
				SetVar("g_QuestSuggest", 8);
		}
		case "GEN_MAIL":
		{
			// - отвезти информпакет
			SetVarChar("g_buildtarget", GetRandomBuild(GetVarChar("CurrentBuild")));
			SetVar("g_time", RandomInt(6)+5);
			award(1.3*fKoef);
			SetVar("g_QuestSuggest", 9);
		}
		case "GEN_MAIL_1": 
		{
			//- отвезти груз
			SetVarChar("g_buildtarget", GetRandomBuild(GetVarChar("CurrentBuild")));
			award(0.5*fKoef);
			SetVar("g_QuestSuggest", 10);
		}
		case "GEN_MAIL_2": 
		{
			// - передать сообщение механойду
			SetVar("g_time", RandomInt(6)+5);
			SetVarChar("g_glidertarget", GetRandomGlider(""));
			SetVarChar("g_buildtarget", GetVarChar("CurrentBuild"));
			award(1.0*fKoef);
			if (GetVarChar("g_glidertarget")!="")
				SetVar("g_QuestSuggest", 11);
		}
		case "GEN_TRANS": 
		{
			// - сопроводить грузовую платформу
			end_glider_point();
			SetVarChar("g_target", GetVarChar("end_poindid"));
			SetVarChar("g_glidertarget", GetUniqueMechID());
			end_glider_point2(GetVarChar("end_poindid"));
			SetVarChar("g_targetend", GetVarChar("end_poindid"));
			award(6.0*fKoef);
			SetVar("g_QuestSuggest", 12);
			SetVarChar("g_buildtarget", GetVarChar("CurrentBuild"));
		}
		case "GEN_TRANS_1": 
		{
			// сопроводить глайдер
			glid_point(); // записывает точку в pointid
			SetVarChar("g_target", GetVarChar("poindid"));
			SetVarChar("g_glidertarget", GetUniqueMechID());

			end_glider_point();
			SetVarChar("g_targetend", GetVarChar("end_poindid"));
			award(2.0*fKoef);
			SetVar("g_QuestSuggest", 13);
			SetVarChar("g_buildtarget", GetVarChar("CurrentBuild"));
		}
	} //end case
} //end proc


// "B_L1_BASE.T1", "B_L1_BASE.T2", "B_L1_BASE.T3", char;
// В этой функции мы случайно генерируем случаное задание
void proc AddGenTaskToBuild(char buildID, char cq, int tq)
{
	char cClanOwner;
	cClanOwner = GetBuildOwner(buildID);
	bool bIsClan;
	bIsClan = !(cClanOwner=="ORG_FREE" || cClanOwner=="" || cClanOwner=="ORG_NONE");
	
		int iValue;
		iValue = tq;
		char sTaskName;
		sTaskName = buildID+".T"+char(tq);
		
		if (RandomInt(3)==2) 
		{
			SetVarChar(sTaskName, "BZ");
		}//end if
		else
		{
		   bool bFound;
		   bFound = false;
		   int iTry;
		   iTry = 0;
		   
		   while ( !bFound && iTry<100)
		   {
			   SetVarChar(sTaskName, "");
			   iTry = iTry+1;
			   int taskType; 
			   taskType = RandomInt(13);
				switch(taskType) //Определяем тип квеста
				{
					case 0:	
						if (GetVar("GEN_DELIVER") == 1)
								SetVarChar(sTaskName, "GEN_DELIVER");
					case 1:	
						if (GetVar("GEN_DELIVER_1") == 1)
							SetVarChar(sTaskName, "GEN_DELIVER_1");
					case 2:
						if (GetVar("GEN_DELIVER_2") == 1)
							SetVarChar(sTaskName, "GEN_DELIVER_2");
					case 3:
						if (GetVar("GEN_FIND") == 1)
							SetVarChar(sTaskName, "GEN_FIND");
					case 4:
						if (GetVar("GEN_KILL") == 1 && bIsClan)
							SetVarChar(sTaskName, "GEN_KILL");
					case 5:
						if (GetVar("GEN_KILL_1") == 1 && bIsClan)
							SetVarChar(sTaskName, "GEN_KILL_1");
					case 6:
						if (GetVar("GEN_KILL_2") == 1 && bIsClan)
							SetVarChar(sTaskName, "GEN_KILL_2");
					case 7:
						if (GetVar("GEN_KILL_3") == 1 && bIsClan)
							SetVarChar(sTaskName, "GEN_KILL_3");
					case 8:
						if (GetVar("GEN_MAIL") == 1)
							SetVarChar(sTaskName, "GEN_MAIL");
					case 9:
						if (GetVar("GEN_MAIL_1") == 1)
							SetVarChar(sTaskName, "GEN_MAIL_1");
					case 10:
						if (GetVar("GEN_MAIL_2") == 1)
							SetVarChar(sTaskName, "GEN_MAIL_2");
					case 11:
						if (GetVar("GEN_TRANS") == 1)
							SetVarChar(sTaskName, "GEN_TRANS");
					case 12:
						if (GetVar("GEN_TRANS_1") == 1)
							SetVarChar(sTaskName, "GEN_TRANS_1");
				}
				if (GetVar(GetVarChar(sTaskName))==1) 
					bFound = true;
			}			
			
			if (!bFound) 
				SetVarChar(sTaskName, "BZ");
		}//end else
	//SetTimer("OnKillGenerate", 1, buildID);
}//end proc

