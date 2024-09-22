#include "Ball_Actor.h"
ABall_Actor::ABall_Actor()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Ball"));
	RootComponent = Mesh_Ball;

	Movement_Speed = 2500.0f;
	Movement_Direction = FVector(FMath::FRandRange(-1.0f, 1.0f), FMath::FRandRange(-1.0f,1.0f), 0.0f);
	Mesh_Ball->SetNotifyRigidBodyCollision(true);

	Should_Move = false;

	bReplicates = true;
	bAlwaysRelevant = true;
}

void ABall_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABall_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Should_Move || !HasAuthority())
	{
		return;
	}
	FVector Temp_Location = GetActorLocation() + Movement_Direction * Movement_Speed * DeltaTime;
	Replicated_Location = Temp_Location;
	FHitResult Hit;
	SetActorLocation(Temp_Location, true, &Hit);

	if (Hit.bBlockingHit)
	{
		Movement_Direction = Movement_Direction.MirrorByVector(Hit.Normal);
	}
}

void ABall_Actor::Set_Should_Move()
{
	Should_Move = true;
}

void ABall_Actor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABall_Actor, Replicated_Location);
}

void ABall_Actor::OnRep_ReplicatedLocation()
{
	SetActorLocation(Replicated_Location);
}
