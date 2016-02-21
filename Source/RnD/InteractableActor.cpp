// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "InteractableActor.h"


// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AInteractableActor::Interact_Implementation(AActor* Caller){
    
}
