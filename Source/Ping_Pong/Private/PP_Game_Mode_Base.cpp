#include "PP_Game_Mode_Base.h"

void APP_Game_Mode_Base::BeginPlay()
{
	Super::BeginPlay();
}

void APP_Game_Mode_Base::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	TArray<AActor*> Found_Paddles;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayer_Pawn::StaticClass(), Found_Paddles);

	for(auto* Found_Paddle : Found_Paddles)
	{
		if (auto* Player_Pawn = Cast<APlayer_Pawn>(Found_Paddle))
		{
			if (Player_Pawn->GetController())
			{
				continue;
			}

			NewPlayer->SetIgnoreMoveInput(true);
			NewPlayer->Possess(Player_Pawn);
			break;
		}
	}

	Num_Players++;

	if (Num_Players != Required_Players)
	{
		UE_LOG(LogTemp, Log, TEXT("Waiting for players... %d/%d connected"), Num_Players, Required_Players);
		return;
	}
	StartMatch();
}

void APP_Game_Mode_Base::StartMatch()
{
	if (Game_Started)
	{
		return;
	}

	Game_Started = true;

	UE_LOG(LogTemp, Log, TEXT("Match Started!"));

	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		if (auto* PC = It->Get())
		{
			PC->SetIgnoreMoveInput(false);
		}
	}

	TArray<AActor*> Found_Balls;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABall_Actor::StaticClass(), Found_Balls);

	for (auto* Found_Ball : Found_Balls)
	{
		if (auto* Ball = Cast<ABall_Actor>(Found_Ball))
		{
			Ball->Set_Should_Move();
		}
	}
}
