// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"

#include "PhysicsEngine/RadialForceComponent.h"

ASExplosiveBarrel::ASExplosiveBarrel()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComponent;

	ForceComponent = CreateDefaultSubobject<URadialForceComponent>("ForceComp");
	ForceComponent->SetupAttachment(MeshComponent);
	ForceComponent->ImpulseStrength = 2000.0f;
	ForceComponent->Radius = 700.0f;
	ForceComponent->ForceStrength = 10.f;
}

void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();

	MeshComponent->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::ComponentHit);
}

void ASExplosiveBarrel::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("ComponentHit function called"));
	ForceComponent->FireImpulse();
}

void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

