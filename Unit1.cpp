//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "sqlite3.h"
#include "Unit1.h"
#include "string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;

sqlite3* Database;
int status;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
   sqlite3_open("bub.db" , &Database);
	if (sqlite3_open("bub.db" , &Database)==SQLITE_OK)
	{
		ShowMessage("Добро пожаловать в список контактов");
	}
	 else
	 {
      ShowMessage("Не можем открыть базу");
	 }
	VirtualStringTree1->NodeDataSize = sizeof(BasaBub);
	loadbase() ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::loadbase()
{
char *errmsg;
sqlite3_stmt *stat;
int res = sqlite3_prepare_v2(Database,"SELECT id, name FROM bub", -1, &stat, NULL);
while(true)
{
	res = sqlite3_step(stat);
	if(res != SQLITE_ROW) break;

	int n = sqlite3_column_int(stat, 0);
	unsigned char *str = (unsigned char *)sqlite3_column_text(stat, 1);


	PVirtualNode entryNode = (PVirtualNode)VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
	BasaBub *nodeData = (BasaBub*)VirtualStringTree1->GetNodeData(entryNode);

	nodeData->id=n;
	nodeData->name=(UnicodeString)(char*)str;

}
sqlite3_finalize(stat);
}
void __fastcall TForm1::VirtualStringTree1Text(TBaseVirtualTree *Sender, PVirtualNode Node,
		  TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)
  ///вывод данных
{
BasaBub *nodeData = (BasaBub*)Sender->GetNodeData(Node);
switch(Column)
{
	case 0: CellText = nodeData->id; break;
	case 1: CellText = nodeData->name; break;

}
}

void __fastcall TForm1::VirtualStringTree1Add(TBaseVirtualTree *Sender,
		  PVirtualNode Node)
{
	sqlite3_stmt *stat;
	//Обработчик события для выделения строки
	if(!Node) return;
	BasaBub *nodeData = (BasaBub*)Sender->GetNodeData(Node);

	UnicodeString bub = "SELECT phone FROM bub WHERE id="+IntToStr(nodeData->id);
	wchar_t *st = bub.t_str();
	char u[20];
	wcstombs(u, st, wcslen(st)+1);
	int res = sqlite3_prepare_v2(Database,u,-1,&stat,NULL);
	res = sqlite3_step(stat);
	/// значение в переменную read
	unsigned char *read = (unsigned char *)sqlite3_column_text(stat, 0);
	///на форме
	Label1->Caption = "Тулефон "+(UnicodeString)(char*)read;
	sqlite3_finalize(stat);
}
 void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
sqlite3_close(Database);
}



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	sqlite3_stmt *stat;
		PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;
		BasaBub *nodeData = (BasaBub*)VirtualStringTree1->GetNodeData(selectedNode);
		int selectedNodeIndex = nodeData->id;
			///в базе
		UnicodeString sql_del = "DELETE FROM bub WHERE id=" + IntToStr(selectedNodeIndex);
		wchar_t *del = sql_del.t_str();
		char u[10];
		wcstombs(u, del, wcslen(del)+1);
		int res = sqlite3_prepare_v2(Database,u,-1,&stat,NULL);
		res = sqlite3_step(stat);
		sqlite3_finalize(stat);
		 ///на форме
		VirtualStringTree1->DeleteNode(selectedNode);
		ShowMessage("Контакт удален!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
sqlite3_stmt *stat;
	const char* c = "DELETE FROM bub";
	int res = sqlite3_prepare_v2(Database,c,-1,&stat,NULL);
	res = sqlite3_step(stat);
	sqlite3_finalize(stat);
	/// на форме
	VirtualStringTree1->Clear();
	ShowMessage("Удалены все контакты!");
}
//---------------------------------------------------------------------------

