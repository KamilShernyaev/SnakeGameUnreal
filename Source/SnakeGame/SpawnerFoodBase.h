// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerFoodBase.generated.h"

class AFood;
class ABonusFoodBase;
UCLASS()
class SNAKEGAME_API ASpawnerFoodBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerFoodBase();

	UPROPERTY(EditDefaultsOnly);
	TSubclassOf<AFood> FoodClass;

	UPROPERTY(EditDefaultsOnly);
	TSubclassOf<ABonusFoodBase> BonusFoodClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
		void DestroyFood(AActor* Dest);

	UFUNCTION(BlueprintCallable, Category = "SnakePawn")
		void AddRandomApple();

	UFUNCTION()
		void DestroyBonusFood(AActor* Dest);

	UFUNCTION()
		void SpawnBonusFood();

	//Границы спавна еды и бонусов
	float MinY = -700.f;
	float MaxY = 700.f;

	float MinX = -600.f;
	float MaxX = 540.f;

	float SpawnZ = 50.f;

	float SpawnBonusLimit = 5.f;

	int32 GameMode = 0;
};
