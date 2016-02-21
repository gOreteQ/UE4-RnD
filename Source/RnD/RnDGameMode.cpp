// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "RnDGameMode.h"
#include "RnDPlayerChar.h"

ARnDGameMode::ARnDGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) 
{

	static ConstructorHelpers::FObjectFinder<UBlueprint> Character(TEXT("Blueprint'/Game/Player/BP_RnDChar.BP_RnDChar'"));
	if (Character.Object) {
		DefaultPawnClass = (UClass*)Character.Object->GeneratedClass;
	}

	//DefaultPawnClass = ARnDPlayerChar::StaticClass();
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerController(TEXT("Blueprint'/Game/Player/BP_RnDController.BP_RnDController'"));
	if (PlayerController.Object) {
		PlayerControllerClass = (UClass*)PlayerController.Object->GeneratedClass;
	}
}


