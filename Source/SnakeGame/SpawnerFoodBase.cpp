// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerFoodBase.h"
#include "Food.h"
#include "BonusFoodBase.h"
#include "SnakeBase.h"
#include "PlayerPawnBase.h"
#include "SpawnerFoodBase.h"

// Sets default values
ASpawnerFoodBase::ASpawnerFoodBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerFoodBase::BeginPlay()
{
	Super::BeginPlay();
	AddRandomApple();
	SpawnBonusLimit = 5.f;
}

// Called every frame
void ASpawnerFoodBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (SpawnBonusLimit == 0)
	{
		SpawnBonusFood();
		SpawnBonusLimit += 5.f;
	}
}

void ASpawnerFoodBase::AddRandomApple()
{
	GameMode = 1;
	FRotator StartPointRotation = FRotator(0, 0, 0);

	float SpawnX = FMath::FRandRange(MinX, MaxX);
	float SpawnY = FMath::FRandRange(MinY, MaxY);

	FVector StartPoint = FVector(SpawnX, SpawnY, SpawnZ);
	FTransform Transform(StartPoint);
	AFood* NewFood = GetWorld()->SpawnActor<AFood>(FoodClass, Transform);
	NewFood->OnDestroyed.AddDynamic(this, &ASpawnerFoodBase::DestroyFood);
}

void ASpawnerFoodBase::SpawnBonusFood()
{
	FRotator StartPointRotation = FRotator(0, 0, 0);

	float SpawnX = FMath::FRandRange(MinX, MaxX);
	float SpawnY = FMath::FRandRange(MinY, MaxY);

	FVector StartPoint = FVector(SpawnX, SpawnY, SpawnZ);
	FTransform Transform(StartPoint);
	ABonusFoodBase* NewBonusFood = GetWorld()->SpawnActor<ABonusFoodBase>(BonusFoodClass, Transform);
}

void ASpawnerFoodBase::DestroyBonusFood(AActor* Dest)
{

	SpawnBonusFood();
}

void ASpawnerFoodBase::DestroyFood(AActor* Dest)
{
	SpawnBonusLimit--;
	AddRandomApple();
}


