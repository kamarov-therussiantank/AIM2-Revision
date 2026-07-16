//--------------------
//#include "DotNet.cpp"

#define AMOUNT_ENERGY 1
#define AMOUNT_RATING_QUEST 2
#define AMOUNT_RATING_WAR   3
#define AMOUNT_RATING_TRADE 4

#define CHAR "PLAYER"
#define CLAN "ORG_PLAYER"
#define GetGliderClan GetMechClan
#define GetBuildClan GetBuildOwner

#define ERROR 999
#define EMPTY ""
#define NULL 0 

#define RATING_WAR 0
#define RATING_TRADE 1
#define RATING_QUEST 2

// Типы зданий:
// база
#define BUILDING_BASE 1
// завод
#define BUILDING_PLANT 2
//Сырьевая база
#define BUILDING_FEEDSTOCK 12
//Туннель перехода
#define BUILDING_TUNNEL 3
//Климат-активатор
#define BUILDING_KA 5
//Test Complex
#define BUILDING_IK 6

// Типы слотов оборудования
#define EQIP_GLIDER		1
#define EQIP_REACTOR	2
#define EQIP_REACTOR2	3
#define EQIP_ENGINE		4
#define EQIP_ENGINE2	5
#define EQIP_SHIELD		6
#define EQIP_ARMOR		7
#define EQIP_GUN1		8
#define EQIP_GUN2		9
#define EQIP_CONFIG		10

// Вывод текста
void proc Text(char textID)
{
   UserFunc(1, textID);
}

// Вывод диалога ( не в строении ) с остановкой игры
void proc Dialog(char textID)
{
   UserFunc(32, textID);
}

// Вствить информацию в журнал
void proc SetMsgJ(char messageID)
{
   UserFunc(2, messageID);	
}

// Есть ли информация в журнале
bool proc GetMsgJ(char messageID)
{
   if ( UserFuncInt(46, messageID)==1)
	  return true;
   else
	 return false;
}

// Запуск скрипта
void proc StartScript(char script)
{
   UserFunc(3, script);
}

// Установить значение переменной (int)
void proc SetVar(char event, int iValue=1)
{
  UserFunc(4, event, iValue);
}

// Получить значение переменной (int)
int proc GetVar(char event)
{
   int iValue;
   iValue = UserFuncInt(5, event);
   return iValue;
}

// Добавить итем игроку
void proc AddItem(char itemname, int iCount=1)
{
	UserFunc(6, itemname, iCount);  
}

// Получить итем ( количество штук) у игрока
int proc GetItem(char itemname)
{
  int iValue;
  iValue = UserFuncInt(21, itemname);
  return iValue;
}

// Добавить че-нить ( деньги, славы и т.д.)
void proc AddAmount(int iWhat, int iCount)
{
	UserFunc(7, iWhat, iCount);
}

// Установить точку пеленга
void proc SetPelengPoint( char cPointer, int iMap=1)
{
   UserFunc(8, cPointer, iMap);
}

// Поставить сенсор 
void proc SetSensor( char cPointer, int iIn=1)
{
   UserFunc(9, cPointer, iIn);
}

// Поставить сенсор для NPC`а
void proc SetSensorNPC( char cPointer, char cMech, int iIn=1)
{
   UserFunc(55, cPointer, cMech, iIn);
}

// Создать объект по указателю.
void proc CreateObjectAt( char itemName, char cObjectType, char cPointer)
{
   UserFunc(10, itemName, cObjectType, cPointer);
}

// Удалить объект
void proc DeleteObject( char cItemName)
{
   UserFunc(11, cItemName);
}

// Установить силовое поле между эммиттерами силовых полей с заданными идентификаторами
void proc SetBoundBetween( char cBorder1, char cBorder2, int iEnable)
{
   UserFunc(12, cBorder1, cBorder2, iEnable);
}

// Добавить объект в контейнер
void proc AddItemToContainer( char cContainer, char cObjectType, int iCount=1)
{
   UserFunc(13, cContainer, cObjectType, iCount);
}

// Мертв ли клан на этой локации
int proc IsClanDead(char cClanID)
{
   int iValue;
   iValue = UserFuncInt(14, cClanID);
   return iValue;
}

// Получить рейтинг клана
int proc GetClanRating(char cClanID)
{
   int iValue;
   iValue = UserFuncInt(15, cClanID);
   return iValue;
}

// Установить таймер
// по прошествии этого времени срабатывает процедура cProc,
// в которую передается cItem как параметр
void proc SetTimer(char cProc, float fTime, char cItem="")
{
   UserFunc(16, cProc, fTime, cItem);
}

// Остановить таймер
void proc StopTimer(char cProc, char cItem="")
{
   UserFunc(33, cProc, cItem);
}

// Полусить идентификатор организации, владеющей этим зданием
char proc GetBuildOwner(char cBuildID)
{
   char cValue;
   cValue = UserFunc(17, cBuildID);
   return cValue;
}

// Удалить текст
void proc DeleteText(char cTextID)
{
   UserFunc(18, cTextID);
}

// Свернуть текст
void proc CloseText(char cTextID)
{
   UserFunc(19, cTextID);
}

// Очистить окно вывода текста
void proc ClearWindow()
{
   UserFunc(20);
}

// Забрать у игрока итем
void proc RemoveItem(char itemname, int iCount=1)
{
	UserFunc(22, itemname, iCount);  
}

// Получить случайное здание на локации, исключая передаваемое
char proc GetRandomBuild(char thisBuild)
{
   char cRet;
   cRet = UserFunc(23, thisBuild);
   return cRet;
}

// Просто рандом от 0 до х-1 включительно
int proc RandomInt(int x)
{
   int iValue;
   iValue = UserFuncInt(24, x);
   return iValue;
}

// Запустить процедуру в скрипте
void proc StartScriptEvent(char sScript, char sEvent, char item, char item2="")
{
	UserFunc(25, sScript, sEvent, item, item2);
}

// Установить внешнюю переменную  (char)
void proc SetVarChar(char event, char cValue)
{
  UserFunc(26, event, cValue);
}

// Получить внешнюю переменную  (char)
char proc GetVarChar(char event)
{
   char cValue;
   cValue = UserFunc(27, event);
   return cValue;
}

// Получить случайный товар
char proc GetRandomGoods(char thisBuild)
{
   char cRet;
   cRet = UserFunc(28, thisBuild);
   return cRet;
}

// Получить тип товара
int proc GetGoodsType(char goodsID)
{
   int iValue;
   iValue = UserFuncInt(29, goodsID);
   return iValue;
}

// Получить случайный глайдер, кроме 
// организации игрока и организации, которая указыается в параметре
char proc GetRandomGlider(char orgID)
{
   char cRet;
   cRet = UserFunc(30, orgID);
   return cRet;
}

// Проверка убийства глайдера
int proc IsKilled(char gliderID)
{
   int iRet;
   iRet = UserFuncInt(31, gliderID);
   return iRet;
}

// Выдать идентификатор локции
char proc GetArea()
{ 
   char sID;
   sID = UserFunc(34);
   return sID;
}

// Создание уникального имени механоида
char proc GetUniqueMechID()
{
   char sID;
   sID = UserFunc(40);
   return sID;
}

// создание глайдера в некой точке..
void proc CreateMech(char mechID, char pointID, char configID)
{
	UserFunc(42, mechID, pointID, configID);
}

// Удаление механоида
void proc DeleteMech(char mechID)
{
	UserFunc(43, mechID);
}

// Прикрепляем механоида (а точнее группу в которой он состоит) к игроку 
void proc AssignGliderToPlayer(char mechID, int iAssign)
{
	UserFunc(44, mechID, iAssign);
}

// Механоид переходит в какую-то организацию (в том числе убеждение)
void proc SetMechClan(char mechID, char orgID)
{
	UserFunc(45, mechID, orgID);
}

// Получить тот или иной рейтинг механоида
int proc GetRating(int ratingID)
{
	int iValue;
	iValue = UserFuncInt(90, ratingID);
	return iValue;
}

/*
// ???????? ????????????? ????? ?? ??????
char proc GetBuildClan(char buildID)
{
   char cValue;
   cValue = UserFunc(35, buildID);
   return cValue;
}*/

// Получить идентификатор клана механоида
char proc GetMechClan(char gliderID)
{
   char cValue;
   cValue = UserFunc(36, gliderID);
   return cValue;
}

// Выдача квеста игроку ( в список )
// При нажатии на него запускается событие
// void OnQuest(char questID)
void proc Quest(char questID)
{
	UserFunc(37, questID);
}

// Удалить квест
void proc RemoveQuest(char questID="ALL_GENERATED")
{
	UserFunc(38, questID);
}

// Получить рейтинг глайдера
int proc GetGliderR(char gliderID)
{
	int iValue;
	iValue = UserFuncInt(39, gliderID);
	return iValue;
}

//получить задание
void proc SetQuest(char QuestID, char TextID,  int Award, char cTimer="" )
{
	UserFunc(47, QuestID, TextID, Award, cTimer);
}

// провалить задание
void proc FailQuest(char QuestID)
{
	UserFunc(48, QuestID);
}

//выполнить задание
void proc CompleteQuest(char QuestID)
{
	UserFunc(49, QuestID);
}

// Выдать часть
void proc SetQuestPart(char QuestID, char TextID)
{
	UserFunc(50, QuestID, TextID);
}

// провален ли квест
bool proc IsQuestFail(char QuestID)
{
   if ( UserFuncInt(51, QuestID)==1)
	  return true;
   else
	 return false;
}

//закончен ли квест
bool proc IsQuestComplete(char QuestID)
{
   if ( UserFuncInt(52, QuestID)==1)
	  return true;
   else
	 return false;
}

// выдан ли квест
bool proc IsQuestSet(char QuestID)
{
   if ( UserFuncInt(53, QuestID)==1)
	  return true;
   else
	 return false;
}

// Получить случайный указатель с идентификатором по маске
char proc GetRandomPointerByMask(char sMask)
{
	char sPointer;
	sPointer = UserFunc(57, sMask);
	return sPointer;
}

// Получить тип здание ( типы описаны выше)
int proc GetBuildType(char build)
{
   int iType;
   iType = UserFuncInt(56, build);
   return iType;
}

// Получить отношение кланов друг к другу
int proc GetClanRelation(char clanID, char clan2ID)
{
	int iType;
	iType = UserFuncInt(57, clanID, clan2ID);
	return iType;
}

// Создать группу ( создать из идентификатора препрописанных геймдизайнером групп )
void proc CreateGroup(char groupID, char pointID="", int iOnlyMech=0)
{
	UserFunc(58, groupID, pointID, iOnlyMech);
}

// Послать группу глайдеров куда-то
void proc GliderGo(char gliderID, char pointID)
{
	UserFunc(59, gliderID, pointID);
}

// Установить / снять видимость группы
void proc GliderInvis(char gliderID, int bVisible=1)
{
	UserFunc(60, gliderID, bVisible);
}

// Посчитать количество механоидов в группе
int proc GetGroupCount( char groupID )
{
	int iType;
	iType = UserFuncInt(61, groupID);
	return iType;
}

// Восстановить игрока на локации ( в здании )
void proc Resurrect( char locationID, char buildingID="")
{
	UserFunc(62, locationID, buildingID);
}

// Получить от игрока то или иное оборудование в слоте
char proc GetEquipLayer ( int iEqipLayer )
{
	char sValue;
	sValue = UserFunc(63, iEqipLayer);
	return sValue;
} 

// Получить модификатор оборудования в слоте
int proc GetEquipLayerModif ( int iEqipLayer )
{
	return UserFunc(96, iEqipLayer);
} 

// Установить игроку то или иное оборудование в слоте
void proc InstallEquipLayer ( int iEqipLayer, char eqpID, int iModif = 0 )
{
	UserFunc(64, iEqipLayer, eqpID, iModif);
} 

// Убрать игроку то или иное оборудование в слоте
void proc UninstallEquipLayer ( int iEqipLayer)
{
	UserFunc(65, iEqipLayer);
} 

// Переместиться на локацию
void proc MoveToLocation( char locationID, char buildID = "")
{
	UserFunc(66, locationID, buildID);
}

// Заблокировать / разблокировать интерфейс
void proc SetCaptureInterface( int iCapture = 1)
{
	UserFunc(67, iCapture);
}

// Установить отношение между кланами
void proc SetClanRelation(char clanID, char clan2ID, int iRel)
{
	UserFunc(68, clanID, clan2ID, iRel);
}

// Установить отношение между глайдерами
void proc SetRelation(char gliderID, char glider2ID, int iRel, int iAlways=1)
{
	UserFunc(69, gliderID, glider2ID, iRel, iAlways);
}

// Установить отношение между глайдерами
void proc SetGroupClanRelation(char groupID, char orgID, int iRel)
{
	UserFunc(75, groupID, orgID, iRel);
}

//Задать количество товара в здании.
void proc SetBuildGoods(char cBuild, char cGoods, int iCount)
{
   UserFunc(70, cBuild, cGoods, iCount);
}

//Убита ли вся группа (по идентификаторы).
int proc IsGroupKilled(char groupID)
{
   int iRet;
   iRet = UserFuncInt(71, groupID);
   return iRet;
}

int proc GetHoldMech(char sOrg="")
{
   int iRet;
   iRet = UserFuncInt(72, sOrg);
   return iRet;
}

int proc IsBuildStop(char buildID)
{
   int iRet;
   iRet = UserFuncInt(73, buildID);
   return iRet;
}

int proc GetEquipStandard(char equipID)
{
   int iRet;
   iRet = UserFuncInt(74, equipID);
   return iRet;
}

void proc ThrowFromGlider(char gliderID, char goodID="ENERGY", int iCount=1)
{
   UserFunc(75, gliderID, goodID, iCount);
}

void proc SetMechName(char mechID, char name)
{
   UserFunc(76, mechID, name);
}

void proc SetMechGuard(char mechID, char pointID)
{
	UserFunc(77, mechID, pointID);
}

// Установка механоида в качестве цели
void proc SetTarget(char mechID)
{
	UserFunc(78, mechID);
}

// Активизация пушек.
void proc SetTowerActive(char cTower, int iActive = 1)
{
	UserFunc(79, cTower, iActive);
}

// Стукнуть механоида
void proc DamageGlider(char cMechID, float fValue)
{
	UserFunc(80, cMechID, fValue);
}

//Установить поколение механоида
void proc SetMechGeneration(char cMechID, int iMechGen)
{
	UserFunc(81, cMechID, iMechGen);
}

//Установить лидера клана
void proc SetClanLider(char cClanID, char cMechID)
{
	UserFunc(82, cClanID, cMechID);
}

// пометить в журнале запись
void proc MarkMsgJ(char msg, int iMark)
{
	UserFunc(83, msg, iMark);
}

// Сообщения от Глайдеров. Отличается от Text тем, что пишется от чъего имени 
void proc MechSay(char mechID, char sText)
{
	UserFunc(84, mechID, sText);
}

// добавить ключ на локацию
void proc AddLocationKey(char locID, int iMulty)
{
	UserFunc(85, locID, iMulty);
}

// Проверить ключ на локацию..
bool proc IsLocKey(char locID)
{
	bool bIs;
	bIs = UserFuncInt(86, locID)==1;
	return bIs;
}

// Очищаем список всяких текстов, выводимых на экран
void proc ClearLog()
{
	UserFunc(87);
}

// Получить тип товара (типы есть у Жени)
int proc GetGoodsPrice(char goodsID)
{
   int iValue;
   iValue = UserFuncInt(88, goodsID);
   return iValue;
}

//Удалить пеленг с точки / глайдера
void proc RemovePeleng(char cItem)
{
	UserFunc(89, cItem);
}

// Подтип здания
int proc GetBuildSubType(char cBuild)
{
   int iValue;
   iValue = UserFuncInt(91, cBuild);
   return iValue;
}

// Захват локации
void proc CaptureLocation(char cLoc, char cOrg)
{
	UserFunc(92, cLoc, cOrg);
}

// Выдать количество механоидов, находящихся в данный момент в кластере здания
int proc GetMechInCluster(char cBuild, char cOrg)
{
	int iValue;
	iValue = UserFuncInt(93, cBuild, cOrg);
	return iValue;
}

// Окончание игры с проигрыванием видеоролика.
void proc EndGame()
{
	UserFunc(94);
}

void proc PlayVideo(char cVideo, int iPlay=1)
{
	UserFunc(95, cVideo, iPlay);
}

void proc ThrowGoodsOnRoad(char goodsID, int iCount=1)
{
	UserFunc(97, goodsID, iCount);
}

void proc ChangeObjectID(char sGameID, char sTypeID)
{
	UserFunc(98, sGameID, sTypeID);
}

void proc SetEconomics(char sOrgID, int iValue, int iAdd=0)
{
	UserFunc(99, sOrgID, iValue, iAdd);
}

void proc PushConfig(char sNewConfig)
{
	UserFunc(100, sNewConfig);
}

void proc PopConfig()
{
	UserFunc(101);
}

char proc SetBuildOwner(char cBuildID, char cOrg)
{
   char sRet;
   sRet = UserFunc(102, cBuildID, cOrg);
   return sRet;
}

// Установить отношение между глайдерами
int proc GetRelation(char gliderID, char glider2ID)
{
	int iRel;
	iRel = UserFuncInt(103, gliderID, glider2ID);
	return iRel;
}
