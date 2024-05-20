#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSEnd.h"
#include "GSAbout.h"
#include "GSHighScore.h"
#include "GSSetting.h"
GameStateBase* GameStateBase::CreateState(StateTypes st)
{
		GameStateBase* gs = nullptr;
		switch (st)
		{
		case INVALID:
			break;
		case INTRO:
			gs = new GSIntro();
			break;
		case MENU:
			gs = new GSMenu();
			break;
		case PLAY:
			gs = new GSPlay();
			break;
		case SETTINGS:
			gs = new GSSettings();
			break;
		case ABOUT:
			gs = new GSAbout();
			break;
		case HIGHSCORE:
			gs = new GSHighScore();
			break;
		default:
			break;
		}
		return gs;
}
