#include "Gate_Actor.h"

AGate_Actor::AGate_Actor()
{
	PrimaryActorTick.bCanEverTick = true;
	Box_Component = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(Box_Component);

	Box_Component->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box_Component->SetCollisionResponseToAllChannels(ECR_Overlap);
}

void AGate_Actor::BeginPlay()
{
	Super::BeginPlay();
	
	Box_Component->OnComponentBeginOverlap.AddDynamic(this, &AGate_Actor::OnActorBeginOverlap);


}

void AGate_Actor::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<ABall_Actor>())
	{ 
		//UE_LOG(LogTemp, Warning, TEXT("Goal!!!"));

		EPlayer_ID Player_ID;
		if (OtherActor->GetActorLocation().Y < 0)
		{
			Player_ID = EPlayer_ID::Player2;
		}
		else if (OtherActor->GetActorLocation().Y > 0)
		{
			Player_ID = EPlayer_ID::Player1;
		}

		if (auto* Player_Controller = Cast<APP_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0)))
		{
			Player_Controller->Add_Score(Player_ID);
		}
	}
}

void AGate_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

