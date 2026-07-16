//Файл с провалами заданий..

//Функция вызываеться по окончанию таймера и может очистить слот для генерируемого квеста
void proc OnKillGenerate(char cBuild)
{
	if (RandomInt(2)==1)
		SetVarChar(cBuild+".T1", "");

	if (RandomInt(2)==1)
		SetVarChar(cBuild+".T2", "");

	if (RandomInt(2)==1)
		SetVarChar(cBuild+".T3", "");
		
//	SetTimer("OnKillGenerate", 0.1, cBuild);
}

void proc endhour()
{
	int iTimeLeft;
	iTimeLeft = GetVar("g_timeleft")-1;
	SetVar("g_timeleft", iTimeLeft);
	if (iTimeLeft>0)
	{
        	SetTimer("endhour", 1);
	}
}

// Таймер по времени на генерируемые задания..
void proc endtime()
{
	Text("INT_TIME_OVER");
	Text("INT_QUEST_FAIL");
	SetVar("gen_q", 99);

	if (GetItem("TOV_INFORMPAKET")==1)
		RemoveItem("TOV_INFORMPAKET");
	
}//end proc

// Процедура, запускаемая в момент,
// когда в здании нам говорят о провале квеста.
void proc fail_quest(bool bText = true)
{
	AddAmount(AMOUNT_RATING_QUEST, -GetVar("g_award")/200);

	int iTypeq;
	iTypeq = GetVar("g_QuestSuggest");
	bool bAlt = false;
	if (iTypeq==2) iTypeq = 1;		// GEN_DELIVER_1==GEN_DELIVER
	if (iTypeq==7) iTypeq = 5;		// GEN_KILL_2==GEN_KILL
	//if (iTypeq==13) iTypeq = 12;	// GEN_TRANS_1==GEN_TRANS

	switch(iTypeq) //Определяем тип квеста
	{
		//GEN_DELIVER_1
		case 1: bAlt = GetVar("g_itemrest")!=GetVar("g_itemcount");
		//GEN_DELIVER_2
		case 3: 
		{
			bAlt = GetVar("qen_1")==99;
			if (GetItem("TOV_MECH_GEN"))
				RemoveItem("TOV_MECH_GEN");
		}
		//GEN_FIND
		case 4:
		{ 
			if (GetItem("TOV_UNIQUE_CONTAINER")==1)
				RemoveItem("TOV_UNIQUE_CONTAINER");
			DeleteObject("need_con");
		}
		// GEN_KILL
		case 5:
		{
			bAlt = GetVar("g_gliderdie")==1;
			RemovePeleng(GetVarChar("g_glidertarget"));
		}
		// GEN_KILL_1
		case 6: RemovePeleng(GetVarChar("g_glidertarget"));
		case 8: RemovePeleng(GetVarChar("g_glidertarget"));
		// GEN_MAIL
		case 9: if (GetItem("TOV_INFORMPAKET")==1)
					RemoveItem("TOV_INFORMPAKET");
		// GEN_MAIL_1
		case 10:if (GetItem("TOV_UNIQUE_CONTAINER")==1)
					RemoveItem("TOV_UNIQUE_CONTAINER");
		// GEN_MAIL_2
		case 11:
		{ 
			RemovePeleng(GetVarChar("g_glidertarget"));
			if (GetItem("TOV_INFORMPAKET")==1)
				RemoveItem("TOV_INFORMPAKET");
		}
		case 12:
			{
				bAlt = GetVar("gen_assign")==0;
				RemovePeleng(GetVarChar("g_glidertarget"));
				RemovePeleng(GetVarChar("end_poindid"));
				GliderInvis(GetVarChar("g_glidertarget"), 1);
			}
		case 13:
			{
				RemovePeleng(GetVarChar("g_glidertarget"));
				RemovePeleng(GetVarChar("end_poindid"));
				GliderInvis(GetVarChar("g_glidertarget"), 1);
			}
		
	} //case
	
	SetVar("gen_q", 0);
	SetVar("g_QuestSuggest", 0);
	if (bText)
	{
		if (bAlt)
			Text(GetVarChar("g_questid")+".FAIL2");
		else
			Text(GetVarChar("g_questid")+".FAIL");
	}
	FailQuest(GetVarChar("g_questid"));
	StopTimer("endtime");
	StopTimer("endhour");
}
