#include "Player/Player_Pawn.h"

APlayer_Pawn::APlayer_Pawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Paddle_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Paddle_Mesh"));
	RootComponent = Paddle_Mesh;
	Spring_Arm_Component = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring_Arm_Component"));
	Camera_Comp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera_Comp"));
	
	Spring_Arm_Component->SetupAttachment(Paddle_Mesh);
	Camera_Comp->SetupAttachment(Spring_Arm_Component);

	Move_Speed = 1500.0f;
	Current_Velosity = FVector(0.0f, 0.0f, 0.0f);

	Paddle_Mesh->SetNotifyRigidBodyCollision(true);

	bReplicates = true;
	bAlwaysRelevant = true;
}

void APlayer_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayer_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
}

void APlayer_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayer_Pawn::Server_Move_Pawn_Implementation(const FVector& Movement)
{
	AddActorLocalOffset(Movement, true);
}

bool APlayer_Pawn::Server_Move_Pawn_Validate(const FVector& Movement)
{
	return true;
}


void APlayer_Pawn::Move(const FInputActionValue& Value)
{
	const float MovementValue = Value.Get<float>();
	const FVector Movement(0.f, MovementValue * Move_Speed * GetWorld()->DeltaTimeSeconds, 0.f);
	AddActorLocalOffset(Movement, true);
	Server_Move_Pawn(Movement);
}

