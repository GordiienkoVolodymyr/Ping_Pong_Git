
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Score_Widget.h"
#include "Player_Pawn.h"
#include "PP_Player_Controller.generated.h"

UENUM(BlueprintType)
enum EPlayer_ID : uint8
{
    Player1 UMETA(DisplayName = "Player 1"),
    Player2 UMETA(DisplayName = "Player 2")
};

UCLASS()
class PING_PONG_API APP_Player_Controller : public APlayerController
{
	GENERATED_BODY()
	
public:

    void Add_Score(EPlayer_ID PlayerID);
    void Update_Score_Player1();
    void Update_Score_Player2();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    int64 Score;

    int32 Player_1_Point = 0;
    int32 Player_2_Point = 0;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> Game_Widget_type;

    UPROPERTY()
    UScore_Widget* Widget;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

    void Create_Player_Widget();

private:
    void Setup_Input();
    void Move(const FInputActionValue& Value);

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* PlayerMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* MoveAction;

    APlayer_Pawn* Paddle_Pawn;

};
