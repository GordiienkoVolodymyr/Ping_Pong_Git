#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Player_Pawn.generated.h"

UCLASS()
class PING_PONG_API APlayer_Pawn : public APawn
{
	GENERATED_BODY()

public:
	APlayer_Pawn();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Move_Speed;

protected:
	virtual void BeginPlay() override;	

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_Move_Pawn(const FVector& Movement);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Paddle_Mesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* Spring_Arm_Component;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera_Comp;

	FVector Current_Velosity;
};
