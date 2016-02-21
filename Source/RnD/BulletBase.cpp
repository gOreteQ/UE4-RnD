// Fill out your copyright notice in the Description page of Project Settings.

#include "RnD.h"
#include "BulletBase.h"

ABulletBase::ABulletBase(){
    PrimaryActorTick.bCanEverTick = true;
}

void ABulletBase::Initialize(FVector Direction, float AirDensity){
    Velocity = Direction * MuzzleVelocity;
    mass = Weight/1000; //physical calulations need kg
    drag = (CW*AirDensity*(Caliber*Caliber*pi))/2; //Fdrag = 1/2*cw*rho*A*v² //the v² part will be later
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, *(FString(__FUNCTION__)));
    
    RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
    RV_TraceParams.bTraceComplex = true;
    RV_TraceParams.bTraceAsyncScene = false;
    RV_TraceParams.bReturnPhysicalMaterial = false;
}


/**
 * TODO: run on server, prevents cheating
 **/
void ABulletBase::ApplyDrag(float DeltaSeconds){
    float speed = Velocity.Size()/100; //cm per sec to m/s
    float Fdrag = drag*( speed*speed ); //Fdrag = 1/2*cw*rho*A*v²
    float dAcceleration = Fdrag/mass * DeltaSeconds; //F=m*a -> a=F/m | *deltaTime because we want the change of Acceleration
    dAcceleration *= 100; //convert back to cm per second

    this->Velocity = (speed-dAcceleration)/speed * Velocity; //newSpeed/oldSpeed = percentage ; multiply with Velocity to make Vector
}

void ABulletBase::ApplyGravity(float DeltaSeconds){
    FVector Gravity (0, 0, -980); //in cm | TODO: find way to get Gravity from level

    Velocity = Velocity + ( Gravity*DeltaSeconds );
}

void ABulletBase::MoveBullet(float DeltaSeconds){
    FVector newLocation(0.f);

    newLocation = GetActorLocation() * Velocity * DeltaSeconds; //does this need explaining?
    
    SetActorLocation(newLocation);
    SetActorRotation(Velocity.Rotation());
}

FHitResult ABulletBase::Trace(float DeltaSeconds){
    //Re-initialize hit info
    FHitResult RV_Hit(ForceInit);
    FVector Start = GetActorLocation();
    FVector End = GetActorLocation() + Velocity * DeltaSeconds;
     
    //call GetWorld() from within an actor extending class
    GetWorld()->LineTraceSingle(
        RV_Hit,     //result
        Start,      //start
        End,        //end
        ECC_Pawn,   //collision channel
        RV_TraceParams
    );
    
    return RV_Hit;
}

void ABulletBase::Impact(){
    
}

void ABulletBase::Tick( float DeltaSeconds ){
    FHitResult Hit = Trace(DeltaSeconds);
    if(Hit.bBlockingHit){
        Impact();
    } else {
        MoveBullet(DeltaSeconds);
        ApplyGravity(DeltaSeconds);
        ApplyDrag(DeltaSeconds);
    }
}

float ABulletBase::getWeight() const{
    return Weight;
}

void ABulletBase::BeginPlay(){

}
