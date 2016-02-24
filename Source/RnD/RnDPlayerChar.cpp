// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "RnDPlayerChar.h"

ARnDPlayerChar::ARnDPlayerChar(){
    Inventory=CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
}

void ARnDPlayerChar::BeginPlay(){
    
}

void ARnDPlayerChar::Tick(float DeltaSeconds){
    
}

//void ARnDPlayerChar::SetupPlayerInputComponent(class UInputComponent* InputComponent){
//    
//}

void ARnDPlayerChar::Interact_Implementation(AActor* Caller){
    
}
