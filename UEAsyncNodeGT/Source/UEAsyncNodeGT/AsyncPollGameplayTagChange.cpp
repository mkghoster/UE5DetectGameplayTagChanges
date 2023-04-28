// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncPollGameplayTagChange.h"

UAsyncPollGameplayTagChange* UAsyncPollGameplayTagChange::AsyncPollGameplayTagChange(
	AActor* TargetActor, float PollFrequency)
{
	UAsyncPollGameplayTagChange* obj = NewObject<UAsyncPollGameplayTagChange>();

	if(Cast<IGameplayTagAssetInterface>(TargetActor))
	{
		obj->TargetGTA = TargetActor;
	}
	
	obj->PollFrequency = PollFrequency;
	return obj;
}

void UAsyncPollGameplayTagChange::Activate()
{
	Super::Activate();
	
	if(TargetGTA && IsValid(TargetGTA.GetObject()))
	{
		TargetGTA->GetOwnedGameplayTags(GTCCache);
		
		TargetGTA.GetObject()->GetWorld()->GetTimerManager().SetTimer(
			TimerHandle_Poll, this, &UAsyncPollGameplayTagChange::Poll, PollFrequency, true);
	}
	else
	{
		OnTargetNotValid.Broadcast(FGameplayTagContainer::EmptyContainer);
		SetReadyToDestroy();
		MarkAsGarbage();
	}
}

void UAsyncPollGameplayTagChange::Poll()
{
	if(TargetGTA && IsValid(TargetGTA.GetObject()))
	{
		FGameplayTagContainer CurrentTags;
		TargetGTA->GetOwnedGameplayTags(CurrentTags);

		if(GTCCache != CurrentTags)
		{
			GTCCache = CurrentTags;
			OnGameplayTagChanged.Broadcast(GTCCache);
		}
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle_Poll);
		OnTargetNotValid.Broadcast(FGameplayTagContainer::EmptyContainer);
		
		SetReadyToDestroy();
		MarkAsGarbage();
	}
}
