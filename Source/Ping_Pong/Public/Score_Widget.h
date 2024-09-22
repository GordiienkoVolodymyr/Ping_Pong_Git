#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Score_Widget.generated.h"

UCLASS()
class PING_PONG_API UScore_Widget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void Set_Player_1_Point(int32 Score);
	void Set_Player_2_Point(int32 Score);

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Player_1_Point_Text;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Player_2_Point_Text;
};
