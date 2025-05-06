// Fill out your copyright notice in the Description page of Project Settings.


#include "EVILWOMEN_TASK_SECTORSWITCH.h"

#include <ThirdParty/ShaderConductor/ShaderConductor/External/DirectXShaderCompiler/include/dxc/DXIL/DxilConstants.h>

#include "AICEvilWomen.h"

UEVILWOMEN_TASK_SECTORSWITCH::UEVILWOMEN_TASK_SECTORSWITCH()
{

	NodeName="Sector Switch";
}

EBTNodeResult::Type UEVILWOMEN_TASK_SECTORSWITCH::ExecuteTask(UBehaviorTreeComponent* OwnerComp, uint8* NodeMemory)
{
if (auto cont=Cast<AAICEvilWomen>(OwnerComp->GetAIOwner()))
{

if (auto bc=cont->GetBlackboardComponent())
{

if (auto EvilWomen=cont->GetPawn())
{

     int cs=bc->GetValueAsInt("SectorID");



	EBTNodeResult::Succeeded;
}
	
}
	
}

	return EBTNodeResult::Failed;
}
