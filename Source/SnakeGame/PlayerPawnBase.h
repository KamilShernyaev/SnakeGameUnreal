// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawnBase.generated.h"

class UCameraComponent;
class ASnakeBase;
UCLASS()
class SNAKEGAME_API APlayerPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawnBase();

	UPROPERTY(BlueprintReadWrite)
		UCameraComponent* PawnCamera;

	UPROPERTY(BluePrintReadWrite)
		ASnakeBase* SnakeActor;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASnakeBase> SnakeActorClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void HadlePlayerVerticalInput(float value);
	UFUNCTION()
		void HadlePlayerHorizontalInput(float value);

	UFUNCTION(BlueprintCallable, Category = "SnakePawn")
		int32 GetScore();

	UFUNCTION(BlueprintCallable, Category = "SnakePawn")
		void CreateSnakeActor();

	UFUNCTION(BlueprintCallable, Category = "SnakePawn")
		int32 GetGameMode() const { return GameMode; }

	int32 GameMode = 0;

};
