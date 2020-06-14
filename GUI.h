///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel;
		wxStaticText* m_descriptionText;
		wxRadioButton* m_option1;
		wxRadioButton* m_option2;
		wxRadioButton* m_option3;
		wxChoice* m_funChoice;
		wxStaticText* m_paramText1;
		wxTextCtrl* m_paramCtrl1;
		wxStaticText* m_paramText2;
		wxTextCtrl* m_paramCtrl2;
		wxStaticText* m_paramText3;
		wxTextCtrl* m_paramCtrl3;
		wxStaticText* m_paramText4;
		wxTextCtrl* m_paramCtrl4;
		wxStaticText* m_paramText5;
		wxTextCtrl* m_paramCtrl5;
		wxStaticText* m_paramText6;
		wxTextCtrl* m_paramCtrl6;
		wxStaticText* m_paramText7;
		wxTextCtrl* m_paramCtrl7;
		wxButton* m_saveButton;
		wxStaticText* m_rotateText1;
		wxSlider* m_rotateSlider1;
		wxStaticText* m_rotateVal1;
		wxStaticText* m_rotateText2;
		wxSlider* m_rotateSlider2;
		wxStaticText* m_rotateVal2;
		wxStaticText* m_rotateText3;
		wxSlider* m_rotateSlider3;
		wxStaticText* m_rotateVal3;
		wxButton* m_resetAxes;

		// Virtual event handlers, overide them in your derived class
		virtual void m_panelRepaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_option1OnRadioButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_option2OnRadioButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_option3OnRadioButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_onFunChoice(wxCommandEvent& event) { event.Skip(); }
		virtual void m_paramCtrl1OnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_paramCtrl2OnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_paramCtrl3OnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_paramCtrl4OnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_paramCtrl5OnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_paramCtrl6OnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_paramCtrl7OnText(wxCommandEvent& event) { event.Skip(); }
		virtual void m_saveButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_rotateSlider1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_rotateSlider2OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_rotateSlider3OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_onAxesReset( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Projekt nr 33"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 840,530 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

