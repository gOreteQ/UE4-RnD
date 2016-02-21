// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "InteractableChar.h"


// Sets default values
AInteractableChar::AInteractableChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	RootComponent = SkeletalMesh;
}

// Called when the game starts or when spawned
void AInteractableChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableChar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AInteractableChar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AInteractableChar::Interact_Implementation(AActor* Caller){
    
}
