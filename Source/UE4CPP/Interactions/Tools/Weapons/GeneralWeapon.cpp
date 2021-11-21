// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneralWeapon.h"
#include "DrawDebugHelpers.h"
#include "Engine/StaticMeshSocket.h"

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
	if(CanFire())
		{
			UseAmmo();
			WeaponTrace();
		}
}

bool AGeneralWeapon::CanFire() const
{
	// Can fire if there is ammo in clip
	return(CurrentAmmoInClip > 0 && bIsReloading == false);
}

bool AGeneralWeapon::_CanReload() const
{
	// Reloading is only possible if there is ammo left, clip has free slots and weapon is not reloading
	return((CurrentAmmo > 0) && (CurrentAmmoInClip < AmmoPerClip) && !bIsReloading);
}

void AGeneralWeapon::_Reload()
{
	if(CurrentAmmo >= AmmoPerClip)
	{
		// fill the clip
		CurrentAmmoInClip = AmmoPerClip;
	}
	else
	{
		// fill the clip with remaining ammo
		CurrentAmmoInClip = CurrentAmmo;
	}
}

bool AGeneralWeapon::CanReload_Implementation()
{
	IReloadable::CanReload_Implementation();

	return(_CanReload());
}

void AGeneralWeapon::Reload_Implementation()
{
	IReloadable::Reload_Implementation();

    _Reload();

}

void AGeneralWeapon::UseAmmo()
{
	CurrentAmmoInClip--;
	CurrentAmmo--;
}

FHitResult AGeneralWeapon::WeaponTrace()
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
		DrawDebugSphere(GetWorld(), StartLocation, 3, 10, FColor::Blue, false, 5.0f);
		DrawDebugSphere(GetWorld(), EndLocation, 3, 10, FColor::Green, false, 5.0f);
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Orange, false, 5.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 6, 10, FColor::Red, true, 5.0f);
	}

	OnWeaponHit.Broadcast(HitResult);
	
	return HitResult;
}

void AGeneralWeapon::WeaponTrace(FVector& HitLocation)
{
}