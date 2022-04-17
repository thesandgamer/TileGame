#include "InformationDisplayUi.h"

InformationDisplayUi::InformationDisplayUi(): position{0,0}, infoLinkedTo{nullptr}
{
}

InformationDisplayUi::~InformationDisplayUi()
{
}

void InformationDisplayUi::Draw()
{
	if (infoLinkedTo != nullptr)
	{ 
		DrawText(infoLinkedTo->GetTitle().c_str(), position.x, position.y, 20, WHITE);
	}
}
