//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Notatnik_cpp.h"
#include "OProgramie_cpp.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNotatnik *Notatnik;
bool __fastcall TNotatnik::Sprawdz()
{
                if(!obszar_edycji_tekstu->Modified)
                  return (true);
                int Odp=MessageDlg("Plik zostal zmodyfikowany. Czy zapisac zmiany?",mtConfirmation,mbYesNoCancel,0);
                switch(Odp)
                {
                      case mrYes:
                      ToolButtonZapisz->Click();
                      return (!obszar_edycji_tekstu->Modified);
                      case mrNo:
                           return (true);
                      default:
                              return (false);
                }
}
void __fastcall TNotatnik::FZaznaczono()
{
                if(obszar_edycji_tekstu->SelLength>0)
                {
                  mpWytnij->Enabled=true;
                  ToolButtonWytnij->Enabled=true;
                  Wytnij->Enabled=true;
                  mpKopiuj->Enabled=true;
                  ToolButtonKopiuj->Enabled=true;
                  Kopiuj->Enabled=true;
                  mpUsun->Enabled=true;
                  Usun->Enabled=true;

                }
                else
                {
                  mpWytnij->Enabled=false;
                  ToolButtonWytnij->Enabled=false;
                  Wytnij->Enabled=false;
                  mpKopiuj->Enabled=false;
                  ToolButtonKopiuj->Enabled=false;
                  Kopiuj->Enabled=false;
                  Usun->Enabled=false;
                }
}
void __fastcall TNotatnik::Pasek()
{
                pasek_stanu->Panels->Items[0]->Text=IntToStr(obszar_edycji_tekstu->CaretPos.x+1)+":"+IntToStr(obszar_edycji_tekstu->CaretPos.y+1);
                if(obszar_edycji_tekstu->Modified)
                  pasek_stanu->Panels->Items[1]->Text="Modyfikacja";
                else
                  pasek_stanu->Panels->Items[1]->Text="";
}
//---------------------------------------------------------------------------
__fastcall TNotatnik::TNotatnik(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::OProgramieClick(TObject *Sender)
{
                FOProgramie->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNotatnik::CzcionkaClick(TObject *Sender)
{
                if(FontDialog1->Execute())
                  obszar_edycji_tekstu->Font=FontDialog1->Font;
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ZawijanieWierszyClick(TObject *Sender)
{
                ZawijanieWierszy->Checked=(ZawijanieWierszy->Checked==false);
                obszar_edycji_tekstu->WordWrap=ZawijanieWierszy->Checked;
                if(!ZawijanieWierszy->Checked)
                  obszar_edycji_tekstu->ScrollBars=ssHorizontal;
                else
                  obszar_edycji_tekstu->ScrollBars=ssNone;
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::PasekStanuClick(TObject *Sender)
{
                pasek_stanu->Visible=PasekStanu->Checked==false;
                Widok->Items[0]->Checked=(Widok->Items[0]->Checked==false);
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::PasekNarzedziClick(TObject *Sender)
{
                pasek_narzedzi->Visible=(PasekNarzedzi->Checked==false);
                Widok->Items[1]->Checked=(Widok->Items[1]->Checked==false);
}
//---------------------------------------------------------------------------

void __fastcall TNotatnik::ToolButtonWytnijClick(TObject *Sender)
{
                obszar_edycji_tekstu->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ToolButtonKopiujClick(TObject *Sender)
{
                obszar_edycji_tekstu->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ToolButtonWklejClick(TObject *Sender)
{
                obszar_edycji_tekstu->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ZaznaczWszystkoClick(TObject *Sender)
{
                obszar_edycji_tekstu->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::GodzinaDataClick(TObject *Sender)
{
                obszar_edycji_tekstu->Text=obszar_edycji_tekstu->Text+
                TimeToStr(Time())+" "+DateToStr(Date());
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::FormCloseQuery(TObject *Sender, bool &CanClose)
{
                CanClose=Sprawdz();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ToolButtonOtworzClick(TObject *Sender)
{
                if(Sprawdz()&&OpenDialog1->Execute())
                  obszar_edycji_tekstu->Lines->LoadFromFile(OpenDialog1->FileName);
                obszar_edycji_tekstu->Modified=false;
                Pasek();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ToolButtonNowyClick(TObject *Sender)
{
                if(Sprawdz())
                  obszar_edycji_tekstu->Clear();
                obszar_edycji_tekstu->Modified=false;
                Pasek();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ToolButtonZapiszClick(TObject *Sender)
{
                if(SaveDialog1->FileName=="")
                  ZapiszJako->Click();
                else
                {
                  obszar_edycji_tekstu->Lines->SaveToFile(SaveDialog1->FileName);
                  obszar_edycji_tekstu->Modified=false;
                  Pasek();
                }
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ZakonczClick(TObject *Sender)
{
                Notatnik->Close();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::ZapiszJakoClick(TObject *Sender)
{
                if(SaveDialog1->Execute())
                  obszar_edycji_tekstu->Lines->SaveToFile(SaveDialog1->FileName);
                obszar_edycji_tekstu->Modified=false;
                Pasek();
}
//---------------------------------------------------------------------------

void __fastcall TNotatnik::obszar_edycji_tekstuChange(TObject *Sender)
{
                Pasek();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::mpCofnijClick(TObject *Sender)
{
                if(obszar_edycji_tekstu->HandleAllocated())
                  SendMessage(obszar_edycji_tekstu->Handle,EM_UNDO, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::obszar_edycji_tekstuMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
                FZaznaczono();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::obszar_edycji_tekstuKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
                FZaznaczono();
}
//---------------------------------------------------------------------------


void __fastcall TNotatnik::obszar_edycji_tekstuMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
                Pasek();
}
//---------------------------------------------------------------------------

void __fastcall TNotatnik::obszar_edycji_tekstuDragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
                Pasek();
}
//---------------------------------------------------------------------------

void __fastcall TNotatnik::obszar_edycji_tekstuKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{

                Pasek();
}
//---------------------------------------------------------------------------
void __fastcall TNotatnik::FormCreate(TObject *Sender)
{

                FZaznaczono();
}
//---------------------------------------------------------------------------

