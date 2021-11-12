// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeapon::Fire()
{
}

void AWeapon::CanFire(bool& bCanFire) const
{
}

void AWeapon::CanReload(bool& bCanReload) const
{
}

void AWeapon::Reload()
{
}

void AWeapon::UseAmmo()
{
}

void AWeapon::WeaponTrace()
{
}

void AWeapon::WeaponTrace(FVector& HitLocation)
{
}

