#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Triangle: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Triangle: Click at second corner");
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at third corner");
	pIn->GetPointClicked(P3.x, P3.y);
	RectGfxInfo.isFilled = false;
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2,P3, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
