#pragma once

#include "Ball_Actor.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Player/PP_Player_Controller.h"
#include "Gate_Actor.generated.h"


UCLASS()
class PING_PONG_API AGate_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGate_Actor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Gate")
	UBoxComponent* Box_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Gate")
	UStaticMeshComponent* Mesh_Component;

	UFUNCTION()
	void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
