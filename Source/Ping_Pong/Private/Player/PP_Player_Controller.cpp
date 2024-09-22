#include "Player/PP_Player_Controller.h"

void APP_Player_Controller::BeginPlay()
{
    Super::BeginPlay();

    Paddle_Pawn = Cast<APlayer_Pawn>(GetPawn());

    Setup_Input();
    Create_Player_Widget();
}

void APP_Player_Controller::SetupInputComponent()
{
    Super::SetupInputComponent();
}

void APP_Player_Controller::Create_Player_Widget()
{
    if (!IsLocalController())
    {
        return;
    }

    if (Game_Widget_type)
    {
        Widget = Cast<UScore_Widget>(CreateWidget(this, Game_Widget_type));

        if (Widget)
        {
            Widget->AddToViewport();
        }
    }
}

void APP_Player_Controller::Setup_Input()
{
    if (!Paddle_Pawn)
    {
        return;
    }

    if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(PlayerMappingContext, 0);
    }

    if (InputComponent)
    {
        if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
        {
            EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APP_Player_Controller::Move);
        }
    }
}

void APP_Player_Controller::Move(const FInputActionValue& Value)
{
    if (Paddle_Pawn)
    {
        Paddle_Pawn->Move(Value);
    }
}


void APP_Player_Controller::Add_Score(EPlayer_ID PlayerID)
{
    switch (PlayerID)
    {
        case EPlayer_ID::Player1:
        {
            Player_1_Point = Player_1_Point + 1;
            Update_Score_Player2();
            break;
        }
        case EPlayer_ID::Player2:
        {
            Player_2_Point = Player_2_Point + 1;
            Update_Score_Player1();
            break;
        }
    }

}

void APP_Player_Controller::Update_Score_Player1()
{
    if (Widget)
    {
        Widget->Set_Player_1_Point(Player_1_Point);
    }
}

void APP_Player_Controller::Update_Score_Player2()
{
    if (Widget)
    {      
        Widget->Set_Player_1_Point(Player_2_Point);
    }
}
