//---------------------------------------------------------------------------

#ifndef Notatnik_cppH
#define Notatnik_cppH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TNotatnik : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *menu;
        TMenuItem *Plik;
        TMenuItem *Edycja;
        TMenuItem *Widok;
        TMenuItem *Format;
        TMenuItem *Pomoc;
        TToolBar *pasek_narzedzi;
        TImageList *ImageList1;
        TToolButton *ToolButtonOtworz;
        TToolButton *ToolButtonNowy;
        TToolButton *ToolButtonZapisz;
        TToolButton *ToolButtonSeparator;
        TToolButton *ToolButtonWytnij;
        TToolButton *ToolButtonKopiuj;
        TToolButton *ToolButtonWklej;
        TMemo *obszar_edycji_tekstu;
        TMenuItem *Nowy;
        TMenuItem *Otworz;
        TMenuItem *Zapisz;
        TMenuItem *ZapiszJako;
        TMenuItem *Wytnij;
        TMenuItem *Kopiuj;
        TMenuItem *Wklej;
        TMenuItem *Zakoncz;
        TMenuItem *Usun;
        TMenuItem *ZaznaczWszystko;
        TMenuItem *GodzinaData;
        TMenuItem *PasekStanu;
        TMenuItem *PasekNarzedzi;
        TMenuItem *ZawijanieWierszy;
        TMenuItem *Czcionka;
        TMenuItem *OProgramie;
        TPopupMenu *menu_podreczne;
        TMenuItem *mpCofnij;
        TMenuItem *mpWytnij;
        TMenuItem *mpKopiuj;
        TMenuItem *mpWklej;
        TMenuItem *mpZaznaczwszystko;
        TFontDialog *FontDialog1;
        TOpenDialog *OpenDialog1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *mpUsun;
        TSaveDialog *SaveDialog1;
        TStatusBar *pasek_stanu;
        void __fastcall OProgramieClick(TObject *Sender);
        void __fastcall CzcionkaClick(TObject *Sender);
        void __fastcall ZawijanieWierszyClick(TObject *Sender);
        void __fastcall PasekStanuClick(TObject *Sender);
        void __fastcall PasekNarzedziClick(TObject *Sender);
        void __fastcall ToolButtonWytnijClick(TObject *Sender);
        void __fastcall ToolButtonKopiujClick(TObject *Sender);
        void __fastcall ToolButtonWklejClick(TObject *Sender);
        void __fastcall ZaznaczWszystkoClick(TObject *Sender);
        void __fastcall GodzinaDataClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall ToolButtonOtworzClick(TObject *Sender);
        void __fastcall ToolButtonNowyClick(TObject *Sender);
        void __fastcall ToolButtonZapiszClick(TObject *Sender);
        void __fastcall ZakonczClick(TObject *Sender);
        void __fastcall ZapiszJakoClick(TObject *Sender);
        void __fastcall obszar_edycji_tekstuChange(TObject *Sender);
        void __fastcall mpCofnijClick(TObject *Sender);
        void __fastcall obszar_edycji_tekstuMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall obszar_edycji_tekstuKeyUp(TObject *Sender,
          WORD &Key, TShiftState Shift);
        void __fastcall obszar_edycji_tekstuMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall obszar_edycji_tekstuDragDrop(TObject *Sender,
          TObject *Source, int X, int Y);
        void __fastcall obszar_edycji_tekstuKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNotatnik(TComponent* Owner);
        bool __fastcall TNotatnik::Sprawdz();
        void __fastcall TNotatnik::FZaznaczono();
		void __fastcall TNotatnik::Pasek();
};
//---------------------------------------------------------------------------
extern PACKAGE TNotatnik *Notatnik;
//---------------------------------------------------------------------------
#endif
