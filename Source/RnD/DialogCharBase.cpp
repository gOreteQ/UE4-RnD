// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "DialogCharBase.h"


FDialogData ADialogCharBase::getDialogRowData(int32 RowID)
{
	FDialogData* Result = DialogDataTable->FindRow<FDialogData>(*FString::Printf(TEXT("%d"), RowID), "", true);
	if (Result) {
		return *Result;
	}
	else {
		return FDialogData();
	}
}

// Sets default values
ADialogCharBase::ADialogCharBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADialogCharBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADialogCharBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ADialogCharBase::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ADialogCharBase::Interact_Implementation(AActor* Caller){
    
}