// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"

#include "SGamplayInterface.h"

void USInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* Owner = GetOwner();
	

	FVector EyeLocation;
	FRotator EyeRotaion;
	
	Owner->GetActorEyesViewPoint(EyeLocation, EyeRotaion);
	
	FVector End = EyeLocation + (EyeRotaion.Vector() * 1000.f);
	
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);

	if (AActor* HitActor = Hit.GetActor())
	{
		if (HitActor->Implements<USGameplayInterface>())
		{
			APawn* POwnwer = Cast<APawn>(Owner);
			ISGameplayInterface::Execute_Interact(HitActor, POwnwer);	
		}
	}
}

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

