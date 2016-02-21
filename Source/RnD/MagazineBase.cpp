// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "MagazineBase.h"

AMagazineBase::AMagazineBase()
{
    //PrimaryActorTick.bCanEverTick = true;
}

bool AMagazineBase::isEmpty() const
{
    if(BulletCount <= 0)
        return true;
    return false;
}

void AMagazineBase::SpawnBullet(FTransform SpawnTransform, FVector ShotDir){
    UWorld* const world = GetWorld();
    if(world){
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = GetOwner();
        SpawnParams.Instigator = Instigator;
        ABulletBase* Bullet = world->SpawnActor<ABulletBase>(BulletType, SpawnTransform,  SpawnParams);
        if(Bullet){
            Bullet->Initialize( ShotDir, 1.29f );
        }
    }
}

void AMagazineBase::Interact_Implementation(AActor* Caller){
    /*Pickup*/
    //Some stuff on player
    //remove actor from scene (DON'T DESTROY!!)
    SetOwner(Caller);
}

int AMagazineBase::getBulletCount() const
{
    return BulletCount;
}

float AMagazineBase::getWeight() const
{
    return MagWeight + (BulletCount * BulletType->GetDefaultObject<ABulletBase>()->getWeight());
}

void AMagazineBase::setBulletCount(int32 amount)
{
    this->BulletCount = amount;
}

void AMagazineBase::decrementBulletCount()
{
    this->BulletCount--;
}
