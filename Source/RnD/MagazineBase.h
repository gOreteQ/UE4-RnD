// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableActor.h"
#include "BulletBase.h"
#include "MagazineBase.generated.h"

UCLASS()
class RND_API AMagazineBase : public AInteractableActor
{
    GENERATED_BODY()
public:
    AMagazineBase();
    bool isEmpty() const;
    int getBulletCount() const;
    float getWeight() const;

    void setBulletCount(int32 amount);
    void decrementBulletCount();
    void SpawnBullet(FTransform SpawnTransform, FVector direction);
    
    virtual void Interact_Implementation(AActor* Caller) override;

private:
    TSubclassOf<class ABulletBase> BulletType;
    int32 MaxBulletCount;
    int32 BulletCount;
    float MagWeight; //Mag itself has weight
};
