// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableActor.h"
#include "MagazineBase.h"
#include "RnDPlayerChar.h"
#include "BaseWeapon.generated.h"

/**
 * 
 */
UCLASS()
class RND_API ABaseWeapon : public AInteractableActor
{
	GENERATED_BODY()
	
public:
    ABaseWeapon();
    
    void Init();
    void Fire();
    void Reload();
 	void Recoil();   
	void CalcSpread();
	void Zeroing();	

private:
    TSubclassOf<class AMagazineBase> MagazineType;
    AMagazineBase* CurrentMagazine;
    ARnDPlayerChar* Owner;
    
    USkeletalMeshComponent* WeaponMesh;
    FVector MuzzleLocation;
    FRotator MuzzleRotation;
};
