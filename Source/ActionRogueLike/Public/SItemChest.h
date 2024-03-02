// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGamplayInterface.h"
#include "GameFramework/Actor.h"
#include "SGamplayInterface.h"
#include "SItemChest.generated.h"

class ASInteractionComponent;

UCLASS()
class ACTIONROGUELIKE_API ASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float TargetPitch;

	UFUNCTION()
	void Interact_Implementation(APawn* InstigatorPawn) override;
	
public:	
	// Sets default values for this actor's properties
	ASItemChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> LidMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
