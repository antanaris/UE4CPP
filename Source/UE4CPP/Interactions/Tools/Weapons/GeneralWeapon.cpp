// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneralWeapon.h"
#include "DrawDebugHelpers.h"
#include "Engine/StaticMeshSocket.h"


AGeneralWeapon::AGeneralWeapon()
{
	
}

void AGeneralWeapon::BeginPlay()
{
	Super::BeginPlay();

	// Get weapon mesh and add muzzle socket to it
	UStaticMesh* StaticMesh = Mesh->GetStaticMesh();

	if(StaticMesh)
	{
		MuzzleSocket = NewObject<UStaticMeshSocket>(StaticMesh);

		// defining Muzzle socket
		MuzzleSocket->SocketName = MuzzleSocketName;
		MuzzleSocket->RelativeLocation = FVector(10, 0, 0);
		MuzzleSocket->RelativeRotation = FRotator(0, 0, 0);

		// creating Muzzle socket
		StaticMesh->AddSocket(MuzzleSocket);

		// Muzzle Socket is created
		bHasMuzzleSocket = true;
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Weapon doesn't have visual representation. Defining as a virtual weapon."));
	}
}

void AGeneralWeapon::Fire()
{
	FHitResult HitResult;
	FVector StartLocation;
	FVector EndLocation;

	if(bHasMuzzleSocket)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Firing from the muzzle on the weapon mesh"));
		StartLocation = Mesh->GetSocketLocation(MuzzleSocketName);
		EndLocation = StartLocation + (Mesh->GetSocketRotation(MuzzleSocketName).Vector() * Range);	
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Firing from the virtual weapon"));
		StartLocation = GetActorLocation();
		EndLocation = StartLocation + (GetActorRotation().Vector() * Range);
	}

	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility);

	if(bIsDebug)
	{
		DrawDebugSphere(GetWorld(), StartLocation, 3, 10, FColor::Blue, false, 25.0f);
		DrawDebugSphere(GetWorld(), EndLocation, 3, 10, FColor::Green, false, 25.0f);
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Orange, false, 25.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 6, 10, FColor::Red, true, 25.0f);
	}
}

void AGeneralWeapon::CanFire(bool& bCanFire) const
{
}

void AGeneralWeapon::CanReload(bool& bCanReload) const
{
}

void AGeneralWeapon::Reload()
{
}

void AGeneralWeapon::UseAmmo()
{
}

void AGeneralWeapon::WeaponTrace()
{
}

void AGeneralWeapon::WeaponTrace(FVector& HitLocation)
{
}