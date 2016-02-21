// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BulletBase.generated.h"

/**
 * Big Thanks to the guy who made RealisticBlueprintWeapons!
 */
UCLASS()
class RND_API ABulletBase : public AActor
{

    GENERATED_BODY()

public:
    /*CONSTRUCTOR*/
    ABulletBase();
    void Initialize(FVector Direction, float AirDensity);

    /*GETTERS*/
    float getWeight() const;
    float getCaliber() const;
    float getMuzzleVelocity() const;
    float getDrag() const;
    FVector getVelocity() const;

    /*FUNCTIONS*/
    void MoveBullet(float DeltaSeconds);
    FHitResult Trace(float DeltaSeconds);
    void ApplyDrag(float DeltaSeconds);
    void ApplyGravity(float DeltaSeconds);
    void Impact();

    /*ON HOLD*/
    //void ApplyWind();
    //void Ricochet();
    //void Penetrate();
    //void SpawnImpactEffect();

    /*DEFAULTS*/
    virtual void BeginPlay() override;
    virtual void Tick( float DeltaSeconds ) override;

private:
    float Weight; //Of the Bullet, without shell!
    float Caliber;
    float MuzzleVelocity; //cm per sec
    float CW; //Air Resistance (sphere ~0.5, streamlined ~0.06)
    FVector Velocity;

    float pi = 3.141459;

    float drag; // 1/2*cw*rho*A
    float mass; // mass in kg
    FCollisionQueryParams RV_TraceParams;
};
