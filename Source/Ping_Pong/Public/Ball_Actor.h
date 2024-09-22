#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "Ball_Actor.generated.h"

UCLASS()
class PING_PONG_API ABall_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABall_Actor();

	virtual void Tick(float DeltaTime) override;

	void Set_Should_Move();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_ReplicatedLocation();

	UPROPERTY(ReplicatedUsing = OnRep_ReplicatedLocation)
	FVector Replicated_Location;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* Mesh_Ball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float Movement_Speed;

	FVector Movement_Direction;

private:
	bool Should_Move;
};
