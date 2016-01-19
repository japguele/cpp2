#include "stdafx.h"
#include "KingCard.h"


KingCard::KingCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
}


KingCard::~KingCard()
{
}

void KingCard::StartTurn()
{
	
}
