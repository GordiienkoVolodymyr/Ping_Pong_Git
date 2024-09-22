#pragma once

#include "Ball_Actor.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Gate_Actor.h"
#include "Player/Player_Pawn.h"
#include "Kismet/GameplayStatics.h"

#include "PP_Game_Mode_Base.generated.h"

UCLASS()
class PING_PONG_API APP_Game_Mode_Base : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;

private:
	void StartMatch();

	const int32 Required_Players = 2;
	bool Game_Started = false;
	int32 Num_Players = 0;
};
