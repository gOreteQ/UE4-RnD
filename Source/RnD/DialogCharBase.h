// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableChar.h"
#include "DialogCharBase.generated.h"

USTRUCT(Blueprintable)
struct FDialogData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
        FText Question;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		FText Answer1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		FText Answer2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		FText Answer3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		FText Answer4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		FText AnswerEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		int32 A1Goto;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		int32 A2Goto;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		int32 A3Goto;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
		int32 A4Goto;
};

UCLASS()
class RND_API ADialogCharBase : public AInteractableChar
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	UDataTable* DialogDataTable;

	UFUNCTION(BlueprintCallable, Category = Dialog)
	FDialogData getDialogRowData(int32 RowID);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FName CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	int32 DialogStartRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	uint32 bListenOnly : 1; //using bitfield to save memory (sun)

	// Sets default values for this character's properties
	ADialogCharBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
        
        virtual void Interact_Implementation(AActor* Caller) override;

};
