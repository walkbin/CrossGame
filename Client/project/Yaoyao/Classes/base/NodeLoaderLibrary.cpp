/********************************************************************
	文件名: 	TacNodeLoaderLibrary.cpp
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:18
	
	说明:		
*********************************************************************/
//project
#include "Base/TacNodeLoaderLibrary.h"
#include "Base/TacLabelBMFontLoader.h"
#include "Base/TacLabelTTFLoader.h"
#include "Base/TacControlButtonLoader.h"

//UI
#include "../Plaza/UI/ChatLayer.h"
#include "../Plaza/UI/ProfileImageSelect.h"
#include "../Plaza/UI/LoadingLayer.h"
#include "../Plaza/UI/LoginBoard.h"
#include "../Plaza/UI/LoginLayer.h"
#include "../Plaza/UI/PasswordBoard.h"
#include "../Plaza/UI/ProfileLayer.h"
#include "../Plaza/UI/ProfileSetting.h"
#include "../Plaza/UI/RoomItem.h"
#include "../Plaza/UI/RoomLayer.h"
#include "../Plaza/UI/RoomState.h"
#include "../Plaza/UI/SignupBoard.h"
#include "../Plaza/UI/StarsignBoard.h"
#include "../Plaza/UI/WarningLayer.h"
#include "../Plaza/UI/StoreItem.h"
#include "../Plaza/UI/StoreItemList.h"
#include "../Plaza/UI/StoreLayer.h"
#include "../Plaza/UI/SettingLayer.h"
#include "../Plaza/UI/TimeBonus.h"
#include "../Plaza/UI/RoomUnlock.h"
#include "../Plaza/UI/DailyBonus.h"
#include "../Plaza/UI/RoomInfoBar.h"
#include "../Plaza/UI/SysLoadingBoard.h"
#include "Plaza/UI/ProfileProp.h"
#include "Plaza/UI/ProfileDetail.h"
#include "Plaza/UI/PublicNotice.h"
#include "Plaza/UI/StoreTablebar.h"

#include "../Game/UI/NumberBallPannel.h"
#include "../Game/UI/Game1card.h"
#include "../Game/UI/Game2card.h"
#include "Game/UI/GameResult.h"
#include "../Game/UI/NumberBall.h"
#include "../Game/UI/BingoRules.h"
#include "../Game/UI/GameSelectCard.h"
#include "../Game/UI/AllNumPad.h"
#include "../Game/UI/GuidePannel.h"
#include "../Game/UI/RankCard.h"
#include "../Game/UI/RuleButton.h"
#include "../Game/UI/LevelUpBoard.h"
#include "Game/UI/LevelUpPrizePannel.h"
#include "../Game/UI/GuidePannel.h"
#include "../Game/UI/BingoCard.h"
#include "../Game/UI/ChatIcon.h"
#include "../Game/UI/PropShow.h"
#include "../Game/UI/PropStage.h"
#include "../Game/UI/Powertube.h"
#include "../Game/UI/PropImage.h"
#include "Game/UI/CardExp.h"
#include "Game/UI/CardNum.h"
#include "Game/UI/CardPropGet.h"
#include "Game/UI/CardWatermark.h"

#include "Game/UI/GameplayMoney.h"

#include "Game/UI/WaitingBoard.h"


TacNodeLoaderLibrary::TacNodeLoaderLibrary(void)
{
}


TacNodeLoaderLibrary::~TacNodeLoaderLibrary(void)
{
}

void TacNodeLoaderLibrary::registerDefaultCCNodeLoaders()
{
	//多国语言
	registerCCNodeLoader("CCLabelTTF", LabelTTFLoader::loader());
	registerCCNodeLoader("CCLabelBMFont", LabelBMFontLoader::loader());
	registerCCNodeLoader("CCControlButton", ControlButtonLoader::loader());
	//具体项目相关
	registerCCNodeLoader("BingoboardAni", NumberBallPannelLoader::loader());
	registerCCNodeLoader("Bingoball", NumberBallLoader::loader());
	registerCCNodeLoader("Bingowinboard", BingoRulesLoader::loader());
	registerCCNodeLoader("ChatScene", ChatLayerLoader::loader());
	registerCCNodeLoader("Gameplay_ready", GameSelectCardLoader::loader());
	registerCCNodeLoader("Gameplay_1card", Game1cardLoader::loader());
	registerCCNodeLoader("Gameplay_2cards", Game2cardLoader::loader());
	registerCCNodeLoader("Imageboard", ProfileImageSelectLoader::loader());
	registerCCNodeLoader("LoadingScene", LoadingLayerLoader::loader());
	registerCCNodeLoader("LoginBoard", LoginBoardLoader::loader());
	registerCCNodeLoader("LoginScene", LoginLayerLoader::loader());
	registerCCNodeLoader("Numberboard", AllNumPadLoader::loader());
	registerCCNodeLoader("Passwordboard", PasswordBoardLoader::loader());
	registerCCNodeLoader("ProfileScene", ProfileLayerLoader::loader());
	registerCCNodeLoader("ProfileEditboard", ProfileSettingLoader::loader());
	registerCCNodeLoader("rankcard", RankCardLoader::loader());
	registerCCNodeLoader("Ranklist", RankItemLoader::loader());
	registerCCNodeLoader("RanklistAni", RankPannelLoader::loader());
	registerCCNodeLoader("Result", GameResultLoader::loader());
	registerCCNodeLoader("RoomItem", RoomItemLoader::loader());
	registerCCNodeLoader("RoomScene", RoomLayerLoader::loader());
	registerCCNodeLoader("RoomInfoBar",RoomInfoBarLoader::loader());
	registerCCNodeLoader("roomstate", RoomStateLoader::loader());
	registerCCNodeLoader("rulebutton", RuleButtonLoader::loader());
	registerCCNodeLoader("SignupBoard", SignupBoardLoader::loader());
	registerCCNodeLoader("Starsignboard", StarsignBoardLoader::loader());
	registerCCNodeLoader("Waitingboard", WaitingBoardLoader::loader());
	registerCCNodeLoader("warningboard", WarningLayerLoader::loader());
	registerCCNodeLoader("storeitem", StoreItemLoader::loader());
	registerCCNodeLoader("storeselect", StoreItemListLoader::loader());
	registerCCNodeLoader("Store", StoreLayerLoader::loader());
	registerCCNodeLoader("setting", SettingLayerLoader::loader());
	registerCCNodeLoader("Timebonus",TimeBonusLoader::loader());
	registerCCNodeLoader("levelup",LevelUpBoardLoader::loader());
    registerCCNodeLoader("levelupprize",LevelUpPrizePannelLoader::loader());
	registerCCNodeLoader("roomunlock",RoomUnlockLoader::loader());
	registerCCNodeLoader("DailyBonus",DailyBonusLoader::loader());
	registerCCNodeLoader("tutorial",GuidePannelLoader::loader());
	registerCCNodeLoader("bingocard",BingoCardLoader::loader());
	registerCCNodeLoader("sysloading",SysLoadingBoardLoader::loader());
	registerCCNodeLoader("chaticon", ChatIconLoader::loader());
	registerCCNodeLoader("propsystem", PropShowLoader::loader());
	registerCCNodeLoader("propstage", PropStageLoader::loader());
	registerCCNodeLoader("powertube", PowertubeLoader::loader());
	registerCCNodeLoader("prop", PropImageLoader::loader());
    registerCCNodeLoader("expflow", CardExpLoader::loader());
    registerCCNodeLoader("cardlattic", CardNumLoader::loader());
    registerCCNodeLoader("propget", CardPropGetLoader::loader());
    registerCCNodeLoader("watermark",CardWatermarkLoader::loader());
    registerCCNodeLoader("profileProp",ProfilePropLoader::loader());
    registerCCNodeLoader("profileDetail",ProfileDetailLoader::loader());
	registerCCNodeLoader("news", PublicNoticeLoader::loader());
    registerCCNodeLoader("storesheet",StoreTablebarLoader::loader());
	registerCCNodeLoader("GameplayMoney",GameplayMoneyPanelLoader::loader());
	CCNodeLoaderLibrary::registerDefaultCCNodeLoaders();
}

TacNodeLoaderLibrary * TacNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary() 
{
	TacNodeLoaderLibrary * ccNodeLoaderLibrary = TacNodeLoaderLibrary::library();
	ccNodeLoaderLibrary->registerDefaultCCNodeLoaders();
	return ccNodeLoaderLibrary;
}