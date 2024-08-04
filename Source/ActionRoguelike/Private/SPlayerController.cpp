// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerController.h"

#include "EnhancedInputSubsystems.h"


ASPlayerController::ASPlayerController()
{
	bReplicates = true;
}

void ASPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(SContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
}
