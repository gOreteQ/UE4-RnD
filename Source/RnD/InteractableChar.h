// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "InteractableChar.generated.h"

UCLASS()
class RND_API AInteractableChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AInteractableChar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
    void Interact(AActor* Caller);
    virtual void Interact_Implementation(AActor* Caller);
	
private:

};
