// Fill out your copyright notice in the Description page of Project Settings.


#include "WallKiller.h"
#include "SnakeBase.h"
#include "SnakeElementBase.h"

// Sets default values
AWallKiller::AWallKiller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallKiller::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallKiller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Destroy Snake
void AWallKiller::Interact(AActor* Interactor, bool bIsHead)
{
	auto Snake = Cast<ASnakeBase>(Interactor);
	if (IsValid(Snake))
	{
		Snake->Destroy();

	}
}
