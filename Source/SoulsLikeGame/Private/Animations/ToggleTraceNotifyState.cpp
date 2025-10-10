// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ToggleTraceNotifyState.h"




UTraceComponent* UToggleTraceNotifyState::GetTraceComponent(USkeletalMeshComponent* SkeletalMesh)
{
	UTraceComponent* TraceComp{
		SkeletalMesh->GetOwner()->FindComponentByClass<UTraceComponent>()
	};
	return TraceComp;
}

void UToggleTraceNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	UTraceComponent* TraceComp{ GetTraceComponent(MeshComp) };

	if (!IsValid(TraceComp)) { return; }

	TraceComp->bisAttacking = true;
}

void UToggleTraceNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	UTraceComponent* TraceComp{ GetTraceComponent(MeshComp) };

	if (!IsValid(TraceComp)) { return; }

	TraceComp->bisAttacking = false;
}
