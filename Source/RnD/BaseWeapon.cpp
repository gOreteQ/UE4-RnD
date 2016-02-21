// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "BaseWeapon.h"

ABaseWeapon::ABaseWeapon(){
    //PrimaryActorTick.bCanEverTick = true;
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    RootComponent = WeaponMesh;
    MuzzleLocation = WeaponMesh->GetSocketLocation("Muzzle");
    MuzzleRotation = WeaponMesh->GetSocketRotation("Muzzle");
}

void ABaseWeapon::Init(){
    
    Owner = Cast<ARnDPlayerChar>(GetOwner());
    
    if(Owner->GetMagazineCount(MagazineType) > 0){
        CurrentMagazine = Owner->GetMagazine(MagazineType);
    }
}

void ABaseWeapon::Reload(){
    if(CurrentMagazine->isEmpty()){
        Owner->RemoveCurrentMagazine();
    }
    if(Owner->GetMagazineCount(MagazineType) > 0){
        CurrentMagazine = Owner->GetNextMagazine(MagazineType);
    }
}

void ABaseWeapon::Fire(){
    if(!CurrentMagazine->isEmpty()){
		FVector ShotDirection = (CalcSpread()+Zeroing()).Normalize();
        CurrentMagazine->SpawnBullet( MuzzleTransform, ShotDirection );
		Recoil();
    } 
    else if (Owner->DoesAutoReload()){
        Reload();
    }
}
