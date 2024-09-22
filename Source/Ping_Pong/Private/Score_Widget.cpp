// Fill out your copyright notice in the Description page of Project Settings.


#include "Score_Widget.h"

void UScore_Widget::Set_Player_1_Point(int32 Score)
{
    if (Player_1_Point_Text)
    {
        Player_1_Point_Text->SetText(FText::FromString(FString::FromInt(Score)));
    }
}

void UScore_Widget::Set_Player_2_Point(int32 Score)
{
    if (Player_2_Point_Text)
    {
        Player_2_Point_Text->SetText(FText::FromString(FString::FromInt(Score)));
    }
}