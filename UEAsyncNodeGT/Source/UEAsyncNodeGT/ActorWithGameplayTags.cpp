// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorWithGameplayTags.h"


void AActorWithGameplayTags::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = OwnedGameplayTags;
}
