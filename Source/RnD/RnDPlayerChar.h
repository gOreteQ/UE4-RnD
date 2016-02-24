// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableChar.h"
#include "InventoryComponent.h"
#include "RnDPlayerChar.generated.h"

/**
 * 
 */
UCLASS()
class RND_API ARnDPlayerChar : public AInteractableChar
{
	GENERATED_BODY()
public:
    ARnDPlayerChar();
    
    bool DoesAutoReload();
    int GetMagazineCount(TSubclassOf<class AMagazineBase> MagazineType);
    AMagazineBase* GetMagazine(TSubclassOf<class AMagazineBase> MagazineType);
    AMagazineBase* GetNextMagazine(TSubclassOf<class AMagazineBase> MagazineType);
    
    void RemoveCurrentMagazine();
       
    virtual void BeginPlay() override;
    virtual void Tick( float DeltaSeconds ) override;
    //virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    virtual void Interact_Implementation(AActor* Caller) override;
    
private:
    bool bAutoReload;
    UInventoryComponent* Inventory;
};
